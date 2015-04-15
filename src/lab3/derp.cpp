#include <iostream>
#include <queue>

using namespace std;

int main() {
  queue<int> q;
  for(unsigned i = 0; i < 6; ++i) {
    cout << "Pushing i (" << i << ")" << endl;
    q.push(i);
  }

  while (!q.empty()) {
    cout << "Popping (" << q.front() << ")" << endl;
    q.pop();
  }

  if (q.empty()) cout << "queue is empty" << endl;

  return 0;
}