size_t Node::base::countofelements = 0, Node::base::countofpoints = 0, Node::base::countofarrays = 0, Node::base::countofvector = 0, Node::base::countofmaping = 0, Node::base::countofother = 0;

template <typename T>
Node::point<T>::point(const T &__value) : base(Node::_S_point)
{
    value = __value;
    base::countofpoints++;
}
template <typename T>
Node::point<T>::point(const point<T> &other) : base(other)
{
    std::copy(value, other.value);
}
template <typename T>
Node::point<T>::point(point<T> &&other) : base(std::move(other))
{
    other.value = std::move(value);
}

template <typename T>
const T &Node::point<T>::get() const
{
    return value;
}
template <typename T>
void Node::point<T>::set(const T &__value)
{
    value = __value;
}

template <typename T>
Node::point<T>::~point()
{
    // if constexpr T ==
    // value.~T();
}
template <size_t N>
Node::array<N>::array(const std::initializer_list<Node::base *> &list) : base(Node::_S_array)
{
    size_t size = list.size();
    size_t n = 0;
    size = size < N ? size : N;
    while (n < size)
    {
        values[n] = *(list.begin() + n);
        n++;
    }
    for (size_t i = n; i < N; i++)
        values[i] = nullptr;
    base::countofarrays++;
}
template <size_t N>
Node::array<N>::array(const array &other) : base(other)
{
    for (size_t i = 0; i < N; i++)
        std::copy(values[i], other.values[i]);
}
template <size_t N>
Node::array<N>::array(array &&other) : base(std::move(other))
{
    for (size_t i = 0; i < N; i++)
    {
        values[i] = other.values[i];
        other.values[i] = nullptr;
    }
}
template <size_t N>
Node::array<N>::~array()
{
    for (size_t i = 0; i < N; i++)
        if (values[i] != nullptr)
            delete values[i];
}
template <size_t N>
Node::base *&Node::array<N>::operator[](size_t pos)
{
    return values[pos];
}
template <size_t N>
const Node::base *Node::array<N>::at(size_t pos) const
{
    if (pos >= N)
        throw std::runtime_error("Error acceso ilegal");
    return values[pos];
}
template <size_t N>
void Node::array<N>::replace(Node::base *element, size_t pos)
{
    if (pos >= N)
        throw std::runtime_error("Error acceso ilegal");
    delete values[pos];
    values[pos] = *element;
}
template <size_t N>
void Node::array<N>::remove(size_t pos)
{
    if (pos >= N)
        throw std::runtime_error("Error acceso ilegal");
    delete values[pos];
    values[pos] = nullptr;
}

Node::vector::vector(const std::initializer_list<base *> &list) : Node::base(Node::_S_vector)
{
    values = std::vector(list);
    base::countofvector++;
}
Node::vector::vector(const std::vector<base *> &factor) : Node::base(Node::_S_vector)
{
    values = factor;
    base::countofvector++;
}
Node::vector::vector(const Node::vector &other) : Node::base(Node::_S_vector)
{
    values = std::move(other.values);
    base::countofvector++;
}
Node::vector::vector(Node::vector &&other) : Node::base(std::move(other))
{
    values = other.values;
}
void Node::vector::insert(size_t pos, base *value)
{
    values.insert(values.begin() + pos, value);
}
void Node::vector::insert(const std::vector<base *>::iterator &pos, base *value)
{
    values.insert(pos, value);
}
void Node::vector::replace(size_t pos, base *value)
{
    values[pos] = value;
    // Why!?
}
void Node::vector::remove(size_t pos)
{
    values.erase(values.begin() + pos);
}
void Node::vector::remove(const std::vector<base *>::iterator &pos)
{
    values.erase(pos);
}
Node::vector::~vector()
{
    for (auto &&i : values)
        if (i != nullptr)
            delete i;
}

template <typename _Key>
Node::mapped<_Key>::mapped(const std::initializer_list<std::pair<_Key, base *>> &list) : Node::base(Node::_S_mapped)
{
    values = std::map<_Key, base *>(list);
    base::countofmaping++;
}
template <typename _Key>
Node::mapped<_Key>::mapped(const std::map<_Key, base *> &factor) : Node::base(Node::_S_mapped)
{
    values = factor;
    base::countofmaping++;
}
template <typename _Key>
Node::mapped<_Key>::mapped(const Node::mapped<_Key> &other) : Node::base(Node::_S_mapped)
{
    std::copy(values, other.values);
    base::countofmaping++;
}
template <typename _Key>
Node::mapped<_Key>::mapped(Node::mapped<_Key> &&other) : Node::base(std::move(other))
{
    values = std::move(other);
}
template <typename _Key>
Node::mapped<_Key>::~mapped()
{
    for (auto &&i : values)
        delete i->second;
    values.clear();
}