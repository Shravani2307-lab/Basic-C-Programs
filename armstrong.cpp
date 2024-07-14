// armstrong number 
#include<iostream>
using namespace std;
int main()
{
    int num,sum=0,t,digit;
    cout << "Enter a number: \n";
    cin >> num;
    t=num;
    while (t>0)
    {
      digit= t%10;
      sum=sum+digit*digit*digit; 
      t = t/10;
       
    }
    
    
    if(num==sum)
    {
        cout << "Its an amstrong number !!!";
    }
    else
    {
        cout << "Its not an amstrong number ";
    }
}

