/*
 % -------------------------------------------------------------------
 % GIE SESAM-VITALE & GIP "CPS"
 %
 % PROJET   : GALSS
 %
 % FICHIER  : galsserr.h
 %
 % Codes des erreurs retourn�es par le GALSS.
 % -------------------------------------------------------------------
 */

#ifndef __GALSSERR_H_VU__
#define __GALSSERR_H_VU__


/*
 * D�finition des codes d'erreurs
 * ------------------------------
 */

/* Erreurs g�n�rales. */
#define G_NOERROR		 0x0000 /* Pas d'erreur.                             */
#define G_ERRLOG		 0x0001 /* Erreur interne du GALSS.                  */
#define G_ERRDIM		 0x0002 /* Plus de num�ro de session ou exclusivit�. */
#define G_ERREXCL		 0x0004 /* Ressource prise en exclusivit�.           */
#define G_ERRCMD		 0x0008 /* Encha�nement de commandes incorrect.      */
#define G_ERRTAILLE		 0x0010 /* Taille du buffer de sortie insuffisante.  */
#define G_ERRCTX		 0x0020 /* Pas de bloc ou de donn�es de contexte.    */
#define G_ERRABMAT		 0x0040 /* Abandon de l'�change par l'ex�cutant.     */
#define G_ERRABSTA		 0x0080 /* Abandon de l'�change par l'initiateur.    */
#define G_ERRTEMPS		 0x0100 /* Temps maximal de traitement d�pass�.      */
#define G_ERRTRANS		 0x0200 /* Erreur de transmission sur port physique. */
#define G_ERRTIMOUT		 0x0400 /* Pas de r�ponse de l'ex�cutant.            */
#define G_ERROUVERT		 0x0800 /* Session d�j� ouverte pour cette ressource.*/
#define G_ERREXIST		 0x1000 /* Num�ro de session inconnu.                */
#define G_ERRRESS		 0x2000 /* Nom de ressource non d�fini.              */
#define G_ERRPARAM		 0x4000 /* Erreur dans les param�tres d'appel.       */

/* Erreurs de configuration. */
#define G_ERRRMI         0x8000 /* Erreur de comm client-serveur (en Java).  */
#define G_ERRFICHIERINI  0x8001 /* Fichier de configuration non trouv�.      */
#define G_ERRGALSSSRV	 0x8002 /* Erreur au d�marrage du GALSS serveur.     */
#define G_ERRDIMTABLES	 0x8003 /* Nombre de ressources trop important.      */
#define G_ERRNOPROT      0x8004 /* Rubrique Protocole absente.               */
#define G_ERRBADPROT     0x8005 /* Num�ro de protocole invalide.             */
#define G_ERRLOADLIBPRO  0x8006 /* Erreur au chargement lib/classe protocole.*/
#define G_ERRNOINDEX     0x8007 /* TCanal ou Index absent ou incorrect.      */
#define G_ERRPROINIT     0x800A /* Erreur � l'initialisation d'un protocole. */
#define G_ERRPROCNX      0x800C /* Erreur � la connexion d'un canal.         */
#define G_ERRNONBCANAUX  0x800D /* Rubrique NbCanaux absente.                */
#define G_ERRCOMPAT      0x800E	/* Incompatibilit� entre les composants.     */
#define G_ERRBADPAD      0x800F /* Rubrique PAD absente ou incorrecte.       */
#define G_ERRBADLAD      0x8010 /* Rubrique LAD absente ou incorrecte.       */
#define G_ERRBADNAME     0x8011 /* NomLAD ou NomAliasn absent ou incorrect.  */
#define G_ERRPRODCNX     0x8012 /* Erreur � la d�connexion d'un canal.       */
#define G_ERRPROTERM     0x8013 /* Erreur � la terminaison d'un protocole.   */
#define G_ERRLOADFUNCPRO 0x8014 /* Erreur � l'instanciation d'un protocole.  */

#endif

/*
 % -------------------------------------------------------------------
 % Fin du fichier galsserr.h
 % -------------------------------------------------------------------
 */
