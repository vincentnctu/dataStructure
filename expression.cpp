#include <iostream>

using namespace std;

typedef struct stack {
  int data;
  struct stack *next;
} Stack;

Stack *Head = NULL;
Stack *HeadValue = NULL;

void 
push(Stack **head, char data) {
  if (*head == NULL) {
    Stack *ptr = new Stack;
    ptr->data = data;
    ptr->next = NULL;
    *head = ptr;
    return;
  }
  
  Stack *ptr = new Stack;
  ptr->data = data;
  ptr->next = *head;
  *head = ptr;
}

bool 
pop(Stack **head, char *data) {
  if (*head == NULL) {
    return false;
  } 

  Stack *ptr = *head;
  *head = ptr->next;
  *data = ptr->data;
  delete ptr;
  ptr = NULL;
  return true;
}

bool 
isEmpty(Stack **head) {
  if (*head == NULL) {
    return true;
  }
  return false;
}

void 
visit(Stack **head) {
  Stack *ptr = *head;

  while (ptr) {
    cout << ptr->data;
    ptr = ptr->next;
  }
  cout << endl;
}

bool 
preview(Stack **head, char *top) {
  Stack *ptr = *head; 
  if (!isEmpty(head)) {
    *top = ptr->data;
    return true;
  }

  return false;
}

int 
priority(char op) {
  switch (op) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '(':
    return 0;

  default:
    cout << "Invalid character" << endl;
    return -1;
  }
}


string 
infixToPostfix(const string &infixExpress) {
  Stack **head = static_cast<Stack **>(&Head);
  string postFixExpression = "";
  char out;
  char op;

  for (char c : infixExpress) {
    if (c == ' ') continue;
    if (isdigit(c)) {
      postFixExpression += c;
    } else if (c == '(') {
      push(head, c);
    } else if (c == ')') {
      while (pop(head, &out)) {
        if (out == '(') {
          break;
        }
        postFixExpression += out;
      }
    } else {
nextOp:
      if (isEmpty(head)) {
        push(head, c);
      } else {
        preview(head, &op);
        if (priority(c) <= priority(op)) {
          pop(head, &out);
          postFixExpression += out;
          goto nextOp;
        } else {
          push(head, c);
        }
      }
    }
  }

  while (!isEmpty(head)) {
    pop(head, &out);
    postFixExpression += out;
  }

  return postFixExpression;
}

int
main(int argc, char *argv[]) {
  string infixExpress = "(1 + 2) * 6 - (4 + 5) / 3";
  string postfixExpress = infixToPostfix(infixExpress);

  Stack **head = static_cast<Stack **>(&HeadValue);
  char op1, op2;
  int v;
  cout << postfixExpress << endl;
  for (char ch:postfixExpress) {
    if (isdigit(ch)) {
      push(head, ch - '0');
    } else {
      pop(head, &op2);
      pop(head, &op1);
      switch (ch) {
      case '+':
        v = op1 + op2;
        break;
      case '-':
        v = op1 - op2;
        break;
      case '*':
        v = op1*op2;
        break;
      case '/':
        v = op1/op2;
        break;
      }
      push(head, v);
    }
  }
  int result;
  preview(head, (char *)&result);
  cout << result << endl;
  return 0;
}
