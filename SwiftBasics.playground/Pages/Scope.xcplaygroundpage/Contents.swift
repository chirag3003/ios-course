//: [Previous](@previous)

import Foundation

var age = 43

@MainActor
func printAge() {
    print("My age is \(age)")
}

func printTenNames(){
    var name = "Akshita"
    
    for i in 1...5 {
        print("Index: \(i), Name: \(name)")
    }
    
//   print("Index: \(i), Name: \(name)")
}
printTenNames()

struct Person {
    var name: String
    var id: Int
   
    init(name: String, id: Int){
        self.name = name
        self.id = id
    }
}

var personObject = Person(name: "Akshita", id: 1234)

print("Name: \(personObject.name), ID: \(personObject.id)")
