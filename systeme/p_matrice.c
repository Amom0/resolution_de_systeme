#include <stdio.h>
#include <stdlib.h>
#include "p_matrice.h"

void nouvelle_matrice(t_matrice* ceci, int nb_lignes, int nb_colonnes){
    ceci->le_nb_lignes = nb_lignes;
    ceci->le_nb_colonnes = nb_colonnes;
    ceci->les_valeurs = (t_coefficient**)malloc(sizeof(t_coefficient*)*nb_lignes);
     for(t_indice i=0;i<nb_lignes;i++){
        ceci->les_valeurs[i] = (t_coefficient*)malloc(nb_colonnes * sizeof(t_coefficient));
    }
}

int detruire_matrice(t_matrice* ceci){
    if(ceci->les_valeurs ==NULL){
        return 0;
    }
    for(t_indice n = 0;n <ceci->le_nb_lignes;n++){
        free(ceci->les_valeurs[n]);
    }
    free(ceci->les_valeurs);
    ceci->les_valeurs = NULL;
    return 1;
}

void afficher_matrice(t_matrice ceci){
    printf("-----------\n");
    for(t_indice i=0; i < ceci.le_nb_lignes; i++){
        printf("[");
        for(t_indice j=0; j < ceci.le_nb_colonnes; j++){
            printf("%f ",ceci.les_valeurs[i][j]);
        }
        printf("]\n");
    }
    printf("-----------\n");
}

void remplir_matrice(t_matrice* ceci, t_indice num_ligne, t_indice num_colonne, t_coefficient valeur){
    ceci->les_valeurs[num_ligne][num_colonne] = valeur;
}

int produit_matrice(t_matrice ceci, t_matrice cela, t_matrice dans){
    nouvelle_matrice(&dans, ceci.le_nb_lignes,cela.le_nb_colonnes);
    if(ceci.le_nb_colonnes != cela.le_nb_lignes){
        return 0;
    }
    for (int i=0;i<ceci.le_nb_lignes;i++)
    {
        for (int j=0;j<cela.le_nb_colonnes;j++)
        {
            for (int k=0;k<ceci.le_nb_colonnes;k++)
            {
                dans.les_valeurs[i][j]=ceci.les_valeurs[i][k]*cela.les_valeurs[k][j];
            }
        }
    }
    afficher_matrice(dans);
    return 1;
}

void ecrire_matrice(t_matrice ceci, FILE* fichier){
    fprintf(fichier, "%d %d\n", ceci.le_nb_lignes, ceci.le_nb_colonnes);
    for(int i = 0; i<ceci.le_nb_lignes; i++){
        for(int j =0; j < ceci.le_nb_colonnes; j++){
            fprintf(fichier, "%f ", ceci.les_valeurs[i][j]);
        }
    }
}

int sauver_matrice(t_matrice ceci, char* nom_fichier){
    FILE* mon_fichier;
    mon_fichier = fopen(nom_fichier, "w");
    ecrire_matrice(ceci, mon_fichier);
    fflush(mon_fichier);
    fclose(mon_fichier);
}

void lire_matrice(t_matrice* ceci, FILE* fichier){
    int mon_nb_lignes, mon_nb_colonnes;
    t_coefficient mon_coefficient;
    fscanf(fichier, "%d", &mon_nb_lignes);
    fscanf(fichier, "%d", &mon_nb_colonnes);
    nouvelle_matrice(ceci, mon_nb_lignes, mon_nb_colonnes);
    for(int i = 0; i<ceci->le_nb_lignes; i++){
        for(int j =0; j < ceci->le_nb_colonnes; j++){
            fscanf(fichier, "%f", &mon_coefficient);
            remplir_matrice(ceci, i, j, mon_coefficient);
        }
    }
}

int charger_matrice(t_matrice* ceci, char* nom_fichier){
    FILE* mon_fichier;
    mon_fichier = fopen(nom_fichier, "r");
    lire_matrice(ceci, mon_fichier);
    fclose(mon_fichier);
}