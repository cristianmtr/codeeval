#!/usr/bin/python
# -*- encoding: utf-8 -*-
# Write a program that outputs all possibilities
# to put + or - or nothing between the numbers
# 1, 2, ..., 9 (in this order) such that the result
# is always 100.
# For example: 1 + 2 + 34 – 5 + 67 – 8 + 9 = 100.
from itertools import product as cartesianproduct


def main():
    cases = [list(case) for case in list\
             (cartesianproduct([' ','-','+'],repeat=8))]
    print 'total nr of cases = {}'.format(len(cases))
    solutions = 0
    for case in cases:
        # first we need to combine the numbers that have
        # blanks between them
        numbers = [1,2,3,4,5,6,7,8,9]
        while " " in case:
            idx = case.index(" ")
            numbers[idx] = numbers[idx] * 10 + numbers.pop(idx+1)
            case.pop(idx)
        i = 0
        while i < len(case):
            symbol = case[i]
            if symbol == '-':
                numbers[0] = numbers[0] - numbers.pop(1)
            if symbol == '+':
                numbers[0] = numbers[0] + numbers.pop(1)
            i += 1
        if numbers[0] == 100:
            solutions += 1
            print 'found case: {}'.format(''.join(case))
    print 'solutions = {}'.format(solutions)
    return


if __name__ == "__main__":
    main()

