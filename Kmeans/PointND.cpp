//
// Created by Francesco on 1/13/19.
//

#include <math.h>
#include "PointND.h"
#include <iostream>
#define K 3
//piu dimensioni
PointND::PointND(std::vector<float>* punto3){
    for (int i = 0; i < punto3->size(); i++)
        coordinate.push_back(punto3->at(i));  // -> perchè punto3 è l'indirizzo di un oggetto vector<float> (cioè vector<float>*)
}

vector<float>* PointND::getCoordinate(){
    return &coordinate;
}

void PointND::setCluster(int vicino){
    indiceClusterAppartenenza = vicino;
}

void PointND::stampaCoordinate(){
    std::cout << "( ";
    for (int i = 0; i < coordinate.size()-1; i++){
        cout << coordinate.at(i) << " , ";
    }
    cout << coordinate.at(K-1)<<" ) " <<endl;
}
int PointND::getClusterAppartenenza(){
    return indiceClusterAppartenenza;
}

float PointND::distanceFrom(PointND punto){
    float sum=0.0;
    for (int i = 0; i < coordinate.size(); i++)
        sum=sum+(powf(coordinate[i]-punto.getCoordinate()->at(i),2));
    //       std::cout << "differenza[" << i << "]=" << coordinate[i]-punto.getCoordinate()->at(i)<<endl; //stampa ogni differenza
    //       std::cout << "valore di coordinate capacity" << coordinate.size() <<endl; //numero coordinate
    return sqrtf(sum);
}


bool PointND::confrontaCoord(std::vector<float>* coordinate){
    for(int i = 0; i<this->coordinate.size();i++){
//        if(this->coordinate.at(i) != coordinate.at(i)){
        if(std::abs(this->coordinate.at(i) - coordinate->at(i)) > 0.001){
            return false;
        }
    }
    return true;
}