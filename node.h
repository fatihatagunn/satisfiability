namespace my
{
    template <class T>
    class Node
    {
    public:
        Node(const T &t_value = 0, Node<T> *t_next = nullptr);

        ~Node();

        const T &value() const;
        Node<T> *next() const;

        void set_value(const T &t_value);
        void set_next(Node<T> *t_next);

    private:
        T m_value;
        Node<T> *m_next{nullptr};
    };
}
