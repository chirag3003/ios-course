
var validAge = 21
var myAge = 18 < validAge ? "Minor" : "Major"

// Nil Colescing Operator

var groupPartner: String? = "Prasad"
var partnerName = groupPartner ?? "Chirag"
print(partnerName)

var defaultColor: String? = "Red"
var finalPrintColor = defaultColor ?? "Blue"
print(finalPrintColor)

// Closed Range operators

for index in 1...4 {
    print(index)
    print(index * 2);
}

var list = [11, 22, 45,35,2663]

for values in list {
    if values > 20 {
        print(values)
    }
}



var hasDoorCode = true
var retinaScanPassed = false

if hasDoorCode && retinaScanPassed {
    print("Enter the room")
} else {
    print("Don't enter the room")
}

let fingerPrintScan = true

if(fingerPrintScan || retinaScanPassed) {
    print("Enter the room ")
} else {
    print("Don't enter the room")
}
