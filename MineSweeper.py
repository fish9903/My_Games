# minesweeper(print map)

row, col = map(int, input().split())

# input map
matrix = []
for i in range(row):
    matrix.append(list(input()))

# '.' -> 0
for i in range(row):
    for j in range(col):
        if matrix[i][j] == '.':
            matrix[i][j] = int(0)

# find '*' and work
for i in range(row):
    for j in range(col):
        
        if matrix[i][j] == '*':
            
            for ii in range(i - 1, i + 2):
               for jj in range(j - 1, j + 2):
                  
                    if ii < 0 or ii > row - 1 or jj < 0 or jj > col - 1:
                        continue
                    if matrix[ii][jj] != '*':
                        matrix[ii][jj] += 1


# print
for i in range(row):
    for j in range(col):
        print(matrix[i][j], end = ' ')
    print()