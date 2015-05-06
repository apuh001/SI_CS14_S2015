#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Greater{
    bool operator()(int a, int b){
        return a > b;
    }
};

void pq_sort(vector<int> &v)
{
    priority_queue<int, vector<int>, Greater> orderedQ;
    
    for(auto it = v.begin();  it != v.end(); it++)
        orderedQ.push(*it);
    
    v.clear();
    
    while(!orderedQ.empty())
    {
        v.push_back(orderedQ.top());
        orderedQ.pop();
    }
}

int main()
{
    vector<int> vals;
    vals.push_back(5);
    vals.push_back(-2);
    vals.push_back(23);
    vals.push_back(-123);
    vals.push_back(0);
    vals.push_back(888);
    vals.push_back(69);
    
    pq_sort(vals);
    
    for(auto it = vals.begin();  it != vals.end(); it++)
        cout << *it << endl;
        
    return 0;
}