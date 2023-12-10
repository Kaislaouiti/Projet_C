#include "struct.h"
#include <stdlib.h>
// Created by kaisl on 11/11/2023.
//
p_d_cell create_cell(int val , int niveau){
    p_d_cell cellule = (p_d_cell)malloc(sizeof(t_d_cell));
    cellule->value=val;
    cellule->level=niveau;
    cellule->next = (p_d_cell *)calloc(15, sizeof(p_d_cell));


    return cellule;
}