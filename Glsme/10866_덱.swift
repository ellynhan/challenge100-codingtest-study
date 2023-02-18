import Foundation

func setDeque(count: String) {
    guard let count = Int(count) else { return }
    
    var answer: [Int] = []
    
    for _ in 1...count {
        let line = readLine()!
        
        if line.contains("push_front") {
            let array = line.components(separatedBy: " ")
            guard let num = Int(array[1]) else { return }
            
            answer.append(num)
        } else if line.contains("push_back") {
            let array = line.components(separatedBy: " ")
            guard let num = Int(array[1]) else { return }
            
            answer.insert(num, at: 0)
        } else if line == "pop_front" {
            if answer.isEmpty {
                print(-1)
            } else {
                print(answer[answer.count - 1])
                answer.removeLast()
            }
        } else if line == "pop_back" {
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
            if answer.isEmpty {
                print(-1)
            } else {
                print(answer[answer.count - 1])
            }
        } else if line == "back" {
            if answer.isEmpty {
                print(-1)
            } else {
                print(answer[0])
            }
        }
    }
}

let firstLine = readLine()!
setDeque(count: firstLine)
