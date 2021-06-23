#ifndef P_SYSTEME_H_INCLUDED
#define P_SYSTEME_H_INCLUDED

#include "p_matrice.h"

typedef struct s_systeme{
    t_matrice les_coefficients;
    t_indice* les_inconnus; /* contiendra des informations sur les pivots réalisés */
}t_systeme;



void nouveau_systeme(t_systeme* ceci, int nb_equations, int nb_inconnus);

void remplir_systeme(t_systeme* ceci, t_matrice*cela, t_coefficient solution[]);

void detruire_systeme(t_systeme* ceci);

void afficher_systeme(t_systeme ceci);

int charger_systeme(t_systeme* ceci, char* nom_fichier);

int sauver_systeme(t_systeme ceci, char* nom_fichier);

void multiplier_ligne_systeme(t_systeme* ceci, t_indice num_equation, t_coefficient coeff);

void ajouter_multiple_systeme(t_systeme* ceci, t_indice equation_multiple, t_indice num_equation, t_coefficient coeff);

void echanger_lignes_systeme(t_systeme* ceci, t_indice num_equation_1, t_indice num_equation_2);

int * trouver_pivot(t_systeme* ceci, t_indice colonne_pivot, t_indice ligne_pivot);

void resoudre_pivot(t_systeme* ceci);

#endif