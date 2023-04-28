import Foundation

let count = Int(readLine()!)!
let nums = readLine()!.split(separator: " ").map { Int(String($0))! }
let targetNum = Int(readLine()!)!

var result = 0

for num in nums where num == targetNum {
    result += 1
}

print(result)
