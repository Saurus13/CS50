from cs50 import get_int

while True:  # prompt user for height
    num = get_int("Height: ")
    if num > 0 and num < 9:
        break

for i in range(0, num, 1):  # double 'for' loop to print height
    for j in range(0, num, 1):
        if i + j < num - 1:
            print(" ", end="")
        else:
            print("#", end="")
    print()
