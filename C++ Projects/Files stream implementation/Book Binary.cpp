/*
Define the Book structure with members: title, author, and price. 
Suppose that the book.dat binary file contains 100 of those structures. 
Write a program that reads the sequence number of a book entry (e.g., 25), the new data, and replace the existing data with the new data. 
Then, the program should read from the file the data of that entry and display them, 
in order to verify that it was written correctly.


Analysing :
It must be in a Fixed Size!
E.g., 
title size: 25
author size: 25
total size per book: 54 bytes

So we can move freely by seeking the pointer of the file stream.
(seeking bytes)*(i-th - 1) of the book

*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

struct Book{
    char title[25], author[25]; //char size=1 , total: 25*2
    float price;
};
int main(int argc, char **argv){
    string FP;
    if (argc==2)
        FP=argv[1];
    else {
        cout<<"Insert book data file path: ";cin>>FP;
    }
    fstream *fst=new fstream(FP.c_str() , ios_base::in |ios_base::out|ios_base::binary );
    if (!fst->is_open()){
            cout<<"ERROR : File is not opened!\n";
            delete fst;
            fst=nullptr;
            exit(EXIT_FAILURE);
    }
    int number;
    cout<<"Insert Book ID [1-50] : ";
    cin>>number;

    Book b;

    const int Seeker=(50+sizeof(float))*(number-1);
    
    fst->seekg(Seeker);

    fst->read((char*)b.title , sizeof(b.title ));
    fst->read((char*)b.author , sizeof(b.author));
    fst->read((char*)&b.price , sizeof(float));
    
    cout<<number<<"-"<<b.title<<"  "<<b.author <<"  "<<b.price<<"$\n\n";
    cout<<"Insert the new data for this book (Title Author Price)\n";
    cin>>b.title>>b.author >>b.price;
    
    fst->seekp(Seeker);

    fst->write((char*)b.title , sizeof(b.title ));
    fst->write((char*)b.author , sizeof(b.author));
    fst->write((char*)&b.price , sizeof(float));

    //Display all in order to verifying:
    fst->seekg(0);
    number=1; //I used this variable in order to avoid initializing a new one(just saving memory).
    while(number++)
    {
        fst->read((char*)b.title , sizeof(b.title ));
        fst->read((char*)b.author , sizeof(b.author));
        fst->read((char*)&b.price , sizeof(float));
    
        if (!(*fst))
            break;
    
        cout<<(number-1)<<"-"<<b.title<<"  "<<b.author <<"  "<<b.price<<"$\n";
    }

    fst->close();
    delete fst;
    fst=nullptr;

    cout<<"Done!";


    return 0;    
}