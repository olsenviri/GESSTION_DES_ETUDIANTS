#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "information.h"
#include "gestion_etudiant.h"


/********************************************
*       VERIFIER SI LE NUMERO EXISTE
*********************************************/

int recherche_etudiant(int validite)
{
   FILE *fichier = NULL;

   fichier = fopen("etudiant.txt", "r");

   /**
   * VERIFIE SI LE FICHIER A ETE OUVERT
   * SI OUI ON LE LIT
   * SINON ON NE FAIT RIEN
   */

  if (fichier != NULL){
        do{
            fscanf(fichier, "%d   %s   %s  %s \n", &Etude.numero, &Etude.nom, &Etude.prenom, &Etude.Filiere);
            fflush(stdin); // Netoie l'entree

            if(Etude.numero == validite){
                fclose(fichier);
                return 1;
            }
          } while(!feof(fichier));

    }fclose(fichier);
    return -1;

}


/********************************************
*       FONCTIONS D'AJOUT D'ETUDIANT
*********************************************/

void ajouter_un_etudiant()
{
    int num; // Numero de l'etudiant qui sera comme identifiant

    printf("\n\n                     ....................AJOUT D'UN ETUDIANT.................... \n\n");

    //Declare le fichier qui va contenir les etudiants
    FILE *fichier = NULL;
    fichier = fopen("etudiant.txt", "a"); // Ouverture du fichier etdudiant.txt

    //Si le fichier est ouvert on entre dans la boucle
    //sinon on ne fait rien

    if(fichier != NULL)
    {

        printf("\n NUMERO: ");
        scanf("%d", &num);

        fflush(stdin); // Nettoyage de l'entree

        while(recherche_etudiant(num) == 1)
        {
            printf("\n NUMERO DEJA PRIS VEUILLEZ CHANGER !!");
            printf("\n\n NUMERO: ");
            scanf("%d", &num);

            fflush(stdin); //Nettoyage de l'entree
        }

        Etude.numero = num;

        printf("\n NOM: ");
        gets(Etude.nom);

        fflush(stdin);

        printf("\n PRENOM: ");
        gets(Etude.prenom);

        fflush(stdin);

        printf("\n FILIERE: ");
        gets(Etude.Filiere);
        fflush(stdin);

        fprintf(fichier, "%d  %s  %s   %s \n", Etude.numero, Etude.nom, Etude.prenom, Etude.Filiere); //Enregistre dans le fichier

        printf("\n\n L'Etudiant %s %s a ete bien enregistrer \n\n", Etude.nom , Etude.prenom);

    }

        fclose(fichier); // Fermeture du fichier
}







void recherhe_et_affichage()
{
    int choix;

    system("cls"); // netoie le terminal

    /**************************************************
    *               MENU DES RECHERCES
    ***************************************************/

    printf("\n\n                   ....................RECHERCHE DES ETUDIANTS.................... \n\n");
    printf("                 1.EFFECTUER LA RECHERCHE PAR LE NOM DE L'ETUDIANT \n");
    printf("                 2.EFFECTUER LA RECHERCHE PAR LE PRENOM DE L'ETUDIANT \n");
    printf("                 3.EFFECTUER LA RECHERCHE PAR LE NUMERO DE L'ETUDIANT \n");
    printf("                 4.AFFICHER LES ELEVES DE LA MEME FILIERE \n");


    printf("\n            -Entrer votre choix: ");
    scanf("%d", &choix);

    system("cls");

    switch(choix)
    {
        case 1:  recherche_par_nom(); break;
        case 2:  recherche_par_prenom(); break;
        case 3:  recherche_par_numero(); break;
        case 4:  recherche_par_filiere(); break;
        default:
            {
                printf("\n\n VALEUR NON PRIS EN CHARGE VEUILLEZ REESSAYER... \n\n");
                break;
            }
    }

}





/**********************************************
*     FONCTION DE LA MODIFICATION ETUDIANT
***********************************************/


