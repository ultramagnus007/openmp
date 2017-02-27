#include <iostream>
#include <omp.h>
#include <vector>
#include <ctime>
using namespace std;


int main()
{
	const  int N = 10000000;
	double step_size = 1.0/N;
	double pi = 0;
	vector<double> result(4, 0);
	clock_t begin = clock();
	omp_set_num_threads(1);
	#pragma omp parallel
	{
		int ID = omp_get_thread_num();
		double x = 0;
		int num_threads = omp_get_num_threads(); 
		for(int i = ID; i < N; i+=num_threads)
		{
			x = (i+0.5)*step_size;
			//area of each strip = y*step_size
			result[ID]+= (4.0/(1+x*x))*step_size;
		}
	}
	for(int i = 0; i < result.size();i++)
		pi+=result[i];
	clock_t end = clock();
	cout<<(double(end - begin)/ CLOCKS_PER_SEC)<<endl;
	cout<<pi<<endl;
	return 0;
}
