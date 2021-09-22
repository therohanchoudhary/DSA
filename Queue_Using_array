#include<iostream>
using namespace std;

int que[100001];
int si=0, ei, q, type, val;

void print()
{
    for(int i=si;i<=ei;i++) cout << que[i] << " ";
    cout << endl;
}

int main()
{
    cin >> ei >> q; ei--; 
    for(int i=0;i<=ei;i++) cin >> que[i];
    
    while(q--) //pop,insert queries
    {
        cin >> type;
        if(type) // 1 insert
        {
            cin >> val;
            ei++;
            que[ei]=val;
        }
        else if(type==0 && si<ei) si++; //pop
        print();
    }
}
