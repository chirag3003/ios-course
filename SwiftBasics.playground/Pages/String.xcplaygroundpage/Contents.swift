let joke = """
Why did the \"banana\" go to the doctor?
\t Because it wasn't peeling well!
"""

print(joke)

//let str = ""
let str = String()
print("Is my string empty: ",str.isEmpty)

let num = 10

let interpolated = "The value of num is: \(num)"

print(interpolated)

print("5 x 6 = \(5 * 6)")
let unitPrice = 100.0
let quantity = 4
let amount = unitPrice * Double(quantity)
let tax = amount * 0.12
let totalAmount = amount + tax

print("""
    
    
    Name\t\t\t\tQuantity\t\tUnit Price\t\tAmount
    Dsa Basics\t\t\t\(quantity)\t\t\t\t\(unitPrice)\t\t\t\(amount)
    
    Tax: \(tax)
    Total Amount: \(totalAmount)
    """)

let month = "JaAAnuary"
let otherMonth = "February"

if month == otherMonth {
    print("They are the same!")
} else {
    print("They are not the same!")
}


print(month.lowercased())
print(month)

if(month.contains("JaAA")) {
    print("contains")
}
else {
    print("not contains")
}
