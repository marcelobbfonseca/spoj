#include <stdio.h>
#include <string.h>
//#include <algorithm>


int color[100],sum[100][100],memo[100][100];

int solve(int, int);

int main(){
    int n;
    
    while(scanf("%d",&n) == 1){
        for(int i = 0;i < n;++i) 
        	scanf("%d",&color[i]);

        for(int i = 0;i < n;++i) 
        	sum[i][i] = color[i];
        
        for(int i = 0;i < n;++i){
            for(int j = i+1;j < n;++j){
                sum[i][j] = sum[i][j-1] + color[j];
                if(sum[i][j] >= 100) sum[i][j] -= 100;
            }
        }
        
        memset(memo,-1,sizeof(memo));
        printf("%d\n",solve(0,n-1));
    }
    
    return 0;
}
int solve(int a, int b){
    if(b == a) 
    	return 0;
    if(b == a+1) 
    	return color[a] * color[b];
    
    int ret = memo[a][b],aux; //&ret
    
    if(ret == -1){
        for(int i = a;i+1 <= b;++i){
            aux = sum[a][i] * sum[i+1][b] + solve(a,i) + solve(i+1,b);
            if(ret == -1 || aux < ret) ret = aux;
        }
    }
    
    return ret;
}
/*
#include <stdio.h>

void testCase(int testsnumber);

int main(int argc, char const *argv[])
{
	int testsnumber=0;

	scanf("%d", &testsnumber);
	testCase(testsnumber);

	return 0;
}

void testCase(int testes){
	int mixtures, mixture ,aux=0;

	for (int i = 1; i <= testes; i++){

		scanf("%d",&mixtures);
		for (int j = 0; j < mixtures; j++){
			scanf("%d",&mixture);
			aux = mixture

		}
	}//fim for:loop de testes

	return;
}

*/