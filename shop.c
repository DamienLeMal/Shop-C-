#include <stdio.h>
#include <string.h>

int compteur = 2;

struct Item {
	int id;
	int prix;
	int qqte_inventaire;
	char nom[99];
};
typedef struct Item item;


int sort(item * varItem,item * varItem2){
	int result = 0;
	int holder = 0;
	char holder_c[1][99];
	result = strncmp((*varItem).nom,(*varItem2).nom,20);
	if(result > 0) {
      printf("str1 > str2");

      holder = (*varItem).prix;
      (*varItem).prix = (*varItem2).prix;
      (*varItem2).prix = holder;

      holder = (*varItem).qqte_inventaire;
      (*varItem).qqte_inventaire = (*varItem2).qqte_inventaire;
      (*varItem2).qqte_inventaire = holder;

      strcpy(holder_c[1],(*varItem).nom);
      strcpy((*varItem).nom,(*varItem2).nom);
      strcpy((*varItem2).nom,holder_c[1]);

      return 0;
   } else {
      return 1;
   }
}

void addItem(item * varItem){

}

void display_inventory(){
	//afficher nom
	//afficher qtté
	for (int i = 0; i < compteur; ++i){
		/* code */
	}
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
	int test = 0;
	//definition des structures de bases
	item article[99];
	article[0].id = 1;
	article[0].prix = 10;
	article[0].qqte_inventaire = 0;
	strcpy(article[0].nom,"Chocolat");

	article[1].id = 2;
	article[1].prix = 20;
	article[1].qqte_inventaire = 0;
	strcpy(article[1].nom,"Banane");

	char prenom[99][99];

	strcpy(prenom[article[0].id],article[0].nom);
	strcpy(prenom[article[1].id],article[1].nom);
	while (exit == 0){
		printf("Menu :\n[1] Inventaire \n[2] Magasin \n[3] Nouvel Item dans le magasin ! \n[4] Quitter");
		scanf("%d",&choix);
		switch (choix){
			case 1:
				printf("%s\n",article[0].nom);
				break;
			case 2:
				//sorting
				test = 0;
				while (test == 0){
					test = 0;
					for (int i = 0; i < compteur-1; ++i){
				
						test += sort(&article[i],&article[i+1]);

					}
				}


				printf("___________________________\n          Magasin          \n___________________________\n");
				
				//boucle display
				for (int i = 0; i < compteur; ++i){
					display_shop(&article[i]);
				}

				//achat
				scanf("%d",&choix);
				if (choix <= compteur){
					printf("Vous avez achete : %s\n",prenom[choix]);
				}
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

