#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ncurses.h>
#include "fonction_du_CD.h"


//-----------------------fonction nouvelle consultation-----------------------------------------------

void nouvelle_consultation(FILE*F, char name[50], char num[25])
{
    int loop=0;
    patient malade;
    FILE* FTMP;
    int found=0, dent, choix;
    char acte[100], commentaire[200], para[50];
    date d;
    float prix;
        F=fopen(name, "r");
        if(!F)
        {
            printf("ERREUR LORS DE L'OUVERTURE DU FICHIER");
            exit(1);
        }
        FTMP=fopen("patienttmp.dat", "w");
        if (!FTMP)
        {
            printf("ERREUR LORS DE L'OUVERTURE DU FICHIER");
            exit(1);
        }
         do
         {
          fread(&malade, sizeof(patient),1,F);
            if(strcmp(malade.fiche.numero_de_dossier, num)==0)
            {
                found=1;
                break;
            }
         }while(!feof(F));
     fclose(F);
     if(found==1)
     {
         while(loop==0){
            system("clear");
            printf("\n\n\t\t\tNOUVELLE CONSULTATION\n");
            printf("\t\t\t\tListe des actes :\n\t NOM DE L'ACTE \t\t PRIX DE L'ACTE\n");
            printf("1. PROPHYLAXIE BUCCO-DENTAIRE \t\t\t[50;70[$");
            printf("\n2. RADIOGRAPHIES \t\t\t[41;90[$");
            printf("\n3. CHIRURGIE BUCCALE \t\t\t[80;150[$");
            printf("\n4. Gouttières, contentions \t\t\t[30;50[$");
            printf("\n5. Prothèses conjointes \t\t\t[30;70[$");
            printf("\n6. Prothèses adjointes \t\t\t[50;80[$");
            printf("\n7. Parodontologie \t\t\t[45;90[$");
            printf("\n8. Implantologie \t\t\t[40;500[$");
            printf("\n9. Chirurgie maxilo-faciale \t\t\t[150;500[$");
            printf("\n9. Prothèse maxilo-faciale \t\t\t[200;55[$");
            printf("\n10. BILAN \t\t\t[10;50[$");
            printf("\nVeuiller choisir un acte a appliquer : ");
            scanf("%d", &choix);
            switch(choix)
            {
            case 1 : {strcpy(acte,"PROPHYLAXIE BUCCO-DENTAIRE");loop=1;break; }
            case 2 : {strcpy(acte,"RADIOGRAPHIES");break; loop=1;}
            case 3 : {strcpy(acte,"CHIRURGIE BUCCALE");loop=1;break;}
            case 4 : {strcpy(acte,"Gouttières, contentions");loop=1;break;}
            case 5 : {strcpy(acte,"Prothèses adjointes");loop=1;break;}
            case 6 : {strcpy(acte,"Parodontologie");loop=1;break;}
            case 7 : {strcpy(acte,"Implantologie");loop=1;break;}
            case 8 : {strcpy(acte,"Chirurgie maxilo-faciale");loop=1;break;}
            case 9 : {strcpy(acte,"Prothèse maxilo-faciale");loop=1;break;}
            case 10 : {strcpy(acte,"BILAN");loop=1;break;}
            default : {printf("ERREUR ! VEUILLEZ CHOISIR UN ACTE PARMI LA LISTE CI-DESSUS");loop=0; break;}
            }}
            printf("Inserez le montant de l'operation : ");
            scanf("%f", &prix);
            printf("Inserer le numero de la dent a traiter :");
            scanf("%d", &dent);
            printf("Vos commentaires : ");
            fgets(commentaire, sizeof(commentaire), stdin);
            int h,min,s,day,mois,an;
        time_t now;
        time(&now);
          struct tm *local = localtime(&now);
          h = local->tm_hour;
          min = local->tm_min;
          s = local->tm_sec;
          day = local->tm_mday;
          mois = local->tm_mon + 1;
          an = local->tm_year + 1900;
            d.annee=an;
            d.mois=mois;
            d.jour=day;
            d.heure=h;
            d.second=s;
            d.minute=min;
        F=fopen(name, "r");
            do
            {
                fread(&malade, sizeof(patient), 1, F);
                if(strcmp(para,malade.fiche.numero_de_dossier)!=0)
                {
                if(strcmp(malade.fiche.numero_de_dossier, num)==0)
                {
                    patient t=malade;
                    for(int a=0;a<MAX; a++)
                    {if(t.consult[a].i!=1)
                     {
                    strcpy(t.consult[a].acte, acte); strcpy(t.consult[a].commentaire, commentaire);
                    t.consult[a].dat=d; t.consult[a].dent=dent; t.consult[a].prix=prix;t.consult[a].i=1;
                    fwrite(&t, sizeof(patient), 1, FTMP);
                    strcpy(para,malade.fiche.numero_de_dossier); break;}
                    }
                }
                else
                {
                    strcpy(para,malade.fiche.numero_de_dossier);
                    fwrite(&malade, sizeof(patient),1, FTMP);
                }}
            }while(!feof(F));
        fclose(FTMP);
        fclose(F);
        remove(name);
        rename("patienttmp.dat", name);
        printf("OPPERATION REUSSI\n");
     }
     else
     {
         printf("PATIENT INEXISTANT");
         fclose(FTMP);
     }
     {
             SITUATION_FINANCIERE sitf;int a; float montant;
    char mode[20];
    date d;
    int h, min, s, day, mois, an;
    char para[50];
    patient malade;
    FILE* FTMP;
    int found;
        F=fopen(name, "r");
        if(!F)
        {
            printf("ERREUR LORS DE L'OUVERTURE DU FICHIER TENPON");
            exit(1);
        }
        FTMP=fopen("patienttmp.dat", "w");
        if (!FTMP)
        {
            printf("ERREUR LORS DE L'OUVERTURE DU FICHIER");
            exit(1);
        }

         do
         {
          fread(&malade, sizeof(patient),1,F);
            if(strcmp(malade.fiche.numero_de_dossier, num)==0)
            {
                found=1;
                break;
            }
         }while(!feof(F));
     fclose(F);
     if(found==1)
     {

          montant=prix;
          strcpy(mode,"En espece");
          int h,min,s,day,mois,an;
        time_t now;
        time(&now);
          struct tm *local = localtime(&now);
          h = local->tm_hour;
          min = local->tm_min;
          s = local->tm_sec;
          day = local->tm_mday;
          mois = local->tm_mon + 1;
          an = local->tm_year + 1900;
          d.annee=an;
          d.mois=mois;
          d.jour=day;
          d.heure=h;
          d.minute=min;
          d.second=s;
        F=fopen(name, "r");
            do
            {
                fread(&malade, sizeof(patient), 1, F);
                if(strcmp(para,malade.fiche.numero_de_dossier)!=0)
                {
                if(strcmp(malade.fiche.numero_de_dossier, num)==0)
                {
                    patient t=malade;
                    for(int a=0;a<MAX; a++)
                    {if(t.sitf[a].i!=1)
                     {t.sitf[a].montant=montant; t.sitf[a].dat=d;
                    strcpy(t.sitf[a].mode, mode);t.sitf[a].i=1;
                    fwrite(&t, sizeof(patient), 1, FTMP);
                    strcpy(para,malade.fiche.numero_de_dossier);break;}}
                }
                else
                {
                    strcpy(para,malade.fiche.numero_de_dossier);
                    fwrite(&malade, sizeof(patient),1, FTMP);
                }}
            }while(!feof(F));
        fclose(FTMP);
        fclose(F);
        remove(name);
        rename("patienttmp.dat", name);
        getchar();
     }
     else
     {
         printf("PATIENT INEXISTANT");
         fclose(FTMP);
     }
     }
}


    void Afficher_consultation(FILE* F, char name[50],char num[25])
{
    F=fopen(name,"r");
        if(!F) {
        printf ("Erreur\n") ;
        exit(-1) ;}
    patient p;
    printf("\n\n\tDATE ET HEURE\t\tACTE\t\t\t\tDENT\t\tMONTANT\t\tCOMMENTAIRE\n");
    while(fread(&p, sizeof(patient),1,F)==1)
    {
        if(strcmp(p.fiche.numero_de_dossier,num)==0)
        {
            for(int a=0; a<MAX; a++)
            {
                if(p.consult[a].i==1)
                {printf("%2d/%2d/%4d (%2d h/%2dmin/%2ds)\t%s\t\t%d\t\t%f\t\t%s\n" , p.consult[a].dat.jour, p.consult[a].dat.mois, p.consult[a].dat.annee, p.consult[a].dat.heure, p.consult[a].dat.minute, p.consult[a].dat.second, p.consult[a].acte, p.consult[a].dent, p.consult[a].prix, p.consult[a].commentaire);}
            }
        }
    }
    fclose(F);
    getchar();
     system("clear");
}


 //------------------------fonction nouveau RDV--------------------------
