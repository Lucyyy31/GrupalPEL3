//
// Created by lucia on 14/12/2023.
//
#include <iostream>
#ifndef GRUPO6_AC3_DYNARRAY_H
#define GRUPO6_AC3_DYNARRAY_H
using namespace std;

template <typename T>
class Dynarray {
private:
public:
//atributos
    T *first;
    size_t count;
    size_t max_count;

    Dynarray() {
        Dynarray::first = nullptr;
        Dynarray::count = 0;
        Dynarray::max_count = 1;
    };
    Dynarray(size_t c) {
        Dynarray::first = new T[c];
        Dynarray::count = 0;
        Dynarray::max_count = c;
    };
//metodos
    void insert(T e) {
        if (Dynarray::count >= Dynarray::max_count) {
            Dynarray::alloc();
        }
        Dynarray::first[Dynarray::count] = e;
        Dynarray::count++;
    };

    void remove(T e) {
        int index = -1;
        for (int i = 0; i < count && index == -1; ++i) {
            if (first[i] == e) {
                index = i;
            }
        }
        if (index != -1) {
            for (int i = index; i < count - 1; ++i) {
                first[i] = first[i + 1];
            }
            --count;
            T* newFirst = new T[count];
            for (int i = 0; i < count; ++i) {
                newFirst[i] = first[i];
            }
            delete[] first;
            first = newFirst;
            max_count = count;
        }
    }

    T search(T e) {
        for (int i = 0; i < count; ++i) {
            if (first[i] == e) {
                return first[i];
            }
        }
        throw std::runtime_error("Element not found");
    };

    void A_Zsort() {
        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < count - 1; ++j) {
                if (first[j] > first[j + 1]) {
                    T aux = first[j];
                    first[j] = first[j + 1];
                    first[j + 1] = aux;
                }
            }
        }
    };

    float suma() {
        float suma = 0;
        for (int i = 0; i < count; ++i) {
            suma += first[i];
        }
        return suma;
    };
    float promedio() {
        return suma() / count;
    };
    float moda() {
        int moda = 0;
        int max = 0;
        for (int i = 0; i < count; ++i) {
            int aux = 0;
            for (int j = 0; j < count; ++j) {
                if (first[i] == first[j]) {
                    aux++;
                }
            }
            if (aux > max) {
                max = aux;
                moda = first[i];
            }
        }
        return moda;
    };
    void MaxSize() {
        cout << "Max size: " << Dynarray::max_count << endl;
    };
    void alloc() {
        T* aux_ = new T[Dynarray::max_count * 2];
        for (int i = 0; i < Dynarray::count; ++i) {
            aux_[i] = Dynarray::first[i];
        }
        delete[] Dynarray::first;
        Dynarray::first = aux_;
        Dynarray::max_count *= 2;
    };

    void print() {
        for (int i = 0; i < count; ++i) {
            cout << first[i] << endl;
        }
    };
    //destructores
    ~Dynarray() {
        delete[] Dynarray::first;
        cout << "Dynarray deleted" << endl;
    };


};

#endif //GRUPO6_AC3_DYNARRAY_H
