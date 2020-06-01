#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include "LinkNode.h"
using std::cout;
using std::endl;

template <typename T>
class SinglyLinkedList
{
protected:
    int count;
    LinkNode<T>* start;
    LinkNode<T>* end;
    
public:
    //Ctor
    SinglyLinkedList() : count(0), start(nullptr), end(nullptr) { }
    
    //Dtor
    virtual ~SinglyLinkedList();
    
    //Getters
    int getCount() { return count; }
    
    //Setters
    void incrementCount() { count++; }
    void decrementCount() { count--; }
    
    //Generic List type implementation functions
    bool find(T obj);
    void printList() const;
    bool isEmpty();
    
    //Linked List Specific Functions
    LinkNode<T>* getNode(T inputData);
    void appendNode(T inputData);
    void prependNode(T inputData);
    void insertNode(int pos, T inputData);
    void insertNode(T obj, T inputData);
    void deleteNode(T inputData);
};

template <typename T>
bool SinglyLinkedList<T>::find(T obj)
{
    if (start == nullptr)
        return false;
    else
    {
        LinkNode<T>* nodePtr = nullptr;
        nodePtr = start;
        
        while (nodePtr != nullptr)
        {
            if (nodePtr->data == obj)
                return true;
            
            nodePtr = nodePtr->next;
        }
        return false;
    }
}


template <typename T>
bool SinglyLinkedList<T>::isEmpty()
{
    return (start == nullptr);
}

template <typename T>
LinkNode<T>* SinglyLinkedList<T>::getNode(T obj)
{
    if (start == nullptr)
        return nullptr;
    else
    {
        LinkNode<T>* nodePtr = start;
        while (nodePtr != nullptr)
        {
            if (nodePtr->data == obj)
                return nodePtr;
            nodePtr = nodePtr->next;
        }
    }
    return nullptr;
}

template <typename T>
void SinglyLinkedList<T>::prependNode(T inputData)
{
    LinkNode<T>* newNode = new LinkNode<T>;
    newNode -> data = inputData;
    if(isEmpty())
    {
        start = newNode;
        end = newNode;
    }
    else
    {
        newNode -> next = start;
        start = newNode;
    }
    incrementCount();
}

template <typename T>
void SinglyLinkedList<T>::appendNode(T inputData)
{
    LinkNode<T>* newNode = nullptr; // Points to new node
    LinkNode<T>* nodePtr = nullptr; // Move through the list
    
    //Make new node, populate with data and set next to nullptr
    newNode = new LinkNode<T>;
    newNode->data = inputData;
    newNode->next = nullptr;
    
    if (isEmpty())
    {
        start = newNode;
        end = newNode;
    }
    else
    {
        nodePtr = start;      //start traversing from start node
        
        while (nodePtr->next)
        {
            nodePtr = nodePtr->next;   //set nodePtr to the next node
        }
        
        //insert newNode and end as next
        nodePtr->next = newNode;
        end = nodePtr->next;
    }
    
    incrementCount();
}

template <typename T>
void SinglyLinkedList<T>::insertNode(int pos, T inputData)
{
    if(pos == 0)
    {
        prependNode(inputData);
    }
    else if(pos == count - 1)
    {
        appendNode(inputData);
    }
    else if(pos>0&&pos < count - 1)
    {
        LinkNode<T>* currNode = start; //Get to correct index
        for(int i = 0;i<pos;i++)
        {
            currNode = currNode -> next;
        }
        LinkNode<T>* newNode = new LinkNode<T>; //insert new LinkNode
        newNode -> data = inputData;
        newNode -> next = currNode -> next;
        currNode -> next = newNode;
    }
}

template <typename T>
void SinglyLinkedList<T>::insertNode(T obj, T inputData)
{
    if(start -> data == obj)
    {
        prependNode(inputData);
    }
    else if(end -> data == obj)
    {
        appendNode(inputData);
    }
    LinkNode<T>* currNode = start; //Get to correct index
    while(currNode->data!=obj)
    {
        currNode = currNode -> next;
    }
    LinkNode<T>* newNode = new LinkNode<T>;//insert new LinkNode
    newNode -> data = inputData;
    newNode -> next = currNode -> next;
    currNode -> next = newNode;

}

template <typename T>
void SinglyLinkedList<T>::deleteNode(T inputData)
{
    LinkNode<T>* nodePtr = nullptr;
    LinkNode<T>* previous = nullptr;
    
    if (isEmpty())
        return;
    
    //If we are deleting first node
    if (start->data == inputData)
    {
        nodePtr = start->next;
        delete start;
        start = nodePtr;
        
        decrementCount();
    } else
    {
        nodePtr = start;
        //Traverse through list
        while (nodePtr != nullptr && nodePtr->data != inputData)
        {
            previous = nodePtr;
            nodePtr = nodePtr->next;
            
            end = nodePtr;
        }
        
        //If not the last node
        if (nodePtr)
        {
            previous->next = nodePtr->next;
            delete nodePtr;
        }
        decrementCount();
    }
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    LinkNode<T>* nodePtr;
    LinkNode<T>* next;
    
    nodePtr = start;
    while (nodePtr != nullptr)
    {
        next = nodePtr->next;
        delete nodePtr;
        nodePtr = next;
    }}

template<typename T>
void SinglyLinkedList<T>::printList() const
{
    LinkNode<T>* nodePtr;
    nodePtr = start;
    
    while (nodePtr != nullptr)
    {
        cout << nodePtr->data << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}

#endif /* LinkedList_h */
