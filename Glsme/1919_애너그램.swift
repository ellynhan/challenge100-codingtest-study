import Foundation

let firstLine = readLine()!
let secondLine = readLine()!

var alphabets = Array("abcdefghijklmnopqrstuvwxyz")
var firstAlphabets = Array(repeating: 0, count: 26)
var secondAlphabets = Array(repeating: 0, count: 26)

var count = 0

for index in firstLine {
    firstAlphabets[alphabets.firstIndex(of: index)!] += 1
}

for index in secondLine {
    secondAlphabets[alphabets.firstIndex(of: index)!] += 1
}

for index in 0..<26 {
    if firstAlphabets[index] > secondAlphabets[index] {
        count += (firstAlphabets[index] - secondAlphabets[index])
    } else {
        count += (secondAlphabets[index] - firstAlphabets[index])
    }
}

print(count)
