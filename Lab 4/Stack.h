#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>
#include "LinkedList.hpp"
#include "LinkNode.hpp"
using std::cout;
using std::endl;
using std::cerr;

template<typename T>
class Stack : protected SinglyLinkedList<T>
{
public:
    //Ctor
    Stack() : SinglyLinkedList<T>() { }
    
    //Dtor
    virtual ~Stack() { };
    
    //Generic List type implementation functions
    virtual void print() override;
    virtual bool isEmpty() override;
    virtual void clear() override;
    virtual string getStructName() override { return "Stack"; }
    
    //Stack Specific Functions
    void push(T inputData);
    void pop(T &obj);
    void peek(T &obj);
};

template<typename T>
void Stack<T>::print()
{
    SinglyLinkedList<T>::print();
}

template<typename T>
bool Stack<T>::isEmpty()
{
    return SinglyLinkedList<T>::isEmpty();
}

template<typename T>
void Stack<T>::clear()
{
    SinglyLinkedList<T>::clear();
}

template<typename T>
void Stack<T>::push(T inputData)
{
    SinglyLinkedList<T>::prependNode(inputData);
}

template<typename T>
void Stack<T>::pop(T &obj)
{
    if (SinglyLinkedList<T>::isEmpty())
    {
        cerr << this->getStructName() << " is empty." << endl;
        return;
    }
    
    obj = SinglyLinkedList<T>::start->data;
    SinglyLinkedList<T>::deleteNode(SinglyLinkedList<T>::start->data);
    SinglyLinkedList<T>::decrementCount();
}

template<typename T>
void Stack<T>::peek(T &obj)
{
    if (SinglyLinkedList<T>::isEmpty())
    {
        cerr << this->getStructName() << " is empty." << endl;
        return;
    }
    
    obj = SinglyLinkedList<T>::start->data;
}


#endif /* Stack_hpp */
