//
// Created by kaisl on 19/11/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Contact.h"


t_contact create_contact(const char *prenom, const char *nom) {
    t_contact new_contact;
    new_contact.nom = strdup(nom);       // Allocation pour la chaîne nom
    new_contact.prenom = strdup(prenom); // Allocation pour la chaîne prenom
    return new_contact;
}
t_rdv create_rdv(int jour, int mois, int annee, int heure, int minute, int dureeHeure, int dureeMinute, const char *objet) {
    t_rdv new_rdv;
    new_rdv.jour = jour;
    new_rdv.mois = mois;
    new_rdv.annee = annee;
    new_rdv.heure = heure;
    new_rdv.minute = minute;
    new_rdv.dureeHeure = dureeHeure;
    new_rdv.dureeMinute = dureeMinute;
    new_rdv.objet = strdup(objet);
    return new_rdv;
}
void print_rdv( t_rdv *rdv) {
    printf("Rendez-vous:\n");
    printf("Date: %02d/%02d/%d\n", rdv->jour, rdv->mois, rdv->annee);
    printf("Heure: %02d:%02d\n", rdv->heure, rdv->minute);
    printf("Durée: %02d:%02d\n", rdv->dureeHeure, rdv->dureeMinute);
    printf("Objet: %s\n", rdv->objet);
}

p_entre_agenda create_entre_agenda(t_contact contact, t_rdv *rdv, int nb_rdv) {
    p_entre_agenda entre = (p_entre_agenda)malloc(sizeof(entre_agenda));

    // Vérifier si l'allocation de mémoire a réussi


    // Initialiser les champs de la nouvelle entrée
    entre->contact = contact;
    entre->rdv = (t_rdv *)malloc(nb_rdv *sizeof(t_rdv));
    entre->nb_rdv = nb_rdv;
    entre->next = (p_entre_agenda *)calloc(4, sizeof(p_entre_agenda));
    for (int i = 0; i < nb_rdv; i++) {
        entre->rdv[i] = rdv[i];
    }




    entre->lvl=0;
    return entre;
}
p_agenda create_agenda(){
    p_agenda list = (p_agenda)malloc(sizeof(t_s_agenda));
    list->max_levels=4;
    list->heads = (p_entre_agenda *)malloc(4 * sizeof(p_entre_agenda));

    for(int i=0;i<4;i++){
        *(list->heads + i)=NULL;

    }
    return list;
}
void insert_rdv_niveau(p_entre_agenda entre,p_agenda liste,int niveau){
    if (liste->heads[niveau-1]==NULL){

            entre->next[niveau-1]=NULL;
            liste->heads[niveau-1] = entre;
        }
    else {

    }
}

void insert_rdv(p_entre_agenda entre,p_agenda liste){
    if (liste->heads[0]==NULL){
        for (int i = 0; i <= 3; i++) {
            entre->next[i]=NULL;
            liste->heads[i] = entre;
        }

    }
    else{
        p_entre_agenda temp1=liste->heads[0];
        p_entre_agenda temp2=liste->heads[0]->next[0];
        while (temp2!=NULL&&strcmp(temp2->contact.nom,entre->contact.nom)<0){
            temp1=temp2;
            temp2=temp2->next[0];
        }
        *(entre->next)=NULL;
        temp1->next[0]=entre;
        entre->next[0]=temp2;
        int elements_different=0;

        for(int j=0;j<3;j++){

            if (temp1->contact.nom[j]!=entre->contact.nom[j]){
                entre->lvl=4-j;
                for (int i=1;i<=3-elements_different;i++){


                    p_entre_agenda prec=liste->heads[i];
                    p_entre_agenda temp=liste->heads[i]->next[i];
                    while (temp!=NULL&&strcmp(temp->contact.nom,entre->contact.nom)<0){
                        prec=temp;
                        temp=temp->next[i];
                    }
                    prec->next[i]=entre;
                    entre->next[i]=temp;}
                break;
            }    elements_different++;}
        for(int j=0;j<=3;j++){

            if (entre->next[3-j]!=NULL){
                entre->next[3-j]->lvl--;

            if (entre->next[3-j]->contact.nom[j]==entre->contact.nom[j]){
                if (entre->next[3-j]->next[3-j]==NULL){
                    entre->next[3-j]=NULL;
                }
                else {entre->next[3-j]=entre->next[3-j]->next[3-j];}

            }else {break;}}

        }



}}
p_entre_agenda recherche_contact_simple(p_agenda agenda,const char *nom ){
    if (agenda->heads[0]==NULL){
        return NULL;
    }
    p_entre_agenda temp=agenda->heads[0];
    while (temp!=NULL){
        if (temp->contact.nom==nom){
            return temp;
        }
        temp=temp->next[0];
    }return NULL;
}
p_entre_agenda recherche_contact_sommet(t_s_agenda agenda ){
    char chaine[4]; // Un tableau de 4 caractères (3 pour les lettres et 1 pour le caractère nul '\0')
    p_entre_agenda temp=agenda.heads[3];
    for (int i=0;i<3;i++){
    printf("Entrez la lettre %d : \n",i+1);
    scanf(" %c", &chaine[i]);

    while (temp!=NULL&&temp->contact.nom[i]!=chaine[i]){
        temp=temp->next[3-i];
    }if (temp==NULL)
    {
        return NULL;}


    }
    p_entre_agenda tab[10];
    int indice=0;
    while (temp->contact.nom[2]==chaine[2]&&temp->contact.nom[1]==chaine[1]&&temp->contact.nom[0]==chaine[0]){
        printf("test");
        tab[indice]=temp;
        temp=temp->next[0];
        indice++;
    }
    int choix;
    do {
        printf("Indiquez votre choix :\n");
        printf("0 Aucun\n");

        for (int j=0;j<indice;j++){
            printf("%d) %s\n",j+1,tab[j]->contact.nom);
        }
        scanf("%d",&choix);
    } while( choix<0||choix>3);
    if (choix==0){
         return NULL;
    }else {
        display_client_rdv(*temp);
        return tab[choix-1];}

}