void nouveau_RDV(FILE*F, char name[50], char num[25])
{

    patient malade;
    FILE* FTMP;
    char para[50];
    date d; char motif[50];
    int found;
        F=fopen(name, "r");
        if(!F)
        {
            printf("ERREUR LORS DE L'OUVERTURE DU FICHIER");
            exit(1);
        }
        FTMP=fopen("patienttmp.dat", "w");
        if (!FTMP)
        {
            printf("ERREUR LORS DE L'OUVERTURE DU FICHIER");
            exit(1);
        }

         do
         {
          fread(&malade, sizeof(patient),1,F);
            if(strcmp(malade.fiche.numero_de_dossier, num)==0)
            {
                found=1;
                break;
            }
         }while(!feof(F));
     fclose(F);
     if(found==1)
     {
    int h,min,s,day,mois,an;
        time_t now;
        time(&now);
          struct tm *local = localtime(&now);
          h = local->tm_hour;
          min = local->tm_min;
          s = local->tm_sec;
          day = local->tm_mday;
          mois = local->tm_mon + 1;
          an = local->tm_year + 1900;
    printf("SAISISSEZ LA DATE DE RENDEZ-VOUS :");
    printf("\nHEURE LOCAL : %d/%d/%d\t %d h %d min %d s", day, mois, an, h, min, s);
    d.jour=50;
    while(d.jour>32)
    {
    printf("\nJOUR : ");
    scanf("%d", &d.jour);
    if(d.jour>32 ) {printf("ERREUR! VEUILLEZ INSERER UN JOURS SUPERIEUR OU EGALE AU JOUR EN COURS");}
    }
    d.mois=15;
    while(d.mois>13 || d.mois<mois)
    {
    printf("MOIS : ");scanf("%d", &d.mois);
    if(d.mois>13 || d.mois<mois) {printf("ERREUR! VEUILLEZ INSERER UN MOIS SUPERIEUR OU EGALE AU MOIS EN COURS\n"); }
    }
    while(d.annee>(an+1) || d.annee<an)
    {
    printf("ANNEE : "); scanf("%d", &d.annee);
    if(d.annee>(an+1) || d.annee<an)    { printf("ERREUR! VEUILLEZ INSERER UNE ANNEE AU PLUS A L'ANNEE EN COUR\n"); }
    }
    d.heure=50;
    while(d.heure>24)
    {
        printf("HEURE : ");scanf("%d", &d.heure);
        if (d.heure>24) { printf("ERREUR! VEUILLEZ REESSAYER\n");}
    }
    printf("Motif du RDV : ");
    fgets(motif, sizeof(motif), stdin);
        F=fopen(name, "r");
            do
            {
                fread(&malade, sizeof(patient), 1, F);
                if(strcmp(para,malade.fiche.numero_de_dossier)!=0)
                {
                if(strcmp(malade.fiche.numero_de_dossier, num)==0)
                {
                    patient t=malade;
                    for(int a=0;a<MAX; a++)
                    {if(t.rdv[a].i!=1)
                     {
                    t.rdv[a].dat=d;
                    strcpy(t.rdv[a].motif, motif); t.rdv[a].i=1;
                    fwrite(&t, sizeof(patient), 1, FTMP);
                    strcpy(para,malade.fiche.numero_de_dossier);break;}
                    }
                }
                else
                {
                    strcpy(para,malade.fiche.numero_de_dossier);
                    fwrite(&malade, sizeof(patient),1, FTMP);
                }}
            }while(!feof(F));
        fclose(FTMP);
        fclose(F);
        remove(name);
        rename("patienttmp.dat", name);
        printf("OPPERATION REUSSI\n");
        getchar();
     }
     else
     {
         printf("PATIENT INEXISTANT");
         fclose(FTMP);
     }
}

