#include<iostream>
using namespace std;

int winner(int a[][3])
{
    int cnt0,cnt1;
    
    //cout << "Here0\n";
    for(int i=0;i<3;i++)
    {
        cnt0=0; cnt1=0;
        for(int j=0;j<3;j++)
        {
            if(a[i][j]==0) cnt0++;
            else if(a[i][j]==1) cnt1++;
        }
    }
    if(cnt0==3) return 0;
    if(cnt1==3) return 1;
    
    for(int i=0;i<3;i++)
    {
        cnt0=0; cnt1=0;
        for(int j=0;j<3;j++)
        {
            if(a[j][i]==0) cnt0++;
            else if(a[j][i]==1) cnt1++;
        }
    }
    
    if(cnt0==3) return 0;
    if(cnt1==3) return 1;
    
    cnt0=0; cnt1=0;
   	for(int i=0;i<3;i++)
    {
    	if(a[i][i]==0) cnt0++;
        else if(a[i][i]==1) cnt1++;
    }
    
    if(cnt0==3) return 0;
    if(cnt1==3) return 1; 
    
    cnt0=0; cnt1=0;
    for(int i=0;i<3;i++)
    {
    	if(a[i][2-i]==0) cnt0++;
        else if(a[i][2-i]==1) cnt1++;
    }
    
    if(cnt0==3) return 0;
    if(cnt1==3) return 1; 
    
    return 2;
}

void print(int a[][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++) 
        {
            if(a[i][j]==0) cout << "O ";
            else cout << "X  ";
        }
        cout << endl;
    }
    cout << endl;
}

void util(int a[][3], int x, int y, int cnt0, int cnt1)
{
    if(x>3 || y>3 || cnt0>5 || cnt1>4) return;
    if(x==3) { print(a); return; }
    if(y==3) util(a,x+1,0,cnt0,cnt1);
    
    a[x][y]=0;
    util(a,x,y+1,cnt0+1,cnt1);
        
    a[x][y]=1;
    util(a,x,y+1,cnt0,cnt1+1);
}

int main()
{
    int a[3][3]={{2,2,2},{2,2,2},{2,2,2}};
    util(a,0,0,0,0);
	return 0;
}
