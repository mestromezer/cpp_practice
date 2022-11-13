#pragma once
#include "Node.hpp"
#include "List.hpp"

class MyIterator
{
    Node *Current;
    public:

    MyIterator(Node *First) : Current(First)
    {}

    int operator*()
    {
        return Current->Value;
    }

    MyIterator& operator++(int Value)  // Value - просто заглушка
    {
        Current=Current->Next;
        return *this;
    }

    MyIterator& operator--(int Value) // Value - просто заглушка
    {
        Current=Current->Prev;
        return *this;
    }

    bool operator!=(const MyIterator& obj)
    {
        if(this->Current != obj.Current) return true;
        return false;
    }
};