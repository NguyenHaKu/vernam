/* 
			Codage du message 
	On ecrit un programme qui à partir d'un fichier message et 
	d'un fichier clé produira un fichier message_code
*/
	
/* 
	1. La méthode la plus simple les noms de fichiers sont connus
	2. On demande le nom des fichiers à l'utilisateur
	3. Les noms de fichiers sont passés en paramètres sur le ligne de commande
*/


#include <stdio.h>
#include <stdlib.h>
#include "codage.h"

void codage() {
	FILE *f_m, *f_k, *f_mc; /* strcutures permettant, une fois FOPEN 
	exécuté de recupérer des informations pour manipuler les fichiers
	en C */
	
	int c;
	int k1;
	int calcul;
	
	char * cheminFic_m = "message.txt";
	f_m = fopen(cheminFic_m, "r");
	/* Traitement erreur */
	char * cheminFic_k = "cle.txt";
	f_k = fopen(cheminFic_k, "r");
	/* Traitement erreur */
	char * cheminFic_mc = "message_c.txt";
	f_mc = fopen(cheminFic_mc, "w");
	/* Traitement erreur */
	
	
	while ((c = fgetc(f_m)) != EOF)
		
	{
		k1 = fgetc(f_k);
		calcul = (c+k1) % 256;
		fputc(calcul, f_mc);
	}
	
	
	fclose(f_m);
	fclose(f_k);
	fclose(f_mc);
	
}

void decodage() {
	FILE *f_m, *f_k, *f_mdc; /* strcutures permettant, une fois FOPEN 
	exécuté de recupérer des informations pour manipuler les fichiers
	en C */
	
	int c;
	int k1;
	int calcul;
	
	char * cheminFic_m = "message_c.txt";
	f_m = fopen(cheminFic_m, "r");
		/* Traitement erreur */
	 char * cheminFic_k = "cle.txt";
	f_k = fopen(cheminFic_k, "r");

	/* Traitement erreur */
	char * cheminFic_mdc = "message_dc.txt";
	f_mdc = fopen(cheminFic_mdc, "w");
		/* Traitement erreur */
	
	while ((c = fgetc(f_m)) != EOF)
		
	{
		k1 = fgetc(f_k);
		calcul = c-k1 >= 0?c-k1:256-(c-k1);
		fputc(calcul, f_mdc);
	}
	
	
	fclose(f_m);
	fclose(f_k);
	fclose(f_mdc);
	
}