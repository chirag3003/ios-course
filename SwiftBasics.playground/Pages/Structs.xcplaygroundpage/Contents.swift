//: [Previous](@previous)

import Foundation

struct Person {
    var name: String
    var age: Int

    func sayHello() {
        print("Hi I am \(name), I am \(age) years old")
    }
}

let person = Person(name: "Xiamong", age: 3)
print(person)


struct BankAccount {
    var accountNumber: Int
    var balance = 0;
}

let account = BankAccount(accountNumber: 123456789, balance: 0)

struct Temperature{
    let celsius: Double
    var fahrenheit: Double {
        celsius * 9 / 5 + 32
    }
    var kelvin: Double {
        celsius + 273
    }
    
    init(celsius: Double) {
        self.celsius = celsius
    }
    
    func getCelsius() -> Double{
        return celsius
    }
    
    func getFahrenheit() -> Double {
        return celsius * 9 / 5 + 32
    }
    
    func getKelvin() -> Double {
        return celsius + 273
    }
}

let boiling = Temperature(celsius: 100)
print(boiling)
print(boiling.celsius)
print(boiling.getKelvin())


struct Odometer {
    var count: Int = 0;
    
    mutating func increment() {
        count += 1
    }
    
    mutating func increment(by amount: Int){
        count += amount
    }
    
    mutating func reset() {
        count = 0
    }
}
var odometer = Odometer()
odometer.increment()
print(odometer.count)

struct StepCounter {
    var totalSteps: Int = 0 {
        willSet {
            print("About to set totalSteps to \(newValue)")
        }
        didSet {
            if totalSteps > oldValue {
                print("Steps increased by \(totalSteps - oldValue)")
            } else {
                print("Steps decreased by \(oldValue - totalSteps)")
            }
        }
    }
}

var stepCounter = StepCounter()

stepCounter.totalSteps = 10000
stepCounter.totalSteps = 9999



struct Temp {
    static let boilingPoint = 100.0
    
    static func convertedFromFahrenheit(_ fahrenheit: Double) -> Double {
        return (fahrenheit - 32) * 5 / 9
    }
    
}

struct Size {
    var height: Double
    var width: Double
}

var size = Size(height: 10, width: 20)
var anotherSize = size

anotherSize.width = 500

print(size)
print(anotherSize)

