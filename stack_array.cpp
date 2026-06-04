#include <iostream>
using namespace std;
const int MAX = 10;

class stack
{
    private:
    int arr[MAX],tos=-1,y;

    public:
    bool is_full()
    {
     return tos == MAX - 1;
    }

    bool is_empty()
    {
        return tos == -1;
    }

    void push(int x)
    {
        if(is_full())
        {
            cout<<"The stack is full"<<endl;
            return;
        }
        
        tos++;
        arr[tos] = x;
        cout<<"The value pushed is: " <<x<<endl;
    }

    void pop()
    {
        if(is_empty())
        {
            cout<<"The stack is empty!!!"<<endl;
            return;
        }
        y = arr[tos];
        tos--;
        cout<<"The value popped is: "<<y<<endl;
    }

    int peek()
    {
        if(is_empty())
        {
            cout<<"The stack is empty!!!"<<endl;
            return;
        }
        return arr[tos];
    }
};

int main()
{
    stack s;
    int choice,z;

    do 
    {
    cout<<".....Stack driven menu......"<<endl;
    cout<<"1.Push"<<endl;
    cout<<"2.Pop"<<endl;
    cout<<"3.Peek"<<endl;
    cout<<"4.Exit"<<endl;

    cin>>choice;
     
    switch(choice)
    {
        case 1:
        cout<<"Enter the value u want to push"<<endl;
        cin>>z;
        s.push(z);
        break;

        case 2:
        s.pop();
        break;

        case 3:
        cout<<"The value peek is: "<<s.peek()<<endl;
        break;

        case 4:
        cout<<"Thank you for visiting"<<endl;
        break;

        
    }
    }while(choice != 4);



    return 0;

}


