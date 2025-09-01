#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "Instance.h"

using namespace std;

class Solution {
    //lista de influencers que cubren todos los segmentos con el menor costo
private:
    int _costoTotal; // costo total de la solucion
    set<int> _segmentosCubiertos; // Set de segmentos cubiertos por los influencers en la solucion
    vector<int> _influencersUsados; // Vector de influencers usados en la solucion

public:
    // Constructors
    Solution(int numInfluencers);
    void addInfluencer(int influencer, const Instance& inst);
    void removeInfluencer(int influencer, const Instance& inst);
    bool containsInfluencer(int influencer) const;
    void printSolution() const;
    
    
};

#endif // SOLUTION_H
