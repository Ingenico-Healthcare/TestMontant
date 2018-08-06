# TestMontant
L’objectif de cette application de test est de démontrer les interfaces que peut mettre en oeuvre un Logiciel Professionnel de Santé (LPS) et les applications de paiement sur un terminal Ingenico Healthcare.

Ces échanges permettent au LPS de :
· transmettre une demande de paiement au terminal Ingenico Healthcare,
· récupérer l’état de la transaction bancaire.

## Spécifications

### Protocole d'échange
Les échanges s'appuient sur le Protocole Santé Social (PSS) et sur le Gestionnaire d'Accès Lecteur Santé Social (GALSS).
Ce protocole fonctionne dans un mode de type « question / réponse » : l’initiateur de la requête (LPS) émet une commande vers un  destinataire (terminal) qui la traite et renvoie la réponse.

#### Ordre "Demande d'encaissement par Carte Bancaire"

| Libellé      |     Nb. car.    |   Type car. |   Valeur |
| :--- |:--- | :--- | :---|
| Domaine commun     |        1        |      B |0xFF |
| Destinataire applicatif        |        1        |      B |0x01 |
| Code fonction "Demande d’encaissement par carte bancaire"     |        1        |      B |0x0A |
| Montant transaction en centimes   |        8        |      A |~ |
| Nom monnaie   |        3        |      A | EUR|
| Code monnaie   |        3        |      N |978 |

#### Réponse "Demande d'encaissement par Carte Bancaire"

| Libellé      |     Nb. car.    |   Type car. |   Valeur |
| :--- |:--- | :--- | :---|
| Nature du message     |        1        |      B |0x32 |
| Code réponse     |        1        |      B | 0x00 Transaction aboutie <br> 0x20 Transaction non aboutie|

#### Convention

| Libellé      |     Nb. car.    |
| :--- |:--- |
| A     |        Alphanumérique ASCII (0x20 à 0x7F)        |
| B     |        Binaire        |
| N     |        Numérique ASCII (0x30 à 0x39)        |
| ~     |        Valeur quelconque comprise dans la gamme autorisée<br>Ex : 0x30 0x30 0x30 0x30 0x30 0x31 0x32 0x33        |

## Pré-requis
Les instructions ci-dessous permettent de mettre en oeuvre rapidement une chaîne de test permettant d'envoyer un montant vers un terminal Ingenico Healthcare et de réaliser un paiement.

### Installation
Tout d'abord il est nécessaire d'installer sur le poste de travail les éléments suivants (récupérables auprès du marketing d'Ingenico Healthcare) : 
- Driver Ingenico Healthcare,
- Driver Filtre Injection Montant,
- GALSS.

### Configuration GALSS.ini
Le fichier GALSS.ini doit contenir à minima les éléments ci-dessous : 

```
[PROTOCOLE0]
Config=1000,1,15000
TempoInit=1,200,1000
NomLib=PSSINW32.DLL

[CONFIG]
NbCanaux=1

[CANAL1]
TCanal=1
; Numero du port COM a modifier en fonction de la configuration
Index=8
Protocole=0
Caracteristiques=9600,1,8,0,0
NbPAD=1

[CANAL1.PAD1]
PAD=2
NbLAD=3

[CANAL1.PAD1.LAD1]
LAD=1
NomLAD=CPS
NbAlias=1
NomAlias1=TRANSPA1

[CANAL1.PAD1.LAD2]
LAD=0
NomLAD=Log_SV
NbAlias=0

[CANAL1.PAD1.LAD3]
LAD=2
NomLAD=Vitale
NbAlias=1
NomAlias1=TRANSPA2
```

### Branchement Terminal
Le terminal doit être appairé avec son socle (voir cinématiques en fonction du produit).
Le socle doit être alimenté et branché en USB sur le poste de travail.
Une fois tout installé, le terminal apparait comme un Lecteur Sesam-Vitale avec un port COM définit.

## Exécution
L'outil se lance en ligne de commande (commande "tetMontant.exe") et affiche le résultat dans la fenêtre système dans laquelle il est lancé.

L'outil effectue les opérations suivantes : 
- Ouverture d'une session GALSS sur la ressource "CPS",
- Pose d'une exclusivité sur la session,
- Envoi du montant de 1,23 € au terminal,
- Levée de l'exclusivité,
- Fermeture de la session GALSS.

## Limitations
L'application de test ne fonctionne qu'avec un GALSS 32 bits.
