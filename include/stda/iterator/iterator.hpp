
#ifndef ITERATORS
#define ITERATORS

/* @Documentacion:
 * Este archivo debe contiene la clase de iterdores para T tipo para generar iteradores de cualquier objecto
 * Proximamente se introduciran iteradores a base de funciones que no necesiten de memoria si no de cumplimiento de
 * Funciones booleanas para los recorridos co for-each
*/

namespace Iterators
{
    /// @brief Clase iteradora
    /// @tparam T Tipo de dato que se desea(!Atencion: debe coincidir con el tipo de dato que guarda el arreglo!)
    template<typename T>
    class Iterator
    {
    private:
        /// @brief Puntero al elemento iterado
        const T *__arrarptr__;

    public:
        /// @brief Contructor de la clase ieradora
        /// @param __arrarptr Direccion de memoria
        explicit Iterator(const T *__arrarptr);
        bool operator==(const Iterator &otro) const;
        bool operator>(const Iterator &otro) const;
        bool operator!=(const Iterator &otro) const;
        Iterator operator+(size_t pos);
        Iterator operator-(size_t pos);
        size_t operator-(const Iterator& pos);
        T &operator*();
        T *operator->();
        Iterator operator++()
        {
            this->__arrarptr__++;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator temp(*this);
            ++(*this);
            return temp;
        }
        Iterator operator--()
        {
            this->__arrarptr__--;
            return *this;
        }
        Iterator operator--(int)
        {
            Iterator temp(*this);
            --(*this);
            return temp;
        }
        virtual ~Iterator();
    };
    /// @brief Clase iteradora de reversa
    /// @tparam T Tipo de dato que se desea(!Atencion: debe coincidir con el tipo de dato que guarda el arreglo!)
    template<typename T>
    class Reverse_Iterator
    {
    private:
        /// @brief Puntero al elemento iterado
        const T *__arrarptr__;

    public:
        /// @brief Contructor de la clase ieradora
        /// @param __arrarptr Direccion de memoria(!Atencion: El iterador de inicio debe ser la direccion final o la direccion de inicio mas el tamano disminuido en 1! y el valor del iterador final la direccion de inicio - 1 para que funcione correctamente en caso de arreglos o Trails<T>)
        explicit Reverse_Iterator(const T *__arrarptr);
        bool operator==(const Reverse_Iterator &otro) const;
        bool operator>(const Reverse_Iterator &otro) const;
        bool operator!=(const Reverse_Iterator &otro) const;
        T &operator*();
        T *operator->();
        Reverse_Iterator operator+(size_t pos);
        Reverse_Iterator operator-(size_t pos);
        size_t operator-(const Reverse_Iterator& pos);
        Reverse_Iterator operator++()
        {
            --(this->__arrarptr__);
            return *this;
        }
        Reverse_Iterator operator++(int)
        {
            Reverse_Iterator temp(*this);
            ++(*this);
            return temp;
        }
        Reverse_Iterator operator--()
        {
            ++(this->__arrarptr__);
            return *this;
        }
        Reverse_Iterator operator--(int)
        {
            Reverse_Iterator temp(*this);
            --(*this);
            return temp;
        }
        virtual ~Reverse_Iterator();
    };
} // namespace Iterators

#include "Iterator.tpp"

#endif