void Afficher_RDV(FILE* F, char name[50],char num[25])
{
    patient malade;
    F=fopen(name,"r");
        if(!F) {
        printf ("Erreur\n") ;
        exit(-1) ;}
    printf("\nDate\t\t\tHEURE \t\tMOTIF\n");
    while(fread(&malade, sizeof(patient),1,F)==1)
    {
        if(strcmp(malade.fiche.numero_de_dossier,num)==0)
        {
            for(int a=0; a<MAX; a++)
            {
                if(malade.rdv[a].i==1)
                {printf("%2d/%2d/%4d\t\t%d\t\t%s\n", malade.rdv[a].dat.jour, malade.rdv[a].dat.mois, malade.rdv[a].dat.annee, malade.rdv[a].dat.heure , malade.rdv[a].motif);}
            }
        }
    }
    fclose(F);
     getchar();
     system("clear");
}

void list_RDV(FILE* F, char name[50])
{
     patient malade;
    F=fopen(name,"r");
        if(!F) {
        printf ("Erreur\n") ;
        exit(-1) ;}
        int h,min,s,day,mois,an;
        time_t now;
        time(&now);
          struct tm *local = localtime(&now);
          h = local->tm_hour;
          min = local->tm_min;
          s = local->tm_sec;
          day = local->tm_mday;
          mois = local->tm_mon + 1;
          an = local->tm_year + 1900;
    printf("\nDate\t\t\tHEURE \t\tMOTIF\t\t\t\t\tNOM\t\tPRENOM\n");
    while(fread(&malade, sizeof(patient),1,F)==1)
    {
            for(int a=0; a<MAX; a++)
            {
                if(malade.rdv[a].i==1)
                {
                if(malade.rdv[a].dat.jour==day)                     {printf("%2d/%2d/%4d\t\t%d\t\t%s\t\t\t%s\t\t%s\n", malade.rdv[a].dat.jour, malade.rdv[a].dat.mois, malade.rdv[a].dat.annee, malade.rdv[a].dat.heure , malade.rdv[a].motif, malade.fiche.prenom, malade.fiche.prenom);}

                }
            }
    }
    fclose(F);
}
void Historique_RDV(FILE* F, char name[50])
{
     patient malade;
    F=fopen(name,"r");
        if(!F) {
        printf ("Erreur\n") ;
        exit(-1) ;}
        int h,min,s,day,mois,an;
        time_t now;
        time(&now);
          struct tm *local = localtime(&now);
          h = local->tm_hour;
          min = local->tm_min;
          s = local->tm_sec;
          day = local->tm_mday;
          mois = local->tm_mon + 1;
          an = local->tm_year + 1900;
    printf("\nDate\t\tHEURE\t PRENOM\t NOM\t\t MOTIF\n");
    while(fread(&malade, sizeof(patient),1,F)==1)
    {
            for(int a=0; a<MAX; a++)
            {
                if(malade.rdv[a].i==1)
                {
                if(malade.rdv[a].dat.annee>=an)                     {printf("%2d/%2d/%4d\t\%d\t %s\t %s\t\t %s\n", malade.rdv[a].dat.jour, malade.rdv[a].dat.mois, malade.rdv[a].dat.annee, malade.rdv[a].dat.heure , malade.fiche.prenom, malade.fiche.nom, malade.rdv[a].motif);}

                }
            }
    }
    fclose(F);
}

