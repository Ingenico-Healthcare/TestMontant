/*
 % -------------------------------------------------------------------
 % GIE SESAM-VITALE & GIP "CPS"
 %
 % PROJET   : GALSS
 %
 % FICHIER  : galsserr.h
 %
 % Codes des erreurs retournées par le GALSS.
 % -------------------------------------------------------------------
 */

#ifndef __GALSSERR_H_VU__
#define __GALSSERR_H_VU__


/*
 * Définition des codes d'erreurs
 * ------------------------------
 */

/* Erreurs générales. */
#define G_NOERROR		 0x0000 /* Pas d'erreur.                             */
#define G_ERRLOG		 0x0001 /* Erreur interne du GALSS.                  */
#define G_ERRDIM		 0x0002 /* Plus de numéro de session ou exclusivité. */
#define G_ERREXCL		 0x0004 /* Ressource prise en exclusivité.           */
#define G_ERRCMD		 0x0008 /* Enchaînement de commandes incorrect.      */
#define G_ERRTAILLE		 0x0010 /* Taille du buffer de sortie insuffisante.  */
#define G_ERRCTX		 0x0020 /* Pas de bloc ou de données de contexte.    */
#define G_ERRABMAT		 0x0040 /* Abandon de l'échange par l'exécutant.     */
#define G_ERRABSTA		 0x0080 /* Abandon de l'échange par l'initiateur.    */
#define G_ERRTEMPS		 0x0100 /* Temps maximal de traitement dépassé.      */
#define G_ERRTRANS		 0x0200 /* Erreur de transmission sur port physique. */
#define G_ERRTIMOUT		 0x0400 /* Pas de réponse de l'exécutant.            */
#define G_ERROUVERT		 0x0800 /* Session déjà ouverte pour cette ressource.*/
#define G_ERREXIST		 0x1000 /* Numéro de session inconnu.                */
#define G_ERRRESS		 0x2000 /* Nom de ressource non défini.              */
#define G_ERRPARAM		 0x4000 /* Erreur dans les paramètres d'appel.       */

/* Erreurs de configuration. */
#define G_ERRRMI         0x8000 /* Erreur de comm client-serveur (en Java).  */
#define G_ERRFICHIERINI  0x8001 /* Fichier de configuration non trouvé.      */
#define G_ERRGALSSSRV	 0x8002 /* Erreur au démarrage du GALSS serveur.     */
#define G_ERRDIMTABLES	 0x8003 /* Nombre de ressources trop important.      */
#define G_ERRNOPROT      0x8004 /* Rubrique Protocole absente.               */
#define G_ERRBADPROT     0x8005 /* Numéro de protocole invalide.             */
#define G_ERRLOADLIBPRO  0x8006 /* Erreur au chargement lib/classe protocole.*/
#define G_ERRNOINDEX     0x8007 /* TCanal ou Index absent ou incorrect.      */
#define G_ERRPROINIT     0x800A /* Erreur à l'initialisation d'un protocole. */
#define G_ERRPROCNX      0x800C /* Erreur à la connexion d'un canal.         */
#define G_ERRNONBCANAUX  0x800D /* Rubrique NbCanaux absente.                */
#define G_ERRCOMPAT      0x800E	/* Incompatibilité entre les composants.     */
#define G_ERRBADPAD      0x800F /* Rubrique PAD absente ou incorrecte.       */
#define G_ERRBADLAD      0x8010 /* Rubrique LAD absente ou incorrecte.       */
#define G_ERRBADNAME     0x8011 /* NomLAD ou NomAliasn absent ou incorrect.  */
#define G_ERRPRODCNX     0x8012 /* Erreur à la déconnexion d'un canal.       */
#define G_ERRPROTERM     0x8013 /* Erreur à la terminaison d'un protocole.   */
#define G_ERRLOADFUNCPRO 0x8014 /* Erreur à l'instanciation d'un protocole.  */

#endif

/*
 % -------------------------------------------------------------------
 % Fin du fichier galsserr.h
 % -------------------------------------------------------------------
 */
