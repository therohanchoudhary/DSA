#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
	int n; cin >> n; for(int i=0;i<n;i++) cin >> a[i];
    for(int i=(n-1)/2;i>=0;i--)
    {
        for(int j=i;(2*j+1)<n;)
        {
            int desc1 = 2*j+1, desc2 = 2*j+2;
            if(a[j]>a[desc1] && (desc2>=n || a[j]>a[desc2])) break;
            
            int nxtInd = (desc2>=n || a[desc1]>a[desc2]) ? desc1 : desc2;
            swap(a[j],a[nxtInd]);
            j=nxtInd;
        }
    }
    for(int i=0;i<n;i++) cout << a[i] << " ";
	return 0;
}