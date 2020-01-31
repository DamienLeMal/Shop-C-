#include <stdio.h>
#include <string.h>

int compteur = 3;

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
	char holder_c[99];
	result = strncmp((*varItem).nom,(*varItem2).nom,20);
	if (result > 0){

        holder = (*varItem).prix;
        (*varItem).prix = (*varItem2).prix;
        (*varItem2).prix = holder;

        holder = (*varItem).qqte_inventaire;
        (*varItem).qqte_inventaire = (*varItem2).qqte_inventaire;
        (*varItem2).qqte_inventaire = holder;

        strcpy(holder_c,(*varItem).nom);
        strcpy((*varItem).nom,(*varItem2).nom);
        strcpy((*varItem2).nom,holder_c);
        return 0;
    } else {
        return 1;
    }
}

void addItem(item * varItem){
	int test = 0;
	char name[99];
	int price = 0;
	printf("___________________________\n        Nouvel Item        \n___________________________\n");
	printf("Choisissez un nom : ");
	scanf("%s",name);
    printf("\n");
	strcpy(varItem->nom,name);
    printf("Choisissez un prix : ");
	scanf("%d",&price);
    printf("\n");
	varItem->prix = price;
	compteur += 1;
	varItem->id = compteur;
}

void display_inventory(item * varItem){
	//afficher nom
	printf("%s ---", (*varItem).nom);
	//afficher qqte
	printf(" %d \n", (*varItem).qqte_inventaire);
	
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
	int coin = 100;
	int profit = 0;
	//definition des structures de bases
	item article[99];
	article[0].id = 1;
	article[0].prix = 10;
	article[0].qqte_inventaire = 1;
	strcpy(article[0].nom,"Banane");

	article[1].id = 2;
	article[1].prix = 20;
	article[1].qqte_inventaire = 0;
	strcpy(article[1].nom,"Chocolat");

	article[2].id = 3;
	article[2].prix = 20;
	article[2].qqte_inventaire = 0;
	strcpy(article[2].nom,"Milkshake");

	while (exit == 0){
		printf("___________________________\n           Menu           \n___________________________\nBourse : %d£\n[1] Inventaire \n[2] Magasin \n[3] Nouvel Item dans le magasin ! \n[4] Quitter\n",coin);
		scanf("%d",&choix);
		switch (choix){
			case 1:
				choix = 0;
				printf("___________________________\n        Inventaire         \n___________________________\nBourse : %d£\n",coin);
				//boucle display
				for (int i = 0; i < compteur; ++i){
					if (article[i].qqte_inventaire != 0){
						display_inventory(&article[i]);
					}
				}
				printf("[1] Quitter l'Inventaire\n");
				scanf("%d",&test);
				break;
			case 2:
				choix = 0;
        		int choix_shop = 0;
				printf("___________________________\n          Magasin          \n___________________________\nBourse : %d£\n",coin);

				test = 0;
				while (test == 0){
					test = 0;
					for (int i = 0; i < compteur-1; ++i){
						test += sort(&article[i],&article[i+1]);

					}
				}
				//boucle display
				printf("[0] Quitter le Magasin\n");
				for (int i = 0; i < compteur; ++i){
					display_shop(&article[i]);
				}
				//achat
				test = 0;
				while (test == 0){
					scanf("%d",&choix_shop);
					if ((choix_shop <= compteur)&&(choix_shop != 0)){
						article[choix_shop-1].qqte_inventaire += 1;
						coin -= article[choix_shop-1].prix;
						printf("Vous avez achete : %s\nBourse : %d£\n",article[choix_shop-1].nom,coin);
					}else if (choix_shop == 0){
							test =1;
					}
				}
				break;
			case 3:
				choix = 0;
				addItem(&article[compteur]);
				profit = article[compteur-1].prix * 3;
				coin += profit;
				printf("Vous gagnez %d£ grace a la vente de votre \" %s \" \n",profit,article[compteur-1].nom);
				break;
			case 4:
				exit = 1;
				break;
			default :
				choix = 0;
				printf("...\nJe vous ai proposé 4 options, alors POURQUOI vous en choisissez une autre ??? Vous vous croyez malin ?? Parceque vous ne l'êtes PAS !\n");
				break;
		}
	}
}