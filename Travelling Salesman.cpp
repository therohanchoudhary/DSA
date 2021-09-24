#include<bits/stdc++.h>
#define vt vector
using namespace std;

int n,VISITED_ALL; 
vt<vt<int>> dist,dp;

int tsp(int mask,int pos)
{
    // visited all positions
    if(mask==dp.size()-1) return dist[pos][0];
    
    // no recursion, use dp
    if(dp[mask][pos]!=INT_MAX) return dp[mask][pos];

    for(int city=0;city<n;city++)
	if((mask&(1<<city))==0) // city not visited
		dp[mask][pos]=min(dp[mask][pos],dist[pos][city]+tsp(mask|(1<<city),city));
		
    return dp[mask][pos];
} 

int main()
{
    cin >> n;
    dp.resize(1<<n,vt<int>(n,INT_MAX));
    dist.resize(n,vt<int>(n));
    
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> dist[i][j];
    cout << tsp(1,0) << endl;
    
    return 0;
}
