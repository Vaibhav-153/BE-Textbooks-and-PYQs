def generateMagicSquare(n):
    if n % 2 == 0:
        print("Magic squares are only defined for odd order. Please provide an odd value of n.")
        return

    magic_square = [[0] * n for _ in range(n)]

    i, j = 0, n // 2
    num = 1

    while num <= n * n:
        magic_square[i][j] = num
        num += 1

        newi, newj = (i - 1) % n, (j + 1) % n

        if magic_square[newi][newj] == 0:
            i, j = newi, newj
        else:
            i += 1

    print("Magic Square for n =", n)
    print("Common sum for each row, column, and diagonal:", n * (n * n + 1) // 2, "\n")

    for row in magic_square:
        for element in row:
            print('%2d ' % element, end='')
        print()

# Driver Code
n = int(input("Enter the order of the Magic Square (odd number): "))
generateMagicSquare(n)
