#ifndef STACK_H_
#define STACK_H_

#include <memory>
#include <exception>
#include <iterator>
#include <cstddef>

class StackOverflow : public std::exception {
public:
    const char* what() const noexcept override {
        return "StackOverflow : la pile est pleine";
    }
};

class StackUnderflow : public std::exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflow : la pile est vide";
    }
};

template <typename T>
class Stack {
    std::unique_ptr<T[]> data;
    std::size_t capacity;
    std::size_t top;

public:
    explicit Stack(std::size_t cap = 10)
        : data(new T[cap]), capacity(cap), top(0) {}

    template <typename It>
    Stack(It debut, It fin)
        : data(nullptr), capacity(0), top(0) {
        capacity = static_cast<std::size_t>(std::distance(debut, fin));
        data.reset(new T[capacity]);
        for (; debut != fin; ++debut)
            push(*debut);
    }

    void push(const T& valeur) {
        if (top == capacity)
            throw StackOverflow();
        data[top] = valeur;
        top++;
    }

    void pop() {
        if (top == 0)
            throw StackUnderflow();
        top--;
    }

    const T& peek() const {
        if (top == 0)
            throw StackUnderflow();
        return data[top - 1];
    }

    bool empty() const {
        return top == 0;
    }

    std::size_t size() const {
        return top;
    }
};

#endif /* STACK_H_ */
