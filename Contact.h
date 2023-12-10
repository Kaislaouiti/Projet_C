//
// Created by kaisl on 19/11/2023.
//


#ifndef UNTITLED_CONTACT_H
#define UNTITLED_CONTACT_H

#endif //UNTITLED_CONTACT_H
typedef struct Contact {
    char *nom;     /**< Nom du contact. */
    char *prenom;  /**< Prénom du contact. */
}t_contact;
typedef struct RendezVous {
    // Date du rendez-vous
    int jour;
    int mois;
    int annee;

    // Heure du rendez-vous
    int heure;
    int minute;

    // Durée du rendez-vous
    int dureeHeure;
    int dureeMinute;

    // Objet du rendez-vous
    char *objet;
}t_rdv;
typedef struct entre_agenda{
    t_contact contact;
    t_rdv *rdv;
    int nb_rdv;
    int lvl ;
    struct entre_agenda ** next;
}entre_agenda,*p_entre_agenda;

typedef struct liste_agenda
{
    p_entre_agenda *heads; // Tqblequ dynamique qui stock les tetes
    int max_levels;
} t_s_agenda,*p_agenda;
void print_rdv( t_rdv *rdv);

t_contact create_contact(const char *, const char *) ;
t_rdv create_rdv(int , int , int , int , int , int , int , const char *) ;
p_entre_agenda create_entre_agenda(t_contact , t_rdv *, int ) ;
p_agenda create_agenda();
void insert_rdv_niveau(p_entre_agenda ,p_agenda ,int );
void insert_rdv(p_entre_agenda ,p_agenda );
void display_agenda_niveau(t_s_agenda , int );
void display_agenda(t_s_agenda );
void display_client_rdv(entre_agenda entre);
p_entre_agenda recherche_contact_sommet(t_s_agenda  );
void entrer_rdv(p_entre_agenda );
void supprimer_rdv(p_entre_agenda );







