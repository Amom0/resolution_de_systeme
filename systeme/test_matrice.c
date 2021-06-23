#include <stdio.h>
#include "p_matrice.h"
#include "p_systeme.h"

int main(){
    t_matrice ma_matrice;
    t_matrice ma_matrice2, ma_matrice3;
    t_matrice mon_produit; 

    t_systeme mon_systeme;
    t_coefficient solution[3] = {1.0,2.0,3.0};
    
    

    nouvelle_matrice(&ma_matrice, 3, 2);
    //afficher_matrice(ma_matrice); 
    remplir_matrice(&ma_matrice, 0, 0, 1.0);
    remplir_matrice(&ma_matrice, 0, 1, 2.0);
    remplir_matrice(&ma_matrice, 1, 0, 3.0);
    remplir_matrice(&ma_matrice, 1, 1, 4.0);
    remplir_matrice(&ma_matrice, 2, 0, 5.0);
    remplir_matrice(&ma_matrice, 2, 1, 6.0);
    //afficher_matrice(ma_matrice);

    //printf("Produit de matrice\n");
    nouvelle_matrice(&ma_matrice2, 2, 2);
    remplir_matrice(&ma_matrice2, 0, 0, 1.0);
    remplir_matrice(&ma_matrice2, 0, 1, 2.0);
    remplir_matrice(&ma_matrice2, 1, 0, 3.0);
    remplir_matrice(&ma_matrice2, 1, 1, 4.0);
    //afficher_matrice(ma_matrice2);
    
    //produit_matrice(ma_matrice, ma_matrice2, mon_produit);
    //afficher_matrice(mon_produit);

    sauver_matrice(ma_matrice, "bla_bla.txt");
    t_matrice ma_matrice_3;
    charger_matrice(&ma_matrice_3, "bla_bla.txt");
    //afficher_matrice(ma_matrice_3);

    detruire_matrice(&ma_matrice_3);
    
//----------------------------------------------------------------------------------------------

    nouveau_systeme(&mon_systeme, 3,3);
    remplir_systeme(&mon_systeme, &ma_matrice, solution);
    afficher_systeme(mon_systeme);

    printf("\nSystème sauvegardé :\n");
    sauver_systeme(mon_systeme,"systeme_save.txt");
    t_systeme mon_systeme2,mon_systeme3;
    charger_systeme(&mon_systeme2, "systeme_save.txt");
    afficher_systeme(mon_systeme2);

    printf("\nMultiplication d'une ligne :\n");
    multiplier_ligne_systeme(&mon_systeme2, 1,2);
    afficher_systeme(mon_systeme2);

    printf("\nAjout ligne avec coeff :\n");
    ajouter_multiple_systeme(&mon_systeme2,0,1,-6);
    afficher_systeme(mon_systeme2);

    printf("\nEchange entre 2 lignes :\n");
    echanger_lignes_systeme(&mon_systeme2,0,1);
    afficher_systeme(mon_systeme2);
    
    
    printf("\nPivot de Gauss :\n");

    

    // Matrice test
    
    //Matrice 3x3
    // t_coefficient solution2[3] = {1.0,6.0,2.0};
    // nouvelle_matrice(&ma_matrice3, 3, 3);
    // remplir_matrice(&ma_matrice3, 0, 0, 1.0);
    // remplir_matrice(&ma_matrice3, 0, 1, -3.0);
    // remplir_matrice(&ma_matrice3, 0, 2, 3.0);
    // remplir_matrice(&ma_matrice3, 1, 0, -2.0);
    // remplir_matrice(&ma_matrice3, 1, 1, 0.0);
    // remplir_matrice(&ma_matrice3, 1, 2, 2.0);
    // remplir_matrice(&ma_matrice3, 2, 0, 1.0);
    // remplir_matrice(&ma_matrice3, 2, 1, -1.0);
    // remplir_matrice(&ma_matrice3, 2, 2, 4.0);
    // nouveau_systeme(&mon_systeme3, 3,3);

    //Matrice 4x4
    // t_coefficient solution2[4] = {0.0,-1.0,3.0,2.0};
    // nouvelle_matrice(&ma_matrice3, 4, 4);
    // remplir_matrice(&ma_matrice3, 0, 0, 0.0);
    // remplir_matrice(&ma_matrice3, 0, 1, 0.0);
    // remplir_matrice(&ma_matrice3, 0, 2, 3.0);
    // remplir_matrice(&ma_matrice3, 0, 3, 2.0);
    // remplir_matrice(&ma_matrice3, 1, 0, 1.0);
    // remplir_matrice(&ma_matrice3, 1, 1, 1.0);
    // remplir_matrice(&ma_matrice3, 1, 2, -1.0);
    // remplir_matrice(&ma_matrice3, 1, 3, -1.0);
    // remplir_matrice(&ma_matrice3, 2, 0, 1.0);
    // remplir_matrice(&ma_matrice3, 2, 1, 2.0);
    // remplir_matrice(&ma_matrice3, 2, 2, -2.0);
    // remplir_matrice(&ma_matrice3, 2, 3, -4.0);
    // remplir_matrice(&ma_matrice3, 3, 0, 0.0);
    // remplir_matrice(&ma_matrice3, 3, 1, 1.0);
    // remplir_matrice(&ma_matrice3, 3, 2, 2.0);
    // remplir_matrice(&ma_matrice3, 3, 3, -1.0);
    // nouveau_systeme(&mon_systeme3, 4,4);

    //Matrice 2x4
    t_coefficient solution2[2] = {1.0,6.0};
    nouvelle_matrice(&ma_matrice3, 2, 4);
    remplir_matrice(&ma_matrice3, 0, 0, 1.0);
    remplir_matrice(&ma_matrice3, 0, 1, 1.0);
    remplir_matrice(&ma_matrice3, 0, 2, -1.0);
    remplir_matrice(&ma_matrice3, 0, 3, -1.0);
    remplir_matrice(&ma_matrice3, 1, 0, 1.0);
    remplir_matrice(&ma_matrice3, 1, 1, 2.0);
    remplir_matrice(&ma_matrice3, 1, 2, -2.0);
    remplir_matrice(&ma_matrice3, 1, 3, 2.0);
    nouveau_systeme(&mon_systeme3, 2,4);
   
    remplir_systeme(&mon_systeme3, &ma_matrice3, solution2);
    afficher_systeme(mon_systeme3);
    resoudre_pivot(&mon_systeme3);
    afficher_systeme(mon_systeme3);


    return 0;
}