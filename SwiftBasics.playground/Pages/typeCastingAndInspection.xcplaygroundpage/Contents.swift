//: [Previous](@previous)

import Foundation

class Employee {
    var name: String
    init(_ name: String) {
        self.name = name
    }
    func work() {
        print("\(self.name) Employee is working")
    }
}

class Manager: Employee {
    init() {
        super.init("Manager")
    }
    override func work() {
        print("\(self.name) is managing employees")
    }

    func conductingMeeting() {
        print("\(self.name) is conducting meeting")
    }
}

class Developer: Employee {
    init() {
        super.init("Developer")
    }
    override func work() {
        print("\(self.name) is coding")
    }

    func writeCode() {
        print("\(self.name) writes code")
    }

}

class Intern: Employee {
    init() {
        super.init("Intern")
    }
    init(name: String) {
        super.init(name)
    }
    override func work() {
        print("\(self.name) is assisting senior developers")
    }

    func learn() {
        print("\(self.name) is learning")
    }
}

let intern = Intern()
intern.work()
intern.learn()

var staff: [Employee] = [
    Manager(),
    Developer(),
    Intern(),
    Intern(name: "Chirag"),
]

for person in staff {
    person.work()
    
    switch person {
    case is Manager:
        (person as! Manager).conductingMeeting()
    case is Developer:
        (person as! Developer).writeCode()
    case is Intern:
        (person as! Intern).learn()
    default:
        break
    }
}

var items: [Any] = [54, "Hello", true]
print(type(of: items))
