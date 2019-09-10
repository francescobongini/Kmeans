//
// Created by Francesco on 1/13/19.
//

#ifndef KMEANS_SERIALE_KMEANS_H
#define KMEANS_SERIALE_KMEANS_H

#include <vector>
#include "PointND.h"

using namespace std;

class Kmeans{
public:
    Kmeans(int numero_thread);
    Kmeans(std::vector<PointND>* vettore);
    Kmeans();
    vector<PointND>* getPunti ();
    vector<PointND>* getListacentroidi ();
    void generaCentroidi(int k);
    bool confrontaCentroidi();
    void upgradecentroidi(int k);
    void kmeans(int k);
    void kmeans_omp(int k);
    void kmeans_sequenziale(int k);
    void kmeans_parallelo(int k);
    void stampaCluster();
    void ClusterToCSV();
    void stampaCentroidi();

private:
    vector<PointND> punti;
    vector<PointND> listacentroidi;
    vector<PointND> newlistacentroidi;
    int nThread;
};

#endif //KMEANS_SERIALE_KMEANS_H
