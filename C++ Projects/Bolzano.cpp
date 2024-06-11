/*

In math, the bisection method is used to find a root of a continuous function f(x) in a given interval [x0, x1] provided that f(x0)*f(x1) < 0. If this applies, the Bolzano’s theorem states that the function has one root at least in the interval (x0, x1). 
The method repeatedly bisects the interval and then selects the subinterval in which the function changes sign, and, therefore, must contain a root. 

Write a program that implements the bisection method according to the following steps:

1. Read initial x0 and x1 values so that f(x0)*f(x1) < 0.

2. Read a positive number err for root tolerance error.

3. Read the maximum number of bisections (max_steps).

4. Calculate the approximated root middle = (x0+x1)/2.

5. If |f(middle)| <= err or x1-x0 becomes sufficiently small, that is, x1-x0 <= 2*err or the 
current number of bisections is greater than the input number (max_steps) then go to Step 7, 
otherwise go to Step 6

6. Calculate the product mul = f(x0)*f(middle).
    a. if mul < 0, then the root must be in the new subinterval where x0 = x0 and x1 = middle.
    b. if mul > 0, then the root must be in the new subinterval where x0 = middle and x1 = x1.
    Then, go to Step 4.

7. Display middle as root.
Apply the bisection method to find the root of f(x)= x3+x-1 in a given interval (e.g., [0, 1])

*/

#include <iostream>
using std::cin;
using std::cout ;
using std::endl;

double fun(double x)
{
    return x*x*x-x-1 ;
}

double Bolzano(double x0 , double x1 , int Max_bi , float err)
{
 double middle=(x0+x1)/2 ;
 for (int i=0; i<Max_bi ; i++)
 {
    cout<<i<<endl;
    middle=(x0+x1)/2 ;
    double f=fun(middle) ;
    if ((f<0 ? f*(-1)  : f  ) <=err || (x1-x0)<=2*err )
        break ;
    else if (f*fun(x0)<0)
    x1=middle ;
    else x0=middle ;
 }   
 return middle ;
}

int main()
{
    double y=Bolzano(-10000 ,20000 , 100 , 0.0000005f) ;
    cout<<y;
    cout<<endl<<fun(y);
    return  0 ;
}
