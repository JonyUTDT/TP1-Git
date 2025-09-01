#include "BruteForceSolver.h"
#include <iostream>
#include <algorithm>

BruteForceSolver::BruteForceSolver() {}

Solution BruteForceSolver::solve(const Instance& instance) {
    Solution bestSolution(instance.getNumInfluencers());
    return bestSolution;
}

