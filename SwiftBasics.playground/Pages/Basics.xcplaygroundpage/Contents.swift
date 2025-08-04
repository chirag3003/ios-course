import Cocoa
var greeting = "Hello, playground"
print(greeting);
let constant1 = 10;
for i in 0..<10 {
    print((i+1) , greeting);
}

var score: Int?;
score = nil;

struct Person {
    let firstName: String;
    let lastName: String;
    
    func sayHello() {
        print("Hello there! My name is \(firstName) \(lastName).")
    }
}


let aPerson = Person(firstName: "John", lastName: "Doe");
aPerson.sayHello();

let playerNmae = "Chirag"
var playerScore = 1000;
var gameOver = false

var chara: Character = "C";


let char: Character = "\u{0061}"
print(char)
