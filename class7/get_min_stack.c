
class GetMinStack {
   Stack<int> minStack;
   Stack<int> elements;

   void push(int x) {
       elements.push(x);
       if (minStack.empty() || x <= minStack.top())
           minStack.push(x);
   };

   int pop() {
       if (elements.empty()) throw Exception("Stack is Empty");

       if (elements.top() == minStack())
           minStack.pop();
       return elements.pop();
   }

   int getMin() {
       if (minStack.empty()) throw Exception("Stack is Empty");

       return minStack.top();
   }
}
