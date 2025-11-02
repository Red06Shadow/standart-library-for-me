
#ifndef ITERATORS
#define ITERATORS
namespace iterators
{
    template<typename T>
    class iterator
    {
    private:
        const T *__arrarptr__;

    public:
        explicit iterator(const T *__arrarptr);
        bool operator==(const iterator &otro) const;
        bool operator!=(const iterator &otro) const;
        T &operator*();
        T *operator->();
        iterator operator++()
        {
            this->__arrarptr__++;
            return *this;
        }
        iterator operator++(int)
        {
            iterator temp(*this);
            ++(*this);
            return temp;
        }
        virtual ~iterator();
    };
    template<typename T>
    class reverse_iterator
    {
    private:
        const T *__arrarptr__;

    public:
        explicit reverse_iterator(const T *__arrarptr);
        bool operator==(const reverse_iterator &otro) const;
        bool operator!=(const reverse_iterator &otro) const;
        T &operator*();
        T *operator->();
        reverse_iterator operator++()
        {
            --(this->__arrarptr__);
            return *this;
        }
        reverse_iterator operator++(int)
        {
            reverse_iterator temp(*this);
            ++(*this);
            return temp;
        }
        virtual ~reverse_iterator();
    };
} // namespace iterators

#include "iterator.tpp"

#endif