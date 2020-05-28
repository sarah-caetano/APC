#include <stdio.h>

int main(){
	FILE *banana;
	char palavra[20], outra[]= "FOME";

	banana= fopen("banana.txt", "w");

	if (banana==NULL)
	{
		printf("Você não conseguiu abrir o arquivo!\n");
		return 1;
	}
	printf("Escreva uma palavra:  ");
	gets(palavra);

	fprintf(banana, "%s\n", palavra);
	fprintf(banana, "%s\n", outra);

	fclose(banana);

	banana= fopen("banana.txt", "r");

	while(fgets(palavra, sizeof(palavra), banana) != NULL){/*Enquanto não for o fim do arquivo esse loop colocará na tela tudo que estiver dentro do arq*/
		printf("A palavra é: ");
		printf("%s\n", palavra);
	}/*A leitura do que está no arquivo é feita de tal forma que o que está lá ficou armazenado nos vetores "palavra" e "outra"*/

	fclose(banana);

	printf("Dados gravados com sucesso!\n");

	return 0;
}