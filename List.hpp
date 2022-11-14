#pragma once
#include "Node.hpp"
#include "MyIterator.hpp"

class List
{
    Node* Head;

    public:

    List()
    {
        Head = new Node(0);
        Head->Next = Head;
        Head->Prev = Head;
    }

    ~List()
    {
        Node* tmp = Head;
        Head->Prev->Next = nullptr;
        while(tmp)
        {
            Head = Head->Next;
            delete tmp;
            tmp = Head;
        }
    }

    friend class Iterator;

    MyIterator begin() {return MyIterator(Head->Next);}
    MyIterator end(){return MyIterator(Head);};

    Node Incert(Node* Current, int Value) // add before Node* Obj
    {
        Node* tmp = Current->Prev; //Previous
        
        Node* Newbie = new Node(Value); // Is a new element

        tmp->Next = Newbie; // [-] -> [-] [-]
        Newbie->Prev = tmp; // [-] <-> [-] [-]

        Newbie->Next = Current; // [-] <-> [-] -> [-]
        Current->Prev = Newbie; // [-] <-> [-] <-> [-]

        return *Newbie;
    }

    void PushBack(int Value)
    {
        Incert(Head, Value);
    }
    void IncertInHead(int Value)
    {
        Node* tmp = Head->Next;

        *Head = Incert(tmp, Value);
    }

    
};
