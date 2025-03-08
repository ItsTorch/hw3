#include <iostream>
#include "stack.h"

using namespace std;

int main() {
  Stack<int> s;

  // test empty
  cout << "is stack empty? " << (s.empty() ? "yes" : "no") << endl;
  cout << "stack size: " << s.size() << endl;

  // test push
  s.push(1);
  s.push(7);
  s.push(13);
  s.push(3);

  cout << endl << "pushing 4 elements into stack" << endl;
  cout << "stack size: " << s.size() << endl;
  cout << "top element: " << s.top() << endl;

  // test pop
  s.pop();
  cout << endl << "pop once" << endl;
  cout << "stack size: " << s.size() << endl;
  cout << "top element: " << s.top() << endl;

  // pop all elements, then check throw when stack is empty
  s.pop();
  s.pop();
  s.pop();

  cout << endl << "is stack empty? " << (s.empty() ? "yes" : "no") << endl;
  try {
    s.pop();
  }
  catch (const underflow_error& e) {
    cout << e.what() << endl;
  }
  
  try {
    s.top();
  }
  catch (const underflow_error& e) {
    cout << e.what() << endl;
  }
}