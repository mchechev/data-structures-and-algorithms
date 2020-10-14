import sys

nums = list(map(lambda x: int(x), sys.stdin.readlines()[1:]))
total = 0
for i in range(1, len(nums)):
    if nums[i] > nums[i - 1]:
        total += nums[i] - nums[i - 1]
print(total)
