/**
  ******************************************************************************
  * @file    testMontant.c
  * @author  Ingenico Healthcare
  * @version V01.01
  * @date    06/08/2018
  ******************************************************************************
  * @copy 
  *
  * THE PRESENT CODE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, INGENICO HEALTHCARE SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH CODE AND/OR THE USE MADE BY CUSTOMERS OF THE 
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2018 Ingenico Healthcare</center></h2>
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "galss.h"
#include "galsserr.h"

#define LG_STRING		255
#define NUMVERSION		"01.01"
#define TAILLE_BUFFER	1024
#define TMAX			65535

/* Message OP : Injection de montant */
char message_injection_montant[] = {
	0xff, /* Domaine commun */
	0x01, /* Destinataire : Telium Manager */
	0x0a, /* Demande d'encaissement par CB */
	0x30, /* Début du montant sur 8 caractères */
	0x30, 
	0x30,
	0x30,
	0x30,
	0x31,
	0x32,
	0x33, /* Fin du montant sur 8 caractères */
	'E',  /* Début nom monnaie sur 3 caractères */
	'U',
	'R',  /* Fin nom monnaie sur 3 caractères */
	0x39, /* Début code monnaie sur 3 digits */
	0x37,
	0x38 /* Fin code monnaie sur 3 digits */
};	

int main(int argc, char* argv[])
{
	unsigned short cr;
	unsigned short i;
	int code=0;
	int fin=0;
	unsigned short NumSession;
	unsigned char NumRessource;
	char application[LG_STRING];
	char ressource[LG_STRING];
	char chaine[LG_STRING];
	unsigned short NumExclusivite;
	char reponse[TAILLE_BUFFER];
	unsigned long longMessage=3;
	unsigned long longReponse;
	unsigned char isSessionOpened = 0;
	unsigned char isMutexed = 0;

	printf("\n\n*******************************\n");
	printf("*      Application de test    *\n");
	printf("*      d'envoi du montant     *\n");
	printf("*           v. %s          *\n", NUMVERSION);
	printf("*      Ingenico Healthcare    *\n");
	printf("*******************************\n\n");

	// Ouverture de la session GALSS "CPS"
	printf("***************************\n");
	printf("*  Ouverture session CPS  *\n");
	printf("***************************\n");
	cr = OuvrirSession("TESTGALS", "CPS", &NumSession, &NumRessource);
	if (cr==G_NOERROR)
	{
		printf("Session ouverte avec succes\n");
		printf("Numero de session   : %u\n", NumSession);
		printf("Numero de ressource : %x\n\n", NumRessource);
		isSessionOpened = 1;
	}
	else
	{
		printf("\n/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\ \n");
		printf("Erreur ouverture session : 0x%04X\n\n", cr);
		printf("/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\ \n\n");
	}

	// Pose d'une exclusivité sur la ressource CPS
	if (cr==G_NOERROR)
	{
		printf("***************************\n");
		printf("*  Prise exclusivite CPS  *\n");
		printf("***************************\n");
		
		sprintf_s(chaine, sizeof(chaine), "%u:1", NumSession);
		cr = DebutExclusivite(chaine, application, ressource, &NumExclusivite);

		if (cr==G_NOERROR)
		{
			printf("Exclusivite prise avec succes\n");
			printf("Numero de l'exclusivite : %u\n\n", NumExclusivite);
			isMutexed = 1;
		}
		else
		{
			printf("\n/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\ \n");
			printf("Erreur prise exclusivite : 0x%04X\n\n", cr);
			printf("/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\ \n\n");
		}
	}

	if (cr==G_NOERROR)
	{
		printf("***************************\n");
		printf("*  Envoi du montant       *\n");
		printf("***************************\n");
		
		longMessage = sizeof(message_injection_montant);
		longReponse=TAILLE_BUFFER;
		memset(reponse, 0, TAILLE_BUFFER);
		cr = Echange(NumSession, TMAX, message_injection_montant, &longMessage, reponse, &longReponse);

		if ((cr == G_NOERROR)/* && (longReponse > 0)*/)
		{
			printf("Montant envoye avec succes\n");
			printf("Reponse du terminal : %lu octets\n", longReponse);
			for (i=0; i<longReponse; i++)
			{
				printf("0x%02X",(unsigned char)(reponse[i]));
				if (i<longReponse-1)
					printf(" ");
			}

			if(reponse[0] == 0x32)
			{
				if(reponse[1] == 0x20)
				{
					printf(" => paiement KO");
				}
				else if(reponse[0] == 0x00)
				{
					printf(" => paiement OK");
				}
				else
				{
					printf(" => code inconnu");
				}
			}
			else
			{
				printf(" => code inconnu");
			}

			printf("\n\n");
		}
		else
		{
			printf("\n/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\ \n");
			printf("Erreur envoi du montant : 0x%04X\n\n", cr);
			printf("/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\ \n\n");
		}
	}

	// Levee de l'exclusivite sur la CPS
	if (isMutexed)
	{
		printf("***************************\n");
		printf("*  Levee exclusivite CPS  *\n");
		printf("***************************\n");
		cr = FinExclusivite(NumExclusivite);
		if (cr==G_NOERROR)
		{
			printf("Exclusivite levee avec succes\n\n");			
		}
		else
		{
			printf("\n/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\ \n");
			printf("Erreur levée exclusivité : 0x%04X\n\n", cr);
			printf("/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\ \n\n");
		}		
	}

	// Fermeture de la session
	if (isSessionOpened)
	{
		printf("***************************\n");
		printf("*  Fermeture session CPS  *\n");
		printf("***************************\n");
		cr = FermerSession(NumSession, &NumExclusivite);
		if (cr==G_NOERROR)
		{
			printf("Session fermee avec succes\n\n");			
		}
		else
		{
			printf("\n/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\ \n");
			printf("Erreur fermeture session : 0x%04X\n\n", cr);
			printf("/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\ \n\n");
		}		
	}
	
	return 0;
}
