#include <iostream>
#include "List.hpp"
using namespace std;

int main()
{
    List a;

    for(int i = 0; i<3;i++)
    {
        a.PushBack(rand()%10);
    }

    auto it = a.begin();

    for(int i = 0; it != a.end();i++)
    {
        cout<< *it <<endl;
        it++;
    }
    cout<<*it<<endl;

    return 0;
}