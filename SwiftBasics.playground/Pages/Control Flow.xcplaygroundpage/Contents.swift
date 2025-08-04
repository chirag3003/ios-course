
var isPluggedIn = false
var hasBatteryPower = false
if isPluggedIn || hasBatteryPower {
    print(" Device is powered on.")
} else {
    print("💀")
}

let switchChar = 1

switch switchChar {
case 1:
    print("🔌")
    fallthrough
case 2:
    print("②")
    fallthrough
default:
    print("💀")
}

enum Direction {
    case north
    case south
    case east
    case west
}

var direction: Direction = .north

switch direction {
case .north:
    print("North")
case .south:
    print("South")
case .east:
    print("East")
case .west:
    print("West")
}

let char = "z"
switch char {
case "a", "e", "i", "o", "u":
    print("Vowel")
default:
    print("Consonant")
}

let age: Int = 18
switch age {
case 1..<18:
    print("Minor")
case 18...100:
    print("Not a minor")
default:
    print("How are you alive")
}

let temp = 66
switch temp {
case 65...75:
    print("The temperature is just right")
case ..<65:
    print("It's too cold.")
default:
    print("It's too hot")
}

let a = 15
let b = 4
var largest = a > b ? a : b
