#include "sentence.h"

Sentence::Sentence()
    : m_words()
{
}

Sentence::Sentence(std::string t_file_path)
    : m_words()
{
    read_file(t_file_path);
}

const my::List<Word> &Sentence::words() const
{
    return m_words;
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
            head_s = head_s->next();
        }
        head_f = word.weight() != 0 ? m_words.head() : head_f->next();
    }
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
            size_t letter_size;
            size_t word_size;

            std::istringstream(line) >> l_program >> cnf >> letter_size >> word_size;

            std::cout << l_program << " "
                      << cnf << " " << letter_size << " "
                      << word_size << std::endl;

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
