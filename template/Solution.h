#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include "Instance.h"

class Solution {
private:


public:
    // Constructors
    Solution(int numInfluencers);
    void addInfluencer(int influencer);
    void removeInfluencer(int influencer);
    bool containsInfluencer(int influencer) const;
    void printSolution() const;
    
    
};

#endif // SOLUTION_H
