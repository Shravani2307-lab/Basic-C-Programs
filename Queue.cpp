#include<iostream>
#define Max 5
using namespace std;
struct Student
{
char Name[20];
int Roll;
Student()
{
Name[0]='\0';
Roll=-1;
}
void get()
{
cout<<"\nEnter Name & Roll No.\n";
cin>>Name>>Roll;
}
void put()
{
cout<<"\nName:"<<Name;
cout<<"\nRoll No.:"<<Roll;
}
};
class Queue
{
Student Q[Max];
int Front,Rear;
public:
Queue() {Front=0;Rear=-1;}
int isFull();
int isEmpty();
void Insert(Student);
Student Remove();
};
int Queue::isEmpty()
{
if(Rear==-1)
return 1;
return 0;
}
int Queue::isFull()
{
if(Rear!=-1 && (Rear+1)%Max==Front)
return 1;
return 0;
}
void Queue::Insert(Student S)
{
if(!isFull())
{
Rear=(Rear+1)%Max;
Q[Rear]=S;
}
else cout<<"\nQueue Full";
}
Student Queue::Remove()
{
Student S;
if(!isEmpty())
{
S=Q[Front];
cout<<"\nRemoved Data:";
Front=(Front+1)%Max;
if((Rear+1)%Max==Front)
{
Front=0;Rear=-1;}
}
else cout<<"\nQueue Empty";
return S;
}
int main()
{
int i,ch;
Queue Q;
Student S;
do
{
cout<<"\n1:Insert\n2:Delete\n3:Exit";
cout<<"\nEnter the Choice";
cin>>ch;
switch(ch)
{
case 1:
if(!Q.isFull())
{
S.get();
Q.Insert(S);
S.put();
}
else
cout<<"\nQueue Full (Overflow)";
break;
case 2:
if(!Q.isEmpty())
{
S=Q.Remove();
S.put();
}
else
cout<<"\nQueue Empty(Underflow)";
break;
}
}
while(ch!=3);
}