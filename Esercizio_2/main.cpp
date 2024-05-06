#include <iostream>
#include "SortingAlgorithm.hpp"
#include <time.h>
#include <chrono>

using namespace std;
using namespace SortLibrary;
using namespace chrono;

// la dimensione dei vettori viene inserita nella command line (inputCL)
// primo argomento = dimensione vettore di interi
// secondo argomento = dimensione vettore di stringhe.
// Inserendo un solo argomento le due dimensioni saranno
// identiche e pari a tale valore
int main(int n, char** inputCL)
{
    // inizializziamo il seme utilizzando il tempo del computer
    // in modo da avere un risultato diverso ad ogni iterazione
    srand(unsigned(time(NULL)));

    const string alphabet = "qwertyuioplkjhgfdsazxcvbnm";

    int dimI = 0;
    int dimS = 0;

    // l'input da command line deve essere un intero
    if (n == 2){
        dimI = stoi(inputCL[1]);
        dimS = dimI;}

    else if (n == 3){
        dimI = stoi(inputCL[1]);
        dimS = stoi(inputCL[2]);
    }

    else{
        cerr<<"il numero di interi inseriti nella command line puo' essere solo 1 o 2"<<endl;
        return 1;
    }

    cout<<"dimensione vettore di interi = "<<dimI<<endl<<endl;
    cout<<"dimensione vettore di stringhe = "<<dimS<<endl<<endl;

    // dichiarazione dei vettori da ordinare
    vector<int> vi = {};
    vector<string> vs = {};
    vi.reserve(dimI);
    vs.reserve(dimS);

    // generazione vettore numeri interi positivi casuali
    for (int i=0; i<dimI; i++){
        vi.push_back(rand());
    }

    // generazione vettore di stringhe di lunghezza 3
    // composte dalle lettere (minuscole) dell'alfabeto
    for (int i =0; i< dimS; i++) {
        string s = "";
        for (int j=0; j<3; j++){
            int pos = rand() % 26;
            s += alphabet[pos];
        }
        vs.push_back(s);
    }

    // vengono generate delle copie vettori casuali
    // in modo da essere ordinate dagli algoritmi
    // di BubbleSort e MergeSort
    vector<int> viB = {};
    vector<string> vsB = {};
    vector<int> viM = {};
    vector<string> vsM = {};
    viB.reserve(dimI);
    vsB.reserve(dimS);
    viM.reserve(dimI);
    vsM.reserve(dimS);
    viB = vi;
    vsB = vs;
    viM = vi;
    vsM = vs;


    // ordinamento con Bubble sort, con misurazione del tempo di elaborazione
    steady_clock::time_point beginIB = steady_clock::now();
    BubbleSort(viB);
    steady_clock::time_point endIB = steady_clock::now();
    cout<<"tempo di ordinamento BubbeSort vettore di interi = "<<duration_cast<microseconds>(endIB - beginIB).count() << " [microsecondi] \n" <<endl;

    steady_clock::time_point beginSB = steady_clock::now();
    BubbleSort(vsB);
    steady_clock::time_point endSB = steady_clock::now();
    cout<<"tempo di ordinamento BubbeSort vettore stringhe = "<<duration_cast<microseconds>(endSB - beginSB).count() << " [microsecondi] \n" <<endl;



    // ordimanento con Mergesort, con misurazione del tempo di elaborazione
    steady_clock::time_point beginIM = steady_clock::now();
    MergeSort(viM);
    steady_clock::time_point endIM = steady_clock::now();
    cout<<"tempo di ordinamento MergeSort vettore di interi = "<<duration_cast<microseconds>(endIM - beginIM).count() << " [microsecondi] \n" <<endl;

    steady_clock::time_point beginSM = steady_clock::now();
    MergeSort(vsM);
    steady_clock::time_point endSM = steady_clock::now();
    cout<<"tempo di ordinamento MergeSort vettore stringhe = "<<duration_cast<microseconds>(endSM - beginSM).count() << " [microsecondi] \n" <<endl;


    // Se "print" è vero, vengono visualizzati in output
    // i due vettori non ordinati e i loro ordinamenti secondo
    // i due algoritmi BubbleSort e MergeSort.
    // Se "print" è falso, nessun vettore viene stampato
    // (per evitare di stampare vettori eccessivamente lunghi)
    bool print = true;

    if(print){
        cout<<"vettore di numeri interi non ordinato:"<<endl;
        for (int& e : vi)
            cout<<e<<endl;

        cout<<endl<<"vettore di stringhe di lunghezza 3 non ordinato:"<<endl;
        for (string& e : vs)
            cout<<e<<endl;

        cout<<endl<<"stampa di viB:"<<endl;
        for (int& e : viB)
            cout<<e<<endl;

        cout<<endl<<"stampa di vsB:"<<endl;
        for (string& e : vsB)
            cout<<e<<endl;

        cout<<endl<<"stampa di viM:"<<endl;
        for (int& e : viM)
            cout<<e<<endl;

        cout<<endl<<"stampa di vsM:"<<endl;
        for (string& e : vsM)
            cout<<e<<endl;
    }

    return 0;
}

/*
 * Si può notare come per vettori brevi (ovvero con dimensione minore di 50 circa)
 * l'algoritmo BubbleSort sia mediamente più veloce, mentre invece per vettori
 * lunghi (ovvero con dimensione maggiore di 100 circa) sia mediamente più
 * veloce l'algoritmo MergeSort.
 * Il comportamento è simile sia per il vettore di interi che per quello di stringhe.
*/
