//: [Previous](@previous)

import Foundation

var  birthdayIsToday = false
var invitedGuests: [String] = []
var cakeCandlesLit = 0

@MainActor
func singHappyBirthday(){
    guard birthdayIsToday else {
        print("Birthday is not today")
        return;
    }
    print("Happy Birthday to you!")
}

func divide(_ dividend: Float, by divisor: Float) -> Float{
    guard divisor != 0 else {
        fatalError("Cannot divide by zero")
    }
    return dividend / divisor
}

func processBook(title: String?, price: Double?, pages: Int?){
    guard let title = title, let price = price, let pages = pages else {
        return
    }
    print("Title: \(title), Price: \(price), Pages: \(pages)")
}

processBook(title: nil, price: nil, pages: nil)
print(divide(4.0, by: 0.0))
