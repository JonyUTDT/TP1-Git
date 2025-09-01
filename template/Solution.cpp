#include "Solution.h"
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

Solution::Solution(int numInfluencers) {

    _costoTotal = 0; // Inicializo el costo total en 0
    _segmentosCubiertos = {}; // Inicializo los segmentos cubiertos en cero
    _influencersUsados = vector<int>(numInfluencers, 0); // Inicializa el vector de influencers usados con todas las posiciones en cero, no tengo ningun influencer

}

void Solution::addInfluencer(int influencer, const Instance& inst) {

    if ((_influencersUsados[influencer] == 0) && (inst.hasInfluencer(influencer))) { 

        // si NO está en el subconjunto y SÍ es un influencer válido
        _influencersUsados[influencer] = 1; // lo agrego al vector de influencers usados
        _segmentosCubiertos.insert(inst.getInfluencer(influencer).second.begin(), inst.getInfluencer(influencer).second.end()); // agrego los segmentos cubiertos
        _costoTotal = _costoTotal + inst.getInfluencer(influencer).first; // actualizo el costo total

    } else if ((_influencersUsados[influencer] == 0) && !(inst.hasInfluencer(influencer))) {

        cout << "El influencer: " << influencer << " No es valido" << endl;

    } else {

        cout << "El influencer: " << influencer << " Ya esta en el diccionario" << endl;
    
    }

}

void Solution::removeInfluencer(int influencer, const Instance& inst) {

    if (_influencersUsados[influencer] == 1) { 
        
        _influencersUsados[influencer] = 0;
        _costoTotal -= inst.getInfluencer(influencer).first;

        // Reconstruir los segmentos cubiertos desde cero
        _segmentosCubiertos.clear();
        for (size_t i = 0; i < _influencersUsados.size(); i++) {
            if (_influencersUsados[i] == 1) {
                _segmentosCubiertos.insert(
                    inst.getInfluencer(i).second.begin(),
                    inst.getInfluencer(i).second.end()
                );
            }
        }

    } else {

        cout << "El influencer: " << influencer << " No esta en el diccionario" << endl;
    
    }

}

bool Solution::containsInfluencer(int influencer) const {

    if (_influencersUsados[influencer] == 1) {
        return true;
    } else {
        return false;
    }

}

void Solution::printSolution() const {

    cout << "Solucion actual:" << endl;
    cout << "Influencers usados: ";
    for (size_t i = 0; i <= _influencersUsados.size(); ++i) {
        if (_influencersUsados[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "Costo total: " << _costoTotal << endl;
    cout << "Segmentos cubiertos: { ";
    for (int s : _segmentosCubiertos) cout << s << " ";
    cout << "}" << endl;

}