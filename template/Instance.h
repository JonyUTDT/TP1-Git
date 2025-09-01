#ifndef INSTANCE_H
#define INSTANCE_H

#include <vector>
#include <string>

class Instance {
private:
    int N; // Numero de segmentos
    int M; // Numero de influencers
   
    //Decidir estructura de instancia

public:
    // Constructor
    Instance();
    
    // Cargar instancia desde archivo
    bool loadFromFile(const std::string& filename);
    
    // Getters
    int getNumSegments() const;
    int getNumInfluencers() const;
   
    
    // Mostrar informacion de la instancia
    void printInstance() const;

};

#endif // INSTANCE_H
