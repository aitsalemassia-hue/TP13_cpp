

#ifndef EXERCICE2_MATRICE_H_
#define EXERCICE2_MATRICE_H_


#include <iostream>
#include <initializer_list>

template<typename T, int L, int C>
class Matrice {
private:
    T data[L][C];

    template <typename U, int A, int B> friend class Matrice;

public:
    Matrice() {
        for (int i = 0; i < L; i++)
            for (int j = 0; j < C; j++)
                data[i][j] = T();
    }

    Matrice(std::initializer_list<T> liste) : Matrice() {
        int k = 0;
        for (const T& v : liste) {
            if (k >= L * C) break;
            data[k / C][k % C] = v;
            k++;
        }
    }

    Matrice operator+(const Matrice& autre) const {
        Matrice res;
        for (int i = 0; i < L; i++)
            for (int j = 0; j < C; j++)
                res.data[i][j] = data[i][j] + autre.data[i][j];
        return res;
    }

    template <int P>
    Matrice<T, L, P> operator*(const Matrice<T, C, P>& autre) const {
        Matrice<T, L, P> res;
        for (int i = 0; i < L; i++)
            for (int j = 0; j < P; j++)
                for (int k = 0; k < C; k++)
                    res.data[i][j] += data[i][k] * autre.data[k][j];
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrice& m) {
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < C; j++)
                os << m.data[i][j] << " ";
            os << "\n";
        }
        return os;
    }
};




#endif /* EXERCICE2_MATRICE_H_ */
