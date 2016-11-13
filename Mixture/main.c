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