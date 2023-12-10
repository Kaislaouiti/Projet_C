//
// Created by kaisl on 11/11/2023.
//

#ifndef UNTITLED_STRUCT_H
#define UNTITLED_STRUCT_H

#endif //UNTITLED_STRUCT_H
typedef struct s_d_cell {
    int value;
    struct s_d_cell **next; // Tableau dynamique pour stocker les pointeurs vers les niveaux
    int level; // Nombre de niveaux pour cette cellule
} t_d_cell,*p_d_cell;
typedef struct s_d_list
{
    p_d_cell *heads; // Tqblequ dynamique qui stock les tetes
    int max_levels;
} t_d_list,*p_d_list;

p_d_cell create_cell(int val , int niveau);
p_d_list create_list(int max_niveau);
void insert_list(p_d_cell cellule , p_d_list list);
void display_niveau(p_d_list list, int niveau);
void display_list(p_d_list list);
void display_list_aligne(p_d_list list);
void insert_cell_croissant(p_d_cell cellule , p_d_list list);
p_d_list create_liste_n(int );
int search_top(p_d_list , int );
int recherche_classique(p_d_list  , int);
