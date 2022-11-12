import Foundation

let firstLine = readLine()!

func useQueue(targetNum: String) {
    var answer: [Int] = []
    guard let lineNum = Int(targetNum) else { return }
    
    for _ in 1...lineNum {
        let line = readLine()!
        
        if line.contains("push") {
            let lineArray = line.components(separatedBy: " ")
            guard let num = Int(lineArray[1]) else { return }
            
            answer.append(num)
        } else if line == "pop" {
            if answer.isEmpty {
                print(-1)
            } else {
                print(answer[0])
                answer.removeFirst()
            }
        } else if line == "size" {
            print(answer.count)
        } else if line == "empty" {
            answer.isEmpty ? print(1) : print(0)
        } else if line == "front" {
            answer.isEmpty ? print(-1) : print(answer[0])
        } else if line == "back" {
            answer.isEmpty ? print(-1) : print(answer[answer.count - 1])
        }
    }
}

useQueue(targetNum: firstLine)
