fib_array = [0, 1]

def recursive_fibo(n):
    
    if n < len(fib_array):
        return fib_array[n]
    else:
        fib = recursive_fibo(n-1) + recursive_fibo(n-2)
        fib_array.append(fib)

    return fib
   
