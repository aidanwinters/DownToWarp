#include "DTW.h"
#include "Signal.h"

#include <iostream>
#include <vector>

using namespace std;
 
int main( int argc, const char* argv[])
{

	if (argc != 3){
		cout << "you didnt put enught arguments" << endl;
	}

		vector<double> seq1;
		vector<double> seq2;

		seq1.push_back(1);	
		seq1.push_back(2);	
		seq1.push_back(5);	
		seq1.push_back(4);	
		seq1.push_back(3);	
		seq1.push_back(7);	

		seq2.push_back(2);	
		seq2.push_back(3);	
		seq2.push_back(2);	
		seq2.push_back(1);	
		seq2.push_back(3);	
		seq2.push_back(4);	
		
		DTW dtw( seq1, seq2, -1 );
		
		Signal sig1(argv[1]);
		Signal sig2(argv[2]);
	
		seq1 = sig1.getSignal();
		seq2 = sig2.getSignal();

		cout << "Sig 1: " << seq1.size() << " Sig 2: " << seq2.size() << endl;

/*
		for(int i = 0; i < seq1.size(); i++){
				cout << " - " << seq1[i] << endl;
		}
	*/
	//DTW dtw2( sig1.getSignal(), sig2.getSignal(), -1 );	

		vector<int > temp = dtw.getDirections();		

		for(int i = 0; i < temp.size(); i++){
			cout << " |" << temp[i];
		}
		cout << endl;
}

