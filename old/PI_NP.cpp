#include <iostream>
#include <ctime>
using namespace std;


int main()
{
	const  int N = 10000000;
	double step_size = 1.0/N;
	double pi = 0;
	double x = 0;
        clock_t begin = clock();
	for(int i = 0; i < N; i++)
	{
		x+=step_size;
		//area of each strip = y*step_size
		pi+= (4.0/(1+x*x))*step_size;
	}
        clock_t end = clock();
        cout<<(double(end - begin)/ CLOCKS_PER_SEC)<<endl;
	cout<<pi<<endl;
	return 0;
}
