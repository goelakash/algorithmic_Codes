/* Trivial application of Binary Indexed Trees / Fenwick Trees
    read() and update() from TopCoder tutorial here-
    http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binaryIndexedTrees
*/

#include <iostream>
#include <cstdio>

using namespace std;

int MaxVal,tree[1000005];

int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}


int main()
{
 int n,q;
 scanf("%d%d",&n,&q);
 int i,k;
 MaxVal=n;
for(i=1;i<=n;i++)
   tree[i]=0;

 for(i=1;i<=n;i++)
    {scanf("%d",&k);
     update(i,k);
     }

    char test;
    int x,y;
 for(i=1;i<=q;i++){
    getTest:
    scanf("%c",&test);


    if(test=='S'){
        scanf("%d%d",&x,&y);
        printf("%d\n",read(y+1)-read(x));
    }

    else if(test=='G'){
        scanf("%d%d",&x,&y);
        update(x+1,y);
    }
    else if(test=='T'){
        scanf("%d%d",&x,&y);
        update(x+1,-y);
    }
    else
        goto getTest;

    }

    return 0;
}
