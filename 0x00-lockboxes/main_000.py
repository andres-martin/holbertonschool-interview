#!/usr/bin/python3
canUnlockAll = __import__('0-lockboxes').canUnlockAll
boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))
boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))
boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))
boxes = [[], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))
boxes = []
print(canUnlockAll(boxes))
boxes = [[-1, 5, 3, 4], [], [], [], []]
print(canUnlockAll(boxes))
boxes = [[1, 2, 3, 4, 9, 18], [], [], [], []]
print(canUnlockAll(boxes))
boxes = [[4], [], [], [], [1, 2, 3]]
print(canUnlockAll(boxes))
boxes = [[1], []]
print(canUnlockAll(boxes))
boxes = [[4], [], [], [], [1, 9, 3]]
print(canUnlockAll(boxes))
boxes = [[4], [], [], []]
print(canUnlockAll(boxes))
boxes = [[1], [1,2,4,6,7,8], [9,9,9,9], [], [1, 2]]
print(canUnlockAll(boxes))
boxes = [[], []]
print(canUnlockAll(boxes))
boxes = "a"
print(canUnlockAll(boxes))
