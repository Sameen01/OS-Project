#include<iostream> 
#include<time.h>
#include<stdlib.h>
#define n 20
using namespace std;

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

int partition (int arr[], int low, int high) 
{ 
    clock_t start,stop;
    start=clock();
    int pivot = arr[high];   
    int i = (low - 1); 
   for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    stop=clock();
    RunTime=RunTime+((stop-start)/(double)CLOCKS_PER_SEC);
    return (i + 1); 

} 
void quickSort(int arr[], int low, int high) 
{ 
 clock_t start, stop;
    start=clock();
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
stop=clock();
   
    RunTime=RunTime+((stop-start)/(double)CLOCKS_PER_SEC);
} 
int main() 
{ 
srand(time(NULL));
    int arr[n]; 
for(int i=0;i<n;i++)
arr[i]=rand()%100;
    quickSort(arr, 0, n-1); 
    cout<<"SORTED ARRAY";
for(int i=0;i<n;i++)
cout<<" "<<arr[i]<<" ";
cout<<"runtime: "<<RunTime<<endl;
    return 0; 
}

