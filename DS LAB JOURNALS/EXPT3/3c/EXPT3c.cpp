#include<iostream>
#include<stack>

using namespace std;

string prefix;
string postfix;
int i;
int l;

stack<string> s;



bool isoperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
        return true;
    return false;
}

void convert(int i)
{
    if(i<0)
    {
        postfix = s.top();
        s.pop();
        cout<<"Postfix expression :"<<postfix<<endl;
        return;
    }
    if(isoperator(prefix[i]))
        {
            string p1 = s.top();
            s.pop();
            string p2 = s.top();
            s.pop();

            string temp = p1+p2+prefix[i];

            s.push(temp);
        }
        else{
            s.push(string(1,prefix[i]));
        }
    i = i - 1;
    convert(i);
}

int main()
{
   cout<<"Enter the prefix expression :\n";
   cin>>prefix;

   l = prefix.size();

   convert(l-1);

}

