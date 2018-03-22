from itertools import combinations

from utils import pair_in_partitions_dict


class Formula:
    """
    A `horzlen`-place formula in predicate logic.

    `horz` is a vector of integers between 0 and `vertlen`-1.
    `vert` is a vector of booleans. 0 stands for the universal, 1 for the existential quantifier.

    """

    def __init__(self, vert, horz, partitions_dict={}):
        self.vert = list(vert)
        self.horz = list(horz)

        self.horzlen = len(self.horz)
        self.vertlen = len(self.vert)

        self.partitions_dict = partitions_dict

    def insert(self, index):
        if self.vert[-1]:  # if the last quantifier is existential
            newvert = self.vert + [False]
            newvertlen = self.vertlen + 1
        else:
            newvert = self.vert
            newvertlen = self.vertlen
        newhorz = self.horz[:]
        newhorz.insert(index, newvertlen-1)
        return Formula(newvert, newhorz)

    def complement(self):
        newvert = [not vertval for vertval in self.vert]
        return Formula(newvert, self.horz)

    def abbr(self, gapstr=None):
        # `partitions_dict` must contain the singleton blocks for this to work.
        # The order of the blocks is used as it is, so `Formula` objects that describe
        # the same formula could have different abbreviations.
        if gapstr is None:
            gapstr = ' '
        abbr_str = ''
        for vertindex, vertval in enumerate(self.vert):
            letter = 'e' if vertval else 'a'
            positions = [j for j, horzval in enumerate(self.horz) if horzval == vertindex]
            abbr_str += letter
            if vertindex not in self.partitions_dict.keys():
                for position in positions:
                    abbr_str += str(position + 1)
            else:
                partition = self.partitions_dict[vertindex]

                # check if partition actually is a partition of positions
                should_be_positions = []
                for block in partition:
                    should_be_positions += block
                should_be_positions = sorted(should_be_positions)
                if not should_be_positions == positions:
                    print('The partition does not match the positions!')

                for block in partition:
                    if len(block) > 1:
                        abbr_str += '('
                        for element in block:
                            abbr_str += str(element + 1)
                        abbr_str += ')'
                    else:
                        abbr_str += str(block[0] + 1)
            if vertindex < self.vertlen - 1:
                abbr_str += gapstr
        return abbr_str

    def octal(self):  # pseudo-octal representation of pairs
        digits = ''
        last_a = 0
        for a, b in combinations(range(self.horzlen), 2):
            if not a == last_a:
                digits += '-'  # prettify
            last_a = a
            eleft = self.vert[self.horz[a]]  # True the left side is existential quant. (red)
            if not self.vert[self.horz[a]] == self.vert[self.horz[b]]:
                if self.horz[a] < self.horz[b]:
                    digit = '1' if eleft else '6'
                elif self.horz[a] > self.horz[b]:
                    digit = '3' if eleft else '4'
            else:
                coinciding = pair_in_partitions_dict((a, b), self.partitions_dict)
                if eleft:
                    digit = '5' if coinciding else '7'
                else:
                    digit = '2' if coinciding else '0'

            digits += digit
        return digits