void modification_etudiant()
{
    FILE *fichier, *fichier1;

    int numero_a_modifier, i, valeur_a_modifier;
    char reponse = 'n';
    char nom[100], prenom[100], filiere[100];

    /******************************************
    *    Demande du numero de l'etudiant
    *******************************************/

    printf("\n Numero de l'etudiant a modifier: ");
    scanf("%d",&numero_a_modifier);

    fflush(stdin); // Vide l'entree

    if(recherche_etudiant(numero_a_modifier) == 1) //on fait la verification pour voir si le numero existe reelement
    {
        printf("\n Voulez-vous vraiment modifier ? o = OUI ou n = NON : "); // si oui on demande une confirmation
        scanf("%c",&reponse);

        fflush(stdin);

            if(reponse == 'o' || reponse == 'O')
            {
                fichier = fopen("etudiant.txt", "r"); // on ouvre le fichiier qui regroupe toutes les informations
                fichier1 = fopen("M_etudiant.txt", "a"); //on ouvre un deuxieme fichier intermediaire

                    do{

                       //on procede à la lecture du fichier etudiant.txt

                        fscanf(fichier, "%d   %s   %s   %s \n", &Etude.numero, &Etude.nom, &Etude.prenom, &Etude.Filiere);

                           //le numero saisi correspond au numero de l'étudiant donc on peut faire la modification

                            if(numero_a_modifier == Etude.numero){

                                system("cls");

                                do {
                                        printf("\n\n          ========================================================================        ");
                                        printf("\n                        QUELLE VALEUR VOULEZ-VOUS MODIFIER              ");
                                        printf("\n          ========================================================================       \n\n");
                                        printf("\n            1. MODIFIER LE NOM \n");
                                        printf("\n            2. MODIFIER LE PRENOM\n");
                                        printf("\n            3. MODIFIER LA FILIERE\n");
                                        printf("\n            4. TOUS MODIFIER\n\n");

                                        printf("\n  Entrer une valeur : ");
                                        scanf("%d", &valeur_a_modifier);
                                        fflush(stdin);

                                }while(valeur_a_modifier < 1 || valeur_a_modifier > 4);


                                switch(valeur_a_modifier){
                                    case 1: {printf("\n         ENTRER LE NOUVEAU NOM: "); gets(Etude.nom); fflush(stdin); break;}
                                    case 2: {printf("\n         ENTRER LE NOUVEAU PRENOM: "); gets(Etude.prenom); fflush(stdin); break;}
                                    case 3: {printf("\n         ENTRER LA NOUVELLE FILIERE : "); gets(Etude.Filiere);fflush(stdin); break;}
                                    case 4: {
                                        printf("\n            ENTRER LE NOUVEAU NOM: ");
                                        gets(Etude.nom);
                                        fflush(stdin);
                                        printf("\n            ENTRER LE NOUVEAU PRENOM : ");
                                        gets(Etude.prenom);
                                        fflush(stdin);
                                        printf("\n            ENTRER LA NOUVELLE FILIERE: ");
                                        gets(Etude.Filiere);
                                        fflush(stdin);

                                    }
                                    default: break;
                                }
                                printf("\n      ------------------------------------------------------ \n");
                                printf("\n            NUMERO: %d", Etude.numero);
                                printf("\n            NOM ACTUEL : %s", Etude.nom);
                                printf("\n            PRENOM ACTUEL: %s", Etude.prenom);
                                printf("\n            FILIERE ACTUELLE : %s", Etude.Filiere);
                                printf("\n      ------------------------------------------------------ \n");

                            }
                        fprintf(fichier1, "%d   %s   %s   %s \n", Etude.numero, Etude.nom, Etude.prenom, Etude.Filiere);

                }while(!feof(fichier));
                    fclose(fichier);
                    fclose(fichier1);

                    remove("etudiant.txt");
                    rename("M_etudiant.txt", "etudiant.txt");
                    printf("\n\n         MODIFICATION REUSSIE        \n\n");

            }

            else
                printf("\n\n            MODIFICATION ANNULEE...     \n\n");


    }

    else printf("\n  NUMERO INVALIDE\n\n");

}



/*********************************************
*       FONCTION POUR LA SUPPRESSION
*********************************************/

void suppression_etudiant()
{
    int choix;

	/*********************************************
	*       AFFICHAGE DU MENU
	*********************************************/

    printf("\n\n                   ....................SUPPRESSION DES ETUDIANTS.................... \n\n");
    printf("                 1.EFFECTUER LA SUPPRESSION D'UN SEUL ETUDIANT \n");
    printf("                 2.EFFECTUER LA SUPPRESSION DE TOUT LES ETUDIANTS \n");

    printf("\n            - Entrer votre choix: ");
    scanf("%d", &choix);
    system("cls"); // Netttoie le terminal

    switch(choix)
    {
        case 1:  suppression_etudiant_individuel(); break;
        case 2:  suppression_tout_les_etudiants(); break;
         default:
            {
                printf("\n Valeur non pris en compte, reessayer... \n\n");
                break;
            }

    }

}




/********************************************
*	  FONCTION  DE SUPPRESSION D'ETUDIANT
*********************************************/