//---------------------nouvelle ordonance-------------------
void nouvelle_ordonance(FILE*F, char name[50], char num[25])
{
    ORDONNANCE ordo;char para[50];
    patient malade;
    FILE* FTMP;
    int found;
    float prix;
        F=fopen(name, "r");
        if(!F)
        {
            printf("ERREUR LORS DE L'OUVERTURE DU FICHIER");
            exit(1);
        }
        FTMP=fopen("patienttmp.dat", "w");
        if (!FTMP)
        {
            printf("ERREUR LORS DE L'OUVERTURE DU FICHIER");
            exit(1);
        }


         do
         {
          fread(&malade, sizeof(patient),1,F);
            if(strcmp(malade.fiche.numero_de_dossier, num)==0)
            {
                found=1;
                break;
            }
         }while(!feof(F));
     fclose(F);
     if(found==1)
     {
          int h,min,s,day,mois,an;
        time_t now;
        time(&now);
          struct tm *local = localtime(&now);
          h = local->tm_hour;
          min = local->tm_min;
          s = local->tm_sec;
          day = local->tm_mday;
          mois = local->tm_mon + 1;
          an = local->tm_year + 1900;
          ordo.dat.annee=an;
          ordo.dat.mois=mois;
          ordo.dat.jour=day;
          ordo.dat.heure=h;
          ordo.dat.second=s;
          ordo.dat.minute=min;
          printf("SAISSEZ LE MEDICAMENT PRESCRIT :");
          fgets(ordo.medicament, sizeof(ordo.medicament), stdin);
          printf("INDIQUEZ LA POSOLOGIE :");
          fgets(ordo.posologie, sizeof(ordo.posologie), stdin);
          printf("INDIQUEZ LE NOM DU MEDECIN DONNANT L'ORDONNANCE : ");
          fgets(ordo.medecin, sizeof(ordo.medecin), stdin);
        F=fopen(name, "r");
            do
            {
                fread(&malade, sizeof(patient), 1, F);
                if(strcmp(para,malade.fiche.numero_de_dossier)!=0)
                {
                if(strcmp(malade.fiche.numero_de_dossier, num)==0)
                {
                    patient t=malade;
                    for(int a=0;a<MAX; a++)
                    {if(t.ordo[a].i!=1)
                     {
                    strcpy(t.ordo[a].medecin, ordo.medecin); strcpy(t.ordo[a].medicament, ordo.medicament); strcpy(t.ordo[a].posologie, ordo.posologie);
                    t.ordo[a].dat=ordo.dat; t.ordo[a].i=1;
                    fwrite(&t, sizeof(patient), 1, FTMP);
                    strcpy(para,malade.fiche.numero_de_dossier);break;}
                    }
                }
                else
                {
                    strcpy(para,malade.fiche.numero_de_dossier);
                    fwrite(&malade, sizeof(patient),1, FTMP);
                }}
            }while(!feof(F));
        fclose(FTMP);
        fclose(F);
        remove(name);
        rename("patienttmp.dat", name);
        printf("OPPERATION REUSSI\n");
        getchar();
     system("clear");
     }
     else
     {
         printf("PATIENT INEXISTANT");
         fclose(FTMP);
     }
}

