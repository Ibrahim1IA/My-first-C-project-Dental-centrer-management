#ifndef FONCTION_DU_CD_H_INCLUDED
#define FONCTION_DU_CD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 20
typedef struct _date
{
    int jour;
    int mois;
    int annee;
    int heure;
    int minute;
    int second;
} date;
typedef struct _FICHE_D_INFORMATION
{
    char civilite[50];
    char numero_de_dossier[25];
    char nom[25];
    char prenom[50];
    char profession[50];
    date dat;
    int cin;
    int tel;
    char adresse[100];
    char email[100];
    char ville[25];
    char commentaire[200];

}FICHE_D_INFORMATION;
typedef struct _CONSULTATION
{
   date dat;
   int dent;
   int i;
   char acte[100];
   float prix;
   char commentaire[200];
}CONSULTATION;
typedef struct _ORDONNANCE
{
    int i;
    date dat;
    char medicament[100];
    char posologie[200];
    char medecin[100];
}ORDONNANCE;
typedef struct _SITUATION_FINANCIERE
{
    date dat;
    float montant;
    char mode[20];
    int i;
}SITUATION_FINANCIERE;
typedef struct _RDV
{
    date dat;
    char motif[100];
    int i;
}RDV;
typedef struct _patient
{
    CONSULTATION consult[MAX];
    RDV rdv[MAX];
    ORDONNANCE ordo[MAX];
    //CERTIFICAT cert;
    SITUATION_FINANCIERE sitf[MAX];
    FICHE_D_INFORMATION fiche;
} patient;
typedef struct salle_attente
{
    char nom[50];
    char prenom[100];
    char motif[100];
    char ordre[10];
}salle_attente;

void nouvelle_consultation(FILE*F, char name[50], char num[25]);
void Afficher_consultation(FILE* F, char name[50],char num[25]);
void nouveau_RDV(FILE*F, char name[50], char num[25]);
void Afficher_RDV(FILE* F, char name[50],char num[25]);
void nouvelle_ordonance(FILE*F, char name[50], char num[25]);
void Afficher_ordonance(FILE* F, char name[50],char num[25]);
void nouveau_payement(FILE*F, char name[50], char num[25]);
void Afficher_payement(FILE* F, char name[50],char num[25]);
patient saisir();
void ajouter_patient(FILE* F, char name[50]);
void Afficher_patient(FILE* F, char name[50]);
void supprimer_un_patient(FILE*F, char name[50]);
void list_RDV(FILE* F, char name[50]);


#endif // FONCTION_DU_CD_H_INCLUDED
