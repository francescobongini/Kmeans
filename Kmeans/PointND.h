//
// Created by Francesco on 1/13/19.
//

#ifndef KMEANS_SERIALE_POINTND_H
#define KMEANS_SERIALE_POINTND_H


#include <vector>
#include "cmath"
using namespace std;

class PointND {
public:
    PointND(std::vector<float>* punto3);
    PointND();
    float distanceFrom(PointND punto3);
    std::vector<float>* getCoordinate();
    void  setCluster(int vicino);
    void stampaCoordinate();
    int getClusterAppartenenza();
    bool confrontaCoord(std::vector<float>* coordinate);
protected:
private:
    std::vector<float> coordinate;
    int indiceClusterAppartenenza; //indice nel vettore dei centroidi che indica la posizione del centoide più vicino.
    //puo cambiare ad ogni iterazione.
};


#endif //KMEANS_SERIALE_POINTND_H
//pippo.at(i).getcoordinate.at(j)