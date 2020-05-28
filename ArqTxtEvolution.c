#include <stdio.h>
int main() {
	const int quantidade=3, tamanho=50;
	FILE *banana; 
	int i, escolha, valores[quantidade], valor_lido[quantidade];
	char frase[quantidade][tamanho], frase_lida[quantidade][tamanho];

	printf("Deseja colocar coisas (1) ou ler (2) o arquivo? \n");
	scanf("%d", &escolha);
	getchar();
	if (escolha==1)
	{
		banana=fopen("moranguinho.txt", "w+");
		if (banana==NULL)
		{
			printf("Não dá pra abrir, pq n existe\n");
		}
		printf("Escreva %d frases:\n", quantidade);
		for (i = 0; i < quantidade; ++i)
		{
			scanf("%50[^\n]", frase[i]);
			getchar();
		}
		for (i = 0; i < quantidade; ++i)
		{
			fprintf(banana, "%s\n", frase[i]);
		}
		for (i = 0; i < quantidade; ++i)
		{
			scanf("%d", &valores[i]);
			fprintf(banana, "%d\n", valores[i]);
		}
		fclose(banana);
	}
	if (escolha==2)
	{
		banana=fopen("moranguinho.txt", "r");
		if (banana==NULL)
		{
			printf("Não dá pra abrir, pq n existe\n");
		}
		for (i= 0; i < quantidade; ++i)
		{
			fscanf(banana, "%50[^\n]\n", frase_lida[i]);
			printf("%s\n", frase_lida[i]);
		}
		for (i= 0; i < quantidade; ++i)
		{
			fscanf(banana, "%d", &valor_lido[i]);
			printf("%d\n", valor_lido[i]);
		}
		fclose(banana);
	}
	return 0;
}