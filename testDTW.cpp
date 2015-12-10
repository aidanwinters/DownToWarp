#include "DTW.h"
#include <iostream>


using namespace std;
 
int main(){

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
		
		DTW dtw( seq1, seq2 );
}
