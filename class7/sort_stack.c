stack<int> sort(stack<int> &input) {
    stack<int> output;
    while (!input.empty()) {
        int value = input.top();
        input.pop();
        while (!output.empty() && output.top() < value) {
            input.push(output.top());
            output.pop();
        }
        output.push(value);
    }
    return output;
}
