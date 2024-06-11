/*
Function returns the value of the polynomial a0 + a1x + a2x2 +...+ anxn for a given x.
The function prototype is: double poly(const vector<double>& a, double x, int n);
where the coefficients of the polynomial are stored into a and n represents its degree. Write a
program that reads the degree of a polynomial and its coefficients and stores them in a vector
object. Then, it reads a value (e.g., x) and uses the function to display the value of the polynomial.
The program should restrict the user to input a value for the degree less than 100. To calculate
the power of the coefficients, use the function pow(), which is declared in cmath as: double
pow(double a, double b);
*/

#include <iostream>
#include<cmath>
#include<vector>
using std::cout;
using std::cin;
using std::vector ;
double poly(const vector<double> &a , double x , int n);
void Insertions(vector<double> &a , int num);
int main()
{
    vector<double> p;
    int n ;
    double x;
    cout<<"Insert The polynomial degree: ([0-99])";
    cin>>n;
    cout<<"Now insertion:\n";
    Insertions(p ,n+1);
    cout<<"\n\tInsert x to calculate Pn(x): ";
    cin>>x;
    x=poly(p ,x ,n);
    cout<<"Result:"<<x;
    return 0;
}
double poly(const vector<double> &a , double x , int n){
    double res=a[0];
    for (int i=1; i<=n; i++)
    {
        res+= a[i]*pow(x,i);
    }
    return res;
}
void Insertions(vector<double> &a , int num){
     for (int i=0; i<num ; i++)
    {   double x;
        cin>>x;
        a.push_back(x) ;
    }
}
