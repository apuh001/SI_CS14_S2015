//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn5/main.cpp
/// @brief Assignment 5/Lab 7 for CS 12 Winter 2015
///
/// @author Alexander Puh [apuh001@ucr.edu]
/// @date 2/17/2015
///
/// @par Enrollment Notes 
///     Lecture Section: 002
/// @par
///     Lab Section: 024
/// @par
///     TA: <TA name>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============

#include "MyVector.h"
#include <iostream>

using namespace std;

int main(){
    
    MyVector<string> vec;
    vec.push_back("CS14");
    vec.push_back("World");
    vec.insert("Hello", 0); 
    cout << vec.front() << endl; // "Hello"
    cout << vec.back() << endl; // "World"
    vec.pop_back();
    cout << vec.back() << endl; // "CS14"
    vec.pop_back();
    cout << vec.back() << endl; // "Hello"
    
    MyVector<int> another_vec;
    another_vec.push_back(42);
    cout << another_vec.front() << endl; //42
    
    return 0;
}