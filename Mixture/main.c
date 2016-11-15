#include<stdio.h>
#include <string.h>

int a[100],sum[100][100],dp[100][100];

int teste(int,int);


int main(){
    int n,i,j;
    while(scanf("%d", &n)==1){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

            for(i = 0;i < n;++i) sum[i][i] = a[i];
            for(i=0;i<n;i++){
                for(j=i+1;j<n;j++){
                    sum[i][j]=sum[i][j-1] + a[j];
                    if(sum[i][j]>=100)
                        sum[i][j]-=100;
                }

            }
            memset(dp,-1,sizeof dp);
             printf("%d\n",teste(0,n-1));


    }

    return 0;
}


int teste(int ai,int bi){

	int i,*r,c;
    if(ai==bi){
       return 0;
    }
    if((ai+1)==bi)
        return a[ai] * a[bi];
          r = &(dp[ai][bi]);
        if(*r==-1){
            for(i=ai;i+1<=bi;i++){
               c = sum[ai][i] * sum[i+1][bi] + teste(ai,i) + teste(i+1,bi);
            if(*r==-1 || c < *r)*r = c;
            }
        }
        return *r;
}