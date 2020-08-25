#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>

// A global variable count to count the number of compariosns in mergesort
int count=0;

// A function to compare 2 elements in an array and increment the count variable. This function returns either true or false depending on the values that have been compared to each other.
int comparator(int l, int r)
{
    count++;
    if(l<r){
    	return 0;
    }
    else 
    	return 1;
    
    
}


// Function to sort 2 parts in an array splitted by the variable mid, considering low to mid index elements as one sub array and mid +1 to n index elements as another subarray
void merge(int *array,int low, int mid, int high)
{
// create an array f, to sort elements of  'array'   
int i=low, j=mid+1, n=low, f[high+1];

// repeat the process of comapring and rearranging till all elements of 2 sub arrays are sorted.
  while((i<=mid)&&(j<=high)) {


// compare the first elements of both the sub arrays using comparator function
// copy the least element to the array f.
// increment the index of subarray which has the least element
// increment the counter for comparisons since we did 1 comparison.
 if(comparator(array[i], array[j]))
{
 f[n]=array[j];
 j++;
}

else
{
f[n]=array[i];
i++;
} 

// increment the lower index( index of first element (n).
n++;


  }

  if(i>mid)
{

 while(n<=high) {
    f[n]=array[j];
    n++;
    j++;

    }
}

  if(j>mid)
{

 while(n<=high) {
    f[n]=array[i];
    n++;
    i++;

    }
}
  for(n=low;n<=high;n++)
      array[n]=f[n];
}


// Function to split the given array based on a middle element taking the lowest and highest index of the array and array as input parameters
void mergesort(int *array, int low, int high)
{
  int mid;

  if(low<high){

      mid=(high-1+low)/2;
      mergesort(array,low,mid);

      mergesort(array,mid+1,high);

     merge(array, low, mid, high);

     }
} 

void main()
{

// define 3 timeval variables to find out time taken for running mergesort
  struct timeval  tv_ex,tv_1,tv_2;
// define variables to take the input from use : (Ex : n 9)  
char firstn;
  int size,i, *array;
// Scan the user's input.
 scanf("%c", &firstn);
  scanf("%d", &size);
// Use dynamic memory allocation for the array to size mentioned by user.
  array=(int *)malloc(sizeof(int)*size);
// Save the elements entered by user in the array declared above.
  for(i=0;i<size;i++)
    scanf("%d", &array[i]);

// FInd the present time before performing mergesort
 gettimeofday(&tv_1, NULL);
// Apply the mergesort to the user's input. 
// Send the array, the index of first element of array and it's size as parameters to mergesort
  mergesort(array, 0, size-1);

// Now again find the time after performing mergesort
gettimeofday(&tv_2, NULL);


// print the sorted array
  for(i=0;i<size;i++) {
      printf("%d\n",array[i]);
      //if(i==size-1)
        //printf("\n");
      //else
        //printf(" "); 
    } 

// calculate in milliseconds the running time
double time_ms=(tv_2.tv_usec-tv_1.tv_usec)/1000 ;
double time_s=(tv_2.tv_sec-tv_1.tv_sec)*1000 ;
int time = (int)time_s+time_ms;
// Print the runtime and number of comparison in mergesort to standard error.
fprintf(stderr, "runtime, %d\n", time);
fprintf(stderr, "comparisons, %d\n", count);


}
