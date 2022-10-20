import Foundation
 
let firstLine = readLine()!
let firstLineArray = firstLine.components(separatedBy: " ").map { Int(String($0))! }
let secondLine = readLine()!
let secondLineArray = secondLine.components(separatedBy: " ").map { Int(String($0))! }
    
print(secondLineArray.filter { $0 < firstLineArray[1] }.map { String($0) }.joined(separator: " "))
