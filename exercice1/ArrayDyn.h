#ifndef EXERCICE1_ARRAYDYN_H_
#define EXERCICE1_ARRAYDYN_H_

#include <iostream>
#include <string>
#include <stdexcept>

template<typename T>
class ArrayDyn {
private:
	T *tab;
	std::size_t capacite;
	std::size_t taille;

	void agrandir() {
		capacite = (capacite == 0) ? 1 : capacite * 2;

		T *nouveau = new T[capacite];

		for (std::size_t i = 0; i < taille; i++) {
			nouveau[i] = tab[i];
		}

		delete[] tab;
		tab = nouveau;
	}

public:

	ArrayDyn() {
		tab = nullptr;
		capacite = 0;
		taille = 0;
	}

	// Constructeur avec capacité initiale
	ArrayDyn(std::size_t cap) {
		capacite = cap;
		taille = 0;
		tab = (cap > 0) ? new T[cap] : nullptr;
	}

	// Constructeur de copie
	ArrayDyn(const ArrayDyn &autre) {
		capacite = autre.capacite;
		taille = autre.taille;

		tab = (capacite > 0) ? new T[capacite] : nullptr;

		for (std::size_t i = 0; i < taille; i++) {
			tab[i] = autre.tab[i];
		}
	}

	// Opérateur d'affectation
	ArrayDyn& operator=(const ArrayDyn &autre) {
		if (this != &autre) {
			T *nouveau = (autre.capacite > 0) ? new T[autre.capacite] : nullptr;

			for (std::size_t i = 0; i < autre.taille; i++) {
				nouveau[i] = autre.tab[i];
			}

			delete[] tab;

			tab = nouveau;
			capacite = autre.capacite;
			taille = autre.taille;
		}

		return *this;
	}

	~ArrayDyn() {
		delete[] tab;
	}

	// Ajouter un élément
	void push_back(const T &element) {
		if (taille == capacite) {
			agrandir();
		}
		tab[taille] = element;
		taille++;
	}

	// Supprimer le dernier élément
	void pop_back() {
		if (taille == 0) {
			throw std::out_of_range("Tableau vide !");
		}

		taille--;
	}

	// Accès à un élément
	T& operator[](std::size_t indice) {
		if (indice >= taille) {
			throw std::out_of_range("Indice invalide !");
		}

		return tab[indice];
	}

	// Version constante de operator[]
	const T& operator[](std::size_t indice) const {
		if (indice >= taille) {
			throw std::out_of_range("Indice invalide !");
		}

		return tab[indice];
	}

	// Classe interne Iterator
	class Iterator {
	private:
		T *ptr;

	public:
		Iterator(T *p = nullptr) {
			ptr = p;
		}

		// Accéder à l'élément
		T& operator*() const {
			return *ptr;
		}

		// Avancer
		Iterator& operator++() {
			++ptr;
			return *this;
		}

		// Reculer
		Iterator& operator--() {
			--ptr;
			return *this;
		}

		// Comparer deux itérateurs
		bool operator!=(const Iterator &autre) const {
			return ptr != autre.ptr;
		}
	};

	// Premier élément
	Iterator begin() {
		return Iterator(tab);
	}

	// Position après le dernier élément
	Iterator end() {
		return Iterator(tab + taille);
	}
};

#endif /* EXERCICE1_ARRAYDYN_H_ */
