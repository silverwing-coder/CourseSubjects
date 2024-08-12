def main():

    number = int(input("Enter an Integer: "))

    if number > 1:
        print(2, " ")
        # isPrime = True
        for i in range(3, number+1):
            isPrime = True
            for j in range(2, i-1):
                if (i % j) == 0:
                    isPrime = False
                    break
            if isPrime:
                print(i, " ")

if __name__ == '__main__':
    main()





