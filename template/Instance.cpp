#include "Instance.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

Instance::Instance() : N(0), M(0) {
    _instancia = {};
}

bool Instance::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Cannot open file " << filename << endl;
        return false;
    }
    
    // Leer numero de segmentos
    file >> N;
    if (N <= 0) {
        cout << "Error: Invalid number of segments" << endl;
        return false;
    }
    
    // Leer numero de influencers
    file >> M;
    if (M <= 0) {
        cout << "Error: Invalid number of influencers" << endl;
        return false;
    }
    
    
    // Leer informacion de los influencers
    string line;
    getline(file, line);
    
    for (int i = 0; i < M; i++) {
        getline(file, line);
        stringstream ss(line);
        string token;
        set<int> segments;
        int cost;
        // Leer costo (primer elemento)
        if (getline(ss, token, ',')) {
             //el cout es un placeholder, decidir que hacer con el costo
            cost = stoi(token);
            //_instancia[i+1] = {cost, {segments}};
            //std::cout << "Costo del influencer " << i+1 << ": " << token << std::endl;
        } else {
            //std::cerr << "Error: No se puede leer el costo del influencer " << i+1 << std::endl;
            return false;
        }
        
        // Leer segmentos (elementos restantes)
        while (getline(ss, token, ',')) {
            int segment = stoi(token);
            //el cout es un placeholder, decidir que hacer con los segmentos
            segments.insert(segment);
            //std::cout << "Segmento " << segment << " del influencer " << i+1 << std::endl; 
        }
        _instancia[i+1] = {cost, segments};
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

bool Instance::hasInfluencer(int influencer) const {
    return _instancia.find(influencer) != _instancia.end();
}

const pair<int, set<int>>& Instance::getInfluencer(int influencer) const {
    return _instancia.at(influencer);
}

void Instance::printInstance() const {
    cout << "Numero de segmentos: " << N << "\n";
    cout << "Numero de influencers: " << M << "\n";

    for (const auto& [id, data] : _instancia) {
        const auto& [costo, segmentos] = data;

        cout << "Influencer " << id
                  << ": Costo = " << costo
                  << ", Segmentos = {";

        for (auto it = segmentos.begin(); it != segmentos.end(); ) {
            cout << *it;
            if (++it != segmentos.end()) cout << ", ";
        }
        cout << "}\n";
    }
}

/*
    Instance inst;

    // Probar carga
    if (inst.loadFromFile("C:/Users/juani/OneDrive/Documentos/Di Tella/2025/TD V/templatetp1/template/selected_instances/prueba.txt")) {
        std::cout << "Archivo cargado correctamente." << std::endl;

        // Probar tus getters
        for (int i = 0; i < 2; i++) { // acá supongo 2 influencers
            if (inst.hasInfluencer(i)) {
                auto data = inst.getInfluencer(i);
                int costo = data.first;
                const std::set<int>& segmentos = data.second;

                
            }
        }

        inst.printInstance();
    } else {
        cout << "Error al cargar archivo." << endl;
    }

    return 0;
}
*/