void suppression_etudiant_individuel()
{
     FILE *fichier, *fichier1;
    int numero_a_supprimer, i, reponse;

  // Demande du numero d'etudiant

  printf("\n Numero de l'etudiant a supprimer: ");
  scanf("%d",&numero_a_supprimer);
  fflush(stdin);

    if(recherche_etudiant(numero_a_supprimer) == 1){
        printf("\n Pour confirmer la suppression taper 1: ");
        scanf("%d",&reponse);

        // Si la reponse vaut 1 continuer sinon ne rien faire

        if(reponse == 1){

		// OUVERTURE DES DEUX FICHIERS

        fichier = fopen("etudiant.txt", "r");
        fichier1 = fopen("M_etudiant.txt", "a");

		  /*
		  *	 Dans cette boucle on lit le fichier etudiant.txt
		  *  et on copie tout dans M_etudiant sauf la  ligne
		  *  correspondant à l'etudiant à supprimer
		  */

			do{
                fscanf(fichier, "%d  %s  %s  %s \n", &Etude.numero, &Etude.nom, &Etude.prenom, &Etude.Filiere);

                if(numero_a_supprimer != Etude.numero){
                    fprintf(fichier1, "%d  %s  %s  %s \n", Etude.numero, Etude.nom, Etude.prenom, Etude.Filiere);
                }

            }while(!feof(fichier));

			// Fermeture des deux fichiers

            fclose(fichier);
            fclose(fichier1);

			/**
			* Supprime le fichier etudiant.txt
			* et renomme le fichier M_etudiant par etudiant.txt
			*/

            remove("etudiant.txt");
            rename("M_etudiant.txt", "etudiant.txt");

			printf("\n SUPPRESSION REUSSIE\n\n");

        }

            else printf("\n SUPPRESSION ANNULEE\n\n");


    }

    else  printf("\n NUMERO INVALIDE\n\n");
}




/*************************************************
*		SUPPRESSION  DE TOUS LES ETUDIANTS
**************************************************/
/*
* Il nous suffit juste de supprimer le fichier etudiant.txt*/
void suppression_tout_les_etudiants()
{
  int reponse;
  FILE *fichier = NULL;

     printf("\n Pour confirmer la suppression taper 1: ");
     scanf("%d",&reponse);
     if(reponse == 1){

         remove("etudiant.txt");
         printf("\n SUPPRESSION REUSSIE \n\n");

     }

}




/****************************************************
*			fonction d'affichage des etudiants
****************************************************/

void affichage_de_tout_les_etudiants()
{
    FILE* fichier = NULL;
    int caractereActuel = 0,counter = 0; // Creation d'un counter et initialisation à 0

    printf("\n\n        =========================================================================");
    printf("\n                          AFFICHAGE DES ENREGISTREMENT                 \n");
    printf("        =========================================================================");


    fichier = fopen("etudiant.txt", "r");

    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
            do{
                fscanf(fichier,"%d   %s   %s   %s \n", &Etude.numero, &Etude.nom, &Etude.prenom, &Etude.Filiere);
                    printf("\n\n          ---------------------------------------------------");
                    printf("\n          NUMERO: %d", Etude.numero);
                    printf("\n          NOM: %s", Etude.nom);
                    printf("\n          PRENOM: %s", Etude.prenom);
                    printf("\n          FILIERE: %s", Etude.Filiere);
                    printf("\n          ---------------------------------------------------");
                    printf("\n");

                 	// Incrementation du counter à chaque fois qu'on affiche un etudiant

				    counter++;

            }while(!feof(fichier));

            fclose(fichier);

        }
			/***Si a la fin le counter est toujours egale à zero ça veut dire qu'il n'ya pas d'enregistrement*/
            if(counter == 0) {
                printf("\n\n          DESOLE, AUCUN ENREGISTREMENT TROUVER.   \n\n");
            }
}




/*******************************************************
*			CALCUL  DES MOYENNNES
********************************************************/


void calcul_des_moyennes()
{

    int choix;

	/*******************************************************
	*			AFFICHE LE MENU
	********************************************************/
    printf("\n\n                   ....................CALCUL DES MOYENNES.................... \n\n");
    printf("                 1.MOYENNE D'UN SEUL ETUDIANT \n");
    printf("                 2.MOYENNE DE LA SALLE \n");
    printf("\n            -Entrer votre choix: ");
    scanf("%d", &choix);

    system("cls"); // Nettoie le terminal

    /*******************************************************
	*		Traitement en fonction du choix
	********************************************************/

    switch(choix){

		case 1:  moyenne_etudiant_individuel(); break;
        case 2:  moyenne_de_la_sale(); break;

        default:
            {
                printf("\n VALEUR NON PRISE EN COMPTE, REESSAYER... \n\n");
                break;
            }


    }

}





