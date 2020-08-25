#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>

int comparator(const void *p, const void *q);

static int count=0;  /*counter for counting comparisons*/

int main (){
	int n, i, temp, time;
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

	qsort(arr, n, sizeof(arr[0]), comparator); /*calling sort utility function*/

	gettimeofday(&tv_2, NULL);

	for(i=0; i<n; i++){
		fprintf(stdout, "%d\n", arr[i]);
	}

	time_ms=(tv_2.tv_usec-tv_1.tv_usec)/1000 ;
	time_s=(tv_2.tv_sec-tv_1.tv_sec)*1000 ;
	time = (int)(time_s+time_ms); /*Finding total run time*/

	//Printing runtime and number of comparisons
	fprintf(stderr, "runtime, %d\n", time);
	fprintf(stderr, "comparisons, %d\n", count);

	return  0;
}

int comparator(const void *p, const void *q)
{
    // Get the values at given addresses
    int l = *(const int *)p;
    int r = *(const int *)q;

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
