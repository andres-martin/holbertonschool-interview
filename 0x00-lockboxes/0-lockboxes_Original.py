#!/usr/bin/python3
"""Algorithm practice"""


def canUnlockAll(boxes):
    """ Check if all boxes can be opened"""

    if boxes is None or not isinstance(boxes, list):
        return False

    if not boxes: boxes.append([0])

    keys = set(range(len(boxes)))
    starting_keys = set(boxes[0] or [0])
    available_keys = starting_keys.copy()
    used_keys = set([0])

    while True:
        temp_keys = {0}

        for real_index, index in enumerate(available_keys):
            used_keys.add(index)

            for key in boxes[index]:
                if key not in used_keys:
                    temp_keys.add(key)

        if used_keys == keys:
            return True

        if real_index + 1 == len(available_keys) and len(temp_keys) == 1:
            return False

        available_keys = temp_keys
