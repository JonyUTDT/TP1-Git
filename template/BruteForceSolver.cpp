#include "BruteForceSolver.h"
#include <iostream>
#include <algorithm>

BruteForceSolver::BruteForceSolver() {}


Solution BruteForceSolver::solve(const Instance& instance) {
    int i = 1; 
    Solution bestSolution(instance.getNumInfluencers()); //inicializo vector a devolver
    //Caso base
    if (i == instance.getNumInfluencers()) {
        return bestSolution;
    }else{
        instance[i] 
        bestSolution.addInfluencer();
        bestSolution = solve(instance + i);
    }

    // Comparo de manera iterativa
    //menor costo
    for (int j = 0; j < instance.getNumInfluencers(); j++) {

    //cubre todos los segmentos la solucion ?

    return bestSolution;
}


