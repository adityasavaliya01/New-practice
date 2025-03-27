#include<iostream>
#include <math.h>
using namespace std;
class Timeconvertor
{
    public:
    void tmcnv(int n)
    {
        cout<<"HH:MM:SS: ";
        int a= n/3600;
        cout<<a<<":";
        
        int c=n%3600;
        int b=c/60;
        cout<<b<<":";
        
        c=c%60;
        cout<<c;
    }
    
    void tosecond(int h, int m, int s)
    {
        int hour = h*3600;
        int minute = m*60;
        int sec = s;
        cout<<"total second: "<<hour+minute+sec;
    }
};

int main()
{
    Timeconvertor time;
    int n;
    cout<<"enter total seconds: ";
    cin>>n;
    time.tmcnv(n);
    int h,m,s;
    cout<<endl<<endl<<"enter hour: ";
    cin>>h;
    cout<<"enter min: ";
    cin>>m;
    cout<<"enter sec: ";
    cin>>s;
    time.tosecond(h,m,s);
}