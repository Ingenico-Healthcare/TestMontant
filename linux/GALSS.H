/***************************************************************************
                                GAL.H

PROJET      : Carte de Professionnel de Sante

MODULE      : GAL

DESCRIPTION : definitions des prototypes du Gestionnaire d'Acces au Lecteur

AUTEUR(s)   : Didier RENAULD    ( ILEX )

CREATION    : 09/09/1996 - DREN


****************************************************************************
REVISIONS   :
% --------------------------------------------------------------------------
% Version 1.30
%
% DRE - 28/02/97 - Ajout de l'API LireVersion() et de la structure
%           IdentProtocole
%
% --------------------------------------------------------------------------
% Version 2.00
%
% DRE - 01/12/98 - Changement de la structure IdentProtocole en
%	IdentComposant.
%
****************************************************************************/

#include "linuxdef.h"

#ifndef _GAL_H
#define _GAL_H

/***************************************************************************
                            Inclusions
****************************************************************************/

/***************************************************************************
                            Divers
****************************************************************************/
                                  
/***************************************************************************
                Definitions des prototypes des fonctions publiques
****************************************************************************/

#ifndef GAL_ENTRY
#define GAL_ENTRY UINT16 API_ENTRY
#endif

extern GAL_ENTRY OuvrirSession      ( char          FARPTR      pcNomApplication,
                                    char            FARPTR      pcNomRessource,
                                    unsigned short  FARPTR      pusNumSession,
                                    unsigned char   FARPTR      pusNumRessource);

extern GAL_ENTRY FermerSession      ( unsigned short            usNumSession,
                                    unsigned short  FARPTR      pusNumExclusivite );

extern GAL_ENTRY DebutExclusivite   ( char          FARPTR      pcQuestion,
                                    char            FARPTR      pcNomApplication,
                                    char            FARPTR      pcNomRessource,
                                    unsigned short  FARPTR      pusNumExclusivite);

extern GAL_ENTRY FinExclusivite     ( unsigned short            usNumExclusivite);

extern GAL_ENTRY EcritContexte      ( unsigned short            usOrdre,
                                    unsigned short              usNumSession,
                                    void            FARPTR      pvfContexte,
                                    unsigned short  FARPTR      pusTailleCtx);

extern GAL_ENTRY LitContexte        ( unsigned short            usOrdre,
                                    unsigned short              usNumSession,
                                    void            FARPTR      pvfContexte,
                                    unsigned short  FARPTR      pusTailleCtx);

extern GAL_ENTRY usDump             ( unsigned short            usOrdre,
                                    unsigned short              usNumSession,
                                    unsigned short  FARPTR      pusIndexBloc,
                                    unsigned short  FARPTR      pusLgBloc,
                                    void            FARPTR      pvfBloc);

extern GAL_ENTRY Echange            ( unsigned short            usNumSession,
                                    unsigned short              usTempsExe,
                                    char            FARPTR      Message,
                                    unsigned long   FARPTR      TailleBuff,
                                    char            FARPTR      MsgReponse,
                                    unsigned long   FARPTR      TailleReponse);

/* %v1.30 DRE 28/02/1997 : ajout de l'API LireVersion et la structure associee */

#define         VERSION_SIZE        4
typedef struct {
/* %v2.00 01/12/1998 DRE : version de tous les composants GALSS
    unsigned long       TypeProtocole;
*/
    unsigned long       TypeComposant;
    char                AscVersion[VERSION_SIZE];
/* %v2.00 01/12/1998 DRE : version de tous les composants GALSS
} IdentProtocole;
*/
} IdentComposant;
extern GAL_ENTRY LireVersion        ( char          FARPTR      VersionGALSS,
                                    unsigned short  FARPTR      pusNbComposants,
                                    IdentComposant  FARPTR      pComposants);

/* %v2.00 23/12/1998 DRE : Definition des identifiants des composants */
#define IDENT_PSS		0
#define IDENT_GALSSSRV	100
#define IDENT_GALSSCLI	101
#define IDENT_GALSSINF	102
/* %v2.00 23/12/1998 DRE :Fin */

#endif

