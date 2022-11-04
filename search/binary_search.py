def binary_search(numbers, target):
    first = 0
    last = len(numbers) - 1

    while first <= last:
        midpoint = (first + last)//2
        
        if numbers[midpoint] == target:
            return midpoint
        elif numbers[midpoint] < target:
            first = midpoint + 1
        else:
            last = midpoint - 1

    return None


def verify(index):

    if index is not None:
        print("Target found at index: ", index)
    else:
        print("Target not found in list")


numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

result = binary_search(numbers, 12)
verify(result)

result = binary_search(numbers, 9)
verify(result)
