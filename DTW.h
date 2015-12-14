#ifndef _DTW_H_
#define _DTW_H_

#include <vector>
#include <cfloat>

using namespace std;

class DTW{

	public:
		DTW();
		DTW(vector<double> one, vector<double> two, int window);
		~DTW();
		
		/*
 		*This method returns a vector containing integers indicating the directions for the calculated DTW
 		*/
		vector<int> getDirections(){ return directions; };

		/*
		 *This method is only meant to be used for running multiple DTWs for testing
		 */
		void runDTW(vector<double> one, vector<double> two, int window);

		
	private:
		vector< int > directions;
		vector< double > seqOne;
		vector< double > seqTwo;
		int lengthOne;
		int lengthTwo;
		int windowSize;
	
		static const double MAX = DBL_MAX;

		/*
		 * This method will calculate the similarity between two sequences 
		 *using the dynamic time warping algorithm
		 */
		void DTWDistance();	
	
		/*
		 * This method calculates the distance between two points in the sequence 
		 */
		double distance(double a, double b);
		
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

		/*
		 * This method iterates back through the matrix and produces a vector containing the directions
		 */
		void findDirections(vector< vector<double> > matrix);
};


#endif
