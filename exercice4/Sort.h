#ifndef SORT_H_
#define SORT_H_

#include <vector>
#include <functional>
#include <concepts>
#include <utility>

template<typename T>
concept Sortable = requires(T a, T b) {
	{	a < b}-> std::convertible_to<bool>;
};

template<typename T>
struct Asc {
	bool operator()(const T &a, const T &b) const {
		return a < b;
	}
};

template<typename T>
struct Desc {
	bool operator()(const T &a, const T &b) const {
		return b < a;
	}
};

template<Sortable T, typename Comp>
void quickSortImpl(std::vector<T> &v, int bas, int haut, Comp comp) {
	if (bas >= haut)
		return;

	T pivot = v[haut];
	int i = bas;

	for (int j = bas; j < haut; j++) {
		if (comp(v[j], pivot)) {
			std::swap(v[i], v[j]);
			i++;
		}
	}
	std::swap(v[i], v[haut]);

	quickSortImpl(v, bas, i - 1, comp);
	quickSortImpl(v, i + 1, haut, comp);
}

template<Sortable T, typename Comp = std::less<T>>
void quickSort(std::vector<T> &v, Comp comp = Comp { }) {
	quickSortImpl(v, 0, static_cast<int>(v.size()) - 1, comp);
}

#endif /* SORT_H_ */
