class stackWithMax {
private:
stack<int> valueStack;
stack<int> maxStack;

public:
    void push(int);
    int pop();
    int max();
};

void stackWithMax::push(int value) {
    if (maxStack.empty() || maxStack.top() <= value) {
        maxStack.push(value);
    }
    valueStack.push(value);
}

int stackWithMax::pop() {
    int value = valueStack.top();
    valueStack.pop();
    if (value == maxStack.top()) {
        maxStack.pop();
    }
    return value;
}

int stackWithMax::max() {
    return maxStack.top();
}

