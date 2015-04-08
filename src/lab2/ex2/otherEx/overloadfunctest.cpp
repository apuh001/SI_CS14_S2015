#include <iostream>
using namespace std;

class Counter {
    public:
        Counter() :count(0) {}
        Counter(int x) : count(count) {}
        void operator() () {
            ++count;
        }
        int get_count() {
            return count;
        }
    private:
        int count;
};
int main() {
    Counter count;
    count();
    count();
    cout << count.get_count() << endl;
}