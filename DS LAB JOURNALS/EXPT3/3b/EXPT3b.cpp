#include<iostream>
using namespace std;
int fib(int n);
int main()
{
    int n,i=0;
    cout<<"\nEnter the number of terms for Fibonacci series:";
    cin>>n;
    cout<<"\nFibonacci sequence is as follows::";
    while(i<n)
    {
        cout<<" "<<fib(i);
        i++;
    }
    return 0;
}
int fib(int n)
{
    int fibterm;
    if((n==1)||(n==0))
        return n;
    else
        fibterm=fib(n-1)+fib(n-2);
    return fibterm;
}
