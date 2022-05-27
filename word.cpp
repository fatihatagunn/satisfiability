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

Word &Word::resolution(Word &other) const
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

    Word *n_word = new Word();

    if (opposite_count == 1)
    {
        head_m = m_letters.head();
        head_o = other.m_letters.head();

        while (head_m)
        {
            if (head_m->value() != value_m)
            {
                n_word->m_letters.insert_abs_sort_u(head_m->value());
                n_word->m_weight += abs(head_m->value());
            }
            head_m = head_m->next();
        }

        while (head_o)
        {
            if (head_o->value() != value_o)
            {
                n_word->m_letters.insert_abs_sort_u(head_o->value());
                n_word->m_weight += abs(head_m->value());
            }
            head_o = head_o->next();
        }
    }

    return *n_word;
}

Word &Word::operator=(const Word &other)
{
    my::Node<int> *head = other.m_letters.head();

    while (!m_letters.empty())
    {
        m_letters.pop_front();
    }

    while (head)
    {
        m_letters.push_back(head->value());
        head = head->next();
    }

    m_weight = other.m_weight;

    return *this;
}

std::ostream &operator<<(std::ostream &os, Word &t_word)
{
    os << t_word.m_letters << "W: " << t_word.m_weight << std::endl;
    return os;
}

bool Word::empty()
{
    return m_letters.empty();
}
