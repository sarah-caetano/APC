/*Cria um arquivo binário para escrever nele o que o usuário colocar no terminal,uma string (palavra),
fecha ele, depois reabre para lê-lo*/
#include <stdio.h>
int main(int argc, char **argv){

	FILE *BOLAUM;
	char string[10];
	int lido;

	BOLAUM=fopen("formosa.bin", "wb+");

	if (BOLAUM==NULL)
	{
		printf("You can't go this way, man!\n");
	}
	fwrite(argv[1], sizeof(argv[1]), 1, BOLAUM);
	fwrite(&argc, sizeof(argc), 1, BOLAUM);

	fclose(BOLAUM);

	BOLAUM=fopen("formosa.bin", "rb");

	fread(string, sizeof(argv[1]), 1, BOLAUM);
	fread(&lido, sizeof(lido), 1, BOLAUM);

	printf("o argv lido foi: %s\n", string);
	printf("o argc lido foi: %d\n", lido);

	fclose(BOLAUM);


	return 0;
}
