#include "fichier.h"


void read_names_from_file(FILE *file, t_contact names[], int *num_names) {
    *num_names = 0;
    while (*num_names < 120000 && fscanf(file, "%ms %ms", &names[*num_names].nom, &names[*num_names].prenom) == 2) {
        // Affichez le nom et le prénom pour déboguer
        (*num_names)++;
    }
}
t_contact generate_random_name(t_contact names[], int num_names) {
    int random_index = rand() % num_names;
    return names[random_index];
}
