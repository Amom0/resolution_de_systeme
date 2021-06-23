#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "p_systeme.h"

void nouveau_systeme(t_systeme* ceci, int nb_equations, int nb_inconnus){
    nouvelle_matrice(&(ceci->les_coefficients), nb_equations, nb_inconnus+1);
    ceci->les_inconnus = (t_indice*) malloc(sizeof(t_indice)*nb_equations);
}

void afficher_systeme(t_systeme ceci){
    printf("\n---------------------------\n");
    for(t_indice i=0; i < ceci.les_coefficients.le_nb_lignes; i++){
        for(t_indice j=0; j < ceci.les_coefficients.le_nb_colonnes-1; j++){
            printf("%f ",ceci.les_coefficients.les_valeurs[i][j]);
        }
        printf("= %f ",ceci.les_coefficients.les_valeurs[i][ceci.les_coefficients.le_nb_colonnes-1]);
        printf("\n");
    }
    printf("---------------------------\n");
}

void detruire_systeme(t_systeme* ceci){
    free(ceci->les_inconnus);
    detruire_matrice(&(ceci->les_coefficients));
} 

void remplir_systeme(t_systeme* ceci, t_matrice* cela, t_coefficient solution[]){
    for(t_indice i=0; i < ceci->les_coefficients.le_nb_lignes; i++){
        for(t_indice j=0; j < ceci->les_coefficients.le_nb_colonnes-1; j++){
            ceci->les_coefficients.les_valeurs[i][j] = cela->les_valeurs[i][j];
        }
        ceci->les_coefficients.les_valeurs[i][ceci->les_coefficients.le_nb_colonnes-1] = solution[i];
    }
}

int charger_systeme(t_systeme* ceci, char* nom_fichier){
    charger_matrice(&ceci->les_coefficients,nom_fichier);
    t_indice I;
    FILE* mon_fichier;
    mon_fichier = fopen(nom_fichier, "r");
    fscanf(mon_fichier, "%d", &I);
    
    fclose(mon_fichier);
}

int sauver_systeme(t_systeme ceci, char* nom_fichier){
    sauver_matrice(ceci.les_coefficients,nom_fichier);
    FILE* mon_fichier;
    mon_fichier = fopen(nom_fichier, "a");
    fprintf(mon_fichier, "%d", ceci.les_inconnus);
    fclose(mon_fichier);
}

void multiplier_ligne_systeme(t_systeme* ceci, t_indice num_equation, t_coefficient coeff){
    for (t_indice n = 0; n < ceci->les_coefficients.le_nb_colonnes; n++){
        ceci->les_coefficients.les_valeurs[num_equation][n] *= coeff;
    }
}

void ajouter_multiple_systeme(t_systeme* ceci, t_indice equation_multiple, t_indice num_equation, t_coefficient coeff){
    for (t_indice i = 0; i < ceci->les_coefficients.le_nb_colonnes; i++){
        ceci->les_coefficients.les_valeurs[num_equation][i] += coeff * ceci->les_coefficients.les_valeurs[equation_multiple][i];
    }
}

void echanger_lignes_systeme(t_systeme* ceci, t_indice num_equation_1, t_indice num_equation_2){
    for (t_indice i = 0; i < ceci->les_coefficients.le_nb_colonnes; i++){
        t_coefficient tmp = ceci->les_coefficients.les_valeurs[num_equation_1][i];
        ceci->les_coefficients.les_valeurs[num_equation_1][i] = ceci->les_coefficients.les_valeurs[num_equation_2][i];
        ceci->les_coefficients.les_valeurs[num_equation_2][i] = tmp;
    }
}

t_indice * trouver_pivot(t_systeme* ceci, t_indice colonne_pivot, t_indice ligne_pivot){
    static t_indice r[2];
    for(t_indice j=colonne_pivot; j < ceci->les_coefficients.le_nb_colonnes-1; j++){
        for(t_indice i=ligne_pivot; i < ceci->les_coefficients.le_nb_lignes; i++){
            if (ceci->les_coefficients.les_valeurs[i][j] != 0.0){
                r[0] = i;
                r[1] = j;
                ceci->les_inconnus[colonne_pivot] = j;
                
                return r;
            }
        }
    }
}

void resoudre_pivot(t_systeme* ceci){
    printf("\n-----------DEBUT-----------\n");
    t_indice x = 0;
    t_indice nbr_pivot = 0;
    t_indice prblm = 0;
    for(t_indice i = 0; i <ceci->les_coefficients.le_nb_lignes;i++){
        t_indice *p;
        t_coefficient sum = 0;
        for(t_indice c = 0; c<ceci->les_coefficients.le_nb_colonnes-1;c++){
            sum += pow(ceci->les_coefficients.les_valeurs[i][c],2);
        }
        if(sum == 0 && ceci->les_coefficients.les_valeurs[i][ceci->les_coefficients.le_nb_colonnes-1] != 0){
            prblm = 1;
            i = ceci->les_coefficients.le_nb_lignes;
            break;
        }else if (sum == 0 && ceci->les_coefficients.les_valeurs[i][ceci->les_coefficients.le_nb_colonnes-1] == 0)
        {
            break;
        }
        p = trouver_pivot(ceci,x,x);
        nbr_pivot++;
        printf("| PIVOT : (%d, %d), de valeur %f\n",*(p+0),*(p+1),ceci->les_coefficients.les_valeurs[*(p+0)][*(p+1)]);
        if (*(p+0) != i){
            echanger_lignes_systeme(ceci, *(p+0), i);
            *(p+0) = i;
        }
        t_coefficient coeff = 1/ceci->les_coefficients.les_valeurs[*(p+0)][*(p+1)];
        printf("| Coeff ligne pivot : %f\n",coeff);
        multiplier_ligne_systeme(ceci, *(p+0), coeff);
        for(t_indice k = 0; k < ceci->les_coefficients.le_nb_lignes;k++){
            if(k != *(p+0)){
                if(ceci->les_coefficients.les_valeurs[k][*(p+1)] != 0.0){
                    t_coefficient formule = -(ceci->les_coefficients.les_valeurs[k][*(p+1)]/ceci->les_coefficients.les_valeurs[*(p+0)][*(p+1)]);
                    printf("| Coeff pour ligne %d : %f\n", k, formule);
                    for (t_indice j = x; j < ceci->les_coefficients.le_nb_colonnes; j++){
                        ceci->les_coefficients.les_valeurs[k][j] += formule * ceci->les_coefficients.les_valeurs[*(p+0)][j];
                    }
                }else{
                    printf("| Coeff pour ligne %d : 1.000000\n", k);
                }
            } 
        }
        x++;
    }
    
    
    printf("------------FIN------------\n");
    printf("\n---------RESULTATS---------\n");
    t_indice present = 0;
    if(prblm == 1){
        printf("|       IMPOSSIBLE !\n");
    }else{
        for(t_indice i =0;i<ceci->les_coefficients.le_nb_colonnes-1;i++){
            for(t_indice j=0;j<nbr_pivot;j++){
                if(i==ceci->les_inconnus[j]){
                    printf("| X%d = %f\n",i,ceci->les_coefficients.les_valeurs[i][ceci->les_coefficients.le_nb_colonnes-1]);
                    present = 1;
                    break;
                }
                else{
                    present = 0;
                }  
            }
            if(present == 0){
                printf("| X%d = 0.000000\n",i);
            }
        }
    }
    printf("---------------------------\n");
}