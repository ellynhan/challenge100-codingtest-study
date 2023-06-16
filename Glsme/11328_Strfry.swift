import Foundation

let count = Int(readLine()!)!

for _ in 1...count {
    let array = readLine()!.split(separator: " ").map{ String($0) }
    
    if array[0].sorted() == array[1].sorted() {
        print("Possible")
    } else {
        print("Impossible")
    }
}
