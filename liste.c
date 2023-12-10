#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
p_d_list create_list(int max_niveau){
    p_d_list list = (p_d_list)malloc(sizeof(t_d_list));
    list->max_levels=max_niveau;
    list->heads = (p_d_cell *)malloc(max_niveau * sizeof(p_d_cell));
    list->heads = (p_d_cell *)calloc(max_niveau, sizeof(p_d_cell));


    return list;
}
p_d_list create_liste_n(int n){
    p_d_list liste= create_list(n);
    p_d_cell temp = NULL;
    for (int i = 0; i < pow(2, n)-1; i++) {         // Etape 1 , on va crée la liste avec (2^n)-1 cellule avec les valeurs correspondantes qui seront alors toute de niveau 0

        p_d_cell cellule = create_cell(i + 1, 1);
        if (liste->heads[0] == NULL) {// Pour faire en sorte que la premiere sois la tete
            liste->heads[0] = cellule;

        } else {
            temp = liste->heads[0];// Puis que les autres se lient
            while (temp->next[0] != NULL) {
                temp = temp->next[0];
            }
            temp->next[0] = cellule;
        }}

    int niveau=1;
    for(int j=2;j<=pow(2,n-1);j=j*2){    // Ensuite on utilise les instructions presentent dans le document pour augmenter les niveaux qu"il faut , un sur 2 puis un sur 4 puis un sur 8 ect selon n

        temp=liste->heads[0];// On aura une variable temp qui va parcourir l'entierete du niveau 0 pour voir grace à la valeur si le niveau de chaque cellule doit etre augmenté ou pas
        p_d_cell temp2=NULL;// Et une autre variable temp qui va permettre de lier les maillons des autres niveaux
        while (temp!=NULL){
            if (temp->value%j==0){ //Si on doit rajouter des niveaux pour ce maillon
                temp->level++; //On incremente son niveau
                /*
                temp->next = (p_d_cell *)realloc(temp->next, temp->level * sizeof(p_d_cell));

                */

                if (liste->heads[niveau]==NULL){// Si il n'ya aucun maillot à ce niveau , alors on le mets en tete
                    liste->heads[niveau]=temp;
                    temp2=liste->heads[niveau];
                }
                else{
                    temp2->next[niveau]=temp;// Sinon on le relie
                    temp2=temp2->next[niveau];
                }
            }temp=temp->next[0];
        }
        niveau++;// On augmente le niveau ou on se trouve
    }
    return liste;
}
void display_niveau(p_d_list list, int niveau){
    p_d_cell temp = list->heads[niveau];


    if (temp==NULL){
        printf("[list head_%d [@-]--> NULL",niveau);
    }
    else{
        printf("[list head_%d [@-]-->",niveau);

        while (temp!=NULL){
            printf("[ %d|@-]-->",temp->value);
            temp=temp->next[niveau];
        }
        printf(" NULL");

    }}
void display_list(p_d_list list){
    for (int i=0;i<list->max_levels;i++){
        display_niveau(list,i);
        printf("\n");
    }
}

void display_list_aligne(p_d_list list){
    for (int i=0;i<list->max_levels;i++){
        p_d_cell temp = list->heads[0];
        printf("[list head_%d [@-]-->",i);
        while (temp!=NULL){
            if (temp->level<i+1){
                printf("---------->");
                temp=temp->next[0];
            }
            else{
                printf("[  %d|@-]-->",temp->value);
                temp=temp->next[0];}
        }
        printf("NULL\n");
    }

}
void insert_list(p_d_cell cellule , p_d_list list){
    if (cellule->level>list->max_levels){
        printf("impossible");
    }
   else {
        for (int i = 0; i < cellule->level; i++) {


            cellule->next[i] = list->heads[i];
            list->heads[i] = cellule;
}}}

void insert_cell_croissant(p_d_cell cellule , p_d_list list){
    if (cellule->level>list->max_levels){
        printf("impossible");
}
    else{
        for (int i = 0; i < cellule->level; i++){

            p_d_cell temp = list->heads[i];
        if (temp==NULL|| cellule->value <= temp->value){

                cellule->next[i] = list->heads[i];
                list->heads[i] = cellule;
        }
        else{

        while(temp->next[i] != NULL && temp->next[i]->value <= cellule->value){
            temp=temp->next[i];
        }
        if(temp->next[i]==NULL){
            temp->next[i]=cellule;
        }
        else{
            cellule->next[i]=temp->next[i];
            temp->next[i]=cellule;
        }

    }}}
}
int recherche_classique(p_d_list liste , int val){
    if (liste->heads[0]==NULL){
        return 0;
    }
    p_d_cell temp=liste->heads[0];
    while (temp!=NULL){
        if (temp->value==val){
            return 1;
        }
        temp=temp->next[0];
    }
    return 0;
}
int search_top(p_d_list list, int val)
{
int niveau=list->max_levels-1;
int TL=pow(2, list->max_levels)-1;
p_d_cell tmp = list->heads[niveau];
int gauche = 0;
int droite = TL-1;

while (gauche<=droite){
    if (tmp->value==val){
        return 1;
    }
    else {
        if(tmp->value<val){
            for (int j=niveau;j>-1;j--){
            list->heads[j]=tmp;
            }
            gauche=(gauche+droite)/2;
            tmp=tmp->next[--niveau] ;
            for (int j=niveau;j>-1;j--){
                list->heads[j]=list->heads[j]->next[j];}

        }
        else {droite=(droite+gauche)/2;
            droite = (gauche + droite) / 2;
            niveau--;
            tmp=list->heads[niveau] ;
        }}}

    return 0;
}