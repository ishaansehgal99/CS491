
def check_all_unique_digits(num1, num2):
    n1 = str(num1)
    n2 = str(num2)
    if len(n1) == 4 and len(n2) == 4:
        return False
    if len(n1) == 4 and '0' in n2:
        return False
    if len(n2) == 4 and '0' in n1:
        return False

    if len(set(n1 + n2)) != len(n1 + n2):
        return False
    return True

    # Slightly slower performance
    # digits = set()
    #
    # for num in [num1, num2]:
    #     count = 0
    #     while num > 0:
    #         if num % 10 in digits:
    #             return False
    #         else:
    #             digits.add(num % 10)
    #             num //= 10
    #         count += 1
    #     if count == 4:
    #         if 0 in digits:
    #             return False
    #         else:
    #             digits.add(0)
    # return True


four_range = [num for num in range(1000, 10000)]
four_range = set(filter(lambda x: '0' not in str(x) and len(set(str(x))) == 4, four_range))

five_range = [num for num in range(10000, 100000)]
five_range = set(filter(lambda x: len(set(str(x))) == 5, five_range))

ranges = [four_range, five_range]

N = int(input())

while N != 0:

    combos = []
    for rang in ranges:
        for num in rang:
            if num / N in ranges[0] or num / N in ranges[1]:
                if check_all_unique_digits(num, num // N):
                    combos.append((num, num // N))

    if len(combos) == 0:
        print("There are no solutions for %d." % N)
    else:
        for ans in combos:
            ans0 = str(ans[0])
            ans1 = str(ans[1])

            ans0_len = len(ans0)
            ans1_len = len(ans1)
            if ans0_len == 4 and ans1_len == 4:
                print("0%d / 0%d = %d" % (ans[0], ans[1], N))
            elif ans1_len == 4:
                print("%d / 0%d = %d" % (ans[0], ans[1], N))
            elif ans0_len == 4:
                print("0%d / %d = %d" % (ans[0], ans[1], N))
            else:
                print("%d / %d = %d" % (ans[0], ans[1], N))

    N = int(input())
    if N != 0:
        print()



