#include<iostream>
using namespace std;
class train
{
    public:
        int number;
        string name;
        string source;
        string destination;
        int traintime;
        static int traincount;
        
    train(int trnum,  string trname,  string trsource,  string destn,  int trtime) 
    {
        number = trnum;
        name = trname;
        source = trsource;
        destination = destn;
        traintime = trtime;
        traincount++;
    }
    
    train() { 
        number = 0;
        traintime = 0;
    }
    
    ~train() {
        traincount--;
    }

    void addtrain()
    {
        cout<<"Enter train number: "; cin>>number;
        cout<<"Enter train name: "; cin>>name;
        cout<<"Enter train source: "; cin>>source;
        cout<<"Enter train destiantion: "; cin>>destination;
        cout<<"Enter traintime: "; cin>>traintime;
        
    }
    void displaytrains()
    {
        cout<<"Train number: "<<number<<"\nTrain name: "<<name<<"\nTrain source: "<<source<<"\nTrain destination: "<<destination<<"\nTraintime: "<<traintime;
    }
    
};
int train::traincount = 0;
class railwaysystem {
private:
    train trains[100];
    int totaltrain;
    
    public:
    railwaysystem() {
        totaltrain = 0;
    }
    
        void addTrain()
        {
        if (totaltrain < 100)
        {
            trains[totaltrain].addtrain(); 
            totaltrain++;
        } 
        else
        {
            cout << "Cannot add more trains. Maximum limit reached!" << endl;
        }
    }

    void displayAllTrains()
    {
        if (totaltrain == 0)
        {
            cout << "No train records found." << endl;
            return;
        }
        for (int i = 0; i < totaltrain; i++) {
            cout << "\nTrain " << i + 1 << ":" << endl;
            trains[i].displaytrains();
        }
    }
    
    int searchTrain(int num)
    {
        for (int i = 0; i < totaltrain; i++) {
            if (trains[i].number == num) {
                trains[i].displaytrains();
                return 1;
            }
        }
        return 0;
    }
};
int main()
{
    railwaysystem t;
    int n=1;
    
    while(n!=0)
    {
        cout<<"--Railway Reservation Sysytem--\n1.Add new train record\n2.Display all train records\n3.Search train by number\n4.Exit\n";
        cout<<"Enter choice: ";
        cin>>n;
        switch(n)
        {
            case 1:
                t.addTrain();
                break;
                
            case 2:
                cout<<"\n\t TRAIN RECORDS\n";
                t.displayAllTrains();
                cout<<"\n\n";
                
                break;
            
            case 3:
                {
                    int num;
                    cout << "Enter Train Number: "; cin >> num;
                    if (!t.searchTrain(num))
                    {
                        cout << "Train not found.\n";
                    }
                    break;
                }
                break;
            
            case 0:
                cout<<"Exiting the system!\n";
            default:
                cout<<"\n Please enter valid number\n";
        }
    }
}