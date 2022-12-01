# Le Projet final de INF1015
Voici le repo Git pour le projet final de INF1015

## libraire
D'abord, on a un dossier pour la librairie. Ne pas toucher les dossiers *lib_dir/build* et *lib_dir/target*. Ce sont des dossiers de compilation. Ajouter tous les fichiers ``.h`` dans *lib_dir/include* et tous les fichier ``.cpp`` dans *lib_dir/source*. Pour compiler la librairie, il faut juste faire ``make``. Pour supprimer les fichiers de compilation, juste faire ``make clean``.

## l'exécutable
Le fichier ``main.cpp`` se trouve dans *exec_dir*. Pour compiler l'exécutable, il faut juste faire ``make``. Pour simplifier l'exécution, tu peux faire ``make run``. Ce dernier va compiler l'exécutable et ensuite l'exécuter.