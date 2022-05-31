#include <iostream>
#include <cmath>

#include "sentence.cpp"

int main()
{
    std::string project_path = "/home/fatih/Projects/satisfiability/";
    std::string file_name = "pr" + std::to_string(7);

    Sentence sentence(project_path + "dimacs/" + file_name + ".txt");

    sentence.resolution();

    std::ofstream file_res{project_path + "outputs/resolution_" + file_name + ".txt"};

    file_res << sentence << std::endl;

    file_res.close();

    std::ofstream file_dpll{project_path + "outputs/dpll_" + file_name + ".csv"};

    sentence.dpll_brute_force(file_dpll, pow(2, 24));

    std::cout << file_name << " is " << (sentence.is_sat() ? "SAT" : "UNSAT") << std::endl;

    file_dpll.close();
}
