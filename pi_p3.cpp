#include <iostream>
#include <omp.h>
using namespace std;



int main()
{
	const int N = 1000000000;
	const double step = 1.0/N;
	double ans = 0;
	#pragma omp parallel for reduction(+ : ans)
	for(int i = 0; i < N; i++)
	{
		double x = (i+0.5)*step;
		double y = 4.0/(1+x*x);
		ans += y*step;
	}
	cout<<ans<<endl;

	return 0;
}
