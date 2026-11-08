#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include "Sort.h"

struct Etudiant {
	std::string nom;
	double note;

	bool operator<(const Etudiant &autre) const {
		return note < autre.note;
	}
};

int main() {
	std::vector<int> vi = { 5, 2, 9, 1, 5, 6, -3, 0 };
	quickSort(vi);
	assert(std::is_sorted(vi.begin(), vi.end()));
	for (int x : vi)
		std::cout << x << " ";
	std::cout << "\n";

	quickSort(vi, Desc<int> { });
	assert(std::is_sorted(vi.begin(), vi.end(), Desc<int> { }));
	for (int x : vi)
		std::cout << x << " ";
	std::cout << "\n";

	std::vector<std::string> vs = { "pomme", "banane", "frise" };
	quickSort(vs, Asc<std::string> { });
	assert(std::is_sorted(vs.begin(), vs.end()));
	for (const auto &s : vs)
		std::cout << s << " ";
	std::cout << "\n";

	std::vector<Etudiant> ve = { { "Sara", 14.5 }, { "Omar", 12.0 }, { "Assiya",
			17.25 } };
	quickSort(ve, Desc<Etudiant> { });
	assert(std::is_sorted(ve.begin(), ve.end(), Desc<Etudiant> { }));
	for (const auto &e : ve)
		std::cout << e.nom << " (" << e.note << ")  ";
	std::cout << "\n";

	std::vector<int> un = { 42 };
	quickSort(un);
	assert(un.size() == 1 && un[0] == 42);

	return 0;
}

