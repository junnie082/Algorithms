import random
import sys

numbers = [5, 2, 3, 9, 1]

def is_sorted(values):
    for index in range(len(values)-1):
        if values[index] > values[index+1]:
            return False
    return True

def bogo_sort(values):
    attempt = 0
    while not is_sorted(values):
        print(attempt)
        random.shuffle(values)
        attempt += 1
    return values

print(bogo_sort(numbers))
