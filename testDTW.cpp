#include "DTW.h"
#include "Signal.h"

#include <iostream>
#include <vector>

using namespace std;
 
int main( int argc, const char* argv[])
{

		vector<double> seq1;
		vector<double> seq2;

		seq1.push_back(0.34);	
		seq1.push_back(0.1);	
		seq1.push_back(0.123);	
		seq1.push_back(0.69);	
		seq1.push_back(0.468);	

		seq2.push_back(0.54);	
		seq2.push_back(0.3);	
		seq2.push_back(0.323);	
		seq2.push_back(0.89);	
		seq2.push_back(0.668);	
		
	//	DTW dtw( seq1, seq2 );

		Signal sig1(argv[1]);
		Signal sig2(argv[2]);
	
		seq1 = sig1.getSignal();
		seq2 = sig2.getSignal();

		cout << "Sig 1: " << seq1.size() << " Sig 2: " << seq2.size() << endl;


		for(int i = 0; i < seq1.size(); i++){
				cout << " - " << seq1[i] << endl;
		}

		
	
	DTW dtw2( sig1.getSignal(), sig2.getSignal() );	
}
