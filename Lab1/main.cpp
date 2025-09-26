#include <iostream>


void Exercise1_CheckIfNumberIsOddOrEvent(int number);
void Exercise2_CalculatorSwitch();
void Exercise3_MaxOfTwoNumber(int number1, int number2);
void Exercise4_MultiplicationTable(int number, int max = 10);
void Exercise5_MaxDigitsOfInteger(int number);
void Exercise6_PasswordValidation();
void Exercise7_MenuSimulation();
void Exercise8_RecursiveFactorial(int number);
int Exercise8_RecursiveFactorial_Internal(int number);
void Exercise9_RecursiveFibonacci(int number);
int64_t Exercise9_RecursiveFibonacci_Internal(int64_t number);
void Exercise10_RecursiveDigitsSum(int number);
int Exercise10_RecursiveDigitsSumInternal(const std::string &number, int index);

// Lab 1 ULS 2025
int main() {
    // Exercise1_CheckIfNumberIsOddOrEvent(10);
    // Exercise2_CalculatorSwitch();
    // Exercise3_MaxOfTwoNumber(10,15);
    // Exercise4_MultiplicationTable(5, 15);
    // Exercise5_MaxDigitsOfInteger(456);
    // Exercise6_PasswordValidation();
    // Exercise7_MenuSimulation();
    //Exercise8_RecursiveFactorial(10);
    // Exercise9_RecursiveFibonacci(50);
    // Exercise10_RecursiveDigitsSum(654);
    return 0;
}


void Exercise1_CheckIfNumberIsOddOrEvent(int number) {
    if (number % 2 == 0) {
        std::cout << number << " is even" << std::endl;
    }
    else {
        std::cout << number << " is odd" << std::endl;
    }
}

void Exercise2_CalculatorSwitch() {
    int firstNumber, secondNumber;
    char operation;
    std::cout << "Enter first number \n";
    std::cin >> firstNumber;
    std::cout << "Enter operation \n";
    std:: cin >> operation;
    std::cout << "Enter second number \n";
    std::cin >> secondNumber;

    switch (operation) {
        case '+':
            std::cout << "Sum is " + std::to_string(firstNumber + secondNumber) << std::endl;
            break;
        case '-':
            std::cout << "Substraction is " + std::to_string(firstNumber - secondNumber) << std::endl;
            break;
        case '*':
            std::cout << "Multiplication is " + std::to_string((firstNumber * secondNumber)) << std::endl;
            break;
        case '/':
            if (secondNumber == 0) {
                std::cout << "Cannot divide by zero" << std::endl;
                break;
            }
            std::cout << "Division is " + std::to_string(firstNumber / secondNumber) << std::endl;
            break;
        default:
            std::cout << "Invalid operation" << std::endl;
    }
}

void Exercise3_MaxOfTwoNumber(int number1, int number2) {
    std::cout << "Max is: " + std::to_string(number1 > number2 ? number1 : number2)<< std::endl;
}

void Exercise4_MultiplicationTable(int number, int max) {
    std::string numberStr = std::to_string(number);
    std::cout << "Multiplication table for " + numberStr + '\n';
    for (int i = 0; i < max+1; i++) {
        std::cout << numberStr + " x " + std::to_string(i) + " = " + std::to_string(number * i) << std::endl;
    }
}

void Exercise5_MaxDigitsOfInteger(int number) {
    int result = 0;
    const std::string c_str_number = std::to_string(number);
    for (int i = 0; i < c_str_number.length(); i++) {
        result += c_str_number[i] - '0';
    }
    std::cout << "Sum of digits is: " + std::to_string(result) << std::endl;
}

void Exercise6_PasswordValidation() {
    std::string password;
    do {
        std::cout << "Enter password \n";
        std::cin >> password;
    }
    while (password != "1234");
    std::cout << "Password found!";
}

void Exercise7_MenuSimulation() {
    int input;
    while (true) {
        std::cout << "Enter your choice: \n";
        std::cout << "0: Exit \n";
        std::cout << "1: Connect to host \n";
        std::cout << "2: Kill all connection  \n";
        std::cin >> input;
        switch (input) {
            case 1:
                std::cout << "Connected" << std::endl;
                break;
            case 2:
                std::cout << "Connection killed" << std::endl;
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
            default: ;
        }
        if (input == 0) {
            break;
        }
    }
}

void Exercise8_RecursiveFactorial(int number) {
    int result = Exercise8_RecursiveFactorial_Internal(number);
    std::cout << "Recursive factorial is: " << result << std::endl;
}

int Exercise8_RecursiveFactorial_Internal(int number) {
    if (number == 0) {
        return 1;
    }
    return number * Exercise8_RecursiveFactorial_Internal(number -1);
}

void Exercise9_RecursiveFibonacci(int number) {
    int64_t result = Exercise9_RecursiveFibonacci_Internal(number);
    std::cout << "Recursive fibonacci for number " + std::to_string(number) + " is: " << result << std::endl;
}


int64_t Exercise9_RecursiveFibonacci_Internal(int64_t number) {
 if (number <= 1) {
     return number;
 }
    return Exercise9_RecursiveFibonacci_Internal(number - 1) + Exercise9_RecursiveFibonacci_Internal(number -2);
}

void Exercise10_RecursiveDigitsSum(const int number) {
    const std::string c_str_number = std::to_string(number);
    std::cout << std::to_string(Exercise10_RecursiveDigitsSumInternal(c_str_number, c_str_number.length())) +
            "Recursive sum of digits is: " << std::endl;
}

int Exercise10_RecursiveDigitsSumInternal(const std::string &number, int index) {
    if (index <= 0) {
        return 0;
    }
    return number[index - 1] - '0' + Exercise10_RecursiveDigitsSumInternal(number, index - 1);
}
