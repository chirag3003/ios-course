//: [Previous](@previous)

import Foundation

var names = ["Akshita", "Kamakshi", "Abhishek"]

var number = 50
names.append("Chirag")

var numbers: [Int8] = [1, 2, 3, 4, 5]
numbers.append(contentsOf: [6, 7, 8])

print("hello")
print(names)
print(numbers)

var myArr = [Int](repeating: 4, count: 20)
print(names + ["Chirag"])
print(myArr.count)
names.insert("Hitesh", at: 3)
print(names)

//print(names[names.count])
print([""].isEmpty)
var n2 = names.dropLast()
print(names + n2)

var arr = [[1], [2, 2], [3, 3, 3], [4, 4, 4, 4], [5, 5, 5, 5, 5]]
var arr2 = [[Int]]()
arr2.append([1])
arr2.append([2,2])
arr2.append([3,3,3])
arr2.append([4,4,4,4])
arr2.append([5,5,5,5,5])
print(arr2)
