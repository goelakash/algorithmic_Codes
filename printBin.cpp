#include <iostream>
<<<<<<< HEAD
//this comment is pointless
=======
>>>>>>> 29872943ab587b519c913e87589c02c04acb5555
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
