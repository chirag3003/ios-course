import AppKit

func greet() {
    print("Hello, World!")
}

func displayPi() {
    print(Double.pi)
}

displayPi()

func triple(value: Int) {
    print(value * 3)
}

func sayHello(to person: String, and anotherPerson: String) {
    print("Hello \(person) and \(anotherPerson)")
}

sayHello(to: "Chirag", and: "Ved")

func sayHello2(_ person: String, _ anotherPerson: String) {
    print("Hello \(person) and \(anotherPerson)")
}

sayHello2("Chirag", "VedBoiiiiiiiiii!")

func incrementNumbers(_ value: Int, by number: Int) {
    print("Incremented Value = \(value + number)")
}

func dispUserInfo(name: String, place: String = "Pune") {
    print("Name \t\t\t\t\t Location \t")
    print("\(name) \t\t \(place)")
}

dispUserInfo(name: "Chirag Bhalotia")

func findMinMax(firstNum: Int, secondNum: Int) -> (max: Int, min: Int) {
    if firstNum > secondNum {
        return (max: firstNum, min: secondNum)
    } else {
        return (max: secondNum, min: firstNum)
    }
}

let (max, min) = findMinMax(firstNum: 5, secondNum: 4)
print("Min = \(min), Max = \(max)")

func dateTimeFormat(from date: Date) -> (year: Int, month: Int, day: Int, hour: Int, minute: Int, second: Int){
    let calendar = Calendar.current
    let components = calendar.dateComponents([.year, .month, .day, .hour, .minute, .second], from: date)
    return (
        year: components.year ?? 0,
        month: components.month ?? 0,
        day: components.day ?? 0,
        hour: components.hour ?? 0,
        minute: components.minute ?? 0,
        second: components.second ?? 0
    )
}

print(dateTimeFormat(from: Date()))
