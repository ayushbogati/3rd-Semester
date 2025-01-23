#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <cmath> // For power function
#include <algorithm> // For reverse

using namespace std;

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '$') return 3;
    return 0;
}

// Function to apply operator to two operands
int applyOperator(int operand1, int operand2, char op) {
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2; // Ensure no division by zero in input
        case '%': return operand1 % operand2;
        case '$': return static_cast<int>(pow(static_cast<double>(operand1), static_cast<double>(operand2)));
    }
    return 0;
}

// Evaluate expression (infix)
int evaluateExpression(const string &exp) {
    stack<int> values;
    stack<char> ops;

    for (size_t i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (ch == ' ') continue; // Skip spaces
        if (isdigit(ch)) {
            int value = 0;
            while (i < exp.length() && isdigit(exp[i])) {
                value = value * 10 + (exp[i] - '0');
                i++;
            }
            i--; // Adjust for extra increment in the loop
            values.push(value);
        }
        else if (ch == '(') ops.push(ch);
        else if (ch == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperator(val1, val2, op));
            }
            ops.pop(); // Discard '('
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '$') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(ch)) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperator(val1, val2, op));
            }
            ops.push(ch);
        }
    }

    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperator(val1, val2, op));
    }

    return values.top(); // Final result
}

// Convert infix to postfix
string infixToPostfix(const string &exp) {
    stack<char> ops;
    string result;

    for (size_t i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (isdigit(ch)) result += ch; // Add operands to result
        else if (ch == '(') ops.push(ch);
        else if (ch == ')') {
            while (!ops.empty() && ops.top() != '(') {
                result += ops.top(); ops.pop();
            }
            ops.pop(); // Discard '('
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '$') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(ch)) {
                result += ops.top(); ops.pop();
            }
            ops.push(ch);
        }
    }

    while (!ops.empty()) {
        result += ops.top(); ops.pop();
    }

    return result;
}

// Convert infix to prefix
string infixToPrefix(string exp) {
    reverse(exp.begin(), exp.end()); // Reverse the expression
    for (size_t i = 0; i < exp.length(); i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }

    string postfix = infixToPostfix(exp); // Convert to postfix
    reverse(postfix.begin(), postfix.end()); // Reverse to get prefix

    return postfix;
}

int main() {
    int choice;
    string expression;

    do {
        cout << "\nMenu: \n";
        cout << "1. Convert Infix to Postfix\n";
        cout << "2. Convert Infix to Prefix\n";
        cout << "3. Evaluate Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // To clear input buffer after cin
        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                getline(cin, expression);
                cout << "Postfix expression: " << infixToPostfix(expression) << endl;
                break;

            case 2:
                cout << "Enter infix expression: ";
                getline(cin, expression);
                cout << "Prefix expression: " << infixToPrefix(expression) << endl;
                break;

            case 3:
                cout << "Enter expression (use operators +, -, *, /, %, $): ";
                getline(cin, expression);
                cout << "Result: " << evaluateExpression(expression) << endl;
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
