#include <stdio.h>
int main(int argc, char const **argv)
{
	FILE *comida;
	int numero;
	char lido[10], lido_2[10];
	comida=fopen("coxinha.txt", "w+");
	if (comida==NULL)
	{
		printf("You can't access this, dude!\n");
		return 1;
	}
	printf("%s\n", argv[0]);
	printf("%c %c %c %c %c\n", argv[1][0], argv[1][1], argv[1][2], argv[1][3], argv[1][4]);
	printf("%s\n", argv[2]);

	fprintf(comida, "%s\n%s\n", argv[1], argv[2]);
	fprintf(comida, "%d\n", argc);
	fclose(comida);

	comida=fopen("coxinha.txt", "r");

	fscanf(comida, "%s\n", lido);
	fscanf(comida, "%s\n", lido_2);
	fscanf(comida, "%d\n", &numero);

	printf("o texto lido foi: %s %s %d\n", lido, lido_2, numero);

	fclose(comida);

	return 0;
}