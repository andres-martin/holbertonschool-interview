#!/usr/bin/python3
''' this algo uses best OOP practices, be clean coder!'''


def minOperations(n):
    ''' calculates the fewest number of
        operations needed to result in exactly n '''

    if n <= 1 or not isinstance(n, int):
        return 0

    clip = ClipBoardOperations(1)
    clip.copy_all()

    while n is not clip.clipboard:
        clip.paste()

        if n == clip.clipboard:
            return clip.number_of_operations

        if n % clip.clipboard == 0:
            clip.copy_all()


class ClipBoardOperations:
    ''' clipboard operations '''

    def __init__(self, data):
        self.__clipboard = data
        self.__copy_operation = 0
        self.__number_of_operations = 0

    @property
    def clipboard(self):
        return self.__clipboard

    @property
    def number_of_operations(self):
        return self.__number_of_operations

    @clipboard.setter
    def clipboard(self, value):
        self.__clipboard = value

    def copy_all(self):
        self.__copy_operation = self.__clipboard
        self.__number_of_operations -= -1

    def paste(self):
        self.__clipboard += self.__copy_operation
        self.__number_of_operations -= -1
