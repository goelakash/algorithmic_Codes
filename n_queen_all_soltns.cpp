#include<cstdio>

#define N 5


using namespace std;

void printSol(int sol[N][N])
{
    for(int i=0;i<N;i++)
        {for(int j=0;j<N;j++)
            printf("%d ",sol[i][j]);
        printf("\n");
            }
printf("\n\n");
}

bool isSafe(int x,int y,int sol[N][N]){
int i,j;
for(j=0;j<y;j++)
{
    if(sol[x][j])
        return false;
}
for(i=x,j=y;i>=0&&j>=0;i--,j--)
{
    if(sol[i][j])
        return false;
}
for(i=x,j=y;i<N&&j>=0;i++,j--)
{
    if(sol[i][j])
        return false;
}
return true;
}


bool nQueenUtil(int col, int sol[N][N])
{
    if(col>=N)
        return true;

    for(int i=0;i<N;i++){
        if(isSafe(i,col,sol)){

            sol[i][col]=1;
            if(nQueenUtil(col+1,sol))
                return true;
            sol[i][col]=0;
        }
    }
    return false;
}


void nQueen(){

    for(int i=0;i<N;i++)
    {
    int sol[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        sol[i][j]=0;


        sol[i][0]=1;
        if(nQueenUtil(1,sol))
            printSol(sol);

    else
    printf("No Solution exists! for row %d",i);


    }
}

main(){
nQueen();
}
