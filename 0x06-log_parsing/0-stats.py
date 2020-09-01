#!/usr/bin/python3
"""  script that reads stdin line by line and computes metrics """

import sys

STATUS_CODES = {'200': 0,
                '301': 0, '400': 0,
                '401': 0, '403': 0,
                '404': 0, '405': 0,
                '500': 0}

total_size = 0
number_of_lines = 0


def print_status_code(total_size):
    print("File size: {:d}".format(total_size))
    for key, value in sorted(STATUS_CODES.items()):
        if value != 0:
            print("{}: {:d}".format(key, value))


try:
    for argument in sys.stdin:
        arguments = argument.split(" ")
        status_code = arguments[-2]
        file_size = arguments[-1]

        if status_code in STATUS_CODES:
            STATUS_CODES[status_code] += 1

        total_size += int(file_size)
        number_of_lines += 1

        if number_of_lines == 10:
            print_status_code(total_size)
            number_of_lines = 0

except Exception:
    pass
finally:
    print_status_code(total_size)
