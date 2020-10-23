import sys

def merge(intervals):
    if len(intervals) == 0:
        return []

    intervals.sort()
    new = [intervals[0]]
    for i in range(1, len(intervals)):
        if new[-1][1] >= intervals[i][0]:
            new[-1][1] = max(new[-1][1], intervals[i][1])
        else:
            new.append(intervals[i])

    return new

intervals = []
lines = sys.stdin.readlines()
for i in range(1, len(lines)):
    intervals.append(list(map(lambda x: int(x), lines[i].split())))

for i in merge(intervals):
    print(i[0], i[1])
