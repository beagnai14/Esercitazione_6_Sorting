#include <cmath>       // contiene la funzione floor(), sqrt(), ecc.
#include <iostream>    // per cout, cin, cerr, ecc.
#include <numeric>     // contiene iota(), accumulate(), ecc.
#include <sstream>     // per stringstream e ostringstream
#include <chrono>      // per misurare il tempo (timer ad alta precisione)

#include "SortingAlgorithm.hpp"

using namespace std;

template<typename T>
string ArrayToString(const vector<T>& v)
{
    string str; 		//dichiara una variabile di tipo stringa
    ostringstream toString;   //oggetto di tipo output che scrive su una stringa 
    toString << "[ ";
    for (const T& val: v)
        toString << val << " ";
    toString << "]";

    return toString.str();
}

struct ClassObj{
    double value;
};
inline bool operator < (const ClassObj& lhs, const ClassObj& rhs) {
	return lhs.value < rhs.value; 
	}


int main(int argc, char *argv[])
{
    cout << "argc: " << argc << endl;		//stampa il numero passati al programma incluso il nome
    for(int i = 0; i < argc; i++)			//stampa gli argomenti passati al programma incluso il nome
        cout << argv[i] << " ";
    cout << endl;

	size_t m = 10;							//valore di default m se non viene passato 
	
    if(argc > 1)
    {
        istringstream convert(argv[1]);		//il primo numero passato costiuisce il valore di m
        convert >> m;
        cout << "use value: "  << m << endl;
    }
    else {
        cerr << "use default value: "  << m << endl;
	}

	cout << endl;
	cout << "vectors to order: " << endl;
	
	vector<int> v1(m);
    iota(v1.begin(), v1.end(), -15); //costruisce una sequenza con valori crescenti dal valore -4
	
    cout << "v1: " << ArrayToString(v1) << endl;
	
	
	srand(6);
    vector<double> v2(m);
    for(size_t i = 0; i < m; i++) {
        v2[i] = rand() / ((double)RAND_MAX);		//double compreso tra 0 e 1 
	}
	
	cout << "v2: " << ArrayToString(v2) << endl;

	
	vector<int> v3(m, 0); 
    for(size_t i = floor(m * 0.5) + 1; i < m; i++)
        v3[i] = rand() % 1000;   // modulo mille restituisce dei numeri tra 0 e 1000
    copy(v1.begin(), v1.begin() + floor(m * 0.5) + 1, v3.begin());

	cout << "v3: " << ArrayToString(v3) << endl;

	cout << endl;
	//TEMPO
	const auto today_time = std::chrono::system_clock::now();		//ora corrente 
	cout << "Tempo trascorso dal 1 gennaio 1970: "
          << std::chrono::duration_cast<std::chrono::milliseconds>(		//converte la durata in millesecondi
                 today_time.time_since_epoch()).count() << endl;		//restituisce la durata trascorsa dal 1970

	unsigned int num_experiment = 100;
	
	
	//V1 BUBBLE
	double time_elapsed_bubble_v1 = 0.0;
	
	for(unsigned int t = 0; t < num_experiment; t++)
	{
		vector<int> v(v1);

		std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();		//registra ora inizio e fine dell'esecuzione
		SortLibrary::BubbleSort<int>(v);
		std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
		time_elapsed_bubble_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();		//tempo totale impiegato
	}
	time_elapsed_bubble_v1 /= num_experiment; 			//calcolo del tempo medio impiegato sul numero di esperimenti
	
	cout << "Bubble Sort - v1: " << time_elapsed_bubble_v1 << endl;
	
	//V1 HEAP
	double time_elapsed_heap_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v1 /= num_experiment;

    cout << "Heap Sort - v1: " << time_elapsed_heap_v1 << endl;
	
	//v2 BUBBLE
	double time_elapsed_bubble_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v2 /= num_experiment;

    cout << "Bubble Sort - v2: " << time_elapsed_bubble_v2 << endl;

	//V2 HEAP
	double time_elapsed_heap_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v2 /= num_experiment;

    cout << "Heap Sort - v2: " << time_elapsed_heap_v2 << endl;
	
	
	//V3 BUBBLE
	double time_elapsed_bubble_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v3 /= num_experiment;

    cout << "Bubble Sort - v3: " << time_elapsed_bubble_v3 << endl;
	
	//V3 HEAP
	double time_elapsed_heap_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v3 /= num_experiment;

    cout << "Heap Sort - v3: " << time_elapsed_heap_v3 << endl;

	


    return 0;
}

