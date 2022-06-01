#include <iostream>
#include <cmath>
#include <sys/time.h>

#include "sentence.cpp"

double getProcessTime(struct timeval tStart, struct timeval tStop)
{

    return (tStop.tv_sec - tStart.tv_sec) * 1000.0 + (tStop.tv_usec - tStart.tv_usec) / 1000.0;
}

int main()
{
    std::string project_path = "/home/fatih/Projects/satisfiability/";
    std::string file_name = "pr" + std::to_string(1);

    Sentence sentence(project_path + "dimacs/" + file_name + ".txt");

    struct timeval tStart, tStop;

    gettimeofday(&tStart, NULL);

    // sentence.resolution();
    // std::ofstream file_res{project_path + "outputs/resolution_" + file_name + ".txt"};
    // file_res << sentence << std::endl;
    // file_res.close();

    // std::ofstream file_dpll_s{project_path + "outputs/dpll_s_" + file_name + ".csv"};
    // sentence.dpll_serial(file_dpll_s, 27);
    // file_dpll_s.close();

    std::ofstream file_dpll_p{project_path + "outputs/dpll_p_" + file_name + ".csv"};
    sentence.dpll_parallel(file_dpll_p, 27, 4);
    file_dpll_p.close();

    std::cout << file_name << " is " << (sentence.is_sat() ? "SAT" : "UNSAT") << std::endl;

    gettimeofday(&tStop, NULL);

    std::cout << "Total Process Time = " << getProcessTime(tStart, tStop) << " ms" << std::endl;
}
