import Foundation

let line = readLine()!
var array = Array<Int>(repeating: 0, count: 10)

for num in line {
    array[Int(String(num))!] += 1
}

array[6] += array[9]
array[9] = 0

if array.firstIndex(of: array.max()!)! == 6 {
    let num = (array[6] / 2) + (array[6] % 2)
    array[6] = 0
    print(num > array.max()! ? num : array.max()!)
} else {
    print(array.max()!)
}
