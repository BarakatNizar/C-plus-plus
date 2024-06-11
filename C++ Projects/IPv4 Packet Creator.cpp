#include <iostream>
#include <iomanip>
using namespace std;

void Build_Pkt(const int IP_src[] , const int IP_dst[] , int port);
void Show_Frm(const unsigned char pkt[] , int len);

int main()
{
    char ch ;
    int IP_src[4] , IP_dst[4] , TCP_dst_port;
    
    do{
        cout<<"Enter dst port[1-65535]: ";
        cin>>TCP_dst_port ;
    }
    while(TCP_dst_port<1|| TCP_dst_port>65535);

    cout<<"Insert dst IP (x.x.x.x): \n";
    cin>>IP_dst[0]>>ch>>IP_dst[1]>>ch>>IP_dst[2]>>ch>>IP_dst[3] ;
    
    if (TCP_dst_port==80)
    {
        if ((IP_dst[0]==130 &&IP_dst[0]==140) || (IP_dst[0]==160 && IP_dst[0]==170))
            {
                cout<<"It isn't allowed to connect to network.\n";
                return 0;
            }
    }
    
    cout<<"Insert src IP (x.x.x.x):\n";
    
    cin>>IP_src[0]>>ch>>IP_src[1]>>ch>>IP_src[2]>>ch>>IP_src[3];
    
    Build_Pkt(IP_src , IP_dst , TCP_dst_port);
    
    return 0;

}


void Show_Frm(const unsigned char pkt[] , int len)
{
    for (int i=0 ; i<len ; i++)
    {
        if (i%16==0)
        	cout<<endl;
        
        cout<<setw(2)<<setfill('0')<<hex<<(int)pkt[i]<<' ';
    }    
    
}
void Build_Pkt(const int IP_src[] , const int IP_dst[] , int port){
    unsigned char pkt[40]={0};
    int i, j; 
    pkt[0]=0x45 ;//Version,IHL.
    pkt[8]=255 ;//Time to live.
    pkt[9]=6 ;//Protocol=tcp.

    for (i=12 ,j=0 ;i<16 ; i++ , j++)
        pkt[i]=IP_src[j];//IP source
    for (i=16 ,j=0 ;i<20 ; i++ , j++)
        pkt[i]=IP_dst[j];//IP destination.
    
    pkt[20]=1500>>8;//TCP source Port.
    pkt[21]=1500 & 0xFF ;
    pkt[22]=port>>8 ; //TCP dst Port.
    pkt[23]=port & 0xFF ;

    pkt[33]=2; //SYN bit.
    pkt[34]=0xFF ; //MAX value for window field is all 16 bits set to 1.
    pkt[35]=0xFF;//The value of checksum and Urgent Pointer are set in positions 36-40.Therefore the total length of ip Packet is 40 bytes.

    pkt[2]=0 ;//IP total length.
    pkt[3]=40 ;
    Show_Frm(pkt , 40);
}
