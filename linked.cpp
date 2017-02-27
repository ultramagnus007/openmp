#include <iostream>
#include <omp.h>

using namespace std;

const int N = 5;
const int FS = 38;

class node
{
	public:
	int data;
	int fibdata;
	node* next;
};

int fib(int n) 
{
	if (n < 2)
		return (n);

	int x, y;
	x = fib(n - 1);
	y = fib(n - 2);
	return (x + y);
}

void processwork(node* p) 
{
   int n;
   n = p->data;
   p->fibdata = fib(n);
}

node* init_list(node* p)
{
    node* head = NULL;
    node* temp = NULL;
    
    head = new node();
    p = head;
    p->data = FS;
    p->fibdata = 0;
    for (int i=0; i< N; i++)
	{
       temp  =  new node;
       p->next = temp;
       p = temp;
       p->data = FS + i + 1;
       p->fibdata = i+1;
    }
    p->next = NULL;
    return head;
}

int main()
{
	double start, end;
	node *p=NULL;
	node *temp=NULL;
	node *head=NULL;
     
	cout<<"Process linked list\n";
	cout<<"Each linked list node will be processed by function 'processwork()'\n";
	cout<<"Each ll node will compute "<<N<<" fibonacci numbers beginning with "<<FS<<endl;      
 
	p = init_list(p);
	head = p;

	start = omp_get_wtime();
	while (p != NULL)
	{
		processwork(p);
		p = p->next;
	}

	end = omp_get_wtime();
	p = head;
	while (p != NULL)
	{
		cout<<p->data <<" : "<<p->fibdata<<endl;
		temp = p->next;
		delete (p);
		p = temp;
	}  
	delete (p);
	cout<<"Compute Time: "<< end - start <<" seconds"<<endl;
	return 0;
}
