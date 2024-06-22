//65 A   90 Z
//97 a   122 z
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

bool CaesarAlgo(const string &, int );
void Display_Text_File( const string &FP);
int main()
{
    int choice=0;
    string FP; //File Path
    while(1)
    {
        cout<<"1-File Encryption\n2-File Decryption.\n3-Display File Content.\n4-Program Termination.\n\nInsert a choice [1-3]:";
        cin>>choice;
        
        switch(choice)
        {
            //File Encryption:
            case 1 :
                cout<<"Insert File name:";cin>>FP;
                cout<<"Insert Encryption Key: ";
                cin>>choice; //Considered as a key.
                
                if (CaesarAlgo( FP,choice))
                    cout<<"Done Successfully !\n";
                else
                    cout<<"Process failed !\n";
                break;

            //File Decryption:
            case 2 :
                cout<<"Insert File name:";cin>>FP;
                cout<<"Insert Decryption Key: ";
                cin>>choice;
                choice*=-1;
                
                if (CaesarAlgo(FP , choice))
                    cout<<"Done Successfully !\n";
                else
                    cout<<"Process failed !\n";
                break;

            //Display content:
            case 3 :
                cout<<"Insert File name:";cin>>FP;
                Display_Text_File(FP);

                break;

            //Program Termination:
            case 4 :
                return 0;
    
            
            default:
                cout<<"Insert a valid number!\n";
                break;
        }
        cout<<"\n\n";

    }

    return 0;
}
bool CaesarAlgo(const string &FP,int key ){
    fstream *fst=new fstream(FP.c_str() , ios_base::in | ios_base::out);
    if (!fst->is_open()){
        cout<<"Error: Please insert a valid file path.\n";
        delete fst;
        fst=nullptr;
        return false;
        }
    int Up ,Lo ;
    char x , ch;
    if (key>0)
    {
        Up=65 ;
        Lo=97;
        while(1){
            ch=fst->get();
            if (ch=='\n'|| ch==' ')
                continue;
            if (ch==EOF)
                break;
            
            x=ch+key;
            if ((ch>'Z' && ch<'a') || ch<'A' || ch>'z')
                x=ch;            
            else if (ch>='a' && ch<='z' && ((x%123 > 122)||(x%123 < 97)) )
                x=Lo+x%123;
            else if (ch>='A' && ch<='Z' && ((x%91 > 90)||(x%91 < 65)))
                x=Up+x%91;
            fst->seekp(-1, ios_base::cur);
            (*fst)<<x;
            
        }
        fst->close();
        delete fst;
        fst=nullptr;   
    }
    else if (key<0)
    {
        Up=90;
        Lo=122;
        while(1){
            ch=fst->get();
            if (ch==EOF)
                break;

            x=ch+key;
            if ((ch>'Z' && ch<'a') || ch<'A' || ch>'z')
                x=ch;
            else if (ch>='a' && ch<='z' && x<97 )
                x+=26; 
            else if (ch>='A' && ch<='Z' && x<65)
                x+=26;
            fst->seekp(-1, ios_base::cur);
            (*fst)<<x;
        }   
        fst->close();
        delete fst;
        fst=nullptr;   
    }
    
    return true;    
    


}

void Display_Text_File(const string &FP/*File Path*/){
    if (FP==""|| FP.empty()){
        cout<<"Please Insert a file name!";
        return;
    }
    ifstream *inf=new ifstream(FP.c_str() , ios_base::in); //Input File
    string line;
    while(1)
    {
        getline((*inf) , line);
        cout<<line<<std::endl;
        if (!(*inf))
            break;
    }
    inf->close();
    delete inf;
    inf=nullptr;
    cout<<std::endl<<std::endl;
}

