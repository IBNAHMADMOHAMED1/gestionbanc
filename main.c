#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct
{
    char nom[20];
    char CIN[20];
    float montant ;
    }Compte;
Compte compteBancaire[10] ;
        int nomber_Clinet=0 , i;
        char cartNatioanl[20];
void ajouterCompte();
void information_touts_Comptes();
void Ascendant();
void recherch();
void operation();
void Classment1();
void Fidelisation();
void loop_classement(int i , int j );
void afficher_aper_montantD(float montant);
void afficher_aper_montantA(float montant );
int main()
{
        int choix , a=0;
        printf("\n:::::::::::::::::::::::::::_Bienvenue_A_IBM_Banque_Of_Africa_::::::::::::::::::::::::::\n");
        //============== Menu Principal  ======================================================
    while(1)
    {
        printf("\t\n________________________________________________________________________________________\n");
        printf("\t\n|*-> 1. Ajouter un compte.                                                               |");
        printf("\t\n|*-> 2. Afficher tous les comptes.                                                       |");
        printf("\t\n|*-> 3. Operations :Retrait ou Depot                                                     |");
        printf("\t\n|*-> 4. Afficher Classement (Par Order Ascendant Ou Par Ordre Descendant                 |");
        printf("\t\n|*-> 5. Afficher Classement (comptes bancaire ayant un montant superieur a un chifer     |");
        printf("\t\n|*-> 6. Rechercher un compte.                                                            |");
        printf("\t\n|*-> 7. Personnes beneficiaires Fidelisation                                             |");
        printf("\t\n|*-> 8. Quitter l application                                                            |");
        printf("\n** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** * |");
        printf("\n_________________________________________________________________________________________\n");
        do
        {
            printf("\n Choisi une Operation : ");
            scanf("%d",&choix);
        }while(choix>8 || choix<0);
        switch(choix)
        {
        case 1 :
             ajouterCompte(); break;
        case 2:
            information_touts_Comptes(); break;
        case 3 :
            operation(); break;
        case 4 :
            Ascendant();   break;
        case 5:
            Classment1();  break;
        case 6:
            recherch(); break;
        case 7:
            Fidelisation(); break;
        case 8:
                 printf("Executer le programme...\n");
                 sleep(2);
                 exit(0); break;
        }
    }
    return 0;
}
//============================================ Fonction pour créer un Nouveau compte =============================
void ajouterCompte()
{
        int i =nomber_Clinet ; bool var=true ;
        do
        {
            var=true;
            printf("\nDonner Son CIN*: ");
            scanf("%s",cartNatioanl);
            for (i=0;i<nomber_Clinet;i++)
            {
                if (strcmp(compteBancaire[i].CIN,cartNatioanl)==0) // pour être CIN unique
                {
                    printf("\nCette carte deja exsite.\n");
                    var=false;  break;
                }
            }

        if(var==true) strcpy(compteBancaire[i].CIN,cartNatioanl);

        }while(var==false);
            printf("\nDonner Le Nom de Compte*: ");
            getchar();
            gets(compteBancaire[i].nom);
            printf("\nDonner Le Solde de Compte*: ");
            scanf("%f",&compteBancaire[i].montant);
            system("cls");
            printf("\n\t** **__ super__** ** ");
            printf("\nUn compte a ete cree au nom de %s. \n",compteBancaire[i].nom);
            nomber_Clinet++; //================= Aour Ajouterle nombre de comptes======================
}
            //================================== Fonction pour afficher les comptes ====================
 void information_touts_Comptes()
 {
     int a;
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    for (a;a<nomber_Clinet;a++)
    {
         printf("\nNom de Compte            :%s",compteBancaire[a].nom);
         printf("\nCIN                      :%s",compteBancaire[a].CIN);
         printf("\nSolde de Compte          :%.3fDh",compteBancaire[a].montant);
         printf("\n================================================================");
    }
                                // =========== S'il veut continuer, appuyez sur n'importe quelle lettre===============
     printf("\nAppuyer sur n'mporte quell key pour continue: ");
     getc(stdin);             // ============================== Stdin ==> clavier
     getchar();
 }
                            //============================== Fonction pour afficher un compte par indice ============
 void information_sule_Compte(int a)
 {
         printf("\nNom de Compte            :%s",compteBancaire[a].nom);
         printf("\nCIN                      :%s",compteBancaire[a].CIN);
         printf("\nSolde de Compte          :%.3fDh",compteBancaire[a].montant);
         printf("\n================================================================");
 }
                    //================================Fonction pour triage =====================================
void  Ascendant()
{
    int i , j;  char Choix_Classement;
    printf("\n_______ Menu DE Classement ____________\n");
    printf("\n*==> A. Par Ordre Ascendan. ");
    printf("\n*==> D. Par Ordre Descendant. ");
    do         //  =============================== Pour te donner un autre essai ===========================
    {
        printf("\n Choisir (A ou D):");
        scanf(" %c",&Choix_Classement);
    }while(Choix_Classement=='A' && Choix_Classement=='D');

    switch(Choix_Classement)
    {
    case 'A':   // =============================== Pour tri par order Aescendant ===========================
            loop_classementD(i,j);
            information_touts_Comptes();    break;
    case 'D': // =============================== Pour tri par order Descendant ===========================
            loop_classement(i , j );
            information_touts_Comptes();    break;
    }
}
         //================================ Fonction de recherch par CIN ===================================
