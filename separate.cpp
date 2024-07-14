#include<iostream>
using namespace std;
int main()
{
    int m,digit,sum=0;
    cout << "Enter a number: ";
    cin >> m;
    digit= m%10;
    sum=sum+digit*digit*digit; 
    cout << "Digits are: " << digit;

}