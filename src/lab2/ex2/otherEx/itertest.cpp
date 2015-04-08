#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Guessing that only 42 is outputted since
//vec.begin would point to 42 but after sorting
//it'll be the last element.
//Wrong, 3, 8 , 42 all outputted!


int main() {
    vector<int> vec {42, 8, 3};

    // sort all of the elements in vec in ascending order
    sort(vec.begin(), vec.end());

    /*
        We can use auto to omit the type
        on the left-hand side in C++11!

        Also, this is a way to iterate through a
        vector using iterators with a for-loop!
    */
    for(auto vec_iter = vec.begin(); vec_iter != vec.end(); vec_iter++){
        cout << *vec_iter << ' ';
    }
}