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
    virtual void printList() const override;
    virtual bool isEmpty() override;
    virtual void clear() override;
    
    //Stack Specific Functions
    void push(T inputData);
    void pop(T &obj);
    void peek(T &obj);
};

template<typename T>
void Stack<T>::printList() const
{
    SinglyLinkedList<T>::printList();
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
        cerr << "Stack is empty." << endl;
    else
    {
        LinkNode<T>* ptr = nullptr;
        
        obj = SinglyLinkedList<T>::start->data;
        ptr = SinglyLinkedList<T>::start->next;
        delete SinglyLinkedList<T>::start;
        SinglyLinkedList<T>::start = ptr;

        SinglyLinkedList<T>::decrementCount();
    }
}

template<typename T>
void Stack<T>::peek(T &obj)
{
    if (SinglyLinkedList<T>::isEmpty())
        cerr << "Stack is empty." << endl;
    else
        obj = SinglyLinkedList<T>::start->data;
}

#endif /* Stack_hpp */
