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
                T* tempArray = new T[max];
                int tempTop = -1;
                int tempLength = 0;
                while (!isEmpty() && stackArr[top] > value) {
                    tempArray[++tempTop] = pop();
                    ++tempLength;
                }
                stackArr[++top] = value; 
                ++count;
                for(int i = tempLength; i > 0; --i) {
                    stackArr[++top] = tempArray[i - 1];
                    ++count;
                }
                delete[] tempArray;
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
                T* tempArray = new T[max];
                int tempTop = -1;
                int tempLength = 0;
                while (!isEmpty() && stackArr[top] < value) {
                    tempArray[++tempTop] = pop();
                    ++tempLength;
                }
                stackArr[++top] = value; 
                ++count;
                for(int i = tempLength; i > 0; --i) {
                    stackArr[++top] = tempArray[i - 1];
                    ++count;
                }
                delete[] tempArray;
            }
        }
    }
}

template <typename T>
T MonoStack<T>::pop(){
    if(isEmpty()) {
        cout << "Stack is empty" << endl;
    }
    --count;
    return stackArr[top--];
}

template <typename T>
T MonoStack<T>::peek(){
    if(isEmpty()) {
        cout << "Stack is empty" << endl;
    }
    return stackArr[top]; //what about if it is empty

}

template <typename T>
bool MonoStack<T>::isEmpty(){
    return (count==0);
}

template <typename T>
bool MonoStack<T>::isFull(){
    return (count==max);
}

template <typename T>
int MonoStack<T>::size(){
    return count;
}
#endif