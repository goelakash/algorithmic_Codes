#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

void printSub(int* sub, int size){

for(int i=0;i<size;i++)
    cout<<sub[i]<<"  ";

    cout<<"\n\n";
}

void subset_sum(int* arr,int* sub, int a_size, int s_size, int ite,int sum, int target_sum){

    if(sum == target_sum)
    {
        printSub(sub,s_size);

        if( ite + 1 < a_size && sum - sub[ite] + sub[ite+1] <= target_sum )
        {
            // Exclude previous added item and consider next candidate
            subset_sum(arr, sub, a_size, s_size-1,  ite + 1, sum - arr[ite], target_sum);
        }
        return;
    }
    else{
            if(ite<a_size && sum+arr[ite]<=target_sum)
        {
        for(int i=ite;i<a_size;i++)
        {
            sub[s_size]=arr[i];
            if( sum+arr[i]<=target_sum)
            subset_sum(arr,sub,a_size,s_size+1,i+1,sum+arr[i],target_sum);
        }
        }
    }

}

void genSubset(int* arr, int n, int target_sum){

int* sub = new int[n];
sort(arr,arr+n);
int total;
 for( int i = 0; i < n; i++ )
    {
        total += arr[i];
    }

    if( arr[0] <= target_sum && total >= target_sum )
    {

        subset_sum(arr, sub, n, 0, 0, 0, target_sum);

    }
delete [] sub;
}

main(){
int n;
cout<<"Enter n: ";
cin>>n;
int* arr = new int[n];

for(int i=0;i<n;i++)
    cin>>arr[i];

int target_sum;
cin>>target_sum;

genSubset(arr,n,target_sum);

delete [] arr;

}
