/*
Define the structure type Circle with member the radius and the type Square with member the length. 

Write a function that takes as parameters a pointer of type void* and an integer parameter.

If its value is 0, the pointer points to a structure of type Circle, otherwise to a structure of type Square. 

The function should increase the member of the pointed structure by 5 and return that pointer. 

Write a program to test the function.
*/
#include <iostream>
using namespace std;

struct Circle{
    double radius ;
};
struct Square{
    double length;
};

void * WhatisThis(void* ptr ,int type );
int main()
{
    void* ptr=nullptr;
    Circle c={10.2};
    Square s={50.6};

    ptr=WhatisThis(&c , 0);
    Circle* updatedCircle = static_cast<Circle*>(ptr);    

    ptr=WhatisThis(&s , 12);
    Square *updatedSquare= static_cast<Square*>(ptr);
    cout<<"Updated Circle : "<<updatedCircle->radius<<endl;
    cout<<"Updated Square : "<<updatedSquare->length<<endl<<ptr<<endl<<&s;

    return 0 ;
}
void * WhatisThis(void* ptr ,int type ){
    if (type==0)
    {
        Circle * p= static_cast<Circle*>(ptr);
        p->radius+=5;
        return p;
    }
    else 
    {   Square * p= static_cast<Square*>(ptr);
        p->length+=5;
        return p;
    }
}
