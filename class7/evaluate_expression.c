String numbers = "0123456789";
int evalPostfix(String post) {
  char[] chars = post.toChars();
  Stack<Integer> stack = new Stack();
  for (char c: chars) {
    if (numbers.indexOf(c) >= 0) {
      stack.push(c - '0');
    }
    else if (operatoers.indexOf(c) >=0) {
      int op1 = stack.pop();
      int op2 = stack.pop();
      int result;
      switch(c) {
        case '*':
           result = op1 *op2;
           stack.push(result);
          break;
        case '/':
           result = op2 / op1;
           stack.push(result);
          break;
        case '+':
           result = op1 +op2;
           stack.push(result);
          break;
        case '-':
           result = op2 - op1;
           stack.push(result);
          break;
      }
    }
  }
  return stack.pop();
}
