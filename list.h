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

        void insert_sort(T t_value);
        void insert_sort_u(T t_value);
        void insert_abs_sort_u(T t_value);

        void push_front(T t_value);
        void push_back(T t_value);

        void pop_front();
        void pop_back();

        void erase(T t_value);
        void erase(my::Node<T> *t_node);

        friend std::ostream &operator<<(std::ostream &os, const List<T> &t_list)
        {
            my::Node<T> *head = t_list.head();

            while (head)
            {
                os << head->value() << " ";
                head = head->next();
            }

            return os;
        }

        bool empty();

    protected:
        my::Node<T> *create_node(T t_value, my::Node<T> *t_next = nullptr);

    private:
        my::Node<T> *m_head{nullptr};
    };
}
