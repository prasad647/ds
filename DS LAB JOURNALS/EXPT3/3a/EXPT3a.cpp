#include<iostream>
using namespace std;
int factorial(int n);
int main()
{
    int num;
    cout<<"\nEnter the number:";
    cin>>num;
    cout<<"\nFactorial of entered number:"<<factorial(num);
    return 0;
}
int factorial(int n)
{
    int fact;
    if(n==0)
       return 1;
    else
        fact=n*factorial(n-1);
    return fact;
}
