/*


A simple way to encrypt data is to XOR them with a secret key. 

Write a program that reads a key character and the name of a text file and encrypts its content by XORing each character with the key.
 
The encrypted characters should be stored in a second file selected by the user.
*/ 

#include<iostream>
#include<fstream>
#include <cstring>
#include <cstdlib>

using namespace std;


int main()
{
	cout<<"This Program for Enc/Dec text files using a XOR operation with one key char.\nfor Dec, just insert the encFile as input file.\n";
    int key_ch,ch ;
    string fname;
    cout<<"Insert input file :" ;cin>>fname;

    ifstream* in=new ifstream(fname.c_str());
    if (in->is_open()==false)
        {
            cout<<"Error: File 'in' Cannot be loaded!.\n";
            delete in;
            in=nullptr;
            exit(EXIT_FAILURE);
        }
    cout<<"Insert output File: "; cin>>fname;
    ofstream *out=new ofstream(fname.c_str());
    if (out->is_open()==false)
        {
            cout<<"Error: File 'out' Cannot be loaded!.\n";
            delete out;
            out=nullptr;
            delete in;
            in= nullptr;
            exit(EXIT_FAILURE);
        }
    
    

    cout<<"Insert encryption key: ";
    cin.get();
    key_ch=cin.get();


    while(1)
    {
        ch=in->get();
        if (!(*in))
            break;
        else
            *(out)<<(char)(ch^key_ch);
    }
    in->close();
    out->close();
    delete out;
    out=nullptr;
    delete in;
    in= nullptr;

    
    
    
    
    return 0;

}