/**************************************************
*          FONCTION QUI CALCULE LA MOYENNE
***************************************************/

void moyenne_etudiant_individuel()
{
    int numero_recherche, montrerLesErreurs = 0, numero;
    float moyenne;
    char nom[100], prenom[100], filiere[100];
    FILE *fichier = NULL, *fichier1;

    fichier = fopen("etudiant.txt", "r"); //Ouvre le fichier etudiant.txt
    fichier1 = fopen("moyenne.txt", "a"); //Creer le fichier des moyennes

	/**********************************************************************
	*		REPETER CETTE ACTION TANT QUE ON A PAS D'ENREGISTREMENT
	***********************************************************************/
	do{

		if(montrerLesErreurs == 1) printf("\n Aucun Enregistrer ne correspond a cet numero \n");

	  	printf("\n Entrer le numero de l'etudiant (Entrer -1 pour quitter ): ");
    	scanf("%d", &numero_recherche);
    	montrerLesErreurs = 1; //Mettre montrer Les Erreurs a Vrai

	} while(recherche_etudiant(numero_recherche) != 1 && numero_recherche != -1);

		montrerLesErreurs = 0; //Mettre montrer les erreurs à false;

    if(fichier != NULL)
    {

        do{
        	/*Lit le fichier etudiants pour selectionner l'etudiant */

            fscanf(fichier,"%d   %s   %s   %s \n", &Etude.numero, &Etude.nom, &Etude.prenom, &Etude.Filiere);
            fflush(stdin);

            if(numero_recherche == Etude.numero){

                /*Declaration des variables et initialisation*/

				int i = 0, n, Scoef = 0, j = 0, nombreMatiere, coef;
                float note;
                Scoef = 0;

                /*Demande le nombre de matiere*/

				printf("\n Nombre de Matiere :   ");
                scanf("%d",&nombreMatiere);

					for(j = 0; j < nombreMatiere; j++){

						do{
                            if(montrerLesErreurs==1) printf("\n La note doit etre compris entre 0 et 20 ");
							printf("\n Entrer la %dieme note:   ", j + 1);
                            scanf("%f",&note);

                            montrerLesErreurs = 1; //Mettre Montrer les Erreurs à VRAI

                        }while(note < 0 || note > 20);
                        montrerLesErreurs = 0;

							/*Demande le coefficient de la jième matiere */
							do{

								if(montrerLesErreurs == 1 ) printf("\n Le coefficient doit etre superieur a 0 ");

								printf(" Coefficient :  ");
                            	scanf("%d",&coef);

								montrerLesErreurs = 1;

							}while(coef <= 0);

							montrerLesErreurs = 0;

                         	Etude.moyenne = Etude.moyenne + note*coef; // Somme cummulé des notes multiplié par les coefficients
                            Scoef = Scoef + coef; // Somme cumulé des coefficient

                    }
                        	Etude.moyenne = Etude.moyenne / (Scoef * 1.0); // Calcule de la moyenne
                        	fflush(stdin);

                        	fprintf(fichier1, "%d   %s   %s   %s   %f \n", Etude.numero, Etude.nom, Etude.prenom, Etude.Filiere,Etude.moyenne);

                            if(Etude.moyenne < 10){
                                printf("\n %s %s est RECALER avec une moyenne de: %.2f \n\n", Etude.nom, Etude.prenom,Etude.moyenne);
                            }else if(Etude.moyenne >=10  && Etude.moyenne < 12){
                                printf("\n %s %s est ADMIS avec une moyenne de: %.2f (MENTION PASSABLE) \n\n ",Etude.nom, Etude.prenom,Etude.moyenne);
                            }else if(Etude.moyenne >=12  && Etude.moyenne < 14){
                                printf("\n %s %s est ADMIS avec une moyenne de: %.2f (MENTION ASSEZ BIEN)\n\n ",Etude.nom, Etude.prenom,Etude.moyenne);
                            }else if(Etude.moyenne >=14  && Etude.moyenne < 15){
                                printf("\n %s %s est AMIS avec une moyenne de: %.2f (MENTION BIEN) \n\n",Etude.nom, Etude.prenom,Etude.moyenne);
                            } else if(Etude.moyenne >=15  && Etude.moyenne < 17) {
                                printf("\n %s %s est ADMIS avec une moyenne de: %.2f (MENTION TRES BIEN) \n\n",Etude.nom, Etude.prenom,Etude.moyenne);
                            }else{
                                printf("\n %s %s est AMIS avec une moyenne de: %.2f (MENTION EXCELENT) \n\n",Etude.nom, Etude.prenom,Etude.moyenne);
                            }




            }

        }while(!feof(fichier));
    }
	fclose(fichier);
	fclose(fichier1);
}



	/********************************************
	*			Moyenne de la salle
	*********************************************/

	void moyenne_de_la_sale(){
    int total_etudiant, i, montrerLesErreurs = 0;
    float note, moyenne = 0;

    printf("\n\n                   ....................MOYENNES DE LA SALLE.................... \n\n");
    printf("\n Entrer le nombre des etudiants:  ");
	scanf("%d",&total_etudiant);

    for(i = 0; i < total_etudiant; i++) {
        do{
			if(montrerLesErreurs == 1 ) printf("\n La note doit etre compris entre 0 et 20");
            printf("\n Donner la note de l'etudiant n%d:  ",i+1);
            scanf("%f",&note);
            montrerLesErreurs = 1;

        }while(note < 0 || note > 20);

        montrerLesErreurs = 0;

        moyenne = moyenne + note;

    }

	moyenne = moyenne/total_etudiant;
    printf("\n La moyenne de la classe est de %.2f/20\n\n", moyenne);
}






	/********************************************
	*			AFFICHAGE DES MOYENNES
	*********************************************/

