#include "node.h"

template <class T>
my::Node<T>::Node(T t_value, Node<T> *t_next)
    : m_value(t_value), m_next(t_next)
{
}

template <class T>
my::Node<T>::~Node()
{
    delete m_next;
}

template <class T>
const T &my::Node<T>::value() const
{
    return m_value;
}

template <class T>
my::Node<T> *my::Node<T>::next() const
{
    return m_next;
}

template <class T>
void my::Node<T>::set_value(const T &t_value)
{
    m_value = t_value;
}

template <class T>
void my::Node<T>::set_next(Node<T> *t_next)
{
    m_next = t_next;
}
