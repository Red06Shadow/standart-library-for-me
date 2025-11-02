#include <typeinfo>
#include <utility>

#ifndef STDXUTILITYS
#define STDXUTILITYS

namespace utilitys
{
    template <typename A, typename B>
    class pair
    {
    public:
        A firts;
        B second;
        pair() : firts(), second() {}
        template <typename A1, typename B1>
        pair(A1 __firts, B1 __second) : firts(__firts), second(__second) {}
        pair(const pair &other) : firts(other.firts), second(other.second) {}
        pair(pair &&other) noexcept : firts(std::move(other.firts)), second(std::move(other.second)) {}
        pair &operator=(const pair &other)
        {
            if (this != &other)
            {
                this->firts = other.firts;
                this->second = other.second;
            }
            return *this;
        }
        pair &operator=(pair &&other)
        {
            if (this != &other)
            {
                this->firts = std::move(other.firts);
                this->second = std::move(other.second);
            }
            return *this;
        }
        void swap(pair<A, B> &objectivo1, pair<A, B> &objectivo2)
        {
            std::swap(objectivo1.firts, objectivo2.firts);
            std::swap(objectivo1.second, objectivo2.second);
        }
        std::string type1()
        {
            return typeid(firts).name();
        }
        std::string type2()
        {
            return typeid(second).name();
        }
    };
    template <typename A, typename B, typename C>
    class trio
    {
    public:
        A firts;
        B second;
        C third;
        trio() : firts(), second(), third() {}
        template <typename A1, typename B1, typename C1>
        trio(A1 __firts, B1 __second, C1 __third) : firts(__firts), second(__second), third(__third) {}
        trio(const trio &other) : firts(other.firts), second(other.second), third(other.third) {}
        trio(trio &&other) noexcept : firts(std::move(other.firts)), second(std::move(other.second)), third(std::move(other.third)) {}
        trio &operator=(const trio &other)
        {
            if (this != &other)
            {
                this->firts = other.firts;
                this->second = other.second;
                this->third = other.third;
            }
            return *this;
        }
        trio &operator=(trio &&other)
        {
            if (this != &other)
            {
                this->firts = std::move(other.firts);
                this->second = std::move(other.second);
                this->third = std::move(other.third);
            }
            return *this;
        }
        void swap(trio<A, B, C> &objectivo1, trio<A, B, C> &objectivo2)
        {
            std::swap(objectivo1.firts, objectivo2.firts);
            std::swap(objectivo1.second, objectivo2.second);
            std::swap(objectivo1.third, objectivo2.third);
        }
        std::string type1()
        {
            return typeid(firts).name();
        }
        std::string type2()
        {
            return typeid(second).name();
        }
        std::string type3()
        {
            return typeid(third).name();
        }
    };
    template <typename A, typename B, typename C, typename D>
    class quartet
    {
    public:
        A firts;
        B second;
        C third;
        D fourth;
        quartet() : firts(), second(), third(), fourth() {}
        template <typename A1, typename B1, typename C1, typename D1>
        quartet(A1 __firts, B1 __second, C1 __third, D1 __fourth) : firts(__firts), second(__second), third(__third), fourth(__fourth) {}
        quartet(const quartet &other) : firts(other.firts), second(other.second), third(other.third), fourth(other.fourth) {}
        quartet(quartet &&other) noexcept : firts(std::move(other.firts)), second(std::move(other.second)), third(std::move(other.third)), fourth(std::move(other.fourth)) {}
        quartet &operator=(const quartet &other)
        {
            if (this != &other)
            {
                this->firts = other.firts;
                this->second = other.second;
                this->third = other.third;
                this->fourth = other.fourth;
            }
            return *this;
        }
        quartet &operator=(quartet &&other)
        {
            if (this != &other)
            {
                this->firts = std::move(other.firts);
                this->second = std::move(other.second);
                this->third = std::move(other.third);
                this->fourth = std::move(other.fourth);
            }
            return *this;
        }
        void swap(quartet<A, B, C, D> &objectivo1, quartet<A, B, C, D> &objectivo2)
        {
            std::swap(objectivo1.firts, objectivo2.firts);
            std::swap(objectivo1.second, objectivo2.second);
            std::swap(objectivo1.third, objectivo2.third);
            std::swap(objectivo1.fourth, objectivo2.fourth);
        }
        std::string type1()
        {
            return typeid(firts).name();
        }
        std::string type2()
        {
            return typeid(second).name();
        }
        std::string type3()
        {
            return typeid(third).name();
        }
        std::string type4()
        {
            return typeid(fourth).name();
        }
    };
    template <typename... Types>
    class tuple;
    template <>
    class tuple<>
    {
    public:
        static constexpr size_t size = 0;
    };
    template <typename T, typename... Rest>
    class tuple<T, Rest...>
    {
    private:
        T value;
        tuple<Rest...> rest;

    public:
        tuple(const T &first, const Rest &...others) : value(first), rest(others...) {}
        template <size_t N>
        auto &get()
        {
            if constexpr (N == 0)
                return value;
            else
                return rest.template get<N - 1>();
        }
        static constexpr size_t size = 1 + sizeof...(Rest);
        void print() const
        {
            std::cout << value;
            if constexpr (sizeof...(Rest) > 0)
            {
                std::cout << "|";
                rest.print();
            }
        }
    };
} // namespace utilitys

#endif