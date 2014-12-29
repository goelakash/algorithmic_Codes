#include<bits/stdc++.h>

using namespace std;

int pivotElement(const int* arr,int l,int r){
if(arr[l]<arr[r])
    return 0;
int m;
while(r-l>1){
m=(l + r) /2;
if(arr[m]<=arr[r])
    r = m;
else
    l = m;
}
return m;

}

main(){
int arr[10],n;
cout<<"N :  ";
cin>>n;
for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
if(n = pivotElement(arr,0,n-1))
    cout<<"Array rotated. Starts from index: "<<n;
else
    cout<<"Array unrotated.";
}
