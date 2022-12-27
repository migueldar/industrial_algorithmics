#include "ert.hpp"

using namespace std;

void	print_jobs(Job job_array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Job " << job_array[i].id << ": r: " << job_array[i].ready_time << "  p: " << job_array[i].processing_time << "  s: " << job_array[i].start_time << endl;
	}
}

void	merge(Job fill[], Job job_array1[], Job job_array2[], int size1, int size2)
{
	int count = 0, count1 = 0, count2 = 0;

	while (count1 < size1 && count2 < size2)
	{
		if (job_array1[count1].ready_time > job_array2[count2].ready_time)
			fill[count++] = job_array2[count2++];
		else
			fill[count++] = job_array1[count1++];
	}

	while (count1 < size1)
		fill[count++] = job_array1[count1++];

	while (count2 < size2)
		fill[count++] = job_array2[count2++];
}

void	merge_sort(Job job_array[], int size)
{
	if (size == 1)
		return ;
	
	int roundUp = ceil(size / 2.0), roundDown = floor(size / 2.0);
	Job arr1[roundUp], arr2[roundDown];

	for (int i = 0; i < roundUp; i++)
		arr1[i] = job_array[i];
	for (int i = roundUp; i < size; i++)
		arr2[i - roundUp] = job_array[i];

	merge_sort(arr1, roundUp);
	merge_sort(arr2, roundDown);

	merge(job_array, arr1, arr2, roundUp, roundDown);
}

void	construct_schedule(Job job_array[], int size)
{
	int start = 0;

	for (int i = 1; i <= size; i++) {
		if (start < job_array[i - 1].ready_time)
			start = job_array[i - 1].ready_time;
		job_array[i - 1].start_time = start;
		start += job_array[i - 1].processing_time;
	}
}

int main()
{
	int	n;

	cout << "This is the implementation of ERT scheduling rule" << endl;
	cout << "Introduce the number of jobs: ";
	cin >> n;

	Job	job_array[n];

	for (int i = 1; i <= n; i++) {
		job_array[i - 1].id = i;
		cout << "Introduce the processing time of job " << i << ": ";
		cin >> job_array[i - 1].processing_time;
		cout << "Introduce the ready time of job " << i << ": ";
		cin >> job_array[i - 1].ready_time;
	}
	
	merge_sort(job_array, n);
	construct_schedule(job_array, n);
	print_jobs(job_array, n);

	cout << endl << "Result: " << endl << "Machine 1:" << endl;
	for (int i = 1; i <= n; i++) {
		cout << "Starting time of job " << job_array[i - 1].id << ": " << job_array[i - 1].start_time << ", ending time: " << job_array[i - 1].start_time + job_array[i - 1].processing_time << endl;
	}

}