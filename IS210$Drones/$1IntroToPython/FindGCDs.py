def main():
    # print("main")
    print("Enter two Integers: ")
    number1, number2 = map(int, input().split())

    if number1 > number2:
        smaller = number2
    else:
        smaller = number1

    for i in range(1, smaller+1):
        if((number1 % i == 0) and (number2 % i == 0)):
            gcd = i

    print("GCD of", number1, "and", number2, "is", gcd)


if __name__ == '__main__':
    main()

