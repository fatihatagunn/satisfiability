#include <iostream>
#include <stdexcept>
#include <string>

#include "list.cpp"

class Word
{
public:
    Word();
    Word(std::string t_word);

    Word &resolution(Word &other) const;

    Word &operator=(const Word &other);

    friend std::ostream &operator<<(std::ostream &os, Word &t_word);

    bool empty();

private:
    my::List<int> m_letters;
    uint m_weight{0};
    static const char s_delimiter{' '};
    static const char s_end{'0'};
};
