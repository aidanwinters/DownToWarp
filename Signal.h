#ifndef _SIGNAL_H_
#define _SIGNAL_H_

#include <vector>
#include <string>

using namespace std;

class Signal{

	public:
		Signal();
		Signal(string filename);
		~Signal();
	 	std::vector<double> getSignal();	

	private:
		// data
		int size; // number of data types (17)
		std::vector< std::vector<double> > theInput; // two dimensional array to hold the input data - 
								// outside vector iterates through data types
								// inside vector iterates through data points of a particular type
		std::vector<double> theSignal; // one dimensional array to hold the output data, all normalized and in order. 

		// methods
		void readIn(string filename); // will read from <filename> and fill theInput accordingly
		void normalize(std::vector<double>& a); // will normalize one vector to [0,1]
		void finalize(); // will construct theSignal 

};

#endif
