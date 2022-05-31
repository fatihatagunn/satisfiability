#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

#include "word.cpp"

class Sentence
{
public:
    Sentence();
    Sentence(std::string t_file_path);

    const my::List<Word> &words() const;
    size_t letter_size() const;

    void resolution();

    void dpll_brute_force(std::ostream &os, size_t t_max_loop);

    void increment_logic_states();

    void remove_ineffective_letters();

    bool is_sat() const;

    void read_file(const std::string &t_file_path);

    friend std::ostream &operator<<(std::ostream &os, const Sentence &t_sentence);

private:
    my::List<Word> m_words;
    size_t m_letter_size{0};
    size_t m_word_size{0};
    size_t m_ineffective_letter_size{0};
    uint8_t *m_logic_states;
    bool m_is_sat{false};
    const static char comment = 'c';
    const static char program = 'p';
};
