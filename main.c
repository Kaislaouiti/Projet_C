#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fichier.h"
#include "timer.h"
#include <time.h>

int main() {

    p_d_list my_list = create_list(5);

    p_d_cell cell1 = create_cell(10, 2);
    p_d_cell cell2 = create_cell(20, 2);

    p_d_cell cell4 = create_cell(15, 3);

    // Insérez les cellules dans la liste
    insert_cell_croissant(cell1, my_list);

    insert_cell_croissant(cell2, my_list);
    insert_cell_croissant(cell4, my_list);



    t_rdv rdv1 = create_rdv(2023, 11, 29, 10, 30, 1, 30, "Réunion");
    t_rdv rdv2 = create_rdv(2023, 11, 30, 14, 0, 2, 0, "Présentation");

    t_rdv rdv_array[] = {rdv1, rdv2};


    t_contact new_contact = create_contact("benoit", "kouria");
    t_contact new_contact2 = create_contact("kais", "laouiti");
    t_contact new_contact3 = create_contact("tristan", "aouiti");
    t_contact new_contact4 = create_contact("cristan", "loral");
    t_contact new_contact5 = create_contact("czer", "looral");
    t_contact new_contact6 = create_contact("czar", "loreal");
    t_contact new_contact9 = create_contact("tralois", "lin");
    t_contact new_contact10 = create_contact("czaa", "lina");
    t_contact new_contact11 = create_contact("danois", "louiti");
    t_contact new_contact12 = create_contact("dana", "valui");







    t_rdv rdv_array2[20];

    p_entre_agenda new_entry = create_entre_agenda(new_contact, rdv_array2, 0);
    p_entre_agenda new_entry2 = create_entre_agenda(new_contact2, rdv_array2, 0);
    p_entre_agenda new_entry3 = create_entre_agenda(new_contact3, rdv_array2, 0);
    p_entre_agenda new_entry4 = create_entre_agenda(new_contact4,rdv_array2,0);
    p_entre_agenda new_entry5 = create_entre_agenda(new_contact5,rdv_array2,0);
    p_entre_agenda new_entry6 = create_entre_agenda(new_contact6,rdv_array2,0);
    p_entre_agenda new_entry9 = create_entre_agenda(new_contact9,rdv_array2,0);
    p_entre_agenda new_entry10 = create_entre_agenda(new_contact10,rdv_array2,0);
    p_entre_agenda new_entry11 = create_entre_agenda(new_contact11,rdv_array2,0);
    p_entre_agenda new_entry12 = create_entre_agenda(new_contact12,rdv_array2,0);








    p_agenda agenda = create_agenda();
    p_agenda agenda2 = create_agenda();

    insert_rdv(new_entry,agenda);
    display_agenda(*agenda);

    insert_rdv(new_entry2,agenda);

    insert_rdv(new_entry3,agenda);


    insert_rdv(new_entry4,agenda);

    insert_rdv(new_entry5,agenda);

    insert_rdv(new_entry6,agenda);

    insert_rdv(new_entry9,agenda);
    insert_rdv(new_entry10,agenda);
    insert_rdv(new_entry11,agenda);
    insert_rdv(new_entry12,agenda);
    srand((unsigned int)time(NULL));  // Initialisation de la graine

    FILE *file = fopen("noms.txt", "r");


    t_contact names[120000];
    int num_names;

    // Utilisez read_names_from_file pour remplir le tableau de noms
    read_names_from_file(file, names, &num_names);


    // Utilisez generate_random_name pour obtenir un nom aléatoire
    for (int i = 0; i < 1000; ++i) {

        t_contact new_contact = generate_random_name(names, num_names);
        // Vous pouvez ajuster la taille si nécessaire

        p_entre_agenda new_entry = create_entre_agenda(new_contact, rdv_array2, 0);
        insert_rdv(new_entry, agenda2);

        // Utilisez new_contact comme nécessaire...
    }




    fclose(file);


    int choix;
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Partie 1 et 2\n");
        printf("2. Partie 3\n");
        printf("0. Quitter\n");
        printf("Choisir une option: ");
        scanf("%d", &choice);

        switch (choice) {


            case 1:
                // Traitement pour l'option 2
                printf("Option 1\n");
                while (1) {
                    int choix2;
                    do {
                        printf("Option 1 :creer une liste et effectuer des operations dessus\n");
                        printf("Option 2 Analysez la complexiter des listes n\n");
                        printf("Option 0 : Retour\n");
                    scanf("%d",&choix2);} while (choix2>2);
                if (choix2==1){int listChoice;
                printf("1. Cree une liste normal\n");
                printf("2. Create une liste N\n");
                printf("0. Retour au menu\n");
                scanf("%d", &listChoice);

                if (listChoice == 0) {
                    break; // Retour au menu principal
                }

                p_d_list mylist;

                if (listChoice == 1) {
                    mylist = create_list(5);
                    int ajouter_maillon;
                    do {printf("1 Ajouter un maillon\n");
                        printf("0. Suivant\n");
                        scanf("%d", &ajouter_maillon);
                        if (ajouter_maillon==1){
                            printf("valeur du maillon :");
                            int valeur,niveau;
                            printf("donnez la valeur");
                            scanf("%d", &valeur);
                            do {
                            printf("donnez le niveau");
                            scanf("%d", &niveau);} while (niveau>5||niveau<=0);
                            p_d_cell maillon= create_cell(valeur,niveau);
                            insert_cell_croissant(maillon,mylist);





                        }



                    }while(ajouter_maillon!=0);
                } else if (listChoice == 2) {
                    int n;
                    printf("Entrez la valeur de n: ");
                    scanf("%d", &n);
                    mylist = create_liste_n(n);
                } else {
                    printf("Choix invalide.\n");
                    return 1;
                }

                int displayChoice;
                printf("1. Affichage normal\n");
                printf("2. Affichage aligne\n");
                printf("0. Retour au menu principal\n");
                scanf("%d", &displayChoice);

                if (displayChoice == 1) {
                    display_list(mylist);
                }
                if (displayChoice==2){
                    display_list_aligne(mylist);
                }}
                if (choix2==2) {
                    for (int j=8;j<=13;j++){
                    p_d_list liste= create_liste_n(j);
                    // Testez l'affichage de la liste complète
                    printf("On a une liste n avec n=%d",j);
                    startTimer();

                    for (int i = 1; i < 10000; ++i) {
                        recherche_classique(liste, i);
                    }

                    stopTimer();
                    displayTime();

                    displayTime();

                    printf("recherche_classique pour 10000 recherches: %s\n", getTimeAsString());
                    startTimer();
                    for (int i = 1; i < 10000; ++i) {
                        search_top(liste,239);
                    }

                    stopTimer();
                    printf("recherche_dico Pour 10000 recherches: %s\n", getTimeAsString());
                    startTimer();

                    for (int i = 1; i < 100000; ++i) {
                        recherche_classique(liste, i);
                    }

                    stopTimer();
                    displayTime();

                    displayTime();

                    printf("recherche_classique pour 100000 recherches: %s\n", getTimeAsString());
                    startTimer();
                    for (int i = 1; i < 100000; ++i) {
                        search_top(liste,239);
                    }

                    stopTimer();
                    printf("recherche_dico Pour 100000 recherches: %s\n", getTimeAsString());

                }}



                if (choix2==0){

                break;}}

            case 2:
                printf("");
                int choix1;
                p_agenda nv_agenda;
                do {
                    printf("\nOptions disponibles:\n");
                    printf("1. Utiliser petit agenda(10 contacts) pour mieux visualiser\n");
                    printf("2. Utiliser gros agenda (1000 contacts)\n");
                    printf("0. Quitter\n");

                    printf("Choisissez une option : ");
                    scanf("%d", &choix1);}while(choix1>2);
                if(choix1==1){ nv_agenda=agenda;}if(choix1==2){ nv_agenda=agenda2;}
                int choix;
                do {
                    printf("\nOptions disponibles:\n");
                    printf("1. Rechercher un client de avec une insertion du plus gros element et affiche le temps prix\n");
                    printf("2. Creer un client et l'inserer et afficher le temps pris\n");
                    printf("0. Quitter\n");

                    printf("Choisissez une option : ");
                    scanf("%d", &choix);
                    p_entre_agenda p_entre;
                            if (choix==1){
                            printf("Option 1 : Rechercher un client\n");
                                startTimer();
                             p_entre= recherche_contact_sommet(*nv_agenda);
                                stopTimer();
                                displayTime();
                             if (p_entre==NULL){
                                 printf("Nom cherche non présent\n");
                                 do {printf("Voulez vous cree ce contact?\n1) Oui \n2) Non"); scanf("%d",&choix);
                                 }while(choix!=2&&choix!=1);
                             if (choix==1){printf("Entrez le prenom du contact : ");
                                char prenom[50];
                                scanf("%s", prenom);

                                printf("Entrez le nom du contact : ");
                                char nom[50];
                                scanf("%s", nom);
                                t_contact contact;
                                contact = create_contact(prenom, nom);
                                t_rdv tab_rdv[20];
                                p_entre = create_entre_agenda(contact, NULL, 0);
                                    insert_rdv(p_entre,nv_agenda);
                            }else{break;}
                             }
                              }

                      if (choix==2){
                            printf("Entrez le prenom du contact : ");
                            char prenom[50];
                            scanf("%s", prenom);

                            printf("Entrez le nom du contact : ");
                            char nom[50];
                            scanf("%s", nom);
                            t_contact contact;
                            contact = create_contact(prenom, nom);
                            t_rdv tab_rdv[20];
                            p_entre = create_entre_agenda(contact, NULL, 0);
                            startTimer();
                          insert_rdv(p_entre,nv_agenda);
                          stopTimer();
                          displayTime();
                      }





                      if (choix==0){
                            printf("Au revoir !\n");
                            break;}

                                   if (choix==1||choix==2){

                     int choixx;
                    do {
                        printf("\nMenu :\n");
                        printf("1. Afficher les rendez-vous du contact\n %s %s",p_entre->contact.nom,p_entre->contact.prenom);
                        printf("2. Creer un rendez-vous pour le contact\n");
                        printf("3. Supprimer un rendez-vous\n");
                        printf("4. Afficher agenda\n");
                        printf("0. Quitter\n");

                        printf("Choix : ");
                        scanf("%d", &choixx);

                        switch (choixx) {
                            case 1: display_client_rdv(*p_entre);
                            break;
                            case 2: entrer_rdv(p_entre);
                            break;


                            case 3:
                                supprimer_rdv(p_entre);
                                break;
                            case 4:
                                display_agenda(*nv_agenda);
                                break;

                            case 0:
                                printf("Au revoir!\n");
                                break;
                            default:
                                printf("Choix invalide. Veuillez entrer un nombre entre 0 et 8.\n");
                        }

                    } while (choixx != 0);}

                } while (choix != 0);



            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 0);


    return 0;
}

