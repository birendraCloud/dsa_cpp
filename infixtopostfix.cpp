#include <iostream>
#include <string>
using namespace std;
const int MAX = 20;

class stack
{
    private:
    char arr[MAX];
    int tos;

    public:
    stack()
    {
        tos = -1;
    }

    bool isempty()
    {
       return tos == -1;
    }

    bool isfull()
    {
        return tos == MAX - 1;
    }

    void push(char x)
    {
        tos += 1;
        arr[tos] = x;
    }

    char pop()
    {
    char val=arr[tos];
    tos --;
    return val;
    }

    char peek()
    {
        return arr[tos];
    }


};

class conversion
{
    private:
    stack s;
    int priority(char c)
    {
      if (c == '^')
      {
        return 3;
      }
      if(c == '/' || c == '*')
      {
        return 2;
      }
      if(c == '+' || c== '-')
      {
        return 1;
      }
      return 0;
    }

    public:
    string convert(string exp)
    {
        string result;

        for(int i=0;i<exp.size();i++)
        {
        
            if(exp[i] == '(')
            {
            s.push(exp[i]);
            }


            else if(isalnum(exp[i]))
            {
                result += exp[i];
            }


            else if(exp[i] == ')')
            {
                while(!s.isempty() && s.peek() != '(')
                {
                    result += s.pop();
                }
                s.pop();
            }

            else
            {
                if(s.isempty() || priority(exp[i]) > priority(s.peek()))
                {
                    s.push(exp[i]);
                }

                else
                {
                 while(!s.isempty() && priority(exp[i]) <= priority(s.peek()))
                 {
                    result += s.pop();
                 }
                 s.push(exp[i]);
                }
            }


        }

   while(!s.isempty())
   {
    result += s.pop();
   }
        
    return result;
    }
};

int main()
{
    conversion c;
    string expression;
    cout<<"Enter an infix expression: ";
    cin>>expression;
    cout<<"The equivalent postfix expression is: "<<c.convert(expression)<<endl;
    return 0;
}