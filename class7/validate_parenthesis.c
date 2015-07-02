bool isLeftParentheses (char input) {
    return input == '(' || input == '[' || input == '{';
}

bool isMatchParentheses(char left, char right) {
    switch (left) {
        case '(':
            return right == ')';
        case '[':
            return right == ']';
        case '{':
        return right == '}';
    }
    return false;
}

bool isValidParentheses(string input) {
    stack<char> parenthesesStack;
    for (int i = 0; i < input.length(); i++) {
        if (isLeftParentheses(input[i])) {
            parenthesesStack.push(input[i]);
        } else {
            if (parenthesesStack.empty() || !isMatchParentheses(parenthesesStack.top(), input[i])) {
                return false;
            }
            parenthesesStack.pop();
        }
    }
    return parenthesesStack.empty();
}

