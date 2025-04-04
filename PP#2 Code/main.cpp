#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Function used to convert a numnber from any base (positive or negative) to a decimal
int createDecimal(string number, int base) {
    int decimalValue = 0;
    int length = number.length();
    bool isNegative = false;

    // Checking to see if the number is negative  
    if (number[0] == '-') {
        isNegative = true;
        number = number.substr(1); // Removes negative sign
        length--; // Adjusts the length accordingly after removing the sign
    }
    
    for (int i = 0; i < length; i++) {
        char digit = number[length - 1 - i]; // Process from right (least significant) to left (most significant)
        int digitValue;
        
        if (isdigit(digit)) {
            digitValue = digit - '0'; // Convert a character to an integer
        }
        
        else {
            digitValue = toupper(digit) - 'A' + 10; // Convert A-F to 10-15 for bases > 10
        }
        
        // Apply the formula
        decimalValue += digitValue * pow(base, i);
    }
    
    // If the original number was negative, return a negative result
    if (isNegative) {
        return -decimalValue;
    }
 
    // If the original number was positive, return a positive result 
    else {
        return decimalValue;
    }
}

int main() {
    string number;
    int base;
    
    // Ask for user input
    cout << "Enter the number: ";
    cin >> number;
    cout << "Enter the base: ";
    cin >> base;
    
    // Outputs the answer
    int decimalValue = createDecimal(number, base);
    cout << "The answer is: " << decimalValue << endl;
    
    return 0;
}