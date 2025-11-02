#include <stda/standart/numbers.hpp>
#include <stda/trails/trails.hpp>
#include <memory>
#include <vector>
#include <map>

#ifndef MODESSTD
#define MODESSTD

namespace node
{
    enum id : u8
    {
        _S_base,
        _S_point,
        _S_array,
        _S_vector,
        _S_mapped
    };
    class base
    {
    public:
        node::id pid;

    protected:
        size_t __intern__id;
        static size_t countofelements, countofpoints, countofarrays, countofvector, countofmaping;

    public:
        base(const node::id __id = node::_S_base) : __intern__id(countofelements), pid(__id) { countofelements++; }
        base(const base &other)
        {
            __intern__id = other.__intern__id;
            pid = other.pid;
        }
        base(base &&other)
        {
            __intern__id = other.__intern__id;
            pid = other.pid;
        }
        virtual ~base() = default;
    };
    template <typename T>
    class point : public base
    {
    private:
        T value;

    public:
        point(const T &__value);
        point(const point<T> &other);
        point(point<T> &&other);
        point<T> &operator=(const point<T> &other)
        {
            if (this != &other)
            {
                pid = other.pid;
                __intern__id = other.__intern__id;
                std::copy(value, other.value);
            }
            return *this;
        }
        point<T> &operator=(point<T> &&other)
        {
            if (this != &other)
            {
                pid = other.pid;
                __intern__id = other.__intern__id;
                value = std::move(other.value);
            }
            return *this;
        }
        friend bool operator>(const point<T> &lhs, const point<T> &rhs) { return lhs.get() > rhs.get(); }
        friend bool operator<(const point<T> &lhs, const point<T> &rhs) { return lhs.get() < rhs.get(); }
        friend bool operator>=(const point<T> &lhs, const point<T> &rhs) { return lhs.get() >= rhs.get(); }
        friend bool operator<=(const point<T> &lhs, const point<T> &rhs) { return lhs.get() <= rhs.get(); }
        friend bool operator==(const point<T> &lhs, const point<T> &rhs) { return lhs.get() == rhs.get(); }
        friend bool operator!=(const point<T> &lhs, const point<T> &rhs) { return lhs.get() != rhs.get(); }
        const T &get() const;
        void set(const T &__value);
        ~point() override;
    };
    template <size_t N>
    class array : public base
    {
    private:
        base *values[N];

    public:
        class reverse
        {
        private:
            base * const*__arrarptr__;

        public:
            reverse(const array &__base) : __arrarptr__(__base.values) {}
            iterators::reverse_iterator<base *> begin() const { return iterators::reverse_iterator<base *>(__arrarptr__ + N - 1); }
            iterators::reverse_iterator<base *> end() const { return iterators::reverse_iterator<base *>(__arrarptr__ - 1); }
            ~reverse() {}
        };
        iterators::iterator<base *> begin() const { return iterators::iterator<base *>(values); }
        iterators::iterator<base *> end() const { return iterators::iterator<base *>(values + N); }
        ////////////////////////////////////////////////////////////////////////////////
        iterators::reverse_iterator<base *> rbegin() const { return iterators::reverse_iterator<base *>(values + N - 1); }
        iterators::reverse_iterator<base *> rend() const { return iterators::reverse_iterator<base *>(values - 1); }
        array() : node::base(node::_S_array) { base::countofarrays++; }
        array(const std::initializer_list<base *> &list);
        array(const array<N> &other);
        array(array<N> &&other);
        constexpr size_t size() const { return N; }
        base *&operator[](size_t pos);
        const base *at(size_t pos) const;
        const base *back() const { return values[N - 1]; }
        const base *top() const { return values[0]; }
        void replace(base *element, size_t pos);
        void remove(size_t pos);
        array &operator=(const array &other)
        {
            if (this != &other)
            {
                pid = other.pid;
                __intern__id = other.__intern__id;
                std::copy(values, other.values);
            }
            return *this;
        }
        array &operator=(array &&other)
        {
            if (this != &other)
            {
                pid = other.pid;
                __intern__id = other.__intern__id;
                values = std::move(other.values);
            }
            return *this;
        }
        ~array() override;
    };
    class vector : public base
    {
    private:
        std::vector<base *> values;

    public:
        vector() : node::base(node::_S_vector) { base::countofvector++; }
        vector(const std::initializer_list<base *> &list);
        vector(const std::vector<base *> &factor);
        vector(const node::vector &other);
        vector(node::vector &&other);
        base *&operator[](size_t pos)
        {
            return values[pos];
        }
        const base *at(size_t pos) const
        {
            return values.at(pos);
        }
        vector &operator=(const vector &other)
        {
            if (this != &other)
            {
                pid = other.pid;
                __intern__id = other.__intern__id;
                values = other.values;
            }
            return *this;
        }
        vector &operator=(vector &&other)
        {
            if (this != &other)
            {
                pid = other.pid;
                __intern__id = other.__intern__id;
                values = std::move(other.values);
            }
            return *this;
        }
        void insert(size_t pos, base *value);
        void insert(const std::vector<base *>::iterator &pos, base *value);
        void push_back(base *value) { values.push_back(value); }
        void pop_back() { values.pop_back(); }
        void replace(size_t pos, base *value);
        void reserve(size_t size) { values.reserve(size); }
        size_t capacity() { return values.capacity(); }
        void clear() { values.clear(); }
        void remove(size_t pos);
        void remove(const std::vector<base *>::iterator &pos);
        const size_t size() const { return values.size(); }
        const base *back() const { return const_cast<const base *>(values[values.size() - 1]); }
        const base *top() const { return const_cast<const base *>(values[0]); }
        std::vector<base *>::iterator begin() { return values.begin(); }
        std::vector<base *>::iterator end() { return values.end(); }
        ~vector() override;
    };
    template <typename _Key>
    class mapped : public base
    {
    private:
        std::map<_Key, base *> values;

    public:
        mapped() : node::base(node::_S_mapped) { base::countofmaping++; }
        mapped(const std::initializer_list<std::pair<_Key, base *>> &list);
        mapped(const std::map<_Key, base *> &factor);
        mapped(const node::mapped<_Key> &other);
        mapped(node::mapped<_Key> &&other);
        void insert(_Key key, base *value) { values.insert(key, value); }
        void remove(_Key key) { values.erase(key); }
        void clear() { values.clear(); }
        const size_t size() const { return values.size(); }
        base *&operator[](const _Key &pos)
        {
            return values[pos];
        }
        const base *at(const _Key &pos) const
        {
            return values.at(pos);
        }
        mapped &operator=(const mapped &other)
        {
            if (this != &other)
            {
                pid = other.pid;
                __intern__id = other.__intern__id;
                values = other.values;
            }
            return *this;
        }
        mapped &operator=(mapped &&other)
        {
            if (this != &other)
            {
                pid = other.pid;
                __intern__id = other.__intern__id;
                values = std::move(other.values);
            }
            return *this;
        }
        ~mapped() override;
    };
} // namespace node
#include "nodes.tpp"

#endif