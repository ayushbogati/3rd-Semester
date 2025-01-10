#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>

using namespace std;

class Expression {
public:
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0;
    }

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    string infixToPostfix(const string& infix) {
        stack<char> operators;
        string postfix;

        for (size_t i = 0; i < infix.length(); i++) {
            char c = infix[i];
            if (isalnum(c)) { 
                postfix += c;
            } else if (c == '(') { 
                operators.push(c);
            } else if (c == ')') { 
                while (!operators.empty() && operators.top() != '(') {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.pop(); 
            } else if (isOperator(c)) { 
                while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.push(c);
            }
        }

        while (!operators.empty()) {
            postfix += operators.top();
            operators.pop();
        }

        return postfix;
    }

    string infixToPrefix(const string& infix) {
        string reversedInfix = infix;
        reverse(reversedInfix.begin(), reversedInfix.end());
        for (size_t i = 0; i < reversedInfix.length(); i++) {
            if (reversedInfix[i] == '(') reversedInfix[i] = ')';
            else if (reversedInfix[i] == ')') reversedInfix[i] = '(';
        }

        string postfix = infixToPostfix(reversedInfix);
        reverse(postfix.begin(), postfix.end());
        return postfix;
    }

    double evaluatePostfix(const string& postfix) {
        stack<double> operands;

        for (size_t i = 0; i < postfix.length(); i++) {
            char c = postfix[i];
            if (isalnum(c)) {
                operands.push(c - '0');
            } else if (isOperator(c)) {
                double b = operands.top(); operands.pop();
                double a = operands.top(); operands.pop();

                switch (c) {
                    case '+': operands.push(a + b); break;
                    case '-': operands.push(a - b); break;
                    case '*': operands.push(a * b); break;
                    case '/': operands.push(a / b); break;
                    case '^': operands.push(pow(a, b)); break;
                }
            }
        }

        return operands.top();
    }
};

int main() {
    Expression expr;
    int choice;
    string infix, postfix, prefix;

    do {
        cout << "\nMenu:\n";
        cout << "1. Convert Infix to Postfix\n";
        cout << "2. Convert Infix to Prefix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infix;
                postfix = expr.infixToPostfix(infix);
                cout << "Postfix expression: " << postfix << endl;
                break;

            case 2:
                cout << "Enter infix expression: ";
                cin >> infix;
                prefix = expr.infixToPrefix(infix);
                cout << "Prefix expression: " << prefix << endl;
                break;

            case 3:
                cout << "Enter postfix expression: ";
                cin >> postfix;
                cout << "Result: " << expr.evaluatePostfix(postfix) << endl;
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
	
