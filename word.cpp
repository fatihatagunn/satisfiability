#include "word.h"

Word::Word()
    : m_letters()
{
}

Word::Word(std::string t_word)
    : m_letters()
{
    if (t_word[t_word.size() - 2] == ' ' && t_word[t_word.size() - 1] == s_end)
    {
        t_word.pop_back();
    }
    else
    {
        throw std::runtime_error("Error");
    }

    size_t pos = 0;
    int letter;

    while ((pos = t_word.find(s_delimiter)) != std::string::npos)
    {
        letter = std::stoi(t_word.substr(0, pos));
        m_letters.insert_abs_sort_u(letter);
        m_weight += abs(letter);
        t_word.erase(0, pos + sizeof(s_delimiter));
    }
}

const my::List<int> &Word::letters() const
{
    return m_letters;
}

int Word::weight() const
{
    return m_weight;
}

Word Word::resolution(const Word &other) const
{
    size_t opposite_count = 0;

    my::Node<int> *head_m = m_letters.head();
    my::Node<int> *head_o;
    int value_m, value_o;

    while (head_m)
    {
        head_o = other.m_letters.head();
        while (head_o)
        {
            if (head_m->value() + head_o->value() == 0)
            {
                ++opposite_count;

                value_m = head_m->value();
                value_o = head_o->value();
            }
            head_o = head_o->next();
        }
        head_m = head_m->next();
    }

    Word n_word;

    if (opposite_count == 1)
    {
        head_m = m_letters.head();
        head_o = other.m_letters.head();

        while (head_m)
        {
            if (head_m->value() != value_m)
            {
                n_word.m_weight += abs(n_word.m_letters.insert_abs_sort_u(head_m->value()));
            }
            head_m = head_m->next();
        }

        while (head_o)
        {
            if (head_o->value() != value_o)
            {
                n_word.m_weight += abs(n_word.m_letters.insert_abs_sort_u(head_o->value()));
            }
            head_o = head_o->next();
        }

        if (n_word.m_weight == 0)
        {
            n_word.m_letters.push_front(0);
        }
    }

    return n_word;
}

uint8_t Word::or_the_word(const uint8_t *t_logic_states) const
{
    my::Node<int> *head = m_letters.head();

    while (head)
    {
        int i = abs(head->value()) - 1;
        uint8_t state = t_logic_states[i];

        if (head->value() < 0)
        {
            state = !state;
        }

        if (state)
        {
            return 1;
        }

        head = head->next();
    }

    return 0;
}

bool Word::operator<(const Word &other) const
{
    return m_weight < other.m_weight;
}

std::ostream &operator<<(std::ostream &os, const Word &t_word)
{
    os << "(" << t_word.letters() << ")";
    return os;
}

bool Word::empty()
{
    return m_letters.empty();
}
