from cs50 import get_float


def main():
    cents = get_cents()
    quarters = calculate_quarters(cents)
    dimes = calculate_dimes(cents)
    nickels = calculate_nickels(cents)
    pennies = calculate_pennies(cents)


def get_cents():
    while True:  # prompt user for money
        num = get_float("Change owed: ")
        if num > 0:
            return num

