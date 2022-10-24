#include <stdio.h>
#include <iostream>

using namespace std;

template <class T>
int max_subsequence(T *source, int size, int *id)
{
    if (size == 1)
    {
        *id = 0;
        return 1;
    }
    if (size < 1)
        throw "Sequence is too short";

    T *TmpPointer = source;
    int Condidate = 1;
    int Length = 1;

    for (int counter = 0; counter < size - 1; counter++)
    {
        if (*TmpPointer < *(TmpPointer + 1))
        {
            if (Length == 1)
                *id = counter;
            Length++;
        }
        else
        {
            if (Length > Condidate)
                Condidate = Length;
            Length = 1;
        }
        TmpPointer += 1;
    }
    return Condidate;
}

int main()
{
    int id = 0;
    int array[] = {-1, 0, 2, 5, -4, -5, -3, 0, 15, 16, 17, 18, 19, 20, -5};
    cout << "Max length of subsequence: " << max_subsequence(array, sizeof(array) / 4, &id) << endl;
    cout << "Beggins with: " << id << endl;
    return 0;
}