//write a program to read marks of a student and then print grade depending on the marks
// marks >= 75 distinction
//marks >= 60 first class
//marks >= 55 higher second class
//marks >= 40 second class
//marks <= 40 fail
#include<iostream>
using namespace std;
int main()
{
    int e,m,s,h,g,sum=0,avg;
    cout << "Enter Your Marks";
    cout << "\n Enter Your English Marks: ";
    cin >> e;
    cout << "\n Enter Your Maths Marks: ";
    cin >> m;
    cout << "\n Enter Your Science Marks: ";
    cin >> s;
    cout << "\n Enter Your History Marks: ";
    cin >> h;
    cout << "\n Enter Your Geography Marks: ";
    cin >> g;
    sum=e+m+s+h+g;
    avg=sum/5;
    if(avg>=75)
    {
    cout << "Distinction";
    }
    else if(avg>=60)
    {
    cout << "First class";
    }
    else if(avg>=55)
    {
    cout << "Higher second class";
    }
    else if(avg>=40)
    {
    cout << "Second class";
    }
    else if(avg<=40)
    {
    cout << "FAIL";
    }
    
}