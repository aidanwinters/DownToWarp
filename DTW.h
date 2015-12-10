#ifndef _DTW_H_
#define _DTW_H_

#include <vector>
#include <cfloat>

using namespace std;

class DTW{

	public:
		DTW();
		DTW(vector<double> one, vector<double> two);
		~DTW();

	private:
		vector< int > directions;
		vector< double > seqOne;
		vector< double > seqTwo;
		int lengthOne;
		int lengthTwo;
	
		static const double MAX = DBL_MAX;

		/*
		 * This method will calculate the similarity between two sequences 
		 *using the dynamic time warping algorithm
		 */
		void DTWDistance( int window );	
	
		/*
		 * This method calculates the distance between two points in the sequence 
		 */
		double distance(double aY, int aX, double bY, int bX );
		
		/*
 		*This method wil simply return the max of two ints
 		*/
		int maxINT( int a, int b );

		/*
 		*This method wil simply return the min of two int
 		*/
		int minINT( int a, int b );
		
		/*
 		*This method wil simply return the min of two doubles
 		*/
		double minDBL( double a, double b );
		
		/*
 		* This method will print the current state of the matrix
 		*/	
		void printMatrix(vector< vector<double> > matrix);

		/*
		 * Returns the absolute value of the given integer
		 */
		int absVal(int x);
};


#endif
