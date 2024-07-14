//display all even numbers from 1 to 100
#include<iostream>
using namespace std;
int main()
{
    int i,c;
    for(i=0;i<=100;i++)
    {
        if(i%2==0)
        {
            cout << i <<"\t" ;
            c++; 
        }
    }
}