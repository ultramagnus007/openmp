#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;




int main()
{
	int num_threads = 4;
	const int N = 1000000000;
	const double step = 1.0/N;

	omp_set_num_threads(num_threads);
	double ans = 0;
	bool numthreadset = false;
	#pragma omp parallel
	{
		int tid = omp_get_thread_num();
		double s = 0;
		if(numthreadset==false)
		{
			// may need lock also num_threads ans numthreadset are shared
			int nthreads = omp_get_num_threads();
			num_threads = nthreads;
			numthreadset = true;
		}
		for(int i = tid; i < N; i+=num_threads)
		{
			double x = (i+0.5)*step;
			double y = 4.0/(1+x*x);
			s += y*step;
		}
		#pragma omp atomic
			ans += s;
	}
	cout<<ans<<endl;
	return 0;
}
