#include <iostream>

#include "sentence.cpp"

int main()
{
    Sentence sentence1("/home/fatih/Projects/satisfiability/dimacs/pr1.txt");
    Sentence sentence2("/home/fatih/Projects/satisfiability/dimacs/pr2.txt");

    sentence1.resolution();

    std::ofstream file{"words.txt"};

    file << sentence1 << std::endl;

    file.close();
}
