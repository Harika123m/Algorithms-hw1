#include<sys/time.h>
#include<stdio.h>

//a global counter variable for counting comparisons made in heapsort
static int comparisons=0;

// A function to compare 2 elements in an array and increment the count variable. This function returns either true or false depending on the values that have been compared to each other.
int comparator(int l, int r)
{
    comparisons++;
    if(l<r){
    	return 0;
    }
    else 
    	return 1;
    
    
}

//function for swapping elements in heap (using pointers with a temporary variable)
void swap(int *a, int *b)
{
 int temp;
 temp=*a;
  *a=*b;
  *b=temp;

}


// function to build a max heap
void heapify(int arr[], int n, int i)
{
    int largest = i;  
    int l = 2*i ;  
    int r = 2*i+1;  
 

// check if left subchild index is less than or equal to size of array (n)
if(l<=n)

//compare the left element with the largest element so far in the array, and if left element is greater, append the largest index to index l(left)
 if(comparator(arr[l], arr[largest]))
    largest=l;
 
// check if right subchild index is less than or equal to size of array (n)

if(r<=n)
//compare the right element with the largest element so far in the array, and if right element is greater, append the largest index to index r(right)
 if(comparator(arr[r],arr[largest]))
    largest=r; 


// uncomment to see the heapify method in every iteration for unique values of i and n.
//printf("\n %d %d \n ", n, i) ;
//printArray(arr,n);
    if (largest != i)
    {
 	// if the largest index is not the current index, swap the current index with the fisrt element of array.
        swap(&arr[i], &arr[largest]);

        // again heapify so that parent element is always greater than child after few changes in before steps of heapify.		
        heapify(arr, n, largest);

    }

}
 
// function for sorting the heap elements.
void heapSort(int arr[], int n)
{

// selecting the parent elements from reverse oder and checking if they are greater than their children
    for (int i = (n/ 2) ; i >= 1; i--)
        heapify(arr, n, i);
 

    for (int i=n; i>=1; i--)
    {
// swap the elemnt at top of the heap to the current element
        swap(&arr[1], &arr[i]);
 
 // After swapping,check again if the heap is in proper order, so perform heapify again         
        heapify(arr, i-1, 1);
    }
}
 
// function to print the sorted array, taking array and it's size as parameters.
void printArray(int arr[], int n)
{
    for (int i=1; i<=n; ++i)
         printf("%d\n",arr[i]); 

}
 

int main()
{
// define timeval to calculate the running time, giving 3 variables : one for calculating before, one for after the executiona and the third for storing the diference of the 2 values
    struct timeval  tv_ex,tv_1,tv_2;
// define 2 variables to read the user's input ( n followed by nubmer of elements)   
  char firstn;
    int n,i;
// read the 2 values usinf scanf 
  scanf("%c", &firstn);
    scanf("%d", &n);
// initiaze the array with the users's mentioned size   
 int arr[n];
 // scan the elements (n) into an array.
    for(i=1;i<=n;i++) scanf("%d", &arr[i]);
 
// calulate the time of day before executing the heap sort
gettimeofday(&tv_1, NULL);
    heapSort(arr, n);
// calculate the time after executing the heap sort.
gettimeofday(&tv_2, NULL);
// send the sorted array after performing heapsort to function printArray to print as standard output 
    printArray(arr, n);

 // Now subtract the time (after heap sort-before heap sort)
double time_ms=(tv_2.tv_usec-tv_1.tv_usec)/1000 ;
double time_s=(tv_2.tv_sec-tv_1.tv_sec)*1000 ;
int time = (int)time_s+time_ms;
// print to standard error the runtime and nubmer of comparisons 
fprintf(stderr, "runtime, %d\n", time);
fprintf(stderr, "comparisons, %d\n", comparisons);




}
