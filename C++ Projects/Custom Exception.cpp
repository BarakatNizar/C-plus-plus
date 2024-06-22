/*
	Simple Exception Scenario :
	of course there is a <exception> header file that contains a lot of exception types such as out_of_range ....etc
	But this one is a scenario of a custom exception.
	Also, you can inherit from exception and overload the `what()` function that returns a `const char*` which descripes the error.
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Err_Rpt
{
    private:
        string msg;
    public:
        Err_Rpt(const char *m) : msg(m) {}
    // Add any function you think it is needed.
    void show_msg(){std::cout<<msg<<std::endl;}
    const string getMsg()
    {
        return msg;
    }
};

class StrChk {
    string name;
    public: 
    StrChk(){}
    StrChk(const string& s){ this->name=s; if(name.size() <3)throw Err_Rpt("Must contain more than 3 chars.");else if (name.size()>=10) throw Err_Rpt("Must contain less than 10 chars."); }
    StrChk(const char* s){ this->name=s ;if(name.size() <3)throw Err_Rpt("Must contain more than 3 chars.");else if (name.size()>=10) throw Err_Rpt("Must contain less than 10 chars."); }
   //Copy Constructor 
    StrChk(const StrChk& s){ this->name=s.name;if(name.size() <3)throw Err_Rpt("Must contain more than 3 chars. Already Worn");else if (name.size()>=10) throw Err_Rpt("Must contain less than 10 chars.Already Worn");}
    virtual StrChk& operator=(const StrChk &s){ this->name=s.name;if(name.size() <3)throw Err_Rpt("Must contain more than 3 chars. Already Worn");else if (name.size()>=10) throw Err_Rpt("Must contain less than 10 chars.Already Worn");}
   
    virtual StrChk operator+(const StrChk &x){ string n=name+x.name; return StrChk(n);}
    char& operator[](int i)
    {
        if (i<0 || i>=10)
            throw Err_Rpt("Out of Range!");
        return this->name[i];
    }
    void show() const{
        std::cout<<"String :"<<this->name<<std::endl;    
    }    
};
int main()
{
    try{
/* The following code should be placed in a try-catch block and
if the Err_Rpt exception occurs the program should capture it, display
the msg and terminate. */

	StrChk s1("First"), s2("Sec"); 
/* If the length of the string is less than 3, the constructor should throw an exception. 
Otherwise, the argument should be copied into name. */

	StrChk s3 = s1+s2; 
/* With s1+s2 the name members should be merged (e.g., s3.name should become FirstSec). 
If the length of the new string is greater than 10, the program should throw an exception. */

	s3[1] = 'a'; 
	/* If the index is out of bounds, the program should throw an exception. That is, in this example, an exception should be thrown. */
/* Experiment with the lengths of the strings, for example, change
s1 and s2 to test the operation of the program. For example, if you
change Sec to Second the program should throw the second exception. */
	s3.show();
	}
   catch(Err_Rpt e){
        cout<<e.getMsg();
    }
return 0;
}


//TIP:

//There are two main types of exceptions , login_error and runtime_error .
//Both are defined in stdexcept header file .

//logic_error :
    //domain_error used to indicate the violation of the valid domain of a function.like sqrt(-2);
    //invalid_argument is used to indicate unexpected arguments.
    //length_error is used to indicate that there is no enough space.
    //out_of_range , 
//runtime_error:
    //range_error , overflow_error , underflow_error.


//Special Exception class: bad_alloc exception, which is thrown when the mem allocation with the 'new/new[]' operator fails.
//Defined in the 'new' header file.



//If exception is not caught , the 'terminate()' library function is called ,which call the 'abort()' function that terminate the program.

//You can replace the terminate() with a special function using: 
//	set_terminate(*fn); 		which its parameter takes a pointer to a function of type :
//	void handler_name(){...; abort(); } ; then 
//	set_terminate(handler_name);


