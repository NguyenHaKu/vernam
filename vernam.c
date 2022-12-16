#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "codage.c"

// Prototype de fonction
char* generate_random_key(const char* message);
void remplacer_contenu(const char* chemin_fic, const char* contenu);

int main(int argc, char* argv[])
{
    char* key = generate_random_key("message.txt");
    remplacer_contenu("cle.txt", key);

    // Initialiser le générateur de nombres aléatoires en utilisant l'heure courante
    srand(time(NULL));
    if (strcmp(argv[1],"-c")==0) {
        codage();
    }

    else if (strcmp(argv[1],"-d")==0) {
        decodage();
    }
    else if (strcmp(argv[1],"-k")==0) {
        char* key = generate_random_key("message.txt");
        remplacer_contenu("cle.txt", key);
    }
    // Générer une clé aléatoire pour le message "hello world"

    // Libérer la mémoire allouée pour la clé
    free(key);

    return 0;
}

// Fonction qui génère une clé Vernam aléatoire
char* generate_random_key(const char* message)
{
    // Créer une liste de tous les caractères possibles que la clé peut contenir
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // Récupérer la longueur du message
    int message_length = strlen(message);

    // Allouer de la mémoire pour la clé
    char* key = (char*) malloc(message_length + 1);

    // Parcourir le message et générer un caractère aléatoire pour chaque caractère du message
    for (int i = 0; i < message_length; i++)
    {
        key[i] = characters[rand() % (sizeof(characters) - 1)];
    }

    // Ajouter un caractère de fin de chaîne à la fin de la chaîne
    key[message_length] = '\0';

    // Renvoyer la clé générée
    return key;
}

void remplacer_contenu(const char* chemin_fic, const char* contenu) {
  FILE* f = fopen(chemin_fic, "w");
  fprintf(f, "%s", contenu);
  fclose(f);
}