void display_client_rdv(entre_agenda entre){
    int nombre=entre.nb_rdv;
    if(nombre==0){printf("Aucun rendez vous");}
    else {
        for (int i = 0; i < nombre;i++) {
            printf("Rendez-vous %d:\n", i + 1);
            printf("Date: %02d/%02d/%d\n", entre.rdv[i].jour, entre.rdv[i].mois, entre.rdv[i].annee);
            printf("Heure: %02d:%02d\n", entre.rdv[i].heure, entre.rdv[i].minute);
            printf("Duree: %02d:%02d\n", entre.rdv[i].dureeHeure, entre.rdv[i].dureeMinute);
            printf("Objet: %s\n", entre.rdv[i].objet);
        }

    }

}
void display_agenda_niveau(t_s_agenda list, int niveau){
    p_entre_agenda temp = list.heads[niveau];


    if (temp==NULL){
        printf("[list head_%d [@-]--> NULL",niveau);
    }
    else{
        printf("[list head_%d [@-]-->",niveau);

        while (temp!=NULL){
            printf("[ %s|@-]-->",temp->contact.nom);
            temp=temp->next[niveau];
        }
        printf(" NULL");

    }}
void display_agenda(t_s_agenda list){
    for (int i=0;i<list.max_levels;i++){
        display_agenda_niveau(list,i);
        printf("\n");
    }
}
void entrer_rdv(p_entre_agenda p_entre){
    printf("\nEntrez les informations pour créer un rendez-vous :\n");

    printf("Jour : ");
    int jour, mois, annee, heure, minute, dureeHeure, dureeMinute;
    scanf("%d", &jour);

    printf("Mois : ");
    scanf("%d", &mois);

    printf("Année : ");
    scanf("%d", &annee);

    printf("Heure : ");
    scanf("%d", &heure);

    printf("Minute : ");
    scanf("%d", &minute);

    printf("Durée en heures : ");
    scanf("%d", &dureeHeure);

    printf("Durée en minutes : ");
    scanf("%d", &dureeMinute);

    printf("Objet du rendez-vous : ");
    char objet[100];
    scanf("%s", objet);

    t_rdv rdv = create_rdv(jour, mois, annee, heure, minute, dureeHeure, dureeMinute, objet);
    p_entre->rdv[p_entre->nb_rdv++]=rdv;

}void supprimer_rdv(p_entre_agenda p_entre) {
        display_client_rdv(*p_entre);
        printf("Notez le numero du rdv à enlever\n");
        int choix;

        do {
            printf("Choisissez le numéro du rdv à enlever (1-%d) : ", p_entre->nb_rdv);
            scanf("%d", &choix);
        } while (choix < 1 || choix > p_entre->nb_rdv);

        for (int i = choix - 1; i < p_entre->nb_rdv - 1; i++) {
            p_entre->rdv[i] = p_entre->rdv[i + 1];
        }

        p_entre->nb_rdv--;
        display_client_rdv(*p_entre);
    }
