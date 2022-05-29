#include <iostream>

#include "node.cpp"

namespace my
{

    // template <class T>
    // class List;

    // template <class T>
    // std::ostream &operator<<(std::ostream &os, const my::List<T> &t_list);

    template <class T>
    class List
    {
    public:
        List();

        // ~List();

        my::Node<T> *head() const;

        T insert_sort(const T &t_value);
        T insert_sort_u(const T &t_value);
        T insert_abs_sort_u(const T &t_value);

        T push_front(const T &t_value);
        T push_back(const T &t_value);

        void pop_front();
        void pop_back();

        void erase(T t_value);
        void erase(my::Node<T> *t_node);

        void print(std::ostream &os, char t_end = ' ') const;

        friend std::ostream &operator<<(std::ostream &os, const List<T> &t_list)
        {
            my::Node<T> *head = t_list.head();

            if (head == nullptr)
            {
                return os;
            }

            while (head->next())
            {
                os << head->value() << ' ';
                head = head->next();
            }

            return os << head->value();
        }

        bool empty();

    protected:
        my::Node<T> *create_node(const T &t_value, my::Node<T> *t_next = nullptr);

    private:
        my::Node<T> *m_head{nullptr};
    };
}
