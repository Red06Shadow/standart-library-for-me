
template <typename T>
Iterators::Iterator<T>::Iterator(const T *__arrarptr)
{
    __arrarptr__ = __arrarptr;
}
template <typename T>
bool Iterators::Iterator<T>::operator==(const Iterator<T> &otro) const
{
    return this->__arrarptr__ == otro.__arrarptr__;
}

template <typename T>
bool Iterators::Iterator<T>::operator>(const Iterators::Iterator<T> &otro) const {
    return this->__arrarptr__ > otro.__arrarptr__;
}

template <typename T>
bool Iterators::Iterator<T>::operator!=(const Iterator<T> &otro) const
{
    return this->__arrarptr__ != otro.__arrarptr__;
}
template <typename T>
T &Iterators::Iterator<T>::operator*()
{
    return *const_cast<T *>(__arrarptr__);
}

template <typename T>
Iterators::Iterator<T> Iterators::Iterator<T>::operator+(size_t pos)
{
    return Iterators::Iterator<T>(this->__arrarptr__ + pos);
}
template <typename T>
Iterators::Iterator<T> Iterators::Iterator<T>::operator-(size_t pos)
{
    return size_t(this->__arrarptr__) - pos;
}
template <typename T>
size_t Iterators::Iterator<T>::operator-(const Iterators::Iterator<T>& pos)
{
    return size_t(this->__arrarptr__) - size_t(pos.__arrarptr__);
}

template <typename T>
T *Iterators::Iterator<T>::operator->()
{
    return const_cast<T *>(__arrarptr__);
}
template <typename T>
Iterators::Iterator<T>::~Iterator()
{
    __arrarptr__ = nullptr;
}

template <typename T>
Iterators::Reverse_Iterator<T>::Reverse_Iterator(const T *__arrarptr)
{
    __arrarptr__ = __arrarptr;
}
template <typename T>
bool Iterators::Reverse_Iterator<T>::operator==(const Iterators::Reverse_Iterator<T> &otro) const
{
    return this->__arrarptr__ == otro.__arrarptr__;
}
template <typename T>
bool Iterators::Reverse_Iterator<T>::operator>(const Iterators::Reverse_Iterator<T> &otro) const {
    return this->__arrarptr__ > otro.__arrarptr__;
}

template <typename T>
bool Iterators::Reverse_Iterator<T>::operator!=(const Iterators::Reverse_Iterator<T> &otro) const
{
    return this->__arrarptr__ != otro.__arrarptr__;
}

template <typename T>
Iterators::Reverse_Iterator<T> Iterators::Reverse_Iterator<T>::operator+(size_t pos)
{
    return Iterators::Reverse_Iterator<T>(this->__arrarptr__ + pos);
}
template <typename T>
Iterators::Reverse_Iterator<T> Iterators::Reverse_Iterator<T>::operator-(size_t pos)
{
    return size_t(this->__arrarptr__) - pos;
}
template <typename T>
size_t Iterators::Reverse_Iterator<T>::operator-(const Iterators::Reverse_Iterator<T>& pos)
{
    return size_t(this->__arrarptr__) - size_t(pos.__arrarptr__);
}

template <typename T>
T &Iterators::Reverse_Iterator<T>::operator*()
{
    return *const_cast<T *>(__arrarptr__);
}
template <typename T>
T *Iterators::Reverse_Iterator<T>::operator->()
{
    return const_cast<T *>(__arrarptr__);
}
template <typename T>
Iterators::Reverse_Iterator<T>::~Reverse_Iterator()
{
    __arrarptr__ = nullptr;
}