void Afficher_ordonance(FILE* F, char name[50],char num[25])
{
    patient malade;
    F=fopen(name,"r");
        if(!F) {
        printf ("Erreur\n") ;
        exit(-1) ;}
    printf("\nDate\t\t\tMEDICAMENT \t\tPOSOLOGIE \t\tMEDECIN \n");
    while(fread(&malade, sizeof(patient),1,F)==1)
    {
        if(strcmp(malade.fiche.numero_de_dossier,num)==0)
        {
            for(int a=0; a<MAX; a++)
            {
                if(malade.ordo[a].i==1)
                {printf("%2d/%2d/%4d\t\t%s\t\t%s\t\t%s\n", malade.ordo[a].dat.jour, malade.ordo[a].dat.mois, malade.ordo[a].dat.annee, malade.ordo[a].medicament , malade.ordo[a].posologie, malade.ordo[a].medecin);}
            }
        }
    }
    fclose(F);
        getchar();
     system("clear");
}

// ----------------------------nouveau payement---------------------------

void nouveau_payement(FILE*F, char name[50], char num[25])
{

    SITUATION_FINANCIERE sitf;int a; float montant;
    char mode[20];
    date d;
    int h, min, s, day, mois, an;
    char para[50];
    patient malade;
    FILE* FTMP;
    int found;
        F=fopen(name, "r");
        if(!F)
        {
            printf("ERREUR LORS DE L'OUVERTURE DU FICHIER TENPON");
            exit(1);
        }
        FTMP=fopen("patienttmp.dat", "w");
        if (!FTMP)
        {
            printf("ERREUR LORS DE L'OUVERTURE DU FICHIER");
            exit(1);
        }

         do
         {
          fread(&malade, sizeof(patient),1,F);
            if(strcmp(malade.fiche.numero_de_dossier, num)==0)
            {
                found=1;
                break;
            }
         }while(!feof(F));
     fclose(F);
     if(found==1)
     {

          printf("SAISSISEZ LE MONTANT A PAYER :");
          scanf("%f", &montant );
          printf("DECLARER LE MODE DE PAYEMENT :\n 1. En Espece\n 2. Par Carte Banquaire \nCHOIX :");
            scanf("%d", &a);
            switch(a)
            {
                case 1 : { strcpy(mode, "En Espece");break;}
                case 2 : { strcpy(mode, "Par Carte Banquaire"); break; }

            }
          int h,min,s,day,mois,an;
        time_t now;
        time(&now);
          struct tm *local = localtime(&now);
          h = local->tm_hour;
          min = local->tm_min;
          s = local->tm_sec;
          day = local->tm_mday;
          mois = local->tm_mon + 1;
          an = local->tm_year + 1900;
          d.annee=an;
          d.mois=mois;
          d.jour=day;
          d.heure=h;
          d.minute=min;
          d.second=s;
        F=fopen(name, "r");
            do
            {
                fread(&malade, sizeof(patient), 1, F);
                if(strcmp(para,malade.fiche.numero_de_dossier)!=0)
                {
                if(strcmp(malade.fiche.numero_de_dossier, num)==0)
                {
                    patient t=malade;
                    for(int a=0;a<MAX; a++)
                    {if(t.sitf[a].i!=1)
                     {t.sitf[a].montant=montant; t.sitf[a].dat=d;
                    strcpy(t.sitf[a].mode, mode);t.sitf[a].i=1;
                    fwrite(&t, sizeof(patient), 1, FTMP);
                    strcpy(para,malade.fiche.numero_de_dossier);break;}}
                }
                else
                {
                    strcpy(para,malade.fiche.numero_de_dossier);
                    fwrite(&malade, sizeof(patient),1, FTMP);
                }}
            }while(!feof(F));
        fclose(FTMP);
        fclose(F);
        remove(name);
        rename("patienttmp.dat", name);
        printf("OPPERATION REUSSI\n");
        getchar();
     }
     else
     {
         printf("PATIENT INEXISTANT");
         fclose(FTMP);
     }
}

