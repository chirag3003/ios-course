import Foundation

//Question 1: Calculate Area
func calculateArea(length: Double, width: Double) -> Double {
    return length * width
}
print("Area of 4 and 3 is: ", calculateArea(length: 4, width: 3), "\n")

//Question 2: Reverse a string
func reverseString(str: String) -> String {
    return str.reversed().map(String.init).joined()
}
let str = "Hello World"
print("Original String: \(str)")
print("Reversed String: ", reverseString(str: str), "\n")

//Question 3: Calculate fact of a number using recursion
let factInt = 5
func factorial(n: Int) -> Int {
    if n < 0 {
        return 0
    }
    if n <= 1 {
        return 1
    }
    return n * factorial(n: n - 1)
}
print("Factorial of \(factInt) is: \(factorial(n: factInt)) \n")

//Question 4: Swap 2 integers using inout
func swapValues(a: inout Int, b: inout Int) {
    let temp = a
    a = b
    b = temp
}
var x = 10
var y = 20
print("Before swapping: x = \(x), y = \(y)")
swapValues(a: &x, b: &y)
print("After swappign: x = \(x), y = \(y) \n")

//Question 5: Count the number of vowels in a string
func countVowels(in str: String) -> Int {
    let vowels = ["a", "e", "i", "o", "u"]
    var count = 0
    for character in str.lowercased() {
        if vowels.contains(String(character)) {
            count += 1
        }
    }
    return count
}
print("The number of vowels in \(str) is: ", countVowels(in: str), "\n")

//Question 6: Check if a string is a palindrome or not
func isPalindrome(_ strIn: String) -> Bool {
    let str = strIn.lowercased()
    let count = str.count
    let startIndex = str.startIndex
    let endIndex = str.endIndex
    for i in 0...count / 2 {
        if str[str.index(startIndex, offsetBy: i)]
            != str[str.index(endIndex, offsetBy: -i - 1)]
        {
            return false
        }
    }
    return true
}
print("\(str) is a palindrome: ", isPalindrome(str))
print("ABBA is a palindrome: ", isPalindrome("ABBA"), "\n")

//Question 7: Write a function power(base: Int, exponent: Int) -> Int using recursion
func power(base: Int, exponent: Int) -> Int {
    //Edge cases

    if exponent <= 0 {
        return 1
    }
    if exponent == 0 {
        return 0
    }

    return base * power(base: base, exponent: exponent - 1)
}
print("power(2,3) = ", power(base: 2, exponent: 3), "\n")

//Question 8: write a function displayInfo
func displayInfo(name: String = "DEFAULT", age: Int = 0, location: String = "PUNE") {
    print("Name: \(name)")
    print("Age: \(age)")
    print("Location: \(location)", "\n")
}
displayInfo()

//Question 9: create function sendEmail()
func sendEmail(to recipient: String, subject: String = "no Subject", body: String = "Empty"){
    print("""
    Sending Email to \(recipient)
    Subject: \(subject)
    Body: 
    \(body)
    
    """)
}
sendEmail(to: "chirg@mail.com")
sendEmail(to: "chiragbhalotia@gmail.com", subject: "Test Subject", body: "Test body")
print("\n")


//Question 10
func multiplyNumbers(_ a: Int, _ b: Int = 2) -> Int{
    return a * b
}
print("2 x 3 = ", multiplyNumbers(2, 3))
print("4 x 2 = ", multiplyNumbers(4))
