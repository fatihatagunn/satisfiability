#include <iostream>

#include "sentence.cpp"

int main()
{
    Sentence sentence1("/home/fatih/Projects/satisfiability/dimacs/pr1.txt");
    Sentence sentence2("/home/fatih/Projects/satisfiability/dimacs/pr2.txt");

    Word word;
    Word word1("1 4 -6 0");
    Word word2("1 -4 -6 0");
    Word word3("-1 4 -6 0");
    Word word4("-1 -4 6 0");
    Word word5("2 4 -7 0");
    Word word6("2 -4 -7 0");
    Word word7("-2 4 -7 0");
    Word word8("-2 -4 7 0");
    Word word9("3 4 -8 0");
    Word word10("3 -4 -8 0");
    Word word11("-3 4 -8 0");

    std::cout << "Word 1: " << word1;
    std::cout << "Word 2: " << word2;
    std::cout << "Word 3: " << word3;
    std::cout << "Word 4: " << word4;
    std::cout << "Word 5: " << word5;

    word = word1.resolution(word2);
    std::cout << "Word Resolution (W1 & W2): " << word;

    word = word.resolution(word3);
    std::cout << "Word Resolution (W & W3): " << word;

    word = word4.resolution(word5);
    std::cout << "Word Resolution (W4 & W5): " << word;
}
