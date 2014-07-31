#include <iostream>
using namespace std;

void printBin(int n){
	if(n ==0)
		return;
printBin(n/2);
cout<<n%2;
}


int main() {
	// your code goes here
	for(int i=1;i<17;i++)
		{printBin(i);cout<<endl;}
	return 0;
}
