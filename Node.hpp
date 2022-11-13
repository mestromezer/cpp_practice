#pragma once
struct Node
{
    int Value;
    Node* Next;
    Node* Prev;
    Node(int Value,Node* Next = nullptr,Node* Prev = nullptr)
    {
        this->Value = Value;
        this->Next = Next;
        this->Prev = Prev;
    }
};