# Multiples of 3 and 5
# Problem 1

# Find the sum of all the multiples of 3 or 5 below 1,000

def multiples(n):
    if (n % 3 == 0) or (n % 5 == 0):
        return True
    return False

total = 0
for i in range(0, 1000):
    if multiples(i) == True:
        total += i

print("The total is", total)
