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

void Sentence::resolution()
{
    // Resolution all words of the file.
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

            std::cout << l_program << " " << cnf << " " << letter_size << " " << word_size << std::endl;

            continue;
        }
        m_words.insert_sort(Word(line));

    } while (!file.eof());

    std::cout << m_words << std::endl;
}
