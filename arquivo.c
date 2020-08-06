#include <stdio.h>

int main(){
	FILE *banana;
	
	if(fopen("Aleatorio.txt", "r")==NULL){
		banana=fopen("Aleatorio.txt", "w+");
		fclose(banana);
	}
	
	banana=fopen("Aleatorio.txt", "w+");

	char numero[10];

	scanf("%s", numero);

	fprintf(banana,"%s", numero); 

	fscanf(banana, "%s", numero);

	printf("%s\n", numero);

	fclose(banana);		


	return 0;
}