#!/usr/bin/python3
'''rain algo'''
from typing import List


def rain(walls: List[int]) -> int:
    """ Return: Integer indicating
        total amount of rainwater retained.
    """
    if not walls or len(walls) == 0:
        return 0

    return sum(walls[1:-2])
