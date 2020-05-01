from copy import deepcopy

def placeQueensBoard(board, numQueensLeft, row, col, solutions):
    if numQueensLeft == 0:
        solutions.append(deepcopy(board))
        return
    while row < len(board):
        while col < len(board[0]):
            if couldPlaceQueen(board, row, col):
                addQueen(row, col)
                board[row] = board[row][:col] + 'Q' + board[row][col + 1:]
                placeQueensBoard(board, numQueensLeft - 1, row, col+1, solutions)
                removeQueen(row, col)
                board[row] = board[row][:col] + '.' + board[row][col + 1:]
            col += 1
        col = 0
        row += 1


def couldPlaceQueen(board, row, col):
    if row in rows_set or col in cols_set:
        return False
    elif row - col in hills_set or row + col in dales_set:
        return False
    return True


def addQueen(row, col):
    rows_set.add(row)
    cols_set.add(col)
    hills_set.add(row - col)
    dales_set.add(row + col)


def removeQueen(row, col):
    rows_set.remove(row)
    cols_set.remove(col)
    hills_set.remove(row - col)
    dales_set.remove(row + col)



rows_set, cols_set, hills_set, dales_set = set(), set(), set(), set()

N = int(input())

for i in range(N):
    print("SOLN       COLUMN")
    print(" #      1 2 3 4 5 6 7 8\n")

    test_case = input()
    test_case = input()
    test_case_list = list(test_case)
    row, col = int(test_case_list[0]) - 1, int(test_case_list[2]) - 1

    addQueen(row, col)
    board = ["." * 8 for x in range(8)]
    board[row] = board[row][:col] + 'Q' + board[row][col + 1:]

    solutions = []
    placeQueensBoard(board, 7, 0, 0, solutions)


    answers = []
    for sol in solutions:
        row_answers = []
        col_idx = 0
        while col_idx < 8:
            for row_idx in range(8):
                if sol[row_idx][col_idx] == 'Q':
                    row_answers.append(str(row_idx + 1))
                    col_idx += 1
                    break
        answers.append(row_answers)

    answers.sort()
    idx = 1
    for ans in answers:
        if idx < 10:
            print(" %d      %s" % (idx, ' '.join(ans)))
        else:
            print("%d      %s" % (idx, ' '.join(ans)))
        idx += 1

    removeQueen(row, col)
    if i < N - 1:
        print()




