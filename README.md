pour compiler : il suffit de taper la commande "make run" dans le terminal en se situant dans le dossier ou se trouve les fichiers sources

3 options du program sont disponible :
	-k permet de générer une nouvelle clé aléatoire et stocker dans un fichier "cle.txt"
	-c permet de chiffrer le message et stocker dans message_c.txt
	-d permet de décoder le message chiffré dans message_c.txt et stocker dans message_dc.txt

si l'une de ces 3 options ne fonctionne pas, il est probable qu'un des fichiers message.txt | message_c.txt | message_dc.txt | cle.txt est manquant

exemple d'utilisation :
./vernam -c
./vernam -d
./vernam -k