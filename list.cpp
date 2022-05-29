#include "list.h"

template <class T>
my::List<T>::List()
{
}

// template <class T>
// my::List<T>::~List()
// {
//     delete m_head;
// }

template <class T>
my::Node<T> *my::List<T>::head() const
{
    return m_head;
}

template <class T>
T my::List<T>::insert_sort(const T &t_value)
{
    my::Node<T> *head = m_head;
    my::Node<T> *prev = nullptr;

    while (head)
    {
        if (head->value() < t_value)
        {
            prev = head;
            head = head->next();
        }
        else
        {
            break;
        }
    }

    if (prev != nullptr)
    {
        prev->set_next(create_node(t_value, head));
    }
    else
    {
        m_head = create_node(t_value, head);
    }

    return t_value;
}

template <class T>
T my::List<T>::insert_sort_u(const T &t_value)
{
    my::Node<T> *head = m_head;
    my::Node<T> *prev = nullptr;

    while (head)
    {
        if (head->value() < t_value)
        {
            prev = head;
            head = head->next();
        }
        else if (head->value() == t_value)
        {
            return 0;
        }
        else
        {
            break;
        }
    }

    if (prev != nullptr)
    {
        prev->set_next(create_node(t_value, head));
    }
    else
    {
        m_head = create_node(t_value, head);
    }

    return t_value;
}

template <class T>
T my::List<T>::insert_abs_sort_u(const T &t_value)
{
    my::Node<T> *head = m_head;
    my::Node<T> *prev = nullptr;

    T abs_value = abs(t_value);

    while (head)
    {
        T abs_head_value = abs(head->value());

        if (abs_head_value < abs_value)
        {
            prev = head;
            head = head->next();
        }
        else if (abs_head_value == abs_value)
        {
            return 0;
        }
        else
        {
            break;
        }
    }

    if (prev != nullptr)
    {
        prev->set_next(create_node(t_value, head));
    }
    else
    {
        m_head = create_node(t_value, head);
    }

    return t_value;
}

template <class T>
T my::List<T>::push_front(const T &t_value)
{
    m_head = create_node(t_value, m_head);
    return t_value;
}

template <class T>
T my::List<T>::push_back(const T &t_value)
{
    my::Node<T> *head = m_head;

    if (!head)
    {
        m_head = create_node(t_value);
        return t_value;
    }

    while (head->next())
    {
        head = head->next();
    }

    head->set_next(create_node(t_value));

    return t_value;
}

template <class T>
void my::List<T>::pop_front()
{
    my::Node<T> *prev = m_head;
    m_head = m_head->next();
    prev->set_next(nullptr);

    delete prev;
}

template <class T>
void my::List<T>::pop_back()
{
    my::Node<T> head = m_head;
    my::Node<T> *prev = nullptr;

    if (head != nullptr)
    {
        return;
    }

    while (head->next())
    {
        prev = head;
        head = head->next();
    }

    prev->set_next(nullptr);
    delete head;
}

template <class T>
void my::List<T>::erase(T t_value)
{
    my::Node<T> *head = m_head;
    my::Node<T> *prev = nullptr;

    while (head)
    {
        if (head->value() == t_value)
        {
            prev->set_next(head->next());

            head->set_next(nullptr);

            delete head;
            return;
        }

        prev = head;
        head = head->next();
    }
}

template <class T>
void my::List<T>::erase(my::Node<T> *t_node)
{
    my::Node<T> *head = m_head;
    my::Node<T> *prev = nullptr;

    while (head)
    {
        if (head == t_node)
        {
            if (prev == nullptr)
            {
                m_head = head->next();
            }
            else
            {
                prev->set_next(head->next());
            }

            head->set_next(nullptr);

            delete head;
            return;
        }

        prev = head;
        head = head->next();
    }
}

template <class T>
void my::List<T>::print(std::ostream &os, char t_end) const
{
    my::Node<T> *head = m_head;

    if (head == nullptr)
    {
        return;
    }

    while (head->next())
    {
        os << head->value() << t_end;
        head = head->next();
    }

    os << head->value();
}

// template <class T>
// std::ostream &operator<<(std::ostream &os, const my::List<T> &t_list)
// {
//     my::Node<T> *head = t_list.head();

//     while (head)
//     {
//         os << head->value() << " ";
//         head = head->next();
//     }

//     return os;
// }

template <class T>
bool my::List<T>::empty()
{
    return m_head == nullptr ? true : false;
}

template <class T>
my::Node<T> *my::List<T>::create_node(const T &t_value, my::Node<T> *t_next)
{
    return new my::Node<T>(t_value, t_next);
}
