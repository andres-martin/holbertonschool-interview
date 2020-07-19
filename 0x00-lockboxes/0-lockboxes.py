#!/usr/bin/python3
# import pdb; pdb.set_trace()
"""Algorithm practice"""


def canUnlockAll(boxes):
    """ Check if all boxes can be opened"""

    if len(boxes) == 0 or not isinstance(boxes, list):
        return False

    keys = set(range(len(boxes)))
    starting_keys = set(boxes[0] or [0])
    available_keys = starting_keys.copy()
    used_keys = set([0])

    while True:
        temp_keys = {0}

        for real_index, index in enumerate(available_keys):
            if isinstance(index, int) and not index > len(keys) - 1:
                used_keys.add(index)

                for key in boxes[index]:
                    if key not in used_keys:
                        temp_keys.add(key)

        if used_keys == keys:
            return True

        if real_index + 1 == len(available_keys) and len(temp_keys) == 1:
            return False

        available_keys = temp_keys
