#include <iostream>
#include <stdexcept>
#include <string>

#include "list.cpp"

class Word
{
public:
    Word();
    Word(std::string t_word);

    const my::List<int> &letters() const;
    int weight() const;

    Word resolution(const Word &other) const;

    uint8_t or_the_word(const uint8_t *t_logic_states) const;

    bool operator<(const Word &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Word &t_word);

    bool empty();

private:
    my::List<int> m_letters;
    uint m_weight{0};
    static const char s_delimiter{' '};
    static const char s_end{'0'};
};
