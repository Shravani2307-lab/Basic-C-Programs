#include<iostream>
using namespace std;
class overloading 
{
    public:
    static int add(int a, int b)
    {
        return a+b;
    }
    static int add(int a, int b, int c)
    {
        return a+b+c;
    }
};
int main()
{
    overloading obj;
    cout << obj.add(5,5)<< endl;
    cout << obj.add(5,8,9);
}