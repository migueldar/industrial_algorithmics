#include <iostream>

using namespace std;

//returns index with minimum value in array
int min_index(double arr[], int size)
{
	int index = 0;

	for (int i = 1; i < size; i++)
		if (arr[i] < arr[index])
			index = i;

	return index;
}

//finds maximum element in array
double max_array(double arr[], int size)
{
	int max = arr[0];

	for (int i = 1; i < size; i++)
		if (max < arr[i])
			max = arr[i];

	return max;
}

//the scheduling is calculated at the same time as printing is done
//because it is more optimal than doing them separetly
//The output may be a bit weird, because jobs are assigned to machines 
//as they become ready, and everything is printed directly
int main()
{
	unsigned int n_machines, n_jobs;

	cout << "Aproximate Pm || Cmax" << endl;
	cout << "Introduce the number of machines: ";
	cin >> n_machines;
	cout << "Introduce the number of jobs: ";
	cin >> n_jobs;

	cout << "Introduce the processing time of all jobs, separed just by spaces: ";
	double processing_times[n_jobs];
	for (int i = 0; i < n_jobs; i++)
		cin >> processing_times[i];
	
	double curr[n_machines];
	for (int i = 0; i < n_machines; i++)
		curr[i] = 0;

	int index;
	cout << endl << "Result:" << endl;
	for (int i = 0; i < n_jobs; i++) {
		index = min_index(curr, n_machines);
		cout << "Machine " << index + 1 << ":" << endl;
		cout << "Starting time of job " << i + 1 << ": " << curr[index];
		curr[index] += processing_times[i];
		cout << ", ending time: " << curr[index] << endl;
		cout << endl;
	}
	
	cout << "Cmax = " << max_array(curr, n_machines) << endl;
}