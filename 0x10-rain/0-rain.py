#!/usr/bin/python3
'''rain algo'''


def rain(walls=[]):
    """ self descriptive """
    if not walls or len(walls) == 0:
        return 0

    return sum(walls[1:-2])
