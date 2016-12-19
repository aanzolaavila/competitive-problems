"""2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
"""

n = 2 ** 1000
suma = 0
while n > 0:
    suma += n % 10
    n //= 10

print(suma)
