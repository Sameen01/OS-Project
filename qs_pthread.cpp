#include<iostream> 
#include<time.h>
#include<pthread.h>
#include<stdlib.h>
#define MAX 20
#define THREAD_MAX 4
using namespace std;
int part=0;
int a[MAX];
double RunTime=0;
void swap(int* a, int* b) 
{ 
    clock_t start,stop;
    start=clock();
    int t = *a; 
    *a = *b; 
    *b = t; 
stop=clock();
   
    RunTime=RunTime+((stop-start)/(double)CLOCKS_PER_SEC);
	//cout<<RunTime<<"swap"<<endl;
} 

int partition ( int low, int high) 
{ 
    clock_t start,stop;
    start=clock();
    int pivot = a[high];   
    int i = (low - 1); 
   for (int j = low; j <= high- 1; j++) 
    { 
        if (a[j] <= pivot) 
        { 
            i++; 
            swap(&a[i], &a[j]); 
        } 
    } 
    swap(&a[i + 1], &a[high]); 
    stop=clock();
    RunTime=RunTime+((stop-start)/(double)CLOCKS_PER_SEC);
    return (i + 1); 

} 
void quickSort( int low, int high) 
{ 
 clock_t start, stop;
    start=clock();
    if (low < high) 
    { 
        int pi = partition( low, high); 
        quickSort( low, pi - 1); 
        quickSort( pi + 1, high); 
    } 
stop=clock();
   
    RunTime=RunTime+((stop-start)/(double)CLOCKS_PER_SEC);
} 

void* quickSort(void* arg) 
{ 
 clock_t start, stop;
    start=clock();
int thread_part=part++;
int low=(thread_part)*(MAX/4);
int high=(thread_part+1)*(MAX/4)-1;
    if (low < high) 
    { 
        int pi = partition( low, high); 
        quickSort( low, pi - 1); 
        quickSort( pi + 1, high); 
    } 
stop=clock();
   
    RunTime=RunTime+((stop-start)/(double)CLOCKS_PER_SEC);
} 
int main() 
{ 
srand(time(NULL));
for(int i=0;i<MAX;i++)
a[i]=rand()%100;
pthread_t t1;
for (int i=0;i<4;i++)
pthread_create(&t1,NULL,quickSort,(void*)NULL);
for (int i=0;i<4;i++)
pthread_join(t1,NULL);
   quickSort( 0, MAX-1); 
    cout<<"SORTED ARRAY";
    for(int i=0;i<MAX;i++)
cout<<" "<<a[i]<<" ";
cout<<"runtime: "<<RunTime<<endl;
    return 0; 
}