void affichage_des_moyennes()
{
     int numero_recherche;
     FILE *fichier = NULL;
    int choix;

	/*******************************************************
	*			AFFICHE LE MENU
	********************************************************/
    do{

		printf("\n\n                   ....................AFFICHAGE DE LA MOYENNE.................... \n\n");
    	printf("                 1.MOYENNE D'UN SEUL ETUDIANT \n");
    	printf("                 2.MOYENNE DE TOUS LES ETUDIANTS \n");
    	printf("\n            - Entrer votre choix: ");
    	scanf("%d", &choix);
	}while(choix < 1 || choix > 2);

	/*******************************************************
	*			TRAITEMENT SELON LE CHOIX
	********************************************************/
	switch(choix){
		case 1 : {
			printf("\n Entrer le numero de l'Etudiant: ");
			scanf("%d", &numero_recherche);
			system("cls");

    		printf("\n\n        =========================================================================");
    		printf("\n                          AFFICHAGE DE La MOYENNE DE L'ETUDIANT N*: %d                 \n", numero_recherche);
    		printf("        =========================================================================");
    		fichier = fopen("moyenne.txt", "r");

    		if(fichier != NULL){
    	    	do{

            		fscanf(fichier,"%d   %s   %s   %s  %f \n", &Etude.numero, &Etude.nom, &Etude.prenom, &Etude.Filiere, &Etude.moyenne);
            		fflush(stdin);
            		if(numero_recherche == Etude.numero){
                 		printf("\n\n         ---------------------------------------------------");
                    	printf("\n          NUMERO: %d", Etude.numero);
                   	 	printf("\n          NOM: %s", Etude.nom);
                    	printf("\n          PRENOM: %s", Etude.prenom);
                    	printf("\n          FILIERE: %s", Etude.Filiere);
                    	printf("\n          MOYENNE: %.2f", Etude.moyenne);
                    	printf("\n          ---------------------------------------------------");
                    	printf("\n");
            		}

      			}while(!feof(fichier));

    		}fclose(fichier);

			break;
		}
		case 2: {
			printf("\n\n        =========================================================================");
    		printf("\n                          AFFICHAGE DES MOYENNES                \n");
    		printf("        =========================================================================");
    		fichier = fopen("moyenne.txt", "r");

    		if(fichier != NULL){
    	    	do{

            		fscanf(fichier,"%d   %s   %s   %s  %f \n", &Etude.numero, &Etude.nom, &Etude.prenom, &Etude.Filiere, &Etude.moyenne);
            		fflush(stdin);

                 		printf("\n\n         ---------------------------------------------------");
                    	printf("\n          NUMERO: %d", Etude.numero);
                   	 	printf("\n          NOM: %s", Etude.nom);
                    	printf("\n          PRENOM: %s", Etude.prenom);
                    	printf("\n          FILIERE: %s", Etude.Filiere);
						printf("\n          MOYENNE: %.2f", Etude.moyenne);
                    	printf("\n          ---------------------------------------------------");
                    	printf("\n");


      			}while(!feof(fichier));

    		}fclose(fichier);
			break;
		}
	}



}

