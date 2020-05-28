#include <stdio.h>
int ve_escolha(){
	int escolha, i=0;
	scanf("%d", &escolha);
	while(getchar()!='\n'){i++;};
	while ((escolha!=0 && escolha!=3) || i>0)
	{
		printf("Digite uma opção válida!\n");
		i=0;
		scanf("%d", &escolha);
		while(getchar()!='\n'){i++;};
	}
	return escolha;
}
int main(){
	FILE *pudim;
	int escolha=0, sorte, sorte_lida;
	char frase_do_natal[50];
	printf("\e[H\e[2J");
	while (escolha==0){
		printf("\nO que você quer fazer no arquivo binário, escrever (1) ou ler(2)?\n");
		scanf("%d", &escolha);
		getchar();
		if (escolha==1)
		{
			printf("\nEscreva o que você quer que seja escrito no arquivo binário sobre o natal:\n");
			scanf("%50[^\n]", frase_do_natal);
			printf("Agora escreva um número pra dar sorte: ");
			scanf("%d", &sorte);

			pudim=fopen("buffet.bin", "wb+");
			if (pudim==NULL)
			{
				printf("Não pode abrir, foi mal\n");
				return 0;
			}
			fwrite(frase_do_natal, sizeof(frase_do_natal), 1, pudim);
			fwrite(&sorte, sizeof(sorte), 1, pudim);
			fclose(pudim);
			printf("\nObrigada pela participação!\n\nVocê quer voltar ao menu para ler o que escreveu? Se sim, digite 0, se não digite 3\n");	
			escolha=ve_escolha();
		}
		else if (escolha==2)
		{
			pudim=fopen("buffet.bin", "rb");
			if (pudim==NULL)
			{
				printf("Não pode abrir, foi mal\n");
				return 0;
			}
			fread(frase_do_natal, sizeof(frase_do_natal), 1, pudim);
			fread(&sorte_lida, sizeof(sorte_lida), 1, pudim);
			printf("\nAqui fala-se verdades:  %s\n", frase_do_natal);
			printf("Aqui tem um número da sorte: %d\n", sorte_lida);
			fclose(pudim);
			printf("\nVocê quer voltar ao menu para escrever de novo? Se sim, digite 0, se não digite 3\n");	
			escolha=ve_escolha();
		}
	}

	return 0;
}