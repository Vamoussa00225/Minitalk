# Minitalk

Minitalk est un projet de programmation informatique développé dans le cadre de l'école 42. Il s'agit d'un programme client-serveur permettant la communication entre deux processus via le protocole SIGUSR1/SIGUSR2.

## Installation

Pour installer le programme Minnitalk, vous devez d'abord cloner le dépôt GitHub sur votre machine locale :

```bash
  git clone https://github.com/vamoussa00225/minitalk.git
```

Ensuite, vous devez vous rendre dans le répertoire minnitalk et exécuter la commande make pour compiler le programme :

```bash
  cd minitalk
  make
```
Le programme sera alors compilé et prêt à être exécuté.

## Utilisation

Une fois le programme compilé, vous pouvez l'exécuter en utilisant les commandes suivantes :

Pour lancer le serveur :
```bash
  ./server
```

Pour lancer le client :
```bash
  ./client <PID-du-serveur> <message-à-envoyer>
```

Le paramètre <PID-du-serveur> est le PID du processus serveur, et <message-à-envoyer> est le message que vous souhaitez envoyer.

Le programme client envoie le message au serveur en utilisant les signaux SIGUSR1 et SIGUSR2. Le serveur affiche ensuite le message reçu sur la sortie standard.

## Exemples

Voici un exemple d'utilisation du programme Minnitalk :

```shell
  $ ./server
  Serveur lancé avec succès.

  $ ./client 12345 "Hello, world!"
  Message envoyé avec succès.

  $ Hello, world! (affiché sur la sortie standard du serveur)
```

## Auteurs

Ce programme a été développé par "Vkanate" dans le cadre du projet Minnitalk de l'école 42.
