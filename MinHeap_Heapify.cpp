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
            int l = 2*j+1, r = 2*j+2;
            if(a[j]<a[l] && (r>=n || a[j]<a[r])) break;
            
            int nxtInd = (r>=n || a[l]<a[r]) ? l : r;
            swap(a[j],a[nxtInd]);
            j=nxtInd;
        }
    }
    for(int i=0;i<n;i++) cout << a[i] << " ";
	return 0;
}
