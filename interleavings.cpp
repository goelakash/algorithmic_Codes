#include<bits/stdc++.h>
using namespace std;

void inter_leaving(char* s1,char* s2,char* i_str,int m,int n,int i)
{
    if(m==0&&n==0)
    {
        i_str[i]='\0';
        cout<<i_str<<endl;
    }
    else
    {if(m==0||(m!=0&&n!=0))
    {
        i_str[i] = s2[0];
        inter_leaving(s1,s2+1,i_str,m,n-1,i+1);
    }
    if(n==0||(m!=0&&n!=0))
    {
        i_str[i] = s1[0];
        inter_leaving(s1+1,s2,i_str,m-1,n,i+1);
    }
    }
}

int main()
{
    char str1[100],str2[100],res_str[300];
    scanf("%s%s",str1,str2);
    inter_leaving(str1,str2,res_str,strlen(str1),strlen(str2),0);
}
