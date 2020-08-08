'''
Project Euler, Problem 2
Find the sum of all even-valued terms in fibonacci under 4,000,000
'''

MAX = 4000000
evens = []
total = 0

def fibonacci(n):
    a = 0
    b = 1
    
    if n == 0: return a

    for i in range(2, n+1):
        c = a + b
        a = b
        b = c
    
    return b

for i in range(0, 50):
    temp = fibonacci(i)
    if temp > MAX: break
    if temp % 2 == 0: evens.append(temp)

for n in evens:
    total += n

print(total)

