import Foundation

var numbers: [Int] = []
var answer: [Int] = Array<Int>(repeating: 0, count: 10)
var targetNum: Int = 0

for _ in 1...3 {
    let num = readLine()!
    numbers.append(Int(num)!)
}

targetNum = numbers.reduce(1) { $0 * $1 }

for item in String(targetNum) {
//    print(item)
    let number = Int(String(item))!
    
    answer[number] += 1
}

for num in answer {
    print(num)
}
