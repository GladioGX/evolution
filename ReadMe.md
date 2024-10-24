# Evolution

## Description
`Evolution` est un programme de simulation où vous gérez des spécimens dans un environnement en constante évolution. Le jeu vous permet de créer, observer, interagir et éliminer des spécimens tout en réagissant aux événements aléatoires.

## Fonctionnalités
- **Créer des spécimens** : Ajoutez de nouveaux spécimens à votre troupe.
- **Détruire des spécimens** : Supprimez des spécimens individuellement ou par groupes.
- **Observer les spécimens** : Consultez l’état de chaque spécimen (vivant ou mort).
- **Événements aléatoires** : Chaque jour, des événements peuvent affecter vos spécimens.
- **Recommencer une partie** : Remettez à zéro et relancez la simulation.
- **Nourrire les spécimens** : 
- **Créer des spécimens**

## Structure du code
- **`main.cpp`** : Fichier principal où est gérée la logique du jeu.
- **`event.h`** : Gestion des événements aléatoires affectant les spécimens.
- **`color.h`** : Gestion des couleurs affichées sur le terminal.

## Compilation et Exécution
### Prérequis
- Un compilateur C++ compatible (ex. : `g++` dans MSYS2 ou MinGW).

### Instructions
1. Clonez le dépôt ou téléchargez les fichiers.
2. Compilez le fichier principal :

   ```bash
   g++ main.cpp -o Evolution
    ```

   Exécutez le programme :

   ```bash
   ./Evolution
   ```

Auteur
   ```
   Hector Hamelin, Enzo Tsangouabeka
   ```