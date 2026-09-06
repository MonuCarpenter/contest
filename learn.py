def main():
    test_cases = int(input())
    for i in range(test_cases):
        solve()


def solve():
    n = int(input())
    diff = 0

    if n % 4 != 0:
        print("NO")
    else:
        print("YES")
        for i in range(1, n // 2 + 1):
            diff += i * 2
            print(f"{i * 2}", end=" ")

        for i in range(1, n // 2 + 1):
            diff -= i * 2 - 1
            if i == n // 2:
                print(f"{i * 2 - 1 + diff}", end=" ")
            else:
                print(f"{i * 2 - 1}", end=" ")

        print()


if __name__ == "__main__":
    main()
