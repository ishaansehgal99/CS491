def dfs_floodfill(board, N, visited, x, y):
    if x < 0 or x >= N or y < 0 or y >= N:
        return
    if (x, y) in visited:
        return

    visited[(x, y)] = True
    if board[x][y] == 'x' or board[x][y] == '@':
        board[x][y] = '.'
        dfs_floodfill(board, N, visited, x + 1, y)
        dfs_floodfill(board, N, visited, x, y + 1)
        dfs_floodfill(board, N, visited, x - 1, y)
        dfs_floodfill(board, N, visited, x, y - 1)


def fill_board():
    N = int(input())
    board = []
    for b_idx in range(N):
        b_line = input()
        board.append(list(b_line))
    return board, N


num_tests = int(input())
for i in range(num_tests):
    # Populate board
    board, N = fill_board()

    visited = {}
    num_ships = 0
    for row in range(N):
        for col in range(N):
            if board[row][col] == 'x':
                dfs_floodfill(board, N, visited, row, col)
                num_ships += 1
    print("Case %d: %d" % (i+1, num_ships))

