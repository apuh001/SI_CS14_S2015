#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<int> s;
  for(unsigned i = 0; i < 6; ++i) {
    cout << "Pushing i (" << i << ")" << endl;
    s.push(i);
  }

  while (!s.empty()) {
    cout << "Popping (" << s.top() << ")" << endl;
    s.pop();
  }

  if (s.empty()) cout << "stack is empty" << endl;

  return 0;
}