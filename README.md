# Le Projet final de INF1015
Voici notre projet final, nous sommes Kasra Rahimi 2118712 & Imane Rezki 2118881.

## librairie
D'abord, on a un dossier pour la librairie. Ne pas toucher les dossiers *lib_dir/build* et *lib_dir/target*. Ce sont des dossiers de compilation. Pour compiler la librairie, il faut tout simplement faire ``make``. Pour supprimer les fichiers de compilation, executer la commande ``make clean``.

## l'exécutable
Le fichier ``main.cpp`` se trouve dans *exec_dir*. Pour compiler l'exécutable, il faut juste faire ``make``. Pour simplifier l'exécution, vous pouvez faire ``make run``. Ce dernier va compiler l'exécutable et ensuite l'exécuter. Pour que la compiliation se fasse avec succès, il faut d'abord que la libraire soit compilée. Pour cela, il faut faire un ``make`` lorsque vous vous trouvez dans le dossier *./lib_dir*.

## Windows
Idéalement, ce projet se compile sur un système avec linux ou macOS. Par contre, il est toujours possible de compiler ce projet sur windows. D'abord, il faut s'assurer que votre système permet l'utilisation des Makefiles. Essayez de compiler le projet en suivant les instructions données ci dessus. Ensuite, si la compilation ne fonctionne pas, il faut changer les lignes suivantes du Makefile dans *./lib_dir*:
* 22 - ``mkdir -p $(TRG_DIR)`` -> ``if not exist "$(TRG_DIR)" md $(TRG_DIR)``
* 27 - ``mkdir -p $(BLD_DIR)`` -> ``if not exist "$(BLD_DIR)" md $(BLD_DIR)``

Ensuite, il faut enlever le ``./`` devant le nom des dossier. Par la suite, ce sera possible de compiler le projet sans problème.

## Opérations du jeux :
* <kbd>go [chosen direction]</kbd> -  l'utilisateur se déplace vers la direction spécifiée

  * <kbd>N</kbd> - vers le Nord
  * <kbd>S</kbd> - vers le Sud
  * <kbd>W</kbd> - vers l'Ouest
  * <kbd>E</kbd> - vers l'Est

* <kbd>look [item]</kbd> - s'il n'y a pas d'argument: re-affiche la description de la pièce dans laquelle se trouve l'utilisateur, ainsi que les directions qu'il peut emprunter pour son prochain déplacement. 

  sinon, ça affiche le nom de l'objet précisé, ainsi que sa description.
* <kbd>take [item]</kbd> - enlève l'objet précisé de l'inventaire de la salle et l'ajoute à celui du joueur.
* <kbd>drop [item]</kbd> - enlève l'objet de l'inventaire du jouer et le met dans la salle.
* <kbd>use [item]</kbd> - Utilise l'objet précisé. Ce que ça veut dire dépend du type de l'objet.
* <kbd>quit</kbd> - fin du jeux
