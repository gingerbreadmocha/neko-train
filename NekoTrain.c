#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/* Usually use pointers for struct. */
typedef struct Neko{
	char *name;
	char *personality;
} Neko;

typedef struct Node{
	Neko *neko;	
	struct Node *prev;
	struct Node *next;
} Node; 

Node *head;
Node *tail;
Node *current;

void printNeko(Neko *neko){
	printf("Neko name: %s \n Neko personality: %s \n",neko->name,neko->personality);
}

void printTrain(Node *head){
	Node *currentnode;
	currentnode=head;
	while(currentnode){
		printf("cabin= ");
		printNeko(currentnode->neko);
		currentnode=currentnode->next;
	}
}

void PushNeko(Neko *neko){
	Node *end;
	end=malloc(sizeof(Node));
	end->neko=neko;
	end->next=NULL;
	end->prev=tail;
	tail->next=end;
	tail=end;
}

void UnshiftNeko(Neko *neko){
	Node *begin;
	begin=malloc(sizeof(Node));
	begin->neko=neko;
	begin->prev=NULL;
	begin->next=head;
	head->prev=begin;
	head=begin;
}

void FSNeko(Node *node){ /*This switches with the node before it (current at 3, shift 2 with 3). */
	if(node==head){
		printf("Your train has exited the universe.");
		return;
	}		
	Node *pepe,*jojo,*momo;
	jojo=node->prev;
	pepe=jojo->prev;
	momo=node->next;

	node->next=jojo;
	node->prev=pepe;
	jojo->next=momo;
	jojo->prev=node;
	pepe->next=node;
	if(node==tail){
	tail=jojo;
	} 
	else momo->prev=jojo;
}

void NSNeko(Node *node){ /*This switches with the node after it (current at 3, shift 3 with 4. */
	if(node==tail){
		printf("Your train flew into space!");
		return;
	}
	Node *pepe,*jojo,*momo;
	jojo=node->next;
	pepe=node->prev;
	momo=jojo->next;
	
	pepe->next=jojo;
	jojo->next=node;
	jojo->prev=pepe;
	node->next=momo;
	if(node==head){
	head=jojo;
	}
	else node->prev=jojo;
}
	

int main(){
	printf("Welcome to Neko Train! \n");
	Neko *Pumpkin; /*For typedef, you don't need to put struct in front of ur 'struct' anymore.*/
	Neko *Lexy;
	Neko *Tubbs;
	Neko *Ginger;
	Neko *Pusheen;
	Neko *Snowball;
	
	printf("Your default nekos are: Pumpkin, Tubbs, Lexy, Snowball, Pusheen, and Ginger. \n");
	
	/*Pumpkin's information */
	Pumpkin=malloc(sizeof(Neko));
	Pumpkin->name="Pumpkin";
	Pumpkin->personality="Spacey";
	
	/*Lexy's information */
	Lexy=malloc(sizeof(Neko));
	Lexy->name="Lexy";
	Lexy->personality="expensive-tastes";

	/*Tubbs's information*/
	Tubbs=malloc(sizeof(Neko));
	Tubbs->name="Tubbs";
	Tubbs->personality="finicky feaster";

	/*Ginger's information*/
	Ginger=malloc(sizeof(Neko));
	Ginger->name="Ginger";
	Ginger->personality="bashful";

	/*Plusheen's information */
	Pusheen=malloc(sizeof(Neko));
	Pusheen->name="Pusheen";
	Pusheen->personality="lazy";

	/*Snowball's information */
	Snowball=malloc(sizeof(Neko));
	Snowball->name="Snowball";
	Snowball->personality="mellow";

	/*Conductor Cabin Kotetsujou of the Iron Fortress*/
	
	head=malloc(sizeof(Node));
	head->neko=Tubbs;

	/*Cabin of Kotetsujou*/
	Node *cabin1;
	cabin1=malloc(sizeof(Node));
	cabin1->neko=Lexy;
	cabin1->prev=head;
	head->next=cabin1;

	/*Cabin of Kotetsujou*/
	Node *cabin2;
	cabin2=malloc(sizeof(Node));
	cabin2->neko=Pumpkin;
	cabin2->prev=cabin1;
	cabin1->next=cabin2;
	tail=cabin2;

	PushNeko(Ginger);
	PushNeko(Pusheen);
	UnshiftNeko(Snowball);


	char command[1];
	current=head;

	printf("You are currently at the head of the train. What would you like to do? \n");
	while(1){
	printf("Here are your commands: 1.Go to the next Neko. \n 2.Go to previous Neko. \n 3.Switch places with the next Neko. \n 4.Switch places with the previous Neko. \n 5.Pet Neko. \n 6.Add new Neko to the end. \n 7.Print train. \n Enter command: ");
	scanf("%s",command);
	if(strncmp(command,"1",1)==0){
		if(current==tail){
			printf("You can't go any futher! \n");
		}
		else current=current->next;
	printf("Your are currently at: %s \n",current->neko->name);
	}
	if(strncmp(command,"2",1)==0){
		if(current==head){
			printf("There's nothing there! \n");
		}
		else current=current->prev; 
	printf("Your are currently at: %s \n",current->neko->name);
	}
	if(strncmp(command,"3",1)==0){
		NSNeko(current);
		printf("Your are currently at: %s \n",current->neko->name);
	}
	if(strncmp(command,"4",1)==0){
		FSNeko(current);
		printf("Your are currently at: %s \n",current->neko->name);
	}
	if(strncmp(command,"5",1)==0){
		printf("%s nuzzles your hand adoringly.\n", current->neko->name); 
	}
	if(strncmp(command,"6",1)==0){
		char *namae;
		namae=malloc(10*sizeof(char));
		char *quirk;
		quirk=malloc(20*sizeof(char));
		printf("What is your new Neko's name? \n");
		scanf("%s",namae);
		printf("What is your new Neko's personality? \n");
		scanf("%s",quirk);
		fgets(quirk,20,stdin);
		Neko *newneko;
		newneko=malloc(sizeof(Neko));
		newneko->name=namae;
		newneko->personality=quirk;
		printf("%s %s",newneko->name,newneko->personality);
		PushNeko(newneko);
	}
	if(strncmp(command,"7",1)==0){
		printTrain(head);
	}
	}	
	

	/*printTrain(head);

	NSNeko(tail->prev->prev);

	printTrain(head); */

	return 0;
}

/*git commit -m <--one line message*/
