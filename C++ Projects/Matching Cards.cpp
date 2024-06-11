/*
A popular card game among children is a memory matching game. 

The game starts with a deck of identical pairs of cards face down on a table. 

The player selects two cards and turns them over. 

If they match, they remain face up. If not, they are flipped face down. 

The game ends when all cards are face up. 


Game Simulation: 
write a program that uses the elements of a two-dimensional array as the cards. 
To test your program, use a 4×4 array and assign the values 1-8 to its elements (cards). 
Each number must appear twice. 
Set the values in random positions. 

An example of the array might be:
        5   3   4   8
        4   2   6   1
        3   8   7   6
        2   5   1   7

The program should prompt the user to select the positions of two cards and display a message to indicate if they match or not. 

The program ends when all cards are matched.
*/

/*
1- assigning values to cards 1 -> 8
2- Shiffiling cards
3- The main faced up cards depend on Status[] within value 1;

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;
const int row=4;
const int col=4;
void Show_Board(int cr[row][col] , int st[row][col]);
void Select_card(const int cr[][col]  , int st[row][col] , int *r , int *c);

int main()
{
    int cnt=0 ; //no.flipped cards.
    int status[row][col] ,card[row][col];
    srand(time(NULL)) ;

    //Assinging :
    for (int i=0 , r=0 ; i<row  ; i++) //{1 1 2 2 , 3 3 4 4 , 5 5 6 6 , 7 7 8 8 }
    {
        for (int j=0 ; j<col ; j+=2)
        {
            card[i][j]=card[i][j+1]=r+1;
            r++;
        }
    }
    //Shiffling :
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j<col ; j++)
        {
            int temp=card[i][j] ;
            int r=rand()%row ;
            int c=rand()%col ;
            card[i][j]=card[r][c];
            card[r][c]=temp;
        }
    }
    //The game will end When all cards are faced up.
    int no_try=0 ;
    while(cnt!= col*row)
    {
        int r[2]={-1} , c[2]={-1} ;
        Select_card(card, status , &r[0] , &c[0] ) ; //This will continue once inserted correctly.
        cout<<"Card1: "<<card[r[0]][c[0]]<<endl ;
        
        Select_card(card, status , &r[1] , &c[1] ) ; //This will continue once inserted correctly.
        cout<<"Card2: "<<card[r[1]][c[1]]<<endl; ;
        if (card[r[1]][c[1]]==card[r[0]][c[0]])
            {
            cout<<"Cards Matched! Press Enter to continue." ;
            cin.get();
            cout<<"\n\n\n\n";cnt+=2;}
        else {
            cout<<"Cards are not matched Press Enter to continue." ;
            cin.get();
            status[r[0]][c[0]]=status[r[1]][c[1]]=0;
        }
        no_try++;
        cout<<"\n\n\n\n";
        Show_Board(card , status) ;
    }
    cout<<endl<<endl<<"Done in "<<no_try<<" tries." ;
return 0 ;
}
void Show_Board(int cr[row][col] , int st[row][col])
{
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j<col ; j++)
        {
            if (st[i][j]==1)
                cout<<cr[i][j]<<' ';
            else 
            cout<<"* ";
        }cout<<endl;
    }
}
void Select_card(const int cr[][col]  , int st[row][col] , int *r , int *c)
{
    //Process the insertion to Force user to insert the right value:
    while(1)
    {
        cout<<"Inesrt the row:";cin>>*r;
        cout<<"insert the col:";cin>>*c ;
        (*r)--;
        (*c)--;
        if (*r >= row || *r<0 ||*c >= col || *c<0 )
        {
            cout<<"Out of bound dimensions.\n" ;
            continue;
        }
        if(st[*r][*c]==1)
        {
            cout<<"Error: This card is already flipped.\n";
            continue ;
        }
        st[*r][*c]=1;
        return;
    }
}
