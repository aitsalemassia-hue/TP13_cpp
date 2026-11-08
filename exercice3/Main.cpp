#include <iostream>
#include <vector>
#include <string>
#include "Stack.h"

int main() {

    Stack<int> s(3);
    s.push(15);
    s.push(240);
    s.push(90);
    std::cout << "Sommet : " << s.peek() << "\n";


    try {
    } catch (const StackOverflow& e) {
        std::cout << "Erreur : " << e.what() << "\n";
    }


    s.pop(); s.pop(); s.pop();
    try {
        s.pop();
    } catch (const StackUnderflow& e) {
        std::cout << "Erreur : " << e.what() << "\n";
    }


    std::vector<std::string> v = {"a", "b", "c", "d"};
    Stack<std::string> t(v.begin(), v.end());
    std::cout << "Sommet de t : " << t.peek() << "\n";


    const std::size_t N = 100000;
    Stack<int> grosse(N);
    for (std::size_t i = 0; i < N; i++)
        grosse.push(static_cast<int>(i));
    std::cout << "Taille : " << grosse.size() << "\n";
    while (!grosse.empty())
        grosse.pop();
    std::cout << "Pile vidée : " << std::boolalpha << grosse.empty() << "\n";

    return 0;
}