void Afficher_payement(FILE* F, char name[50],char num[25])
{
    patient malade;
    F=fopen(name,"r");
        if(!F) {
        printf ("Erreur\n") ;
        exit(-1) ;}
    printf("\nDate\t\theure\t\t MONTANT\t\tMODE DE PAYEMENT \n");
    while(fread(&malade, sizeof(patient),1,F)==1)
    {
        if(strcmp(malade.fiche.numero_de_dossier,num)==0)
        {
            for(int a=0; a<MAX; a++)
            {
                if(malade.sitf[a].i==1)          {  printf("%2d/%2d/%4d\t%2d\t\t%f\t\t%s\n", malade.sitf[a].dat.jour, malade.sitf[a].dat.mois, malade.sitf[a].dat.annee, malade.sitf[a].dat.heure, malade.sitf[a].montant, malade.sitf[a].mode);}

            }
        }
    }
    fclose(F);
        getchar();
     system("clear");
}
//fonction pour ajouter un patient
patient saisir()
{
    system("clear");
    patient malade;
    printf("\n\n===================================================== ajouter un patient =============================================== \n");
    printf("\n\tNOM: ");
    fgets(malade.fiche.nom, sizeof(malade.fiche.nom), stdin);
    printf("\n\tPRENOM: ");
    fgets(malade.fiche.prenom, sizeof(malade.fiche.prenom), stdin);
   /* printf("\n\tCIVILITE: ");
    gets(malade.fiche.civilite);
    printf("\n\tPROFESSION: ");
    gets(malade.fiche.profession);
     printf("\n\tDATE DE NAISSANCE (JOUR/MOIS/ANNEE): ");
    scanf("%d/%d/%d", &malade.fiche.dat.jour, &malade.fiche.dat.mois, &malade.fiche.dat.annee);
    printf("\n\tCIN:");
    scanf("%d", &malade.fiche.cin);
     printf("\n\tTEL: ");
     scanf("%d",&malade.fiche.tel);
     printf("\n\tEMAIL: ");
     gets(malade.fiche.email);
     gets(malade.fiche.email);
     printf("\n\tADRESSE: ");
     gets(malade.fiche.adresse);*/
     printf("\n\tNUMERO DE DOSSIER: ");
     fgets(malade.fiche.numero_de_dossier, sizeof(malade.fiche.numero_de_dossier), stdin);
     return malade;
    }
// FIN DE LA FONCTION
//FONCTION POUR AJOUTER UN PATIENT
void ajouter_patient(FILE* F, char name[50]){
    F=fopen(name,"a" );
    if(!F){fopen(name,"w" );}
    patient malade=saisir();
    int n=sizeof(patient);
    unsigned int i;
    i=fwrite(&malade,n,1,F);
    if(i==1)
        printf("ajout avec succes:\n");
    else
        printf("erreur :\n");
    fclose(F);
}


void Afficher_patient(FILE* F, char name[50])
{
    int i=1; char para[50];
     patient malade;
    F=fopen(name, "r");
    if(!F) {
        printf ("Erreur\n") ;
        exit(-1) ;}
     printf("Numero de dossier \t\t Nom \t\t Prenom \n");
    do{
        fread(&malade, sizeof(patient),1, F);
        if(strcmp(para,malade.fiche.numero_de_dossier)!=0)
        {printf("%s\t\t\t\t %s \t\t %s\n", malade.fiche.numero_de_dossier, malade.fiche.nom, malade.fiche.prenom);
        }
        strcpy(para,malade.fiche.numero_de_dossier);
    }while( ! feof(F));
    fclose(F);
}

void supprimer_un_patient (FILE*F, char name[50])
{
    char para[50];
    patient malade;
    FILE* FTMP;
    char num[25]; int found;
        F=fopen(name, "r");
        if(!F)
        {
            printf("ERREUR LORS DE L'OUVERTURE DU FICHIER TENPON");
            exit(1);
        }
        FTMP=fopen("patienttmp.dat", "w");
        if (!FTMP)
        {
            printf("ERREUR LORS DE L'OUVERTURE DU FICHIER");
            exit(1);
        }
     printf("Numero de dossier du patient: ");
     fgets(num, sizeof(num), stdin);
         do
         {
          fread(&malade, sizeof(patient),1,F);
            if(strcmp(malade.fiche.numero_de_dossier, num)==0)
            {
                found=1;
                break;
            }
         }while(!feof(F));
     fclose(F);
     if(found==1)
     {
        F=fopen(name, "r");
            do
            {
                fread(&malade, sizeof(patient), 1, F);
                if(strcmp(para,malade.fiche.numero_de_dossier)!=0)
                {
                if(strcmp(malade.fiche.numero_de_dossier, num)==0)
                {
                    strcpy(para,malade.fiche.numero_de_dossier);
                    continue;
                }
                else
                {
                    strcpy(para,malade.fiche.numero_de_dossier);
                    fwrite(&malade, sizeof(patient),1, FTMP);
                }}
            }while(!feof(F));
        fclose(FTMP);
        fclose(F);
        remove(name);
        rename("patienttmp.dat", name);
        printf("OPPERATION REUSSI\n");
        getchar();
     }
     else
     {
         printf("PATIENT INEXISTANT");
         fclose(FTMP);
     }
}

