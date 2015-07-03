table = {}
def fib(n):
    global table
    if table.has_key(n):
        return table[n]
    if n == 0 or n == 1:
        table[n] = n
        return n
    else:
        value = fib(n-1) + fib(n-2)
        table[n] = value
    return value
