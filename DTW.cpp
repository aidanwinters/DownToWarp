#include "DTW.h"
#include <iostream>
#include <cmath>


using namespace std;

DTW::DTW(){}

DTW::DTW(vector< double > one, vector<double> two)
{
	seqOne = one;
	seqTwo = two;

	//added a comment

	lengthOne = seqOne.size();
	lengthTwo = seqTwo.size();

	DTWDistance(200);
}

DTW::~DTW(){}

/*
* This method will calculate the similarity between two sequences 
*using the dynamic time warping algorithm
*/
void DTW::DTWDistance( int window )
{
		int diff = lengthOne - lengthTwo;
		int w = maxINT( window, absVal(diff));					

		double init = MAX;

		vector< vector < double > > matrix( lengthOne + 1, vector<double>(lengthTwo + 1, init)); //added one row and col to compensate for additional row and col of infinity values
	
		matrix[0][0] = 0;

		printMatrix(matrix);

		for(int i = 1; i <= lengthOne; i++){

			cout << "AT least i got to here" << endl;
			
			int jStart = maxINT(1, i - w);
			int jEnd = minINT(lengthTwo, i + w); 	

			cout << "fuck " << jStart << endl;		
			cout << "fuck2 " << jEnd << endl;		
	
			for(int j = jStart; j <= jEnd; j++){
	
				cout << "AT least i got to here 2" << endl;
					
				double cost = distance(seqOne[i-1], i-1, seqTwo[j-i], j-1);
					
				double both = matrix[i-1][j-1];
				double first = matrix[i-1][j];
				double second = matrix[i][j-1];

				double minimum = minDBL(both, minDBL(first, second));

				if(minimum == both){
					directions.push_back(0); //match
				}
				else if(minimum == first){
					directions.push_back(1); //insertion
				}
				else if(minimum == second){
					directions.push_back(-1); //deletion
				}
				
				matrix[i][j] = cost + minimum;
			}
		}

	cout << directions.size() << endl;	
	printMatrix(matrix);	
}

/*
* This method calculates the distance between two points in the sequence 
*/
double DTW::distance(double aY, int aX, double bY, int bX )
{
	double xPart = bX - aX;
	double yPart = bY - aY;

	double xPartSqrd = xPart * xPart; 
	double yPartSqrd = yPart * yPart; 

	double xAndY = xPartSqrd + yPartSqrd;

	return sqrt(xAndY);
}


/*
*This method wil simply return the max of two ints
*/
int DTW::maxINT( int a, int b )
{
		if( a >= b ){
			return a;
		}
		return b;
}

/*
*This method wil simply return the min of two ints
*/
int DTW::minINT( int a, int b )
{
		if( a >= b ){
			return b;
		}
		return a;
}

/*
*This method wil simply return the min of two doubles
*/
double DTW::minDBL( double a, double b )
{
		if( a >= b ){
			return b;
		}
		return a;
}

/*
* This method will print the current state of the matrix
*/	
void DTW::printMatrix( vector< vector<double> > matrix){

		for(int i = 0; i < lengthOne; i++){
			for(int j = 0; j< lengthTwo; j++){
				cout << "|" << 	matrix[i][j] << "|";
			}
			cout << endl;
		}	
}
/*
 *This method returns the absolute value of the provided int
 */			
int DTW::absVal(int x){
	if(x < 0){
		return x - (2 * x);		
	}
	return x;
}
