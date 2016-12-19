"""
The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
"""

n = 0
i = 1
while i <= 1000:
    n += i**i
    i += 1

n %= (10**10)

print(n)
