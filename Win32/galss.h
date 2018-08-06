/*
 % -------------------------------------------------------------------
 % GIE SESAM-VITALE & GIP "CPS"
 %
 % PROJET   : GALSS
 %
 % FICHIER  : galss.h
 %
 % Déclarations des prototypes de fonctions du GALSS.
 % -------------------------------------------------------------------
 */

#ifndef __GALSS_H_VU__
#define __GALSS_H_VU__

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Inclusions
 * ----------
 */

#include "sys_dep.h"
#include "galsserr.h"


/*
 * Définitions des constantes
 * --------------------------
 */

/* Niveaux d'exclusivité. */
#define EXCLUSIVITE_CANAL	1
#define EXCLUSIVITE_PAD		2
#define EXCLUSIVITE_LAD		3

/* Lieu de stockage du contexte applicatif. */
#define CONTEXTE_SESSION	1 /* Stockage au niveau de la session.   */
#define CONTEXTE_RESSOURCE	2 /* Stockage au niveau de la ressource. */

/* Type de canal. */
#define PSS_PORT_SERIE		1
#define PRO_AUTRE_CANAL		3

/* Taille maximal d'un nom. */
#define LONGUEUR_APPLI		16 /* Taille du nom d'une application.   */
#define LONGUEUR_RESS		8  /* Taille du nom d'une ressource.     */

/* Numéro des composants du GALSS. */
#define IDENT_PSS			0   /* PSS.                              */
#define IDENT_GALSSINF		100 /* GALSS Information.                */
#define IDENT_GALSSCLI		101 /* GALSS Client.                     */
#define IDENT_GALSSSRV		102 /* GALSS Serveur.                    */


/*
 * Définitions des structures publiques
 * ------------------------------------
 */

/* Structure d'information sur la version du protocole. */
#define VERSION_SIZE	4
typedef struct 
{
    unsigned long   TypeComposant;
    char            AscVersion[VERSION_SIZE];
} IdentComposant;


#pragma pack(1)

/* Structures des blocs renvoyés par la fonction Dump. */

/* Canal */
typedef struct  
{
    unsigned char   Type;           /* Type du port physique.         */
    char            Index[40];      /* Nom du port physique.          */
    unsigned short  TypeConnexion;  /* Inutilisé. Toujours 1.         */
    unsigned short  Protocole;      /* Numéro du protocole.           */
    unsigned short  NumExclusivite; /* 1 si le canal est verrouillé,
                                       0 sinon                        */
    unsigned short  FlagEtat;       /* Inutilisé.                     */
    unsigned char   Reserve[41];    /* Inutilisé.                     */
} StructCanal;                 

/* PAD */
typedef struct 
{
    unsigned char   Adresse;        /* Numéro du PAD sur le canal.    */
    unsigned short  NumExclusivite; /* Inutilisé. Toujours 0.         */
    unsigned char   Reserve[41];    /* Inutilisé.                     */
} StructPAD;

/* LAD */
typedef struct 
{
    unsigned char   Adresse;        /* Numéro du LAD sur le PAD.      */
    unsigned short  NumExclusivite; /* 1 si il y a une exclusivité,
                                       0 sinon                        */
    void*           hFicContexte;   /* Inutilisé. Toujours NULL.      */
    unsigned short  TailleCtx;      /* Inutilisé. Toujours 0.         */
    unsigned short  FlagEtat;       /* Inutilisé. Toujours 0.         */
    unsigned char   Reserve[39];    /* Inutilisé.                     */
} StructLAD;

/* Alias */
typedef struct 
{
    unsigned short  NumAlias;        /* Numéro d'ordre. 0 = original. */
    char        Nom[LONGUEUR_RESS+1];/* Valeur de l'alias.            */
} StructAlias;

#pragma pack ()



/*
 * Déclarations des fonctions publiques
 * ------------------------------------
 */

/* Ouverture d'une session. */
extern unsigned short API_ENTRY
OuvrirSession     (const char     FARPTR pcNomApplication,
				   const char     FARPTR pcNomRessource,
				   unsigned short FARPTR pusNumSession,
				   unsigned char  FARPTR pucNumRessource);

/* Fermeture d'une session. */
extern unsigned short API_ENTRY
FermerSession	  (unsigned short        usNumSession,
				   unsigned short FARPTR pusNumExclusivite);

/* Pose d'une exclusivité sur une ou plusieurs ressources. */
extern unsigned short API_ENTRY
DebutExclusivite  (const char     FARPTR pcListeRessources,
				   char           FARPTR pcNomApplication,
				   char           FARPTR pcNomRessource,
				   unsigned short FARPTR pusNumExclusivite);

/* Suppression de l'exclusivité posée par une application. */
extern unsigned short API_ENTRY
FinExclusivite    (unsigned short        usNumExclusivite);

/* Sauvegarde de données applicatives. */
extern unsigned short API_ENTRY
EcritContexte     (unsigned short        usLieu,
				   unsigned short        usNumSession,
				   const void     FARPTR pvContexte,
				   const unsigned short FARPTR pusTailleContexte);

/* Récupération de données applicatives. */
extern unsigned short API_ENTRY
LitContexte       (unsigned short        usLieu,
				   unsigned short        usNumSession,
				   void           FARPTR pvContexte,
				   unsigned short FARPTR pusTailleContexte);

/* Echange d'une requète avec un lecteur. */
extern unsigned short API_ENTRY
Echange           (unsigned short        usNumSession,
				   unsigned short        usTMax,
				   const char     FARPTR pcMessage,
				   const unsigned long FARPTR pulTailleMessage,
				   char           FARPTR pcReponse,
				   unsigned long  FARPTR pulTailleReponse);

/* Versions du GALSS et des protocoles chargés. */
extern unsigned short API_ENTRY
LireVersion       (char            FARPTR pcVersionGalss,
				   unsigned short  FARPTR pusNbComposants,
				   IdentComposant  FARPTR pVersionsComposants);

/* Dump de la table des ressources et des sessions. */
/* Fonction conservée pour compatibilité ascendante. */
extern unsigned short API_ENTRY
usDump            (unsigned short         usTable,
				   unsigned short         usNumSession,
				   unsigned short  FARPTR pusIndexBloc,
				   unsigned short  FARPTR pusTailleBloc,
				   void            FARPTR pvBloc);

#ifdef __cplusplus
}
#endif

#endif

/*
 % -------------------------------------------------------------------
 % Fin du fichier galss.h
 % -------------------------------------------------------------------
 */
