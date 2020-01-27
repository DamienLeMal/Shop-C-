#include <stdio.h>
#include <string.h>

struct Item {
	int id;
	int prix;
	int qqte_inventaire;
	char nom[10];
};
typedef struct Item item;

void addItem(item * varItem){
	
}

void display_inventory(item * varItem){
	scanf(item )
	//afficher nom
	//afficher qtté
}

void display_shop(item * varItem){
	
	//afficher [x]
	printf("[%d] ", (*varItem).id);
	//afficher nom
	printf("%s ---", (*varItem).nom);
	//afficher prix
	printf(" %d £\n", (*varItem).prix);

}

int main(){
	int exit = 0;
	int choix = 0;
	//definition des structures de bases
	item chocolat = {1,10,0,{'C','h','o','c','o','l','a','t'}};


	while (exit == 0){
		printf("Menu :\n[1] Inventaire \n[2] Magasin \n[3] Nouvel Item dans le magasin ! \n[4] Quitter");
		scanf("%d",&choix);
		switch (choix){
			case 1:
				printf("%s\n",chocolat.nom);
				break;
			case 2:
				printf("___________________________\n          Magasin          \n___________________________\n");
				display_shop(chocolat.id, &chocolat);
				break;
			case 3:
				break;
			case 4:
				exit = 1;
				break;
			default :
				printf("...\nJe vous ai proposé 4 options, alors POURQUOI vous en choisissez une autre ??? Vous vous croyez malin ?? Parceque vous ne l'êtes PAS !");
				break;
		}
	}
}