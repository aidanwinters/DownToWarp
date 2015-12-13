#include "DTW.h"
#include <iostream>

using namespace std;

DTW::DTW(){}

DTW::DTW(vector< double > one, vector<double> two, int window)
{
	seqOne = one;
	seqTwo = two;

	lengthOne = seqOne.size();
	lengthTwo = seqTwo.size();

	if(window < 0){
		windowSize = maxINT(lengthOne, lengthTwo);	
	}
	
	DTWDistance();
}

DTW::~DTW(){}

/*
* This method will calculate the similarity between two sequences 
*using the dynamic time warping algorithm
*/
void DTW::DTWDistance()
{
		int diff = lengthOne - lengthTwo;
		int w = maxINT( windowSize, absVal(diff));					

		double init = MAX;

		vector< vector < double > > matrix( lengthOne + 1, vector<double>(lengthTwo + 1, init)); //added one row and col to compensate for additional row and col of infinity values
	
		matrix[0][0] = 0;

		for(int i = 1; i <= lengthOne; i++){
	
			int jStart = maxINT(1, i - w);
			int jEnd = minINT(lengthTwo, i + w); 	
	
			for(int j = jStart; j <= jEnd; j++){
	
				double cost = distance(seqOne[i-1], seqTwo[j-1]);
		
				double both = matrix[i-1][j-1];
				double first = matrix[i-1][j];
				double second = matrix[i][j-1];

				double minimum = minDBL(both, minDBL(first, second));
				
				matrix[i][j] = cost + minimum;
			}
		}
		
		findDirections(matrix);
       //	printMatrix(matrix);
	cout << matrix[lengthOne][lengthTwo] << endl;
}

/*
* This method calculates the distance between two points in the sequence 
*/
double DTW::distance(double a, double b)
{
	double result = a - b;
	return result * result;	
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

		for(int i = 0; i < lengthOne + 1; i++){
			for(int j = 0; j< lengthTwo + 1; j++){
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

/*
* This method iterates back through the matrix and produces a vector containing the directions
*/
void DTW::findDirections(vector< vector<double> > matrix){
		
	int i = lengthOne;
	int j = lengthTwo;

	vector<int> temp;

	while( i > 0 && j > 0){
				
				double both = matrix[i-1][j-1];
				double first = matrix[i-1][j];
				double second = matrix[i][j-1];

				double minimum = minDBL(both, minDBL(first, second));

				if(minimum == both){
					temp.push_back(0); //match
					i--;
					j--;
					//cout << "HERE I AM1" << endl;
				}
				else if(minimum == first){
					temp.push_back(1); //insertion
					i--;
					//cout << "HERE I AM2" << endl;
				}
				else if(minimum == second){
					temp.push_back(-1); //deletion
					j--;
					//cout << "HERE I AM3" << endl;
				}	

	}

	//reverse the vector
	for(int k = temp.size(); k >= 0; k--){
		directions.push_back(temp[k]);
	}

}
