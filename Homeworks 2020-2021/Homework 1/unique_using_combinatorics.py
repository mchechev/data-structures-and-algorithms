import sys


def uniques_between(a, b):
    if b - a < 1000:
        return uniques_between_naive(a, b) # the logic breaks for b - a < 10 so let's brute force it
    a_len = len(str(a))
    b_len = len(str(b))
    uniques = uniques_with_n_digits_bigger_than_w(a) - uniques_with_n_digits_bigger_than_w(b)
    while a_len < b_len:
        a_len += 1
        uniques += uniques_with_n_digits(a_len)

    return uniques


def uniques_between_naive(a, b):
    total = 0
    for i in range(a, b + 1):
        if len(set(str(i))) == len(str(i)):
            total += 1
    return total


def uniques_with_n_digits_bigger_than_w(w):
    n = len(str(w))
    w = next_unique(w)
    last_non_zero = len(w) - 1
    while last_non_zero >= 0 and w[last_non_zero] == 0:
        last_non_zero -= 1

    uniques = 0
    while len(w) == n:
        used_digits = set(w[0: last_non_zero])
        available_digits = set(
            range(w[last_non_zero], 10)).difference(used_digits)
        local_uniques = len(available_digits)
        for i in range(last_non_zero + 1, len(w)):
            local_uniques *= 10 - i
        uniques += local_uniques
        w[last_non_zero] = 0
        last_non_zero -= 1
        w = plus_one(w, last_non_zero)

    return uniques


def uniques_with_n_digits(n):
    uniques = 9
    while n > 1:
        uniques *= 10 - n + 1
        n -= 1
    return uniques


def next_unique(num):
    if isinstance(num, int):
        num = list(map(lambda x: int(x), list(str(num))))

    digits = set()
    fail_index = None
    second_zero = None
    for index, digit in enumerate(num):
        if digit not in digits and second_zero is None:
            digits.add(digit)
        elif digit == 0 and second_zero is None:
            second_zero = index
        elif digit == 0:
            pass
        elif digit != 0 and second_zero is not None:
            fail_index = second_zero
            break
        else:
            fail_index = index
            break

    if fail_index is not None:
        for i in range(fail_index + 1, len(num)):
            num[i] = 0
        num = plus_one(num, fail_index)
        return next_unique(num)
    return num


def plus_one(arr_num, index):
    carry = 1
    for i in range(index, -1, -1):
        arr_num[i] += carry
        if arr_num[i] >= 10:
            arr_num[i] -= 10
            carry = 1
        else:
            carry = 0
    if carry == 1:
        arr_num = [1] + arr_num
    return arr_num


start, end = list(map(lambda x: int(x), sys.stdin.readline().split(' ')))

print(uniques_between(start, end))
