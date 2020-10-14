import sys
import math


def maxDistToClosest(seats):
    left = 0
    for i in range(len(seats)):
        if seats[i] == 'x':
            break
        left += 1

    right = 0
    for i in range(len(seats)):
        if seats[-i - 1] == 'x':
            break
        right += 1

    midCurrent = 0
    midMax = 0
    for i in range(left, len(seats)):
        if seats[i] == 'x':
            midCurrent = 0
        else:
            midCurrent += 1
            midMax = max(midMax, midCurrent)

    return max(left, right, math.ceil(midMax / 2)) - 1


que = sys.stdin.readlines()[1].strip()
print(maxDistToClosest(que))
