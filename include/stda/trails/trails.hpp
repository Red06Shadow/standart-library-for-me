#include <iostream>
#include <stda/iterator/iterator.hpp>

#ifndef TRAISSTDS
#define TRAISSTDS

template <typename T>
class trails
{
protected:
    size_t __size__;
    T *__array__;

public:
    trails() : __array__(nullptr), __size__(0) {}
    trails(const T __array[], size_t size);
    trails(size_t size);
    trails(const trails<T> &other) : trails<T>()
    {
        *this = other;
    }
    trails(trails<T> &&other) noexcept : __array__(other.__array__), __size__(other.__size__)
    {
        other.__size__ = 0;
        other.__array__ = nullptr;
    }
    trails<T> &operator=(const trails<T> &other)
    {
        if (this != &other)
        {
            if (__array__ != nullptr)
                delete[] (__array__);
            __size__ = other.__size__;
            if (__size__ > 0)
            {
                __array__ = new T[__size__];
                std::copy(other.__array__, other.__array__ + __size__, __array__);
            }
            else
            {
                __array__ = nullptr;
            }
        }
        return *this;
    }
    trails<T> &operator=(trails<T> &&other)
    {
        if (this != &other)
        {
            if (__array__ != nullptr)
                delete[] (__array__);
            __size__ = other.__size__;
            __array__ = other.__array__;
            other.__array__ = nullptr;
            other.__size__ = 0;
        }
        return *this;
    }
    T &operator[](size_t pos)
    {
        return __array__[pos];
    }
    const T &operator[](size_t pos) const
    {
        return __array__[pos];
    }
    void assing(const trails<T> &__str);
    void copy(const trails<T> &__str);
    void copy(const trails<T> &__str, size_t nelements);
    T at(size_t pos) const;
    inline size_t size() const { return __size__; }
    inline bool empty() const { return __size__ == 0; }
    friend std::ostream &operator<<(std::ostream &os, const trails<T> &__array)
    {
        os << '[';
        for (size_t i = 0; i < __array.__size__; i++)
            os << __array.__array__[i] << (__array.__size__ - 1 == i ? "" : ", ");
        os << ']' << std::endl;
        return os;
    }
    class reverse
    {
    private:
        const T *__arrarptr__;
        size_t __size__;

    public:
        reverse(const trails<T> &__base) : __arrarptr__(__base.__array__), __size__(__base.__size__) {}
        iterators::reverse_iterator<T> begin() const { return iterators::reverse_iterator<T>(__arrarptr__ ? nullptr : __arrarptr__ + __size__ - 1); }
        iterators::reverse_iterator<T> end() const { return iterators::reverse_iterator<T>(__arrarptr__ ? nullptr : __arrarptr__ - 1); }
        ~reverse() {}
    };
    iterators::iterator<T> begin() const { return iterators::iterator<T>(empty() ? nullptr : __array__); }
    iterators::iterator<T> end() const { return iterators::iterator<T>(empty() ? nullptr : __array__ + __size__); }

    iterators::reverse_iterator<T> rbegin() const { return iterators::reverse_iterator<T>(empty() ? nullptr : __array__ + __size__ - 1); }
    iterators::reverse_iterator<T> rend() const { return iterators::reverse_iterator<T>(empty() ? nullptr : __array__ - 1); }

    const T* operator*() const {
        return __array__;
    }

    virtual ~trails()
    {
        delete[] __array__;
        __array__ = nullptr;
    }
};

#include "trails.tpp"

#endif