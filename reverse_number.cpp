#include<bits/stdc++.h>
#include<string>
using namespace std;

int reverse_num(int x)
{
    if(x<10)
        return x;
    int rem = x%10;

    int next = reverse_num(x/10);
    string str = to_string(rem)+to_string(next);
    return stoi(str);
}

int main()
{
    int n;
    cin>>n;
    cout<<reverse_num(n);
}
