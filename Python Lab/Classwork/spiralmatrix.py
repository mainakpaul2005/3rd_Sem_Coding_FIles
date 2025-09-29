def create_spiral_matrix(n):
    matrix = [[0 for _ in range(n)] for _ in range(n)]
    top, bottom = 0, n - 1
    left, right = 0, n - 1
    num = 1

    while top <= bottom and left <= right:
        # Traverse right
        for i in range(left, right + 1):
            matrix[top][i] = num
            num += 1
        top += 1

        # Traverse down
        for i in range(top, bottom + 1):
            matrix[i][right] = num
            num += 1
        right -= 1

        # Traverse left
        if top <= bottom:  # Check if rows still exist
            for i in range(right, left - 1, -1):
                matrix[bottom][i] = num
                num += 1
            bottom -= 1

        # Traverse up
        if left <= right:  # Check if columns still exist
            for i in range(bottom, top - 1, -1):
                matrix[i][left] = num
                num += 1
            left += 1
    return matrix

def print_matrix(matrix):
    for row in matrix:
        print([f"{x:2d}" for x in row]) # Format for consistent spacing

# Create a 4x4 spiral matrix
n = int(input("Enter no of columns and rows as equal: "))
spiral_matrix = create_spiral_matrix(n)
print_matrix(spiral_matrix)