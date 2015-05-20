#include <utility>
#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
#include <iterator>

/*
 * takes three values and uses comp to put them in sorted order.
 * the median ends up at b.
 */
template<typename T, typename Compare = std::less<T>>
void median_of_three(T & a, T & b, T & c, Compare comp = Compare());
{
    // a b c in order
    //c is not less than b
    //b is not less than a
    //done
    
    // c b a
    // a is less than b, so swap. c a b
    // b is less than a so swap. a c b
    // b is less than c so swap. a b c
    
    // a c b
    // b is less than c swap. a b c
    // b is not less than a nor is c less than b done.
    
    if(comp(c,b))
        swap(c,b);
    if(comp(b,a))
        swap(b,a);
    if(comp(c, b))
        swap(b,a);   
    return;
    
    /*
    comp(a, b) ? ((comp(b, c)) ? b = b : b = b) : ((comp(c, a)) ? swap(b, a); swap(a, c); swap(b, a); b = c;
    //a < b?
    if(comp(a,b))
    {
        //Then is b < c?
        if(comp(b,c))
            return; //Everything is in it's right place
        //Else b > c and the order is a < c < b or c < a < b
        else
        {
            //If order is a c b
            if(comp(a,c))
                swap(c, b); //Order is now a(a), b(c), c(b)
            //Order is c a b
            else
            {
                swap(b, c); // order is now a(a) b(c) c(b)
                swap(a, c); // order is now a(c), b(a), c(b)
            }
        }
    }
    //b < a
    else
    {
        // b < a < c or b < c < a
        if(comp(b, c))
        {
            // b, a, c
            if(comp(a, c))
                swap(a, b); //Order is now a(b), b(a), c(c)
            // b c a
            else
            {
                swap(a, b); //order is now a(b) b(a) c(c)
                swap(b, c); //order is now a(b) b(c) c(a)
            }
        }
        // b < c < a or c < b < a
        else
        {
            if(comp())
        }
    }
    */
}

/*
 * partitions v from first to last using mid as the pivot
 */
template<typename T, typename Compare = std::less<T>>
int partition(std::vector<T> & v, int first, int mid, int last, Compare comp = Compare());
{
    //DO NOT CALL MEDIAN OF THREE
    //median_of_three(v[first], v[second], v[last], comp);
    //Values have been moved to approrpiate places.
    
    //Mid is your index to pivot. Work through as algorithm dictates.
    swap(v[mid], v[last]);
    
    int right_ptr = v.size() - 2;
    int left_ptr = 0;
    
    while(left_ptr <= right_ptr)
    {
        for(; left_ptr > right_ptr || v[left_ptr] >= v[v.size() - 1]); left_ptr++);
        for(; right_ptr < left_ptr || v[right_ptr] <= v[v.size() - 1]; right_ptr--);
        swap(v[left_ptr], v[right_ptr]);
    }
    
    //new pivot val....
    
    return mid;
}
/*
 * same as other partition;
 * creates two vectors for the left and right, then puts all the elements (except for mid)
 * in the two. Then, they are put back in v so that v is partitioned, and returns the
 * index of the pivot value.
 */
template<typename T, typename Compare = std::less<T>>
int naive_partition(std::vector<T> & v, int first, int mid, int last, Compare comp = Compare());
{
    T midVal = v[mid];
    vector<T> leftVec;
    vector<T> rightVec;
    
    for(unsigned i = first, i < mid; i ++)
        leftVec.push_back(v[i]);
    for(unsigned i = mid + 1, i < last; i ++)
        rightVec.push_back(v[i]);
        
    v.clear();
    for(unsigned i = 0, i < leftVec.size(); i ++)
        v.push_back(leftVec[i]);
    for(unsigned i = 0, i < rightVec.size(); i ++)
        v.push_back(rightVec[i]);   
    v.push_back(midVal);
}
/*
 * uses the median of three pivot selection method, and the naive partition method
 * to implement quicksort
 *
 * has a base case of a list of size 1 or fewer
 */
template<typename T, typename Compare = std::less<T>>
void naive_quicksort(std::vector<T> & v, int first, int last, Compare comp = Compare());

/*
 * overload
 */
template<typename T>
void naive_quicksort(std::vector<T> & v) {
    naive_quicksort(v, 0, v.size());
}

/*
 * uses the median of three pivot selection method, and the faster partition method
 *
 * has a base case of a list of size 1 or fewer
 */
template<typename T, typename Compare = std::less<T>>
void quicksort(std::vector<T> & v, int first, int last, Compare comp = Compare());

/*
 * overload
 */
template<typename T>
void quicksort(std::vector<T> & v) {
    quicksort(v, 0, v.size());
}

/*
 * InsertionSort
 */
template<typename T, typename Compare = std::less<T>>
void insertionsort(std::vector<T> & v, int first, int last, Compare comp = Compare()) {
    for(int sorted = first + 1; sorted < last; ++sorted) {
        for(int i = sorted; i > first && comp(v.at(i), v.at(i-1)); --i) {
            std::swap(v.at(i), v.at(i-1));
        }
    }
}

/*
 * overload
 */
template<typename T>
void insertionsort(std::vector<T> & v) {
    insertionsort(v, 0, v.size());
}

/*
 * uses the median of three pivot selection method and the faster partition method
 *
 * insertion sort is called for reasonably small lists
 */
template<typename T, typename Compare = std::less<T>>
void faster_quicksort(std::vector<T> & v, int first, int last, Compare comp = Compare());

/*
 * overload
 */
template<typename T>
void faster_quicksort(std::vector<T> & v) {
    faster_quicksort(v, 0, v.size());
}