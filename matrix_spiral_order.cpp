#include<iostream>
#define R 4
#define C 4
using namespace std;

void spiralOrder(int arr[R][C], int m, int n){
int k,l,i;
k=0;
l=0;
while(k<m && l<n){
    for(i=l;i<n;i++){
        cout<<arr[k][i]<<", ";
    }
    k++;
    for(i=k;i<m;i++)
        cout<<arr[i][n-1]<<", ";
    n--;
    if(k<m)
    {
        for(i=n-1;i>=l;i--)
            cout<<arr[m-1][i]<<", ";
        m--;
    }
    if(l<n)
    {
        for(i=m-1;i>=k;i--)
            cout<<arr[i][l]<<", ";
        l++;
    }
}
}
main()
{
    int m, n;
    cin>>m>>n;
    int arr[R][C];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        cin>>arr[i][j];
    spiralOrder(arr,m,n);
}