void supprimer_un_RDV (FILE*F, char name[50])
{
    system("clear");
    list_RDV(F, name);
    RDV r[MAX];
    char para[50]; int h;
    patient malade;
    FILE* FTMP;
    char num[25]; int found;
        F=fopen(name, "r");
        if(!F)
        {
            printf("ERREUR LORS DE L'OUVERTURE DU FICHIER TENPON");
            exit(1);
        }
        FTMP=fopen("patienttmp.dat", "w");
        if (!FTMP)
        {
            printf("ERREUR LORS DE L'OUVERTURE DU FICHIER");
            exit(1);
        }
     printf("\n\nNumero de dossier du patient du patient qui souhaite annuler son RDV : ");
     fgets(num, sizeof(num), stdin);
     printf("\n\nIndiquer l'heure de son rendrez-vous :");
     scanf("%d", &h);
         do
         {
          fread(&malade, sizeof(patient),1,F);
            if(strcmp(malade.fiche.numero_de_dossier, num)==0)
            {
                found=1;
                break;
            }
         }while(!feof(F));
     fclose(F);
     if(found==1)
     {
        F=fopen(name, "r");
            do
            {
                fread(&malade, sizeof(patient), 1, F);
                if(strcmp(para,malade.fiche.numero_de_dossier)!=0)
                {
                if(strcmp(malade.fiche.numero_de_dossier, num)==0)
                {
                    patient t=malade;
                    for(int j=0; j<MAX; j++)
                    {
                        if(t.rdv[j].dat.heure==h){continue;}
                        else {r[j].dat=t.rdv[j].dat; r[j].i=t.rdv[j].i; strcpy(r[j].motif,t.rdv[j].motif);}

                    }
                    for (int j=0; j<MAX; j++){t.rdv[j].dat=r[j].dat; t.rdv[j].i=r[j].i; strcpy(t.rdv[j].motif,r[j].motif);}
                    fwrite(&t, sizeof(patient), 1, FTMP);
                    strcpy(para,malade.fiche.numero_de_dossier);

                }
                else
                {
                    strcpy(para,malade.fiche.numero_de_dossier);
                    fwrite(&malade, sizeof(patient),1, FTMP);
                }}
            }while(!feof(F));
        fclose(FTMP);
        fclose(F);
        remove(name);
        rename("patienttmp.dat", name);
        printf("OPPERATION REUSSI\n");
        getchar();
     }
     else
     {
         printf("PATIENT INEXISTANT");
         fclose(FTMP);
     }
}

void Historique_journalier(FILE*F, char name[25])
{
    system("clear");
       int h,min,s,day,mois,an;
        time_t now;
        time(&now);
          struct tm *local = localtime(&now);
          h = local->tm_hour;
          min = local->tm_min;
          s = local->tm_sec;
          day = local->tm_mday;
          mois = local->tm_mon + 1;
          an = local->tm_year + 1900;

     patient malade;
    F=fopen(name,"r");
        if(!F) {
        printf ("Erreur\n") ;
        exit(-1) ;}
    printf("\nDate\t\theure\t\t MONTANT\t\tMODE DE PAYEMENT\t\tNOM ET PRENOM \n");
    while(fread(&malade, sizeof(patient),1,F)==1)
    {

            for(int a=0; a<MAX; a++)
            {
                if(malade.sitf[a].dat.jour==day)          {  printf("%2d/%2d/%4d\t%2d\t\t%f\t\t%s\t\t\t%s %s\n", malade.sitf[a].dat.jour, malade.sitf[a].dat.mois, malade.sitf[a].dat.annee, malade.sitf[a].dat.heure, malade.sitf[a].montant, malade.sitf[a].mode, malade.fiche.nom, malade.fiche.prenom);}

            }

    }
    fclose(F);
    system("pause");
}

