/*

*/
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::vector;

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

        bool check const (const T1 k); 

        T1 getKey const (){
            return key;
        };
        
        T2 get() const {
            return val;
        }; 
        


        Map_Key<T1,T2>& operator=(const Map_Key<T1,T2>&); //Copy Assignment
        Map_Key<T1,T2> operator+(const Map_Key<T1,T2>&);

};
template <typename T1,typename T2> bool Map_Key<T1,T2>::check const(const T1 k)
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

int main()
{
	cout<<"This Program only for implement a Pair Value using a template class\n";
    Map_Key<string, int> mk_1("One", 1), mk_2("Two", 2);
    Map_Key<string, int> mk_3 = mk_1 + mk_2;

    vector<Map_Key<string,int>> v;
    v.push_back(mk_1);
    v.push_back(mk_2);
    v.push_back(mk_3);
    cout<<"Insert ur Key (string) to get The value :";
    string k;
    cin>>k;
    for(auto &i : v)
    {
        if (i.check(k)){
            cout<<"Value : "<<i.get();
            return 0;
            }

    }
    cout<<"Couldn't Found !";


return 0;
}
