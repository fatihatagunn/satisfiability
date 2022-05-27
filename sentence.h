#include <iostream>
#include <fstream>
#include <sstream>

#include "word.cpp"

class Sentence
{
public:
    Sentence();
    Sentence(std::string t_file_path);

    void resolution();

    void read_file(const std::string &t_file_path);

private:
    my::List<Word> m_words;
    const static char comment = 'c';
    const static char program = 'p';
};
