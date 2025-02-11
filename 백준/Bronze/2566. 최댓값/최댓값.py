matrix = []

for _ in range(9):
    matrix.append(list(map(int, input().split())))
    
max_value = matrix[0][0]
row_idx, col_idx = 1, 1
for row in range(9):
    for col in range(9):
        if (matrix[row][col] > max_value):
            max_value = matrix[row][col]
            row_idx = row+1
            col_idx = col+1

print(max_value)
print(f"{row_idx} {col_idx}")