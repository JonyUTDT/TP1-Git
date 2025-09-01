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
    vector<int> _solution; //subconjunto de influencers que cubre todos los N segmentos, 
    //cada pos es un influencer y en v[i] está su costo
    vector<int> _costos;
    //con el menor costo total
    //map<int, set<int>> _segmentosInf; mapea todos los segmentos que cubre cada influencer

public:
    // Constructors
    Solution(int numInfluencers);
    void addInfluencer(int influencer);
    void removeInfluencer(int influencer);
    bool containsInfluencer(int influencer) const;
    void printSolution() const;
    
    
};

#endif // SOLUTION_H
