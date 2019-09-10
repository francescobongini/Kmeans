#include "PointND.h"
#include "Kmeans.h"
#include <iostream>
#include <fstream>
#include "float.h"
#include "csvreader.h"
#include "Timer.h"

#define MODE 0 //definisce modalità: 1 per sequenziale e 0 per parallelo.
#define MAXNTHREAD 4 //definisce il numero di thread utilizzati nella modalita' parallela
#define K 3 //definisce il numero dei centroidi/cluster RICORDA CHE E' DEFINITO ANCHE IN POINTND.CPP
#define SCARTO_DISTANZA 0.01 //definisce la tolleranza max con la quale 2 punti vengono considerati uguali
#define DIM_DATASET 200000
#define FRAZIONI 1 //esegue l'algoritmo su n campioni del dataset quanti sono "FRAZIONI"
using namespace std;

int main() {
    CSVReader reader("C:/Users/Francesco/Desktop/dataset/200k.csv");
    Timer timer;
    if (MODE) {
        timer.start();
        Kmeans k_means = Kmeans(); // oggetto di tipo kmeans, al suo interno ci sono i punti
        reader.getData(k_means.getPunti()); //kmeans.getPunti ritorna un indirizzo.
        k_means.generaCentroidi(K); //NB: campionamento con reimmissione. La penultima riga non viene ritornata
        k_means.kmeans_sequenziale(K);
        timer.stop();
        // k_means.stampaCluster(); //stampare cluster?
        //     k_means.ClusterToCSV();
        std::cout << "time sequential code: " << timer.getElapsedTimeInSec() << " seconds \n";
    } else {
        std::ofstream outputFile("results.txt");
        outputFile << "nThread   " << ":" << "nPoint   " << ":" << "Time" << "\n";
        vector<PointND> centroidi[FRAZIONI];
        for (int i = 1; i <= MAXNTHREAD; i++) {
            outputFile << i << "\n";
            for (int j = 1; j <= FRAZIONI; j++) {
                    timer.start();
                    Kmeans k_means = Kmeans(i); //definisce poi da qui nThread
                    reader.getData(k_means.getPunti(), j * DIM_DATASET / FRAZIONI); //kmeans.getPunti ritorna un indirizzo.
                                       if (centroidi[j - 1].size() == 0) {
                    k_means.generaCentroidi(K); //NB: campionamento con reimmissione. La penultima riga non viene ritornata
                                           centroidi[j - 1] = *k_means.getListacentroidi();
                                       } else {
                                           *k_means.getListacentroidi() = centroidi[j - 1];
                                      }
                    k_means.stampaCentroidi();
                    k_means.kmeans_parallelo(K);
                    timer.stop();
                    //k_means.ClusterToCSV();
                    std::cout << "time parallel code: " << timer.getElapsedTimeInSec() << " seconds \n";
                    outputFile << "          " << j * DIM_DATASET / FRAZIONI << "         "
                               << timer.getElapsedTimeInSec()
                               << "\n";

            }
        }
    }
    return 0;
}


//genera dataset in R:
//library(data.table)
// b=cbind(rnorm(500),rnorm(500,1.1),rnorm(500,1.3))
// b=as.data.frame(b)
// fwrite(file="C:/Users/Francesco/Desktop/b.csv", b, row.names = FALSE, col.names = FALSE)
//14 feb aggiunto ciclo rispetto a K e ho cambiato parametri dove adesso c'e (s)