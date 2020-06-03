#include <iostream>
#include "LinkedList.h"
#include "Queue.h"
using namespace std;
int main()
{
    SinglyLinkedList<int> thing;
    for(int i=0;i<5;i++)
    {
        thing.appendNode(i);
    }
    for(int i=20;i>15;i--)
    {
        thing.prependNode(i);
    }
    thing.insertNode(4, 30);
    thing.insertNode(19, 31);
    thing.insertNode(20, 32);
    thing.insertNode(16, 33);
    thing.insertNode(17, 34);
    thing.deleteNode(33);
    thing.deleteNode(34);
    thing.print();
    cout<<thing.isEmpty()<<endl;
    cout<<thing.getCount()<<endl;
    thing.clear();
    cout<<thing.isEmpty()<<endl;
    cout<<thing.getCount()<<endl;
    Queue<int> q;
    for(int i=20;i>15;i--)
    {
        q.enqueue(i);
    }
    while(!q.isEmpty())
    {
        cout<<q.peekFront()<<" "<<q.peekRear()<<endl;
        q.dequeue();
    }
    for(int i=20;i>15;i--)
    {
        q.enqueue(i);
    }
    q.clear();
    while(!q.isEmpty())
    {
        cout<<q.peekFront()<<" "<<q.peekRear()<<endl;
        q.dequeue();
    }
    return 0;
}
