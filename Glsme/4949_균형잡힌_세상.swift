import Foundation

while true {
    let line = readLine()!
    var flag = true
    var stack: [Character] = []
    
    if line == "." {
        break
    }
    
    for char in line {
        if "([".contains(char) {
            stack.append(char)
        } else if char == ")" {
            if !stack.isEmpty, stack.last! == "(" {
                stack.removeLast()
            } else {
                flag = false
                break
            }
        } else if char == "]" {
            if !stack.isEmpty, stack.last! == "[" {
                stack.removeLast()
            } else {
                flag = false
                break
            }
        }
    }
    
    if stack.isEmpty, flag {
        print("yes")
    } else {
        print("no")
    }
}
