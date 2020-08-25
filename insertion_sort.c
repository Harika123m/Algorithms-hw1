#include <stdio.h>
#include<sys/time.h>

void insertion_sort(int n, int arr[]);
int comparator(int l, int r);

static int count=0; /*counter for counting comparisons*/

int main (){
	int n, i, time, temp;
	struct timeval tv_1,tv_2; /*variables for measuring run time*/
	double time_ms, time_s;
	char str;

	scanf("%c", &str); /*reading in first "n" character*/

	scanf("%d", &n); /*reading number of records*/
	int arr[n]; /*initializing array*/

	//reading in unsorted list of elements
	for(i=0; i<n; i++){
		scanf("%d", &temp);
		arr[i]=temp;
	}

	gettimeofday(&tv_1, NULL);

	insertion_sort(n, arr); /*calling insertion sort function*/

	gettimeofday(&tv_2, NULL);
	time_ms=(tv_2.tv_usec-tv_1.tv_usec)/1000 ;
	time_s=(tv_2.tv_sec-tv_1.tv_sec)*1000 ;
	time = (int)(time_s+time_ms); /*Finding total run time*/

	//Printing runtime and number of comparisons
	fprintf(stderr, "runtime, %d\n", time);
	fprintf(stderr, "comparisons, %d\n", count);

	return  0;
}

void insertion_sort(int n, int arr[]){
	int i,j, temp;

	for(i=1; i< n; i++){
		temp=arr[i];
		j=(i-1);
		while(j>=0){
			if(comparator(arr[j],temp)==1){ /*Sending values to comparator*/
				arr[j+ 1]=arr[j]; /*Swapping elements*/
				arr[j]=temp;
			}
			else{
				break;
			}
			j--;
		}
	}

	//Printing final sorted array
	for(i=0; i<n; i++){
		printf("%d\n", arr[i]);
	}
}

int comparator(int l, int r)
{
    count++; /*counting number of comparisons*/
    if(l<r){
    	return -1;
    }
    else if(l>r){
    	return 1;
    }
    else{
    	return 0;
    }
}
