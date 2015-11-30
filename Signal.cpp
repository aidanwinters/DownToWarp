#include "Signal.h"
#include <vector>
#include <string>

//*
// Default constructor for Signal class
//*
Signal::Signal()
{
	size = 17; // number of data types
}

//*
// Constructor for Signal class: with <filename> given
//*
Signal::Signal(std::string filename)
{
	size = 17; // number of data types
	readIn( filename ); // read from <filename> and fill theInput
	finalize(); // construct theSignal from theInput
}

//*
// Destructor for Signal class
//*
Signal::~Signal()
{
	// no dynamic allocation in class data, so nothing to do here
}

//*
// Accessor method for the signal
//*
std::vector<double> Signal::getSignal()
{
	return theSignal;
}

//*
// Reads from <filename> to access and store original data
//*
void Signal::readIn(std::string filename)
{

}

//*
// Normalizes one vector to [0,1]
//*
void Signal::normalize(std::vector<double>& a)
{

}

//*
// Constructs the signal from the original data
//*
void Signal::finalize()
{

}
