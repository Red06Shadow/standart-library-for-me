#include <stda/standart/numbers.hpp>
#include <vector>

#ifndef STDX_ALGORITM
#define STDX_ALGORITM

namespace algoritm
{
    template <typename T>
    void view(const T array[], size_t size);
    template <typename T>
    void view(const trails<T> array);
    template <typename T>
    inline void copy(T _destine_[], const T _sources[], size_t _sdestine_, size_t _ssources);
    template <typename T>
    inline void copy(std::vector<T> &_destine_, const std::vector<T> &_sources);
    inline size_t bitforaround(size_t n);
    template <typename T>
    inline void copy(std::vector<T> &_destine_, const T _sources[], size_t _ssources);
    template <typename U>
    size_t size(const U _sources[]);
    template <typename Q>
    void qickshort(Q array[], size_t size);
    // Escribir codigop para QickShortTwoPivote
    template <typename Q>
    void qickshort2(Q array[], size_t size);
    template <typename Q>
    size_t binarysearch(Q array[], Q element, size_t size);
}

#include "algoritm.tpp"

#endif