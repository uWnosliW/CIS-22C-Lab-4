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
    virtual void print() const override;
    virtual bool isEmpty() override;
    virtual void clear() override;
    virtual string getStructName() override { return "Stack"; }
    
    //Stack Specific Functions
    void push(T inputData);
    void pop(T &obj);
    T peek();
};

template<typename T>
void Stack<T>::print() const
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
        cerr << this->getStructName() << " is empty." << endl;
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
T Stack<T>::peek()
{
    if (SinglyLinkedList<T>::isEmpty())
        cerr << this->getStructName() << " is empty." << endl;
    else
        return SinglyLinkedList<T>::start->data;
}

#endif /* Stack_hpp */
