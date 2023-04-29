import Foundation

let index = Int(readLine()!)!
let numbers = readLine()!.split(separator: " ").map { Int(String($0))! }.sorted()
let targetNum = Int(readLine()!)!

var startIndex = 0
var lastIndex = index - 1
var count = 0

while startIndex < lastIndex {
    let target = numbers[startIndex] + numbers[lastIndex]
    
    if target == targetNum {
        count += 1
        startIndex += 1
        lastIndex -= 1
    } else if target > targetNum {
        lastIndex -= 1
    } else {
        startIndex += 1
    }
}

print(count)
