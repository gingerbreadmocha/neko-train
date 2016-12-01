#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/* Usually use pointers for struct. */
typedef struct Neko{
	char *name;
	char *personality;
} Neko;

void printNeko(Neko *neko){
	printf("Neko name: %s \n Neko personality: %s \n",neko->name,neko->personality);
}


int main(){
	printf("Welcome to Neko Train! \n");
	Neko *Pumpkin; /*For typedef, you don't need to put struct in front of ur 'struct' anymore.*/
	
	/*Pumpkin's information */
	Pumpkin=malloc(sizeof(Neko));
	Pumpkin->name="Pumpkin";
	Pumpkin->personality="Spacey";

	printNeko(Pumpkin);

	return 0;
}
