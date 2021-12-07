/*
#include <iostream>

using namespace std;


   
// C++ program to sort a stack using an 
// auxiliary stack. 
#include <bits/stdc++.h> 
using namespace std; 
  
// This function return the sorted stack 
stack<int> sortStack(stack<int> &a) 
{ 
    stack<int> b;
  
    while (!a.empty()) 
    { 
        // pop out the first element 
        int tmp = a.top(); 
        a.pop(); 
        printf(" %d",tmp);
  
        // while temporary stack is not empty and top 
        // of stack is greater than temp 
        while (!b.empty() && b.top() < tmp) 
        { 
            // pop from temporary stack and push 
            // it to the input stack 
            a.push(b.top()); 
            b.pop();
            printf(" pa\n");
        } 
  
        // push temp in tempory of stack 
        printf("pb \n");
        b.push(tmp); 
    } 
  
    return b; 
} 
  
// main function 
int main() 
{ 
    stack<int> a; 
    a.push(8); 
    a.push(5); 
    a.push(6);
    a.push(3);
    a.push(1); 
    a.push(2);
  
    // This is the temporary stack 
    stack<int> b = sortStack(a); 
    cout << "\nSorted numbers are:"; 
  
    while (!b.empty()) 
    { 
        cout << b.top()<< " "; 
        b.pop(); 
    } 
    */