from random import randint
from decimal import Decimal

with open('data.txt', 'w') as f:
    for x in range(2000):
        value = randint(-100, 200)
        f.write(f"{value}, {Decimal(value*(9/5)+32).quantize(Decimal('0.00'))}\n") #We save the temperature in celcius separated by comma of the temperature in farenheit