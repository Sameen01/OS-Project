#include <iostream>
#include <time.h>
#include <pthread.h>
#include<stdlib.h>
using namespace std;
#define MAX 20
double RunTime=0;
int arr[MAX];
 
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int n, int i)
{
    clock_t t1, t2;
    t1=clock();
              
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(n,largest);
    }
                t2=clock();
                RunTime=RunTime+((t2-t1)/(double)CLOCKS_PER_SEC);

}
// main function to do heap sort
void* heapSort(void* arg)
{
    int n=MAX;
                clock_t start,stop;
                start=clock();
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(n,i);
    }
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(i,0);
    } 
                stop=clock();
                RunTime=RunTime+((stop-start)/(double)CLOCKS_PER_SEC);
}
 
 
void* printArray(void* arg)
{
    cout<<"The SORTED Array is: "<<endl;
    for (int i=0; i<MAX; ++i)
        cout << arr[i] << " ";
cout<<endl;
}
 
 
int main()
{
 srand(time(NULL));
    pthread_t t1,t2;
 for (int i=0;i<MAX;i++)
 {
  arr[i]=rand()%1000;
 }
 
    pthread_create(&t1,NULL,heapSort,(void*)NULL);
    pthread_join(t1,NULL);
    pthread_create(&t2,NULL,printArray,(void*)NULL);
    pthread_join(t2,NULL);
    cout<<"runtime: "<<RunTime<<endl;
    return(0);}

