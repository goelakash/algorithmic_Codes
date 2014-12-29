#include <cstdio>
#include <cmath>
#include<iostream>
using namespace std;
int getMid(int s, int e) {  return s + (e -s)/2;  }

/*  A recursive function to get the sum of values in given range of the array.
    The following are parameters for this function.

    st    --> Pointer to segment tree
    index --> Index of current node in the segment tree. Initially 0 is
             passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented by
                 current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
int getSumUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return 0;
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}

void updateValueUtil(int *st, int ss, int se, int i, int diff, int index)
{
    if (i < ss || i > se)
        return;
    st[index] = st[index] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }

    int diff = new_val - arr[i];

    arr[i] = new_val;

    updateValueUtil(st, 0, n-1, i, diff, 0);
}
int getSum(int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int* arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=i+1;
        scanf("%d",&m);
        char ch = getchar();
        char line[100];
        int l,r,f;
        for(int i=0;i<m;i++)
        {
            ch = getchar();
            if(ch=='0')
                sscanf(line,"%d%d%d",&l,&r,&f);
            else
                sscanf(line,"%d%d",&l,&r);
            cout<<"l: "<<l<<"  r: "<<r;

        }

    }
    return 0;
}
