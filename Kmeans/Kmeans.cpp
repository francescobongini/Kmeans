//
// Created by Francesco on 1/13/19.
//
#include <fstream>
#include "Kmeans.h"
#include <math.h>
#include "PointND.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
//librerie per versione parallela
#ifdef _OPENMP
#include <omp.h> // for OpenMP library functions
#endif
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

Kmeans::Kmeans(int numero_thread){
    nThread = numero_thread;
}
Kmeans::Kmeans(std::vector<PointND>* vettore){

    for (int i = 0; i < vettore->size(); i++)
        punti.push_back(vettore->at(i));
}
Kmeans::Kmeans()
{

}
vector<PointND>* Kmeans::getPunti(){
    return &punti;
}

vector<PointND>* Kmeans::getListacentroidi(){
    return &listacentroidi;
}


void Kmeans::generaCentroidi(int k) {
    for (int i = 0; i < k; i++){
        listacentroidi.push_back(punti.at(rand() %(punti.size())));
    }
}

void Kmeans::stampaCentroidi() {
    for (int i=0; i < listacentroidi.size(); i++ )
        listacentroidi.at(i).stampaCoordinate();
}

void Kmeans::kmeans(int k) {
    for (int i = 0; i < punti.size(); i++){ //per ogni punto (riga)
        float min=100.0;
        int vicino;
        for (int j = 0; j < k; j++) { //per ogni centroide
            if (punti.at(i).distanceFrom(getListacentroidi()->at(j)) < min) {
                vicino = j;
                min =float (punti.at(i).distanceFrom(getListacentroidi()->at(j)));
            }
        }
        //assegni al punto i il nuovo centroide più vicino.
        punti.at(i).setCluster(vicino); //vicino è l'indice del vettore dei centroidi del centroide più vicino.
    }
}

void Kmeans::stampaCluster(){
    for (int i = 0; i < listacentroidi.size(); i++) {
        std :: cout << "Centroide" << i << " =" <<endl;
        listacentroidi.at(i).stampaCoordinate();
        std :: cout << "Lista appartenenza al centroide" <<endl;
        for(int j = 0; j < punti.size(); j++ ){
            if(punti.at(j).getClusterAppartenenza() == i ){
                punti.at(j).stampaCoordinate();
            }
        }
    }
}

void Kmeans::upgradecentroidi(int k) {
    newlistacentroidi=listacentroidi; //per non avere l'errore
    omp_set_dynamic(0);     // Explicitly disable dynamic teams
    omp_set_num_threads(nThread);
#pragma omp parallel for schedule (dynamic)
    for (int i = 0; i < listacentroidi.size() ; ++i) { //per ogni centroide
        for (int j = 0; j <punti.at(0).getCoordinate()->size() ; ++j) { //0 dato che è la stessa per tutti i punti
            int count=0;
            float sum=0.0;
            for (int l = 0; l <punti.size() ; ++l) {
                if(punti.at(l).getClusterAppartenenza() == i ){ //raggruppo i punti secondo il cluster di appartenenza
                    sum=sum+punti.at(l).getCoordinate()->at(j);
                    count=count+1;
                }
            }
            newlistacentroidi.at(i).getCoordinate()->at(j)=sum/count;
        }
    }
}

bool Kmeans::confrontaCentroidi(){
    for(int i = 0; i < listacentroidi.size(); i++){
        float distanza = listacentroidi.at(i).distanceFrom(newlistacentroidi.at(i));
        std::cout <<"distanza: " <<distanza << endl;
        if(listacentroidi.at(i).distanceFrom(newlistacentroidi.at(i)) > 0.001){
            return false;
        }
    }
    return true;
}

void Kmeans::kmeans_sequenziale(int k){
    int count=0;
    do{
        if(count != 0)
            listacentroidi = newlistacentroidi;
        kmeans(k);                //originale (sequenziale)
        upgradecentroidi(k);
        count++;
    }
    while (!confrontaCentroidi());
    std::cout <<" kmeans sequenziale svolto in "<<count<< " iterazioni" << std::endl;
}

void Kmeans::kmeans_parallelo(int k){
    int count=0;
    std::cout<< "Punti " << punti.size()<<std::endl;
    do{
        if(count != 0)
            listacentroidi = newlistacentroidi;
        kmeans_omp(k);                //con omp
        upgradecentroidi(k);
        count++;
    }
    while (!confrontaCentroidi());
    //while (count<100); //per l'analisi al variare di k
    std::cout <<" kmeans parallelo svolto in "<<count<< " iterazioni" << std::endl;
}


void Kmeans::kmeans_omp(int k) {
    omp_set_dynamic(0);     // Explicitly disable dynamic teams
    omp_set_num_threads(nThread);
#pragma omp parallel for schedule (dynamic)
    for (int i = 0; i < punti.size(); i++) { //per ogni punto (riga)
        float min = 100.0;
        int vicino;
        for (int j = 0; j < k; j++) { //per ogni centroide
            if (punti.at(i).distanceFrom(getListacentroidi()->at(j)) < min) {
                vicino = j;
                min = punti.at(i).distanceFrom(getListacentroidi()->at(j));
            }
        }
        //assegni al punto i il nuovo centroide più vicino.
        punti.at(i).setCluster(vicino); //vicino è l'indice del vettore dei centroidi del centroide più vicino.
    }

}

void Kmeans::ClusterToCSV() { //per stampare i cluster nel CSV
    std::ofstream outputFile("output.csv");
    outputFile << "x1"<<","<<"x2"<<","<<"x3"<<","<<"cluster"<< "\n"; //solo in caso di K=3
    for (int i = 0; i < listacentroidi.size(); i++) {
        for (int j = 0; j < punti.size(); j++) {
            if (punti.at(j).getClusterAppartenenza() == i) {
                for (int p = 0; p < punti.at(j).getCoordinate()->size(); p++) {
                    outputFile << punti.at(j).getCoordinate()->at(p) << ",";
                }
                outputFile << i << "\n";
            }
        }
    }
}
