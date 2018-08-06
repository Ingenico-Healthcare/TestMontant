/*---------------------------------------------------------------------------
 PROJET     : Couche de portabilite multi-systeme
 
 PLATE-FORME: LINUX
 
 MODULE     : Definition des macros et des types utilises par la couche 
              d'abstraction systeme pour la plate-forme LINUX.
              
              Le fichier de definition des types portable (ce fichier) doit 
              etre inclus avant tout autre .h de definitions d'APIS gip-cps. 
              Ce fichier definit tous les types et macros dependants du 
              systeme. 

 FICHIER    : common\linux\src\linuxdef.h

 VERSION    : 1.00
 
 DATE       : 10/01/2001
 
 AUTEUR     : ALVARO ROCHA
 
-----------------------------------------------------------------------------
-----------------------------------------------------------------------------
 Modifications:  (nouvelle version, date, auteur, explication)
 ...

 - V4.31 - AROC le 12/02/2001 :
      Ajout des #define TRUE et FALSE ainsi que le typedef int BOOLEEN
-----------------------------------------------------------------------------
---------------------------------------------------------------------------*/


#ifndef __CPSCASDF_H
#define __CPSCASDF_H

/*----------------- definition des macros portables ------------------------*/

/* point d'entree exporte en DLL ?????????????????????????????????????????  */
#define API_ENTRY /* pour l'instant */

#define far
#define FAR

#define PTR *

#define PVOID void PTR
#define FARPTR PTR
#define FPVOID void FARPTR

/* AROC 12/02/2001 debut : */
#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif
/* AROC 12/02/2001 fin */

/*----------------- definition des types portables ------------------------*/

/* AROC 12/02/2001 debut : */
typedef int BOOLEEN;
/* AROC 12/02/2001 fin */

typedef char CHAR;
typedef CHAR PTR PCHAR;

typedef CHAR PTR PSTRG; 

typedef unsigned char UCHAR;
typedef UCHAR PTR PUCHAR;

typedef char INT8;
typedef short INT16;
typedef long INT32;

typedef INT8 PTR PINT8;
typedef INT16 PTR PINT16;
typedef INT32 PTR PINT32;

typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned long UINT32;

typedef UINT8 PTR PUINT8;
typedef UINT16 PTR PUINT16;
typedef UINT32 PTR PUINT32;

/* 11/02/1997 : Ajout DRE pour CPSCAS */
typedef void VOID;
typedef char PTR PSTR;
/* 11/02/1997 : Fin */

typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef unsigned char BYTE;
typedef BYTE far * LPBYTE;

#define Unref( a) a=a

#ifndef min
#define min(a,b) ((a)>(b)?(b):(a))
#endif

#ifndef max
#define max(a,b) ((a)<(b)?(b):(a))
#endif
#endif
