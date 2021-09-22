#include<iostream>
using namespace std;

int n;
int a[100001];

void print()
{
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
}

void merge(int l, int mid, int r)
{
    int merArr[r-l+1];
    int i=l,j=mid+1,k=0;
    
    while(i<=mid && j<=r)
    	merArr[k++]= (a[i]<a[j]) ? a[i++] : a[j++]; 
    
    while(i<=mid) merArr[k++]=a[i++];
    while(j<=r) merArr[k++]=a[j++];
    
    for(int i=l;i<=r;i++) a[i]=merArr[i-l];
}

void mergeSort(int l, int r)
{
    if(l>=r) return;
    
    int mid=(l+r)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    merge(l,mid,r);
}

int main()
{
	  cin >> n; for(int i=0;i<n;i++) cin >> a[i];
    mergeSort(0,n-1);
    print();
}
