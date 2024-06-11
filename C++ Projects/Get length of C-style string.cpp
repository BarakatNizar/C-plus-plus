#include <iostream>

unsigned int test(const char *str);
//it returns the length of C-style string .



int main()
{
    char x[]="Hello";
    std::cout<<test(x);
    return 0 ;
}

unsigned int test(const char *str)
{
	const char *ptr = str;
	
	for(;*str; str++);
	
	return str-ptr;
}
