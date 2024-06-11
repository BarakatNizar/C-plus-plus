//This Algo is just check the validaty of IMEI number.


#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main(){


int ch , i , sum , temp ;
char chk_dig;
cout<<"\n\nWelcome to IMEI Checker \n\n\n";
cout<<"INESRT IMEI TO CHECK:" ;
for (int i=1 ; i<15 ; i++)
{
	ch=cin.get();
	if((i&1)==1)//Then it's odd Position.
		sum+= ch-'0' ;
	else {
	//in even position , we doubly the number if its bigger than 9 , we split it then add.
		temp=2*(ch-'0') ;
		if (temp>=10)
			temp=temp/10 + temp%10 ;
		sum+=temp;
	}
}
//After addition ,the last dig is the checker to do;
ch=cin.get();
ch=ch-'0';
chk_dig=sum%10;
if (chk_dig!= 0)
	chk_dig=10-chk_dig ;
	
if (ch==chk_dig)cout<<"[IMEI] Valid ";
else cout<<"InVaild IMEI"; 



return 0 ;
}
