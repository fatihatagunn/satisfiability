#include <iostream>
#include <fstream>
#include <sstream>

#include "word.cpp"

class Sentence
{
public:
    Sentence();
    Sentence(std::string t_file_path);

    const my::List<Word> &words() const;

    void resolution();

    void read_file(const std::string &t_file_path);

    friend std::ostream &operator<<(std::ostream &os, const Sentence &t_sentence);

private:
    my::List<Word> m_words;
    const static char comment = 'c';
    const static char program = 'p';
};
