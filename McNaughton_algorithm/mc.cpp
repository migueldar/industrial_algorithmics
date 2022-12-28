#include <iostream>

using namespace std;

double calculate_cmax(double arr[], int size, int n_machines)
{
	double sum = 0;
	double maximum = arr[0];

	for (int i = 0; i < size; i++) {
		sum += arr[i];
		if (arr[i] > maximum)
			maximum = arr[i];
	}
	return max(sum / n_machines, maximum);
}

//the scheduling is calculated at the same time as printing is done
//because it is more optimal than doing them separetly
int main()
{
	unsigned int n_machines, n_jobs;

	cout << "Solve Pm | pmtn | Cmax" << endl;
	cout << "Introduce the number of machines: ";
	cin >> n_machines;
	cout << "Introduce the number of jobs: ";
	cin >> n_jobs;

	double processing_times[n_jobs];

	cout << "Introduce the processing time of all jobs, separed just by spaces: ";
	for (int i = 0; i < n_jobs; i++)
		cin >> processing_times[i];
	
	double Cmax = calculate_cmax(processing_times, n_jobs, n_machines);
	double curr;
	int job = 0;

	cout << endl << "Result:" << endl;
	for (int i = 1; i <= n_machines; i++) {
		cout << "Machine " << i << ":" << endl;
		curr = 0;
		while (curr < Cmax && job < n_jobs) {
			cout << "Starting time of job " << job + 1 << ": " << curr;
			if (curr + processing_times[job] <= Cmax)
			{
				curr += processing_times[job];
				job++;
			}
			else
			{
				processing_times[job] -= Cmax - curr;
				curr = Cmax;
			}
			cout << ", ending time: " << curr << endl;
		}
		cout << endl;
	}
	cout << "Cmax = " << Cmax << endl;
}