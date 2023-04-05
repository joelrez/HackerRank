#include <vector>
#include <iostream>
#include <string>
#include <omp.h>


using namespace std;

int birdSightingsSoln(vector<int> arr) {
	vector<int> sightings(arr.size());
	int maxInd = 0;

	#pragma omp parallel num_threads(5)
	{
		int maxInd_local = 0;

		#pragma omp parallel for reduction(+:sightings[:arr.size()])
		for (int i = 0; i < arr.size(); i++) {
			int ind = arr[i] - 1;

			sightings[ind]++;

			if (sightings[ind] == sightings[maxInd_local] && ind < maxInd_local) {
				maxInd_local = ind;
			}
			else if (sightings[ind] > sightings[maxInd_local]) {
				maxInd_local = ind;
			}
		}

		#pragma omp critical
		{
			if (sightings[maxInd] < sightings[maxInd_local]) maxInd = maxInd_local;
		}
	}

	return maxInd + 1;
}

int bigFactorialSoln(int n) {
	int result = 1;
	#pragma omp parallel for reduction(*:result)
	for (int i = 1; i <= n; i++)
		result *= i;

	return result;
}

string factorialSoln(int n, int numzeros) {
	numzeros++;

	if (n == 1) {
		string result = to_string(n);
		for (int i = 0; i < numzeros; i++)
			result += "0";
		return result;
	}

		return to_string(n) + factorialSoln(n - 1, numzeros);
}

int main() {
	vector<int> arr = { 1, 4, 4, 4, 5, 3, 1, 4, 4, 4, 5, 3, 1, 4, 4, 4, 5, 3, 1, 4, 4,
						4, 5, 3, 1, 4, 4, 4, 5, 3, 1, 4, 4, 4, 5, 3, 1, 4, 4, 4, 5, 3,
						1, 4, 4, 4, 5, 3, 1, 4, 4, 4, 5, 3, 1, 4, 4, 4, 5, 3, 1, 4, 4,
						4, 5, 3, 1, 4, 4, 4, 5, 3, 1, 4, 4, 4, 5, 3, 1, 4, 4, 4, 5, 3 };
						/*1, 4, 4, 4, 5, 3, 1, 4, 4, 4, 5, 3, 4, 5, 3, 1, 4, 4, 4, 5, 3,
						5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
						5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
						5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 
						5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };*/
	
	cout << birdSightingsSoln(arr);
	
	/*cout << factorialSoln(25);
	cout << bigFactorialSoln(25);
	*/

	//cout << 

	return 0;
}