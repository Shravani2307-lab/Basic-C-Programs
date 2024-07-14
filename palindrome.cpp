// check palindrome 
#include<iostream>
using namespace std;
int main()
{
    int n,num,rev=0,d;
    cout << "Enter a number:";
    cin >> n;
    num=n;    
    while(n>0)    
    {    
    d=n%10;    
    rev=(rev*10)+d;    
    n=n/10;    
    }    
    if(rev==num)
    {
        cout << "Number is palindrome";
    }
    else
    {
        cout << "Not a palindrome";
    }
}