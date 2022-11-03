import Foundation

var firstLine = readLine()!

func useStack(targetNum: String) {
    var stackArray: [Int] = []
    guard let firstNum = Int(targetNum) else { return }
    
    for _ in 1...firstNum {
        let line = readLine()!
        
        if line.contains("push") {
            let lineArray = line.components(separatedBy: " ")
            guard let num = Int(lineArray[1]) else { return }
            
            stackArray.append(num)
        } else if line == "pop" {
            if stackArray.isEmpty {
                print(-1)
            } else {
                print(stackArray[stackArray.count - 1])
                stackArray.removeLast()
            }
        } else if line == "size" {
            print(stackArray.count)
        } else if line == "empty" {
            stackArray.isEmpty ? print(1) : print(0)
        } else if line == "top" {
            if stackArray.isEmpty {
                print(-1)
            } else {
                print(stackArray[stackArray.count - 1])
            }
        }
    }
}

useStack(targetNum: firstLine)
