import Foundation

var N: Int = 0
var M: Int = 0
var maxx: Int = 0
var sum: Int = 0

// 표준 입력을 위해 readLine 사용
if let input = readLine() {
    let inputs = input.split(separator: " ").map { Int(String($0))! }
    N = inputs[0]
    M = inputs[1]
}

// 배열 초기화
var arr: [Int] = []

if let arrayInput = readLine() {
    arr = arrayInput.split(separator: " ").map { Int(String($0))! }
}

// 조합
for i in 0..<N {
    for j in i+1..<N {
        for k in j+1..<N {
            sum = arr[i] + arr[j] + arr[k]
            if sum > maxx && sum <= M {
                maxx = sum
            }
        }
    }
}

print(maxx)
