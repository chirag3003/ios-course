//: [Previous](@previous)

import Foundation
import SwiftUI

struct Student {
    var name: String
    var entrollmentYear: Int? // Optional Integer
}

let firstStudent: Student = .init(name: "John")
let secondStudent: Student = Student(name: "Chirag", entrollmentYear: 2010)

var serverCode: Int? = nil
serverCode = 200

if(firstStudent.entrollmentYear != nil){
    let actualYear = firstStudent.entrollmentYear!
    print("Enrolled in \(actualYear) \n")
}

let unwrappedYear = firstStudent.entrollmentYear

let str = "123"
let num = Int(str)
print(type(of: num))

func fullName(firstName: String, middleName: String? , lastName: String){
    if let midName = middleName {
        print(firstName + " " + midName + " " + lastName)
    } else {
        print(firstName + " " + lastName)
    }
}

fullName(firstName: "Ved", middleName: "Virendra", lastName: "Chavan")
fullName(firstName: "Chirag", middleName: nil, lastName: "Bhalotia")

func getURL(_ string: String) -> String? {
    if let url = URL(string: string){
        return url.absoluteString
    }
    return nil
}

struct Toddler {
    var birthName: String
    var monthsOld: String
}


