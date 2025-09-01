#include "Solution.h"
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

Solution::Solution(int numInfluencers) {
    _solution = {};
    _costos = vector<int>(numInfluencers, 0); //inicializo vector de costos con ceros
}

void Solution::addInfluencer(int influencer) {
    //NECESITO CHEQUEAR QUE EL INFLUENCER SEA VALIDO??? 
    _solution[influencer] = _costos[influencer]; //agrego el influencer al subconjunto
}

void Solution::removeInfluencer(int influencer) {
    if (find(_solution.begin(), _solution.end(), influencer) != _solution.end()) { // si está en el subconjunto
        _solution.erase(_solution.begin() + influencer);
    }else{
        cout << "El influencer: " << influencer << " no esta en el diccionario" << endl;
    }
}

bool Solution::containsInfluencer(int influencer) const {
    if (find(_solution.begin(), _solution.end(), influencer) != _solution.end()) { // si está en el subconjunto
        return true;
    } else {
        return false;
    }
}

void Solution::printSolution() const {
    cout << "Solución actual:" << endl;
    for (size_t i = 0; i < _solution.size(); i++) {
        cout << "Influencer " << i << ": costo = " << _solution[i] << endl;
    }
}

/*
    // 1. Crear instancia y cargar manualmente influencers
    Instance inst = {};
    inst.loadFromFile("C:/Users/juani/OneDrive/Documentos/Di Tella/2025/TD V/templatetp1/template/selected_instances/prueba.txt");
    Solution sol(3);
    std::cout << "Cargando archivo..." << std::endl;

    // 3. Probar agregar influencers válidos
    sol.addInfluencer(6, inst); // no debería insertarlo
    sol.addInfluencer(1, inst); // debería insertarlo
    sol.addInfluencer(3, inst);
    sol.addInfluencer(0, inst); // debería mostrar "Ya está en el diccionario ó no es válido"

    // 4. Probar agregar un influencer inválido (no está en Instance)
    sol.addInfluencer(5, inst); // debería mostrar "Ya está en el diccionario ó no es válido"

    sol.printSolution();

    // 5. Probar eliminar influencers
    sol.removeInfluencer(3); // debería eliminarlo
    sol.removeInfluencer(4); // debería mostrar "No está en el diccionario"
    
    sol.printSolution();
    return 0;
}

if ((_solution.find(influencer) == _solution.end()) && (inst.hasInfluencer(influencer))) { 
        // si  está en el subconjunto y SÍ es un influencer válido lo pisa
        _solution.at(influencer) = {inst.getInfluencer(influencer).first, inst.getInfluencer(influencer).second}; 

*/