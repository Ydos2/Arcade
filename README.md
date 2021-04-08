# ARCADE

# Prérequis

Les outils nécessaires pour compiler l'arcade sont les suivant :
* cmake (v2.17 minimum)
* make (pour linux)

Les dépendences pour compiler les librairies dynamiques sont les suivantes :
* ncurses
* sdl2
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

Pour compiler et utiliser les librairies dynamiques graphiques, installez les outils suivants :

## **ncurses :**

<details>
<summary>fedora</summary>

```sh
sudo dnf install ncurses-devel
```
</details>
<details>
<summary>unbuntu</summary>

```sh
sudo apt-get install libncurses5-dev libncursesw5-dev
```
</details>

## **sdl2 :**

<details>
<summary>fedora</summary>

```sh
sudo yum install SDL2-devel
```
</details>
<details>
<summary>unbuntu</summary>

```sh
sudo apt-get install libsdl2-dev
```
</details>

## **sfml :**

<details>
<summary>fedora</summary>

```sh
sudo dnf install SFML-devel
```
</details>
<details>
<summary>unbuntu</summary>

```sh
sudo apt-get install libsfml-dev
```
</details>

# compilation

Pour compiler l'arcade et les librairies, executer les commandes :
```
mkdir build
cd build
cmake ..
make
```
Pour isoler les executables :
```
mkdir bin
mv lib bin/lib/
mv arcade bin/arcade
cd bin
```
# usage