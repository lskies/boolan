class Queue {
private:
    stack<int> inputStack;
    stack<int> outputStack;
public:
    void enqueue(int);
    int dequeue();
};

void Queue::enqueue(int value) {
    inputStack.push(value);
}

int Queue::dequeue() {
    int value;
    if (!outputStack.empty()) {
        value = outputStack.top();
        outputStack.pop();
        return value;
    }
    while (!inputStack.empty()) {
        outputStack.push(inputStack.top());
        inputStack.pop();
    }
    value = outputStack.top();
    outputStack.pop();
    return value;
}

