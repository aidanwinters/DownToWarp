#include "Signal.h"
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>


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
Signal::Signal(char* filename)
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
void Signal::readIn(char* filename)
{
	// prep for reading
	std::ifstream infile; // input filestream variable for reading
	infile.open(filename); // open <filename>
	if( !infile.is_open() ) // in case of error
	{
		std::cerr << "Error: cannot open file: " << filename << std::endl;
		std::exit(1);
	}

	// prepare theInput
	for( int i = 0; i < size; i++ )
	{
		theInput.push_back(std::vector<double>()); // create a vector for each data type			
	}

	// reading logistics
	std::string currentLine;
	std::stringstream ss;

	// this next part assumes size=17 so will need to be updated if there are additional/different data types
	double acc_x, acc_y, acc_z, gyr_x, gyr_y, gyr_z, roll, pitch, yaw, emg_1, emg_2, emg_3, emg_4, emg_5, emg_6, emg_7, emg_8;
	
	while( infile.good() )
	{
		std::getline(infile, currentLine);
		ss.clear();
		ss.str(currentLine);
		ss >> acc_x >> acc_y >> acc_z >> gyr_x >> gyr_y >> gyr_z >> roll >> pitch >> yaw;
		ss >> emg_1 >> emg_2 >> emg_3 >> emg_4 >> emg_5 >> emg_6 >> emg_7 >> emg_8;
		// add to theInput
		theInput[0].push_back(acc_x);
		theInput[1].push_back(acc_y);
		theInput[2].push_back(acc_z);
		theInput[3].push_back(gyr_x);
		theInput[4].push_back(gyr_y);
		theInput[5].push_back(gyr_z);
		theInput[6].push_back(roll);
		theInput[7].push_back(pitch);
		theInput[8].push_back(yaw);
		theInput[9].push_back(emg_1);
		theInput[10].push_back(emg_2);
		theInput[11].push_back(emg_3);
		theInput[12].push_back(emg_4);
		theInput[13].push_back(emg_5);
		theInput[14].push_back(emg_6);
		theInput[15].push_back(emg_7);
		theInput[16].push_back(emg_8);
	}
	return;		
}


//*
// Normalizes one vector to [0,1]
//*
void Signal::normalize(std::vector<double>& a)
{
	double min = a[0];
	double max = a[0];

        for( int i = 0; i < a.size(); i++ )
	{
		if( a[i] < min )
			min = a[i];
		if( a[i] > max )
			max = a[i];
	}

	for( int i = 0; i < a.size(); i++ )
	{
		a[i] = (a[i]-min)/(max - min);
	}

	return;	
}


//*
// Constructs the signal from the original data
//*
void Signal::finalize()
{
	for( int i = 0; i < theInput.size(); i++ )
	{
		normalize( theInput[i] );
		for( int j = 0; j < theInput[i].size(); j++ )
			theSignal.push_back(theInput[i][j]);
	} 
}
