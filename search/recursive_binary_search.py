def recursive_binary_search(numbers, target):
    if len(numbers) == 0:
        return False

    midpoint = len(numbers) // 2

    if numbers[midpoint] == target:
        return True

    if numbers[midpoint] < target:
        return recursive_binary_search(numbers[midpoint + 1:], target)
    else:
        return recursive_binary_search(numbers[:midpoint], target)


def verify(result):
    print("Target found: ", result)

numbers = [1,2,3,4,5,6,7,8]

result = recursive_binary_search(numbers, 12)
verify(result)

result = recursive_binary_search(numbers, 6)
verify(result)