void recherch()
{
    char  CIN_recherch[20];int i ;  bool test=false;
    printf(" Chercher un compte par CIN:  ");
    scanf("%s", CIN_recherch);
    for(i=0;i<nomber_Clinet;i++)
    {
             if (strcmp(CIN_recherch,compteBancaire[i].CIN)==0)
            {
                printf("\nCher %s Votre Compte Existe. ",compteBancaire[i].nom);
                printf("\n\n Voila voter information: \n");
                printf("\n____________________________________________________");
                information_sule_Compte(i);
                test=true; break;
            }
    }
    if (test==false)
    {
        printf("\n Votre compte n'existe pas.");
    }
}
// =================================== Fonction pour *Depot et *Retrait ====================================
void operation()
{
    int numero; float montant_Depot; float montant_Retrait;
    printf("Enterz Voter CIN : ");
    scanf("%s",cartNatioanl);
    printf("*\t==>  1.Depot. \n");
    printf("*\t==>  2.Retrait. \n");
    printf("\nChoisissez le numéro de transaction: ");
    scanf("%d",&numero);
    switch(numero)
    {
    case 1:
        for (i=0;i<nomber_Clinet;i++)
        {
            if(strcmp(cartNatioanl,compteBancaire[i].CIN)==0)
            {
                do
                {
                    printf("\nEntrez l'argent que vous voulez deposer: ");
                    scanf("%f",&montant_Depot);
                }while(montant_Depot<0);
                compteBancaire[i].montant+=montant_Depot;  //============= Depot ================
                printf("\n** ** ** Super ** **");
                printf("\nNouveau solde pour le compte %s",compteBancaire[i].nom);  break;
            }
        }
        break;
    case 2:

        for (i=0;i<nomber_Clinet;i++)
        {
            if(strcmp(cartNatioanl,compteBancaire[i].CIN)==0)
            {
                do
                {
                    printf("\nEntrez l'argent que vous voulez retrait : ");
                    scanf("%f",&montant_Retrait);
                }while(montant_Retrait>compteBancaire[i].montant);
                compteBancaire[i].montant-=montant_Retrait;  //===================== Retrait =============
                 printf("\n** ** ** Super ** **");
                printf("\nNouveau solde pour le compte %s",compteBancaire[i].nom);
            }
        }
    }
}
    //============================== Une Fonction qui donne le choix entre a Ascendan et Descendant ===================
void Classment1()
{
    int i , j; char Choix_Classement; float montant ;
    printf("\n_______ Menu DE Classement 2 ____________\n");
    printf("\n\t*==> A. Par Ordre Ascendan. ");
    printf("\n\t*==> D. Par Ordre Descendant. ");
    do
    {
        printf("\n\n Choisir (A ou D):");
        scanf(" %c",&Choix_Classement);
    }while(Choix_Classement=='A' && Choix_Classement=='D');

    printf("\nEntrez le montant de comparaison:    ");
    scanf("%f",&montant);

    switch(Choix_Classement)
    {
    case 'A':
           loop_classement(i , j );
           afficher_aper_montantA(montant);
            break;
    case 'D':
            loop_classementD(i,j);
            afficher_aper_montantA(montant);
            break;
    }
}
                    //=====================Fonction de afficher par montant ==================
void afficher_aper_montantA(float montant)
{
    int a=0 ;
        for(a;a<nomber_Clinet;a++)
        {
            if(compteBancaire[a].montant<montant) continue;
                 printf("\nNom de Compte            :%s",compteBancaire[a].nom);
                 printf("\nCIN                      :%s",compteBancaire[a].CIN);
                 printf("\nSolde de Compte          :%.3fDh",compteBancaire[a].montant);
                 printf("\n================================================================");

        }
     printf("\nAppuyer sur n'mporte quell key pour continue: ");
     getc(stdin);             // ============================== Stdin ==> clavier
     getchar();
}
                //============================== Fonction de fidelasation ===================================
void Fidelisation()
{
        int i , j ,a ;
        loop_classement(i , j);
        for (a =0; a<3; a++)
        {
         compteBancaire[a].montant+=((1.3*compteBancaire[a].montant)/100);
        }
         printf("\n\t\t** Super ** ");
         printf("\n\t| Fidlastion A Ete Effictue |\n\n");
}
                //============================ Fontion de triage par decroissent ===============================
void loop_classement(int i , int j )
{
    for(i=0;i<nomber_Clinet-1;i++)
    {
        for(j=i+1;j<nomber_Clinet;j++)
          {
              if(compteBancaire[i].montant<compteBancaire[j].montant)
                {
                        Compte tmp ;
                        tmp = compteBancaire[i];
                        compteBancaire[i]=compteBancaire[j];
                        compteBancaire[j]=tmp;
                }
            }
      }
}
        //============================ Fontion de triage par croissent ===============================
void loop_classementD(int i , int j)
{
    for(i=0;i<nomber_Clinet-1;i++)
    {
        for(j=i+1;j<nomber_Clinet;j++)
        {
            if(compteBancaire[i].montant>compteBancaire[j].montant)
            {
                Compte tmp ;
                tmp = compteBancaire[i];
                compteBancaire[i]=compteBancaire[j];
                compteBancaire[j]=tmp;
            }
        }
    }
}
