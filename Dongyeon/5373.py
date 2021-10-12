def init():
        cube = [[['w', 'w', 'w'], ['w', 'w', 'w'], ['w', 'w', 'w']],
                [['y', 'y', 'y'], ['y', 'y', 'y'], ['y', 'y', 'y']],
                [['r', 'r', 'r'], ['r', 'r', 'r'], ['r', 'r', 'r']],
                [['o', 'o', 'o'], ['o', 'o', 'o'], ['o', 'o', 'o']],
                [['g', 'g', 'g'], ['g', 'g', 'g'], ['g', 'g', 'g']],
                [['b', 'b', 'b'], ['b', 'b', 'b'], ['b', 'b', 'b']]]

        return cube

def rotate_U(dir, state):
        tmp_cube = init()
        for i in range(6):
                for j in range(3):
                        for k in range(3):
                                tmp_cube[i][j][k] = state[i][j][k]
        if dir == '+':
                tmp_cube[0][0][0] = state[0][2][0]
                tmp_cube[0][0][1] = state[0][1][0]
                tmp_cube[0][0][2] = state[0][0][0]
                tmp_cube[0][1][0] = state[0][2][1]
                tmp_cube[0][1][2] = state[0][0][1]
                tmp_cube[0][2][0] = state[0][2][2]
                tmp_cube[0][2][1] = state[0][1][2]
                tmp_cube[0][2][2] = state[0][0][2]

                tmp_cube[2][0] = state[5][0]
                tmp_cube[3][0] = state[4][0]
                tmp_cube[4][0] = state[2][0]
                tmp_cube[5][0] = state[3][0]

        if dir == '-':
                tmp_cube[0][2][0] = state[0][0][0]
                tmp_cube[0][1][0] = state[0][0][1]
                tmp_cube[0][0][0] = state[0][0][2]
                tmp_cube[0][2][1] = state[0][1][0]
                tmp_cube[0][0][1] = state[0][1][2]
                tmp_cube[0][2][2] = state[0][2][0]
                tmp_cube[0][1][2] = state[0][2][1]
                tmp_cube[0][0][2] = state[0][2][2]

                tmp_cube[2][0] = state[4][0]
                tmp_cube[3][0] = state[5][0]
                tmp_cube[4][0] = state[3][0]
                tmp_cube[5][0] = state[2][0]

        return tmp_cube

def rotate_plain(dir, state):
        tmp_plain = [['', '', ''], ['', '', ''], ['', '', '']]
        for i in range(3):
                for j in range(3):
                        tmp_plain[i][j] = state[i][j]
        if dir == '+':
                tmp_plain[0][0] = state[2][0]
                tmp_plain[0][1] = state[1][0]
                tmp_plain[0][2] = state[0][0]
                tmp_plain[1][0] = state[2][1]
                tmp_plain[1][2] = state[0][1]
                tmp_plain[2][0] = state[2][2]
                tmp_plain[2][1] = state[1][2]
                tmp_plain[2][2] = state[0][2]

        if dir == '-':
                tmp_plain[2][0] = state[0][0]
                tmp_plain[1][0] = state[0][1]
                tmp_plain[0][0] = state[0][2]
                tmp_plain[2][1] = state[1][0]
                tmp_plain[0][1] = state[1][2]
                tmp_plain[2][2] = state[2][0]
                tmp_plain[1][2] = state[2][1]
                tmp_plain[0][2] = state[2][2]

        return tmp_plain

