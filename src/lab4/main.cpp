#include <iostream>
#include "tree.h"
 
using namespace std;
 
int main() {
    
    Tree<int> test;
    //Total should be n(n+1)/2   72/2 = 36
    test.push(3);
    test.push(4);
    test.push(6);
    test.push(8);
    test.push(36);
    test.push(1);
    test.push(2);
    test.push(7);
    test.push(5);
    
    
    // test.push(14);
    // test.push(9);
    // test.push(11);
    // test.push(20);
    // test.push(1);
    // test.push(500);
    // test.push(-22);
    
    test.print();

    //cout << endl << test.get_root()->right->data << endl;
    
    cout << endl;
    cout << "min: " << test.min()->data << endl;
    cout << "max: " << test.max()->data << endl << endl;
    
/*
    cout << "Finding 20: " << test.find(20)->data << endl;
    cout << "Finding 7: " << test.find(7)->data << endl;
    cout << "Finding 9: " << test.find(9)->data << endl;
 */
 
    cout << "Total (Expected 72): " << test.total() << endl;

    Tree<string> strTree;
    strTree.push("paranoid");
    strTree.push("dog");
    strTree.push("dangling");
    strTree.push("digestion");
    strTree.push("word");
    
    strTree.print();
    cout << endl;
    cout << "Min: " << strTree.min()->data << endl;
    cout << "Max: " << strTree.max()->data << endl;
    cout << "strTree total: " << strTree.total() << endl;
    
    return 0;
}