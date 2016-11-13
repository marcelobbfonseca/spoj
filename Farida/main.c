//gcc -ansi -std=c99 main.c -o alo
#include <stdio.h>

void testCase(int testsnumber);

int main(int argc, char const *argv[])
{
	int testsnumber=0;

	scanf("%d", &testsnumber);
	if (testsnumber>0 && testsnumber<=10000)
		testCase(testsnumber);


	return 0;
}

void testCase(int testes){
	int tamanho;//inclusive=0, exclusive=0, temp;
	unsigned long long int coins, inclusive=0, exclusive=0, temp;

	for (int i = 1; i <= testes; i++){

		scanf("%d", &tamanho);//tamanho do vetor de monstros
		if (tamanho==0){
			printf("Case %d: %llu\n",i, inclusive);
			continue;

		}

		if(tamanho > 1000000000)
			return;

		for (int j = 0; j < tamanho; j++){
			scanf("%llu", &coins);//input

			
			temp = inclusive;
			
			if(inclusive < (exclusive+coins))
				inclusive = exclusive+coins;

			exclusive = temp;	
			
		}
		if (inclusive>=exclusive)
			printf("Case %d: %llu\n",i, inclusive);
		else
			printf("Case %d: %llu",i, exclusive);

		exclusive=0;inclusive=0;
	} //fim for:loop de testes

	return;
}