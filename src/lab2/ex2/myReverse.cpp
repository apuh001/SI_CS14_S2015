#include <iostream>
#include <vector>

using namespace std;

template <typename BidirectionalIter>

//We assume iterators will be passed thru
//eg. vector<int>::iterator vec_it;

void my_rotate(BidirectionalIter first, BidirectionalIter n_first,
               BidirectionalIter last)
               {
                   //Iterators are pointers
                   int val;
                   
                   for(int i = n_first; i != last; i++)
                   {
                        val = *first;
                        *first = *n_first;
                        *n_first = val;
                   }
                    
                   return;
               }
               
               //Lets assume 1 3 4 5 2
               //fin 4 5 2 1 3
               //my_rotate(it_beg, it_nbeg, it_ed)
               //
               
int main()
{
    vector<int> v {1, 2, 3, 4, 5, 6, 7};
    vector<int>::iterator beg = v.begin();
    vector<int>::iterator beg_5 = v.begin() + 5;
    vector<int>::iterator ed = v.end();
    
    cout << *beg_5 << endl;
}