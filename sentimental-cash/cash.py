from cs50 import get_float


def main():
    cents = int(get_cents() * 100)

    quarters = calculate_quarters(cents)
    cents = cents - quarters * 25

    dimes = calculate_dimes(cents)
    cents = cents - dimes * 10

    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5

    pennies = calculate_pennies(cents)
    cents = cents - pennies * 1

    coins = quarters + dimes + nickels + pennies
    print(f"{coins}")

def get_cents():
    while True:  # prompt user for money
        num = get_float("Change owed: ")
        if num > 0:
            return num

def calculate_quarters(cents):
    quarters = 0
    for i in range(1, cents, 1):
        if i % 25 == 0:
            quarters += 1
    return quarters

def calculate_dimes(cents):
    dimes = 0
    for i in range(1, cents, 1):
        if i % 10 == 0:
            dimes += 1
    return dimes

def calculate_nickels(cents):
    nickels = 0
    for i in range(1, cents, 1):
        if i % 5 == 0:
            nickels += 1
    return nickels

def calculate_pennies(cents):
    pennies = 0
    for i in range(1, cents, 1):
        if i % 1 == 0:
            pennies += 1
    return pennies

main()


