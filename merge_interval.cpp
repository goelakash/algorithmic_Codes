#include<bits/stdc++.h>

using namespace std;

struct interv{
int a;
int b;
};

bool compare(interv x, interv y){
if(x.a==y.a){
    return x.b<y.b;
}
return x.a<y.a;
}

main(){
int i,n;
scanf("%d",&n);
interv* arr_int=new interv[n];

for(i=0;i<n;i++)
    scanf("%d%d",&(arr_int[i].a),&(arr_int[i].b));

sort(arr_int , arr_int+n , compare);


stack <interv> s;
interv current = arr_int[n-1];
i=n-2;
while(i>=0){
    if(arr_int[i].b>=current.a){
        current.a=arr_int[i].a;
    }
    else{
        s.push(current);
        current = arr_int[i];
    }
    i--;
}
s.push(current);
while(!s.empty()){
    current = s.top();
    printf("(%d,%d)  ",current.a,current.b);
    s.pop();
}

}
//for(i=0;i<n;i++)
//    printf("(%d,%d)  ",arr_int[i].a,arr_int[i].b);
//    printf("i=%d,\tpushed - (%d,%d)  \n",current.a,current.b);
//    printf("\ni=%d,\t(%d,%d)  \n",i,current.a,current.b);