void Historique_hebdomadaire(FILE*F, char name[25])
{
         system("clear");
       int h,min,s,day,mois,an;
        time_t now;
        time(&now);
          struct tm *local = localtime(&now);
          h = local->tm_hour;
          min = local->tm_min;
          s = local->tm_sec;
          day = local->tm_mday;
          mois = local->tm_mon + 1;
          an = local->tm_year + 1900;

     patient malade;
    F=fopen(name,"r");
        if(!F) {
        printf ("Erreur\n") ;
        exit(-1) ;}
    printf("\nDate\t\theure\t\t MONTANT\t\tMODE DE PAYEMENT\t\tNOM ET PRENOM \n");
    while(fread(&malade, sizeof(patient),1,F)==1)
    {

            for(int a=0; a<MAX; a++)
            {
                if(malade.sitf[a].dat.jour>=(day-7) && malade.sitf[a].i==1)          {  printf("%2d/%2d/%4d\t%2d\t\t%f\t\t%s\t\t\t%s %s\n", malade.sitf[a].dat.jour, malade.sitf[a].dat.mois, malade.sitf[a].dat.annee, malade.sitf[a].dat.heure, malade.sitf[a].montant, malade.sitf[a].mode, malade.fiche.nom, malade.fiche.prenom);}

            }

    }
    fclose(F);
    system("pause");
}

void ajouter_patient_en_SA(FILE* F){
    F=fopen("salle d'attente","a" );
    if(!F){F=fopen("salle d'attente","w" );}
    salle_attente salle;
    printf("\n\t\t\t\t\t\tEntrer le nom du patient :");
    fgets(salle.nom, sizeof(salle.nom), stdin);
    printf("\n\t\t\t\t\t\tEntrer le prenom du patient :");
    fgets(salle.prenom, sizeof(salle.prenom), stdin);
    printf("\n\t\t\t\t\t\tQuel est le motif :");
    fgets(salle.motif, sizeof(salle.motif), stdin);
    printf("\n\t\t\t\t\tSaisissez le rang du patient dans la file d'attente : ");
    fgets(salle.ordre, sizeof(salle.ordre), stdin);
    int n=sizeof(salle_attente);
    unsigned int i;
    i=fwrite(&salle,n,1,F);
    if(i==1)
        printf("ajout avec succes:\n");
    else
        printf("erreur :\n");
    fclose(F);
}

void Afficher_patient_en_SA(FILE* F)
{
    int i=1; char para[50];
     salle_attente salle;
    F=fopen("salle d'attente", "r");
    if(!F) {
        printf ("Erreur\n") ;
        exit(-1) ;}
     printf("\n\t\t\t\t\tRang\t\tNom \t\t Prenom\t\t Motif \n");
    do{
        fread(&salle, sizeof(salle_attente),1, F);
        if(strcmp(para,salle.nom)!=0)
        {printf("\t\t\t\t\t%s\t\t%s\t\t %s\t\t %s\n", salle.ordre, salle.nom, salle.prenom, salle.motif);
        }
        strcpy(para,salle.nom);
    }while( ! feof(F));
    fclose(F);
}


void supprimer_un_patient_en_SA(FILE*F)
{
    char para[50];
    salle_attente salle;
    FILE* FTMP;
    char num[10]; int found;
        F=fopen("salle d'attente", "r");
        if(!F)
        {
            printf("ERREUR LORS DE L'OUVERTURE DU FICHIER TENPON");
            exit(1);
        }
        FTMP=fopen("patienttmp.dat", "w");
        if (!FTMP)
        {
            printf("ERREUR LORS DE L'OUVERTURE DU FICHIER");
            exit(1);
        }
     printf("Saisissez le rang du patient dans la file d'attente : ");
     fgets(num, sizeof(num), stdin);
         do
         {
          fread(&salle, sizeof(salle_attente),1,F);
            if(strcmp(salle.ordre, num)==0)
            {
                found=1;
                break;
            }
         }while(!feof(F));
     fclose(F);
     if(found==1)
     {
        F=fopen("salle d'attente", "r");
            do
            {
                fread(&salle, sizeof(salle_attente), 1, F);
                if(strcmp(para,salle.ordre)!=0)
                {
                if(strcmp(salle.ordre, num)==0)
                {
                    strcpy(para,salle.ordre);
                    continue;
                }
                else
                {
                    strcpy(para,salle.ordre);
                    fwrite(&salle, sizeof(salle_attente),1, FTMP);
                }}
            }while(!feof(F));
        fclose(FTMP);
        fclose(F);
        remove("salle d'attente");
        rename("patienttmp.dat", "salle d'attente");
        printf("OPPERATION REUSSI\n");
        getchar();
     }
     else
     {
         printf("PATIENT INEXISTANT");
         fclose(FTMP);
     }
}

