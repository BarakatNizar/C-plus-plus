/*
Suppose that each line of the students.txt text file contains the name of a student and his grades in three courses. 


Write a program that reads the file and displays the name of the student with the best average grade. 

If more than one student has the same best average, the program should display all.
*/

//Pattern: name grd1 grd2 grd3

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

template <typename T1, typename T2> class Map_Key
{
    private:
        T1 key;
        T2 val;
    public:
        //CTor:
        Map_Key()
        {
        }
        Map_Key(T1 t1 , T2 t2)
        {
            this->key=t1;
            this->val=t2;
        }

        bool check  (const T1 k)const; 

        T1 getKey  ()const{
            return key;
        };
        
        T2 get() const {
            return val;
        }; 
        


        Map_Key<T1,T2>& operator=(const Map_Key<T1,T2>&); //Copy Assignment
        Map_Key<T1,T2> operator+(const Map_Key<T1,T2>&);

};
template <typename T1,typename T2> bool Map_Key<T1,T2>::check (const T1 k)const
{
    if (this->key == k)
        return true;
    return false;
}
template <typename T1,typename T2> Map_Key<T1,T2> Map_Key<T1,T2>::operator+(const Map_Key<T1,T2> &mk){
    Map_Key<T1,T2> Temp;
    Temp.key=this->key+ mk.key;
    Temp.val=this->val+ mk.val;
    return Temp;
}
template <typename T1,typename T2> Map_Key<T1,T2>& Map_Key<T1,T2>::operator=(const Map_Key<T1,T2> &mk){
    this->key=mk.key;
    this->val= mk.val;
    return *this;
}
int main(int argc, char**argv)
{
    string FP;
    if (argc==2)
        FP=argv[1];
    else 
    {
        cout<<"Insert file path  (example file : u6.txt) :";cin>>FP;
    }
    ifstream in(FP.c_str());
    if (!in.is_open())
    {
        cout<<"Error : File is not opened.\n";
        exit(EXIT_FAILURE);
    }
    vector< Map_Key<string , float> >stu;
    float *grd=new float[3];

    //Initializing 
    if (1)
    {
        string name;
        float Tavg;
        in>>name>>grd[0]>>grd[1]>>grd[2];
        
        Tavg=(grd[0]+grd[1]+grd[2])/3;
        stu.push_back(Map_Key<string,float>(name , Tavg));

    }

    int no_stu=1;
    while (1)
    {   
        string name;
        float Tavg;

        in>>name>>grd[0]>>grd[1]>>grd[2];
        Tavg=(grd[0]+grd[1]+grd[2])/3;
        
        if (!in)   //End of file already reached.          
            break;
        
        if (Tavg > stu[0].get()){ //Higher average-> Clear&register the new higher avg.
            stu.clear();
            stu.push_back(Map_Key<string,float>(name , Tavg));
            no_stu=1;
        }
        else if (Tavg == stu[0].get()) //Same Average-> just add
            {
            stu.push_back(Map_Key<string,float>(name , Tavg));
            no_stu++;
            }
    }
    in.close();
    delete grd;
    grd=nullptr;
    cout<<no_stu<<endl;
    cout<<"Best Averages: \n";
    for (int i=0 ; i<no_stu ; i++)
        cout<<"Student: "<<stu[i].getKey()<<"\tAvg: "<<stu[i].get()<<endl;
    stu.clear();
    
    return 0;
}
