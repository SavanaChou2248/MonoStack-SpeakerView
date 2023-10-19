/*
Savana Chou
2428859
sachou@chapman.edu
CPSC350-02
Programming Assignment 3: Do You See What I See?

Brief overview:
MonoStack.h defines the implementation of a templated MonoStack class. 
The MonoStack is a stack data structure for either increasing (ascending order) or decreasing (descending order) order. 
The order of the stack, whether increasing or decreasing, is determined by the 'o' parameter passed to the constructor.

*/


#ifndef MONOSTACK_H
#define MONOSTACK_H

#include <iostream>
using namespace std;

template <typename T>
class MonoStack {
public:
    MonoStack();
    MonoStack(int iSize, char o);
    virtual ~MonoStack();
    void push(T value);
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();
    int size();
private:
    T* stackArr;
    int top;
    int count;
    int max;
    char order;
};

template <typename T>
MonoStack<T>::MonoStack() {
    stackArr = nullptr;
    count = 0;
    max = 0;
    top = -1;
    order = ' ';

}

template <typename T>
MonoStack<T>::MonoStack(int iSize, char o){
    count = 0;
    top = -1;
    max = iSize;
    stackArr = new T[iSize];
    order = o;
}

template <typename T>
MonoStack<T>:: ~MonoStack(){
    delete[] stackArr;
}

/*
Name: push
Description: adds an element to the stack while maintaining the desired order. 
for increasing stack, discards all values that are bigger than the value being added
for decreasing stack, discards all values that are smaller than the value being added
*/
template <typename T>
void MonoStack<T>::push(T value){ // 0(n)
    if(isFull()) {
        T* temp = new T[2*max];
        for(int i = 0; i < max; ++i) {
            temp[i] = stackArr[i];
        }
        max *= 2;
        delete[] stackArr;
        stackArr = temp;
    } 

    if (order == 'i') {
        if (isEmpty()) {
            stackArr[++top] = value; 
            ++count;
        } else {
            if (value > stackArr[top]) {
                stackArr[++top] = value; 
                ++count;
            } else {
                while (!isEmpty() && stackArr[top] > value) {
                    pop();
                }
                stackArr[++top] = value; 
                ++count;
            } 
        }
    } else if (order == 'd') {
        if (isEmpty()) {
            stackArr[++top] = value; 
            ++count;
        } else {
            if (value < stackArr[top]) {
                stackArr[++top] = value; 
                ++count;
            } else {
                while (!isEmpty() && stackArr[top] < value) {
                    pop();
                }
                stackArr[++top] = value; 
                ++count;
            }
        }
    }
}

/*
Name: pop
Description: removes and returns the top element from the stack
*/
template <typename T>
T MonoStack<T>::pop(){
    if(isEmpty()) {
        throw runtime_error("Stack is empty");
    }
    --count;
    return stackArr[top--];
}

/*
Name: peek
Description: returns the top element from the stack without removing it
*/
template <typename T>
T MonoStack<T>::peek(){
    if(isEmpty()) {
        throw runtime_error("Stack is empty");
    }
    return stackArr[top]; //what about if it is empty

}

/*
Name: isEmpty
Description: checks if the stack is empty
*/
template <typename T>
bool MonoStack<T>::isEmpty(){
    return (count==0);
}

/*
Name: isFull
Description: checks if the stack is full
*/
template <typename T>
bool MonoStack<T>::isFull(){
    return (count==max);
}

/*
Name: size
Description: returns the current number of elements in the stack of the stack
*/
template <typename T>
int MonoStack<T>::size(){
    return count;
}
#endif
