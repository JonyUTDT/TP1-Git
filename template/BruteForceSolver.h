#ifndef BRUTEFORCE_SOLVER_H
#define BRUTEFORCE_SOLVER_H

#include "Instance.h"
#include "Solution.h"

class BruteForceSolver {
private:
   // Solution _bf;

public:
    BruteForceSolver();
    Solution solve(const Instance& instance);
    
    
    
};

#endif // BRUTEFORCE_SOLVER_H
