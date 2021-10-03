import sys

color = {"black" : 0, "brown" : 1, "red": 2, "orange" : 3, "yellow" : 4, "green" :5 ,"blue" : 6 , "violet" : 7, "grey" : 8, "white" : 9}

def cal_resit():
    front = sys.stdin.readline()[:-1]
    back = sys.stdin.readline()[:-1]
    mul = sys.stdin.readline()[:-1]

    num = str(color[front]) + str(color[back])
    result = str(int(num)*(10**color[mul]))
    return result

if __name__ == "__main__":
    print(cal_resit())
    
