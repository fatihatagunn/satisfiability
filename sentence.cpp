#include "sentence.h"

Sentence::Sentence()
    : m_words()
{
}

Sentence::Sentence(std::string t_file_path)
    : m_words()
{
    read_file(t_file_path);
    
    m_logic_states = new uint8_t[m_letter_size];

    for (size_t i = 0; i < m_letter_size; ++i)
    {
        m_logic_states[i] = 0;
    }
}

const my::List<Word> &Sentence::words() const
{
    return m_words;
}

size_t Sentence::letter_size() const
{
    return m_letter_size;
}

void Sentence::resolution()
{
    my::Node<Word> *head_f = m_words.head();
    my::Node<Word> *head_s;

    Word word;

    while (head_f)
    {
        head_s = m_words.head();
        while (head_s)
        {
            word = head_f->value().resolution(head_s->value());

            if (word.weight() != 0)
            {
                m_words.erase(head_f);
                m_words.erase(head_s);
                m_words.push_front(word);
                head_s = m_words.head();

                break;
            }
            else if (!word.empty())
            {
                std::cout << "(" << head_f->value() << ") (" << head_s->value() << ") therefore the sentence is UNSAT." << std::endl;
                return;
            }

            head_s = head_s->next();
        }
        head_f = word.weight() != 0 ? m_words.head() : head_f->next();
    }
}

void Sentence::dpll_brute_force(std::ostream &os, size_t t_max_loop)
{
    remove_ineffective_letters();

    size_t logic_count = pow(2, m_letter_size - m_ineffective_letter_size);

    for (size_t i = 0; i < m_letter_size; ++i)
    {
        os << i + 1 << ";";
    }
    os << std::endl;

    size_t i;

    for (size_t i = 0; i < logic_count && i < t_max_loop; ++i)
    {
        my::Node<Word> *head = m_words.head();

        while (head)
        {
            if (head->value().or_the_word(m_logic_states) == 0)
            {
                break;
            }

            head = head->next();
        }

        if (!head)
        {
            m_is_sat = true;
            
            for (size_t j = 0; j < m_letter_size; ++j)
            {
                os << (int)m_logic_states[j] << ";";
            }
            os << std::endl;
        }

        increment_logic_states();
    }

    if (i == t_max_loop && m_is_sat == false)
    {
        std::cout << "Maximum number of cycles reached!" << std::endl;
    }
}

void Sentence::increment_logic_states()
{
    size_t i = m_letter_size - 1;

    // for (size_t i = 0; i < m_letter_size; ++i)
    // {
    //     std::cout << (int) m_logic_states[i] << " ";
    // }
    // std::cout << " : " << std::endl;

    while (true)
    {
        if (m_logic_states[i] == 0)
        {
            m_logic_states[i] = 1;
            break;
        }
        else if (m_logic_states[i] == 1)
        {
            m_logic_states[i] = 0;
            --i;
        }
        else
        {
            --i;
        }
    }
}

void Sentence::remove_ineffective_letters()
{
    for (size_t i = 0; i < m_letter_size; ++i)
    {
        m_logic_states[i] = 'x';
    }

    my::Node<Word> *head_sentence = m_words.head();

    while (head_sentence)
    {
        my::Node<int> *head_letter = head_sentence->value().letters().head();

        while (head_letter)
        {
            int i = abs(head_letter->value()) - 1;
            m_logic_states[i] = 0;
            head_letter = head_letter->next();
        }
        head_sentence = head_sentence->next();
    }

    for (size_t i = 0; i < m_letter_size; ++i)
    {
        if (m_logic_states[i] != 0)
        {
            m_logic_states[i] = 'x';
            ++m_ineffective_letter_size;
        }
    }
}

bool Sentence::is_sat() const
{
    return m_is_sat;
}

void Sentence::read_file(const std::string &t_file_path)
{
    std::ifstream file{t_file_path, std::ios::binary};
    std::string line;
    char line_c[100];

    file.getline((char *)&(line_c), 100, '\n');

    do
    {
        line = std::string(line_c);
        file.getline((char *)&line_c, 100, '\n');

        if (line[0] == 'c')
        {
            std::cout << line << " : " << line.size() << std::endl;
            continue;
        }

        if (line[0] == 'p')
        {
            char l_program;
            std::string cnf;

            std::istringstream(line) >> l_program >> cnf >> m_letter_size >> m_word_size;

            std::cout << l_program << " "
                      << cnf << " " << m_letter_size << " "
                      << m_word_size << std::endl;

            continue;
        }
        m_words.push_back(Word(line));

    } while (!file.eof());

    // std::cout << m_words << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Sentence &t_sentence)
{
    my::Node<Word> *head = t_sentence.m_words.head();

    if (head == nullptr)
    {
        return os;
    }

    while (head->next())
    {
        os << head->value() << std::endl;
        head = head->next();
    }

    return os << head->value();
}