def set_plain(plain, state):
        tmp_cube = init()
        for i in range(6):
                for j in range(3):
                        for k in range(3):
                                tmp_cube[i][j][k] = state[i][j][k]


        if plain == 'U': return tmp_cube
        elif plain == 'D':
                tmp_cube[0] = state[1]
                tmp_cube[1] = state[0]
                tmp_cube[2] = rotate_plain('+', rotate_plain('+', state[3]))
                tmp_cube[3] = rotate_plain('+', rotate_plain('+', state[2]))
                tmp_cube[4] = rotate_plain('+', rotate_plain('+', state[4]))
                tmp_cube[5] = rotate_plain('+', rotate_plain('+', state[5]))
        elif plain == 'F':
                tmp_cube[0] = state[2]
                tmp_cube[1] = rotate_plain('+', rotate_plain('+', state[3]))
                tmp_cube[2] = state[1]
                tmp_cube[3] = rotate_plain('+', rotate_plain('+', state[0]))
                tmp_cube[4] = rotate_plain('-', state[4])
                tmp_cube[5] = rotate_plain('+', state[5])
        elif plain == 'B':
                tmp_cube[0] = rotate_plain('+', rotate_plain('+', state[0]))
                tmp_cube[1] = rotate_plain('+', rotate_plain('+', state[1]))
                tmp_cube[2] = state[3]
                tmp_cube[3] = state[2]
                tmp_cube[4] = state[5]
                tmp_cube[5] = state[4]
                tmp_cube = set_plain('F', tmp_cube)
        elif plain == 'L':
                tmp_cube[0] = rotate_plain('-', state[0])
                tmp_cube[1] = rotate_plain('+', state[1])
                tmp_cube[2] = state[4]
                tmp_cube[3] = state[5]
                tmp_cube[4] = state[3]
                tmp_cube[5] = state[2]
                tmp_cube = set_plain('F', tmp_cube)
        elif plain == 'R':
                tmp_cube[0] = rotate_plain('+', state[0])
                tmp_cube[1] = rotate_plain('-', state[1])
                tmp_cube[2] = state[5]
                tmp_cube[3] = state[4]
                tmp_cube[4] = state[2]
                tmp_cube[5] = state[3]
                tmp_cube = set_plain('F', tmp_cube)

        return tmp_cube

def return_plain(plain, state):
        tmp_cube = init()
        for i in range(6):
                for j in range(3):
                        for k in range(3):
                                tmp_cube[i][j][k] = state[i][j][k]

        if plain == 'U':
                return tmp_cube
        elif plain == 'D':
                tmp_cube = set_plain('D', tmp_cube)
        elif plain == 'F':
                tmp_cube[0] = rotate_plain('+', rotate_plain('+', state[3]))
                tmp_cube[1] = state[2]
                tmp_cube[2] = state[0]
                tmp_cube[3] = rotate_plain('+', rotate_plain('+', state[1]))
                tmp_cube[4] = rotate_plain('+', state[4])
                tmp_cube[5] = rotate_plain('-', state[5])
        elif plain == 'B':
                state = return_plain('F', state)
                tmp_cube[0] = rotate_plain('+', rotate_plain('+', state[0]))
                tmp_cube[1] = rotate_plain('+', rotate_plain('+', state[1]))
                tmp_cube[2] = state[3]
                tmp_cube[3] = state[2]
                tmp_cube[4] = state[5]
                tmp_cube[5] = state[4]
        elif plain == 'L':
                state = return_plain('F', state)
                tmp_cube[0] = rotate_plain('+', state[0])
                tmp_cube[1] = rotate_plain('-', state[1])
                tmp_cube[2] = state[5]
                tmp_cube[3] = state[4]
                tmp_cube[4] = state[2]
                tmp_cube[5] = state[3]
        elif plain == 'R':
                state = return_plain('F', state)
                tmp_cube[0] = rotate_plain('-', state[0])
                tmp_cube[1] = rotate_plain('+', state[1])
                tmp_cube[2] = state[4]
                tmp_cube[3] = state[5]
                tmp_cube[4] = state[3]
                tmp_cube[5] = state[2]

        return tmp_cube

def print_up(state):
        for i in range(3):
                print(''.join(state[0][i]))

Total_try = int(input())

for i in range(Total_try):
        tries = int(input())
        cube = init()
        a = input().split()
        for j in range(tries):
                plain = a[j][0]
                dir = a[j][1]
                cube = return_plain(plain, rotate_U(dir, set_plain(plain, cube)))
        print_up(cube)
