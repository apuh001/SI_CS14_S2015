#include <vector>
#include <algorithm>
#include <functional>
#include <assert.h>

using namespace std;

template<typename T, typename Less=std::less<T>>
class MinHeap{
    private:
        std::vector<T> _heap;
        Less _less;
        void fix_order_up(int recent_insert)
        {
            if(recent_insert == 0)
                return;
                
            //left child is 2n, right child is 2n + 1
            int parent = _heap.size();
            //Right child
            if(parent%2 != 0)
                parent = ((parent - 1)/2);
            //Left child
            else
                parent /= 2;
            
            //Parent cannot be 0th index, no more fixing needed
            if(parent <= 0)
                return;
                
            if(parent > _heap[recent_insert])
                swap(_heap[recent_insert], _heap[parent]);
            
            //Checks for all
            fix_order_up(recent_insert - 1);
            return;
        }
    public:
        MinHeap(){
            _heap.push_back(0);
        }
        
        const T &top()
        {
            return _heap[1];
        }
        
        void push(const T &elem)
        {
            _heap.push_back(elem);
            //Check if okay
            fix_order_up(_heap.size() - 1);
        }
        
        void pop()
        {
            _heap.erase(_heap.begin());
            //Check if okay
            fix_order_up(_heap.size() - 1);
        }
        
        bool empty(){    
            if(_heap.size() <= 1)
                return true;
            return false;
        }
        
        void heapify(const std::vector<T> &vec){
            for(unsigned i = 0; i < vec.size(); i++)
                push(vec[i]);
        }
};