#include <stdio.h>
#include <stdlib.h>
#include "fonction_du_CD.h"
int main()
{
    int choix0, choix1, choix2, choix3;
    char nom[50], num[25];
    FILE*F=NULL;
   printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tENTRER LE NOM DU FICHIER\n\t\t\t\t\t\tCHOIX : ");
   gets(nom);
    F=fopen(nom, "r");
    if(!F) { printf("ERREUR! FICHIER INEXISTANT"); fclose(F); }
    else
    {
    fclose(F);
     system("clear");

do{
    system("clear");
    printf("\t\t\t=============================================================\n\t\t\t|\t\t\t\t\t\t\t    |\n\t\t\t|           BIENVENUE DANS NOTRE CABINET DENTAIRE\t    |\n\t\t\t|\t\t\t\t\t\t\t    |\n\t\t\t=============================================================\n\n\n\t\t\t\t\t MENU\n\n\t\t\t\t\t 1.  PATIENT\n\n\t\t\t\t\t 2.  RENDEZ-VOUS\n\n\t\t\t\t\t 3.  Salle d'attente\n\n\t\t\t\t\t 4.  HISTORIQUE D'ACTIVITEE \n\n\t\t\t\t\t 0.  QUITTER \n\n\t\t\t\t\t\n\t\t\t\t\t     CHOIX: ");
    scanf("%d", &choix0);
    system("clear");
    switch(choix0)
    {
    case 1 :
        {
            while(choix1!=0){
            printf("\t\t\t=============================================================\n\t\t\t|\t\t\t\t\t\t\t    |\n\t\t\t|                    PATIENT                     \t    |\n\t\t\t|\t\t\t\t\t\t\t    |\n\t\t\t=============================================================\n\n\n\t\t\t\t\t");
            printf(" 1.  S'OCCUPER D'UN PATIENT\n\n\t\t\t\t\t 2.  AJOUTER UN NOUVEAU PATIENT\n\n\t\t\t\t\t 3.  SUPPRIMER UN PATIENT\n\n\t\t\t\t\t 4.  LISTE DES PATIENTS\n\n\t\t\t\t\t 0. Quitter\n\n\t\t\t\t\t      CHOIX: ");
            scanf("%d", &choix1);
            system("clear");
            printf("\n\n\t\t\t\t\t==========LISTE DES PATIENTS==========\n\n\n");

            switch(choix1)
            {
            case 1 :
                {
                    Afficher_patient(F, nom);
                    printf("\n\n\t\t\t INSERER LE NUMERO DE DOSSIER DU PATIENT A TRAITER : \n\n\t\t\t\t\t CHOIX :");
                    fgets(num, sizeof(num), stdin);
                    F=fopen(nom,"r");
                    if(!F) {
                    printf ("Erreur\n") ;
                    exit(-1) ;}
                    patient p;
                    while(fread(&p, sizeof(patient),1,F)==1)
                    {
                        if(strcmp(p.fiche.numero_de_dossier,num)==0)
                        {
                            fclose(F);
                            system("clear");
                            printf("\n\n\t\t\t\t\t 1.  BILAN DES ACTIVITEES DU PATIENT\n\n\t\t\t\t\t 2.  NOUVEAU CONSULTATION\n\n\t\t\t\t\t 3.  NOUVELLE RDV\n\n\t\t\t\t\t 4.  NOUVELLE ORDONNANCE\n\n\t\t\t\t\t 5.  NOUVEAU PAYEMENT\n\n\t\t\t\t\t 6.  FICHE D'INFORMATION DU PATIENT \n\n\t\t\t\t\t CHOIX :");
                            scanf("%d", &choix2);
                            system("clear");
                            printf("\n\n\t\t\t\t          ==========BILAN DES ACTIVITES DU PATIENT==========\n\n\n");
                            switch (choix2)

                            {
                            case 1 :
                                {
                                    printf("\n\n\t\t\t\t\t\t 1.  CONSULTATIONS\n\n\t\t\t\t\t\t 2.  RDV\n\n\t\t\t\t\t\t 3.  ORDONANCES\n\n\t\t\t\t\t\t 4.  SITUATION FINANCIERE\n\n\t\t\t\t\t\t CHOIX: ");
                                    scanf("%d", &choix3);
                                    system("clear");

                                    switch(choix3)
                                    {
                                        case 1 :
                                            {
                                                printf("\n\n\t\t\t\t\t   ==========LISTE DES CONSULTATIONS==========\n\n");
                                                Afficher_consultation(F, nom, num);break;
                                            }
                                        case 2 :
                                            {
                                                printf("\n\n\t\t\t\t\t   ==========LISTE DES RDV==========\n\n");
                                                Afficher_RDV(F, nom, num);break;
                                            }
                                        case 3 :
                                            {   printf("\n\n\t\t\t\t\t   ==========LISTE DES ORDONANCES==========\n\n");
                                                Afficher_ordonance(F, nom, num);break;
                                            }
                                        case 4 :
                                            {   printf("\n\n\t\t\t\t\t   ==========LISTE DES PAYEMENTS==========\n\n");
                                                Afficher_payement(F, nom, num);break;
                                            }
                                    }break;
                                }
                    case 2 :
                        {
                            nouvelle_consultation(F, nom, num);break;
                        }
                    case 3 :
                        {
                            nouveau_RDV(F, nom, num);break;
                        }
                    case 4 :
                        {
                            nouvelle_ordonance(F, nom, num);break;
                        }
                    case 5 :
                        {
                            nouveau_payement(F, nom, num);break;
                        }
                   /* case 6 :
                        {
                            information_du_patient();
                        }*/
                    }
                }}break;}
            case 2 :
                {
                    ajouter_patient(F, nom);break;
                }
            case 3 :
                {
                    supprimer_un_patient(F, nom);break;
                }
            case 4 :
                {
                    Afficher_patient(F, nom);break;
                }
        }break;}break;}
    case 2 :
        {
           printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t1. MES RDV\n\n\t\t\t\t\t\t2. HISTORIQUE DES RDV\n\n\t\t\t\t\t\tCHOIX : ");
            scanf("%d", &choix1);
            switch (choix1)
            {
            case 1 :
                {
                    system("clear");
                    list_RDV(F, nom);
                    printf("\n\n\n\n\t\t\t\t\t\t1. Traiter un patient\n\n\t\t\t\t\t\t2. ajouter un RDV\n\n\t\t\t\t\t\t3. supprimer um RDV\n\n\t\t\t\t\t\tCHOIX : ");
                    scanf("%d", &choix2);
                    switch(choix2)
                    {
                    case 1 :
                        {
                             printf("\n\n\t\t\t INSERER LE NUMERO DE DOSSIER DU PATIENT A TRAITER : \n\n\t\t\t\t\t CHOIX :");
                    fgets(num, sizeof(num), stdin);
                    F=fopen(nom,"r");
                    if(!F) {
                    printf ("Erreur\n") ;
                    exit(-1) ;}
                    patient p;
                    while(fread(&p, sizeof(patient),1,F)==1)
                    {
                        if(strcmp(p.fiche.numero_de_dossier,num)==0)
                        {
                            fclose(F);
                            system("clear");
                            printf("\n\n\t\t\t\t\t 1.  BILAN DES ACTIVITEES DU PATIENT\n\n\t\t\t\t\t 2.  NOUVEAU CONSULTATION\n\n\t\t\t\t\t 3.  NOUVELLE RDV\n\n\t\t\t\t\t 4.  NOUVELLE ORDONNANCE\n\n\t\t\t\t\t 5.  NOUVEAU PAYEMENT\n\n\t\t\t\t\t 6.  FICHE D'INFORMATION DU PATIENT \n\n\t\t\t\t\t CHOIX :");
                            scanf("%d", &choix2);
                            system("clear");
                            printf("\n\n\t\t\t\t          ==========BILAN DES ACTIVITES DU PATIENT==========\n\n\n");
                            switch (choix2)

                            {
                            case 1 :
                                {
                                    printf("\n\n\t\t\t\t\t\t 1.  CONSULTATIONS\n\n\t\t\t\t\t\t 2.  RDV\n\n\t\t\t\t\t\t 3.  ORDONANCES\n\n\t\t\t\t\t\t 4.  SITUATION FINANCIERE\n\n\t\t\t\t\t\t CHOIX: ");
                                    scanf("%d", &choix3);
                                    system("clear");

                                    switch(choix3)
                                    {
                                        case 1 :
                                            {
                                                printf("\n\n\t\t\t\t\t   ==========LISTE DES CONSULTATIONS==========\n\n");
                                                Afficher_consultation(F, nom, num);break;
                                            }
                                        case 2 :
                                            {
                                                printf("\n\n\t\t\t\t\t   ==========LISTE DES RDV==========\n\n");
                                                Afficher_RDV(F, nom, num);break;
                                            }
                                        case 3 :
                                            {   printf("\n\n\t\t\t\t\t   ==========LISTE DES ORDONANCES==========\n\n");
                                                Afficher_ordonance(F, nom, num);break;
                                            }
                                        case 4 :
                                            {   printf("\n\n\t\t\t\t\t   ==========LISTE DES PAYEMENTS==========\n\n");
                                                Afficher_payement(F, nom, num);break;
                                            }
                                    }break;
                            }
                    case 2 :
                        {
                            nouvelle_consultation(F, nom, num);break;
                        }
                    case 3 :
                        {
                            nouveau_RDV(F, nom, num);break;
                        }
                    case 4 :
                        {
                            nouvelle_ordonance(F, nom, num);break;
                        }
                    case 5 :
                        {
                            nouveau_payement(F, nom, num);break;
                        }
                   /* case 6 :
                        {
                            information_du_patient();
                        }*/
                    }
                }}break;
                        }
                    case 2 :
                        {
                           // ajouter_un_RDV(F, nom);
                        }
                    case 3 :
                        {
                            supprimer_un_RDV(F, nom);break;
                        }
                    }
                break;}
            case 2 :
                {
                    Historique_RDV(F, nom); system("PAUSE");break;
                }
            }break;
        }
    case 3 :
        {
            Afficher_patient_en_SA(F);
            printf("\n\n\t\t\t\t\t1. AJOUTER UN PATIENT EN SALLE D'ATTENTE\n\n\t\t\t\t\t2. SUPPRIMER UN PATIENT DE LA SALLE D'ATTENTE\n\n\t\t\t\t\tCHOIX : ");
            scanf("%d", &choix1);
            switch(choix1)
            {
            case 1 :
                {
                   ajouter_patient_en_SA(F);break;
                }
            case 2 :
                {
                  supprimer_un_patient_en_SA(F);break;
                }
            }break;
        }
    case 4 :
        {
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t1. HISTORIQUE JOURNALIER\n\n\t\t\t\t\t\t2. HISTORIQUE HEBDOMADAIRE\n\n\t\t\t\t\t\tCHOIX : ");
            scanf("%d", &choix1);
            switch(choix1)
            {
            case 1 :
                {
                    Historique_journalier(F, nom);break;
                }
            case 2 :
                {
                    Historique_hebdomadaire(F, nom);break;
                }
            }break;
        }
    }
    }while(choix0!=0);
    }
    return 0;
}
