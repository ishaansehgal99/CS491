from copy import deepcopy

def solveNQueens(n):
    """
    :type n: int
    :rtype: List[List[str]]
    """
    board = ["." * n for x in range(n)]
    solutions = []
    placeQueensBoard(board, n, 0, 0, solutions)
    return solutions

def placeQueensBoard(board, numQueensLeft, row, col, solutions):
    if numQueensLeft == 0:
        solutions.append(deepcopy(board))
        return
    while row < len(board):
        while col < len(board[0]):
            if couldPlaceQueen(row, col):
                addQueen(row, col)
                board[row] = board[row][:col] + 'Q' + board[row][col + 1:]
                placeQueensBoard(board, numQueensLeft - 1, row, col+1, solutions)
                removeQueen(row, col)
                board[row] = board[row][:col] + '.' + board[row][col + 1:]
            col += 1
        col = 0
        row += 1


def couldPlaceQueen(row, col):
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
print(solveNQueens(4))


