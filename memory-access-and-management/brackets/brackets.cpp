#include <iostream>
#include <string>

using namespace std;
const char OPENING_BRACKET = '(';
const char CLOSING_BRACKET = ')';

bool bracketsAreValid(string expression) {
    /* As far as I understand, valid brackets are brackets that are in the expression and do not span
        across semicolons (;) */
    int openingBrackets = 0;
    int closingBrackets = 0;

    for (int i = 0; i < expression.size(); i++) {
        char character = expression[i];
        switch (character)
        {
            case OPENING_BRACKET:
                openingBrackets++;
                break;
            case CLOSING_BRACKET:
                closingBrackets++;
                break;
            case ';':
                if (openingBrackets != closingBrackets) {
                    return false;
                }
                break;
        }
    }

    return true;
}

int main() {
    string expression;
    getline(cin, expression);
    cout << bracketsAreValid("((a+b)/5-d; (a+b; a+b); (a))");
    cout << bracketsAreValid("((a+b)/5-d; (a+b; a+b); (a))");
    cout << "Your brackets are " << (bracketsAreValid(expression) ? "valid!" : "not valid!") << endl;
    return 0;
}
