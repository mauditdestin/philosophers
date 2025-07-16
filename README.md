# 🧠 Philosophers

Ce projet est une implémentation du problème des philosophes à dîner, un classique en programmation concurrente.  
Il vise à mettre en pratique la gestion des threads, la synchronisation, et la prévention des conditions de compétition.

---

## 📋 Objectifs

- Comprendre et gérer la concurrence en C  
- Utiliser les threads (`pthread`) et les mutex pour synchroniser les accès  
- Éviter les interblocages (deadlocks) et les famine (starvation)  
- Implémenter un algorithme efficace pour que les philosophes puissent manger sans blocage  

---

## 🚀 Fonctionnalités

- Création dynamique de philosophes (threads)  
- Gestion des ressources (fourchettes) via mutex  
- Chronométrage précis des actions (manger, penser, dormir)  
- Arrêt du programme si un philosophe meurt (ne mange pas à temps) ou si une condition de fin est atteinte  

---

## ⚙️ Compilation

Utilise le Makefile fourni : 

```bash
make
```

---

## 🏃‍♂️ Usage
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
- number_of_philosophers : nombre de philosophes et de fourchettes

- time_to_die (en ms) : temps maximum sans manger avant qu’un philosophe meure

- time_to_eat (en ms) : durée pour manger

- time_to_sleep (en ms) : durée pour dormir

- number_of_times_each_philosopher_must_eat (optionnel) : nombre minimum de fois que chaque philosophe doit manger avant la fin

---

# 📌 Remarques
Ce projet a été réalisé dans le cadre du cursus de l’École 42.
L’objectif principal est d’apprendre la gestion fine des threads et des mutex en C.
