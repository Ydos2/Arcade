# ARCADE

# Prérequis

Les outils nécessaires pour compiler l'arcade sont les suivant :
* cmake (v2.17 minimum)
* make (pour linux)

Les dépendences pour compiler les librairies dynamiques sont les suivantes :
* ncurses
* sdl
* sfml

# installation

Commencez par intaller **make** et **cmake** si ce n'est pas déja fait :

## **make (linux) :**
<details>
<summary>fedora</summary>

```sh
sudo dnf install make
```
</details>
<details>
<summary>unbuntu</summary>

```sh
sudo apt-get install build-essential
```
</details>

## **cmake :**
<details>
<summary>fedora</summary>

```sh
sudo dnf install cmake
```
</details>
<details>
<summary>unbuntu</summary>

```sh
sudo apt-get install software-properties-common
sudo add-apt-repository ppa:george-edison55/cmake-3.x
sudo apt-get update
sudo apt-get install cmake
```
</details>