//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn5/IntVector.h
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

#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>

class MyVector{
    private:
        unsigned sz;
        unsigned cap;
        T* data;
    
    public:
        MyVector()
        {
            sz = 0;
            cap = 0;
            data = 0;
        }
            
        MyVector(unsigned size)
        {
            sz = size;
            cap = size;
            data = new T[sz];
                
            for(unsigned i = 0; i < sz; i++)
            {
                //Default T
                data[i] = new T;
            }
        }
            
        MyVector(unsigned size, T value)
        {
            sz = size;
            cap = size;
            data = new T[sz];
                
            for(unsigned i = 0; i < sz; i++)
            {
                data[i] = value;
            }
            
        }
        
        ~MyVector()
        {
            delete[] data;
            data = 0;
        }
        
        unsigned size() const
        {
            return sz;
        }
            
        unsigned capacity() const
        {
            return cap;
        }
            
        bool empty() const
        {
            if (sz == 0)
                return true;
            return false;
        }
            
        const T & at(unsigned index) const
        {
            if(index >= sz)
                exit(1);
                
            return data[index];
        }
        
        T & at (unsigned index)
        {
            if(index >= sz)
                exit(1);
                
            return data[index];
        }
        
        void insert(T value, unsigned index)
        {
            if (index > sz)
                exit(1);
                
            sz++;
            
            if(sz > cap)
            {
                if(cap == 0)
                    expand(sz-cap);
                else
                    expand();
            }
            
            if(sz == 1)
            {
                T* tempArr = new T[cap];
                tempArr[0] = value;
                data = tempArr;
                tempArr = 0;
                
                return;
            }
            
            T* tempArr = new T[cap];
            unsigned i = -1;
            
            for(i = 0; i < index; i++)
            {
                tempArr[i] = data[i]; 
            }
           
            for (i = index; i < sz; i++)
            {
                tempArr[i + 1] = data[i];
            }
            
            delete[] data;
            
            tempArr[index] = value;
            data = tempArr;
            tempArr = 0;
            
            return;
        }
                
        void erase(unsigned index)
        {
            if(index >= sz)
                exit(1);
            
            sz--;
            
            unsigned i = -1;
            
            int* tempArr = new T[cap];
            
            for(i = 0; i < index; i++)
            {
                tempArr[i] = data[i]; 
            }
            
            for (i = index + 1; i < sz + 1; i++)
            {
                tempArr[i - 1] = data[i];
            }
            
            delete[] data;
            data = tempArr;
            tempArr = 0;
            
            return;
        }
                
        const T & front() const
        {
            return *data;
        }
                
        T & front()
        {
            return *data;
        }
        
        const T & back() const
        {
            return data[sz - 1];
        }
        
        T & back()
        {
            return data[sz - 1];
        }
        
        void assign(unsigned n, T value)
        {
            sz = n;
            
            if(cap != 0)
            {
                if (sz-cap > (2*cap))
                    expand(sz-cap);
                else
                    expand();
                
                delete[] data;
                data = new T[cap];
                
                for (unsigned i = 0; i < sz; i++)
                {
                    data[i] = value;
                }
            }
            else if (cap == 0)
            {
                if (sz-cap > (2*cap))
                    expand(sz-cap);
                else
                    expand();
                
                data = new T[cap];
                
                for (unsigned i = 0; i < sz; i++)
                {
                    data[i] = value;
                }
            }
            
            return;
        }
        
        void push_back(T value)
        {
            sz++;
            
            if(cap == 0)
            {
                expand(sz - cap);
                
                data[0] = value;
                
                return;
            }
            
            if(sz >= cap)
                expand();
            
            T* newArr = new T[cap];
            
            for (unsigned i = 0; i < sz - 1; i++)
            {
                newArr[i] = data[i];
            }
            
            newArr[sz - 1] = value;
            
            delete[] data;
            data = newArr; 
            newArr = 0;
            
            return;
        }
        
        void pop_back()
        {
            if(sz == 0)
                exit(1);
                
            sz--;
        }
        
        void clear()
        {
            sz = 0;
        }
        
        void resize(unsigned size)
        {
            T temp = new T;
            resize(size, *temp);
            
            return;
        }
        
        void resize(unsigned size, T value)
        {
            if (size < sz)
            {
                sz = size;
            }
            else if (size > sz)
            {
                if (size < cap && cap != 0)
                {
                    unsigned begin = sz; //Old size. WHere the new Values begin 
                    sz = size;
                    unsigned i = -1;
                    
                    T* tempArr = new T[cap];
                    
                    for (i = 0; i < begin; i++)
                    {
                        tempArr[i] = data[i];
                    }
                    
                    for (i = begin; i < sz; i++)
                    {
                        tempArr[i] = value;
                    }
                    
                    delete [] data;
                    data = tempArr;
                    tempArr = 0;
                }
                else if (size > cap && cap != 0)
                {
                    unsigned begin = sz;
                    sz = size;
                    unsigned i = -1;
                    
                    if ((sz-cap) > (2*cap))
                        expand(sz - cap);
                    else
                        expand();
                    
                    int* tempArr = new int[cap];
                    
                    for (i = 0; i < begin; i++)
                    {
                        tempArr[i] = data[i];
                    }
                    
                    for (i = begin; i < sz; i++)
                    {
                        tempArr[i] = value;
                    }
                    
                    delete [] data;
                    data = tempArr;
                    tempArr = 0;
                }
                else if (sz == 0 && cap == 0) //For the default constructors
                {
                    sz = size;
                    
                    if ((sz-cap) > (2*cap))
                        expand(sz - cap);
                    else
                        expand();
          
                    for(unsigned i = 0; i < sz; i++)
                    {
                        data[i] = value;
                    }
                }
            }
            
            return;
        }
                
        void reserve(unsigned n)
        {
            if (cap < n)
            {
                if ((n-cap) < (cap))
                    expand();
                else
                    expand(n-cap);
            }
            
            return;
        }
        
    private:
        void expand()
        {
            if (cap == 0)
                return;
                
            cap*=2;
        
            T* newArr = new T[cap];
            
            for (unsigned i = 0; i < sz - 1; i++)
            {
                newArr[i] = data[i];
            }
            
            delete[] data;
            data = newArr; 
            newArr = 0;
            
            return;
        }
        
        void expand(unsigned amount)
        {
            if (cap == 0)
            {
                cap+=amount;
                
                data = new T[cap];
                
                return;
            }
        
            cap+=amount;
            
            T* newArr = new T[cap];
            
            for (unsigned i = 0; i < sz - 1; i++)
            {
                newArr[i] = data[i];
            }
            
            delete[] data;
            data = newArr; 
            newArr = 0;
            
            return;
        }
        
        //Definitions
};

#endif