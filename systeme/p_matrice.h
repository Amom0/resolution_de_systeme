#ifndef P_MATRICE_H_INCLUDED
#define P_MATRICE_H_INCLUDED

typedef float t_coefficient;
typedef int t_indice;

typedef struct s_matrice{
    int le_nb_lignes;
    int le_nb_colonnes;
    t_coefficient** les_valeurs;
}t_matrice;

void nouvelle_matrice(t_matrice* ceci, int nb_lignes, int nb_colonnes);
void afficher_matrice(t_matrice ceci);
void remplir_matrice(t_matrice* ceci, t_indice num_ligne, t_indice num_colonne, t_coefficient valeur);

/**
 * \brief cette fonction libére la mémoire réservée par la matrice.
 *
 * \param ceci : t_matrice* : le pointeur vers la matrice à libérer.
 * \return int : 1 si la matrice contenait des valeurs
 * \return int : 0 sinon (i.e. la destruction est impossible)
 */
int detruire_matrice(t_matrice* ceci);

/**
 * \brief cette fonction calcule le produit de matrice ceci.cela et place le résultat dans la matrice dans.
 *
 * \warning les dimensions des matrices doivent correspondre pour que le produit soit réalisé
 * \warning si les dimentions ne corresponde pas la fonction retourne 0 (false) et aucun calcul est réalisé.
 * \param ceci : t_matrice : la matrice de gauche.
 * \param cela : t_matrice : la matrice de droite.
 * \param dans : t_matrice : la matrice qui contiendra la résultat.
 * \return int : 0 aucun calcul n'est fait car les dimensions ne correspondent pas
 * \return int : 1 le produit a été réalisé.
 */
int produit_matrice(t_matrice ceci, t_matrice cela, t_matrice dans);

int charger_matrice(t_matrice* ceci, char* nom_fichier);

int sauver_matrice(t_matrice ceci, char* nom_fichier);


#endif // P_MATRICE_H_INCLUDED