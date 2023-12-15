//
// Created by lucia on 14/12/2023.
//
#include <iostream>
#ifndef GRUPO6_AC3_VECTOR_H
#define GRUPO6_AC3_VECTOR_H

#include <iostream>
#include <stdexcept>
using namespace std;


/// @brief una clase vector que permite almacenar elementos de un tipo T con capacidad ampliable
/// @tparam T el tipo a guardar
/// @author Jorge García- material elaborado en clase y descargado del campus 
template <typename T> // T debe ser un tipo default_initializable
class Vector
{
    T *v_,       // inicio del espacio de capacidad reservada para el vector
        *space_, // fin de la secuencia de elementos almacenados
        *last_;  // fin de la capacidad reservada para el vector
    void bounds_check(std::size_t i) const
    {
        if (size() < i)
            throw out_of_range{"indice fuera de rango"};
    }

public:
    Vector() // construye un vector vacío
        : v_{new T[0]}, space_{v_}, last_{v_}
    {
    }
    Vector(Vector<T> const &v)
        : v_{new T[v.capacity()]}, space_{v_ + v.size()}, last_{v_ + v.capacity()}
    {
        try
        {
            for (auto i = size_t{0}; i < v.size(); ++i)
                v_[i] = v[i];
        }
        catch (...)
        {
            delete[] v_;
            throw;
        }
    }
    auto &operator=(Vector<T> const &rhs)
    {
        auto tmp = Vector<T>{rhs};
        std::swap(v_, tmp.v_);
        std::swap(space_, tmp.space_);
        std::swap(last_, tmp.last_);
        return *this;
    }
    ~Vector() { delete[] v_; } // destruye el array apuntado por v_
    // funciones de capacidad_________________________________________
    auto size() const -> std::size_t { return space_ - v_; }
    auto capacity() const -> std::size_t { return last_ - v_; }
    auto empty() const -> bool { return v_ == space_; }
    // funciones de acceso____________________________________________
    // sin bounds checking:
    auto operator[](std::size_t i) -> T & { return v_[i]; }
    auto operator[](std::size_t i) const -> T const & { return v_[i]; }
    // con bounds checking:
    auto at(std::size_t i) -> T &
    {
        bounds_check(i);
        return v_[i];
    }
    auto at(std::size_t i) const -> T const &
    {
        bounds_check(i);
        return v_[i];
    }
    auto begin() -> T * { return v_; }
    auto begin() const -> T const * { return v_; }
    auto end() -> T * { return space_; }
    auto end() const -> T const * { return space_; }
    // Función Push Back
    auto push_back(T const &val)
    {
        if (space_ == last_)
        {                                        // capacidad agotada o primera vez que invocamos push_back
            std::size_t cp = capacity(),         // capacidad actual del vector
                new_cp = (cp == 0) ? 2 : 2 * cp; // nueva capacidad
            T *new_block = new T[new_cp];        // nuevo bloque de memoria
            try
            {
                for (auto i = std::size_t{}; i < cp; ++i)
                    new_block[i] = v_[i];
                new_block[cp] = val;
            }
            catch (...)
            {                       // de lanzarse una excepción...
                delete[] new_block; //... destruimos el nuevo array...
                throw;              // ...y relanzamos la excepción
            }
            // destruimos el array original y reasignamos los punteros:
            delete[] v_;
            v_ = new_block;
            space_ = new_block + cp + 1;
            last_ = new_block + new_cp;
        }
        else
        {
            *space_ = val;
            ++space_;
        }
    }

    void remove(const T &in)
    {
        int index = getIndexOf(in);
        if (index != -1)
        {
            for (int i = index; i < last_ - v_ - 1; i++)
            {
                v_[i] = v_[i + 1];
            }
            space_--;
        }
    }

    void removeElementAt(int index)
    {
        if (index >= 0 && index < last_ - v_)
        {
            for (int i = index; i < last_ - v_ - 1; i++)
            {
                v_[i] = v_[i + 1];
            }
            space_--;
        }
    }
    /// @brief encuentra el indice de la primer aparición de un elemento en el array
    /// @param in el elemento a buscar
    /// @return el indice de la primer aparición o -1 si el elemento no se encuentra en el array
    int getIndexOf(const T &in)
    {
        for (int i = 0; i < last_ - v_; i++)
        {
            if (v_[i] == in)
            {
                return i;
            }
        }
        return -1;
    }
};

#endif //GRUPO6_AC3_VECTOR_H
