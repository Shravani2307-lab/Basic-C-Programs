#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout << "Enter three numbers:";
    cin >> a;
    cin >> b;
    cin >> c;
    if(a>b)
        {
            if(a>c)
            {
                cout << "A is greater";
            }
            else
            {
                cout << "C is greater";
            }
        }
    if(b>c)
        {
            cout << "B is greater";
        }
}