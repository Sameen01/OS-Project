#include<iostream>
#include<omp.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define n 20
int arr[n];
double RunTime=0;
int partition(int arr[], int low_index, int high_index)
{
 clock_t start, stop;
    start=clock();
int i, j, temp, key;
key = arr[low_index];
i= low_index + 1;
j= high_index;
while(1)
{
while(i < high_index && key >= arr[i])
    i++;
while(key < arr[j])
    j--;
if(i < j)
{
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
else
{
temp= arr[low_index];
arr[low_index] = arr[j];
arr[j]= temp;
return(j);
}
}
stop=clock();
   
    RunTime=RunTime+((stop-start)/(double)CLOCKS_PER_SEC);
}
void quicksort(int arr[], int low_index, int high_index)
{
 clock_t start, stop;
    start=clock();
int j;
int k=0;
if(low_index < high_index)
{
j = partition(arr, low_index, high_index);
#pragma omp parallel sections
{
    #pragma omp section
    {
        k=k+1;
        quicksort(arr, low_index, j - 1);
    }
    #pragma omp section
    {
        k=k+1;
        quicksort(arr, j + 1, high_index);
    }

}
}
stop=clock();
   
    RunTime=RunTime+((stop-start)/(double)CLOCKS_PER_SEC);
}
int main()
{
srand(time(NULL));
for(int i=0;i<n;i++)
arr[i]=rand()%1000;
cout<<"Elements of array before sorting \n";
cout<<endl;
for(int i=0;i<n;i++)
{
cout<<" "<<arr[i]<<" ";
}
quicksort(arr, 0, n - 1);
cout<<"Elements of array after sorting \n";
for(int i=0;i<n;i++)
{
cout<<" "<<arr[i]<<" ";
}
cout<<endl;
cout<<"RunTime: "<<RunTime<<endl;
return 0;}

