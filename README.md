
## Projet NEMM Bank 
By
**N**olan Cacheux
**E**liott Peres
**M**ilo Montuori
**M**atthieu Host

  
---


**Le dossier `out` est important !**

Il ne possède pas les exécutables et ses dépendances, mais les fichiers JSON "de base" permettant l'utilisation de la banque.

Dans ces derniers se trouvent les informations des clients (qui pourront être ajouté graphiquement) mais pour une utilisation simplifiée, la présence de client, de compte et d'opération est nécessaire (i.e : le JSON nommé `data.json` correspond à la Banque n°1 et possède le plus d'information pour permettre les tests.)



# Le lancer
Pour lancer le projet, il suffit de lancer le start.cpp à la racine du projet. De ce fait, et d'après les fichiers CMake, tous les exécutables nécessaires seront créer pour le bon fonctionnement.

  
# Actuellement
Tout fonctionne avec différentes banques, la récupération des opérations toutes les 10 secs, l'utilisation de thread pour gérer la banque centrale, les virements sont égalements fonctionnels (en interne et entre 2 banques)...
