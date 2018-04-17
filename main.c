#include <stdio.h>
#include <stdlib.h>
#include "information.h"
#include "gestion_etudiant.h"

    /**************************************************************
    *               FONCTION PRINCIPALE
    **************************************************************/

int main()
{
    int choix, recommencer = 0; //Declaration des variables et initialisation

    system("color 1A"); //Changer la coleur de la console

    do
+      {


      /**************************************************************
      *             AFFICHAGE DU MENU DE L'APPLICATION
      **************************************************************/


        printf("\n\n                     ....................GESTION DES ETUDIANTS....................                   \n\n\n");
        printf("                     1.AJOUTER UN ETUDIANT \n");
        printf("                     2.RECHERCHER UN ETUDIANT \n");
        printf("                     3.MODIFIER LES INFORMATIONS D'UN ETUDIANT \n");
        printf("                     4.SUPPRIMER UN ETUDIANT \n");
        printf("                     5.AFFICHER TOUS LES ETUDIANTS \n");
        printf("                     6.CALCUL DES MOYENNES \n");
        printf("                     7.AFFICHER LES MOYENNES \n");

        //Demande du choix de l'utilisateur

        printf("\n            - Entrer votre choix: ");
        scanf("%d", &choix);


        system("cls"); //Nettois le terminal


      /**************************************************************
      *             TRAITEMENT DU CHOIX DE L'UTILISATEUR
      **************************************************************/

        switch(choix){

            case 1: ajouter_un_etudiant(); break;               // Si le choix vaut 1 , alors ajouter un etudiant.
            case 2: recherhe_et_affichage(); break;             // Si le choix vaut 2 , alors rechercher un etudiant.
            case 3: modification_etudiant(); break;             // Si le choix vaut 3 , alors modifier  un etudiant.
            case 4: suppression_etudiant(); break;              // Si le choix vaut 4 , alors supprimer un etudiant.
            case 5: affichage_de_tout_les_etudiants(); break;   // Si le choix vaut 5 , alors afficher tous les etudiants.
            case 6: calcul_des_moyennes(); break;               // Si le choix vaut 6 , alors calcul des moyennes.
            case 7: affichage_des_moyennes(); break;            // Si le choix vaut 3 , alors afficher les moyennes.
            default:
                {
                   //Si le choix n'est pas pris en compte afficher un message d'erreur
                    printf("\n Valeur non pris en compte, reessayer \n\n");
                    break;
                }

        }

        // On demander à l'utilisateur  cette action
        // si seulement si le choix prealablement entrer
        // est compris entre 1 et 7

        if(choix >= 1 && choix <= 7){

            printf("\n Pour retourner au menu taper 1: ");
            scanf("%d",&recommencer);

            if(recommencer == 1)
                system("cls"); //Nettois le terminal
            else
                printf("\n FERMETURE DE LA SESSION MERCI D'ETRE PASSER.......\n\n\n\n");

        }


  } while(recommencer == 1 || (choix < 1 || choix > 7));



    /******************************************************
    *               FIN DU PROGRAMME
    *******************************************************/

    printf("\n\n");
    system("PAUSE");
    return 0;
}
