import sys
def classRoom():
    bin = sys.stdin.readline().split()
    matrix = []
    for i in range(int(bin[0])):
        row = list(sys.stdin.readline()[:-1])
        matrix.append(row)
    return matrix

def concour(matrix):
    result = 0
    if len(matrix[0]) == 1:
        for a in matrix:
            for b in a:
                if b == ".":
                    result += 1
        return result
    
    if len(matrix) == 1:
        for i in range(len(matrix[0])-1):
            if matrix[0][i] == ".":
                matrix[0][i] = "x"
                matrix[0][i+1] = "x"
                result += 1
        if matrix[0][-1] == ".":
            result += 1
        return result

    for row in range(len(matrix)):
        for col in range(len(matrix[0])):
            if matrix[row][col] == ".":
                result += 1
                if row == 0:
                    if col == 0:
                        matrix[row][col] = "x"
                        matrix[row][col+1] = "x"
                        matrix[row+1][col+1] = "x"
                    elif col == len(matrix[0]) - 1:
                        matrix[row][col] = "x"
                        matrix[row][col-1] = "x"
                        matrix[row+1][col-1] = "x"
                    else:
                        matrix[row][col] = "x"
                        matrix[row][col+1] = "x"
                        matrix[row][col-1] = "x"
                        matrix[row+1][col+1] = "x"
                        matrix[row+1][col-1] = "x"
                elif row == len(matrix) - 1:
                    if col == 0:
                        matrix[row][col] = "x"
                        matrix[row][col+1] = "x"
                        matrix[row-1][col+1] = "x"
                    elif col == len(matrix[0]) - 1:
                        matrix[row][col] = "x"
                        matrix[row][col-1] = "x"
                        matrix[row-1][col-1] = "x"
                    else:
                        matrix[row][col] = "x"
                        matrix[row][col+1] = "x"
                        matrix[row][col-1] = "x"
                        matrix[row-1][col+1] = "x"
                        matrix[row-1][col-1] = "x"      
                else:
                    if col == 0:
                        matrix[row][col] = "x"
                        matrix[row][col+1] = "x"
                        matrix[row-1][col+1] = "x"
                        matrix[row+1][col+1] = "x"
                    elif col == len(matrix[0]) - 1:
                        matrix[row][col] = "x"
                        matrix[row][col-1] = "x"
                        matrix[row-1][col-1] = "x"
                        matrix[row+1][col-1] = "x"
                    else:
                        matrix[row][col] = "x"
                        matrix[row][col+1] = "x"
                        matrix[row][col-1] = "x"
                        matrix[row-1][col+1] = "x"
                        matrix[row-1][col-1] = "x"
                        matrix[row+1][col+1] = "x"
                        matrix[row+1][col-1] = "x"
                
    return result

if __name__ == "__main__":
    result = []
    Testcase = sys.stdin.readline()
    for i in range(int(Testcase)):
        mat = classRoom()
        result.append(concour(mat))
    for i in result:
        print(i)
