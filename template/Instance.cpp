#include "Instance.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

Instance::Instance() : N(0), M(0) {
}

bool Instance::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return false;
    }
    
    // Leer numero de segmentos
    file >> N;
    if (N <= 0) {
        std::cerr << "Error: Invalid number of segments" << std::endl;
        return false;
    }
    
    // Leer numero de influencers
    file >> M;
    if (M <= 0) {
        std::cerr << "Error: Invalid number of influencers" << std::endl;
        return false;
    }
    
    
    // Leer informacion de los influencers
    std::string line;
    std::getline(file, line);
    
    for (int i = 0; i < M; i++) {
        std::getline(file, line);
        std::stringstream ss(line);
        std::string token;
        
        // Leer costo (primer elemento)
        if (std::getline(ss, token, ',')) {
             //el cout es un placeholder, decidir que hacer con el costo
            std::cout << "Costo del influencer " << i << ": " << token << std::endl;
        } else {
            std::cerr << "Error: No se puede leer el costo del influencer " << i << std::endl;
            return false;
        }
        
        // Leer segmentos (elementos restantes)
        while (std::getline(ss, token, ',')) {
            int segment = std::stoi(token);
            //el cout es un placeholder, decidir que hacer con los segmentos
            std::cout << "Segmento " << segment << " del influencer " << i << std::endl; 
        }
    }
    
    file.close();
    return true;
}

int Instance::getNumSegments() const {
    return N;
}

int Instance::getNumInfluencers() const {
    return M;
}

