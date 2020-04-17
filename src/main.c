#include <time.h>
#include <pthread.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <time.h>

#define MAX_THREADS 20 //REEEEEEEE

void *thread_func(void *); 

int main(int argc, char const **argv)
{
	const int threads_num = (argc == 1)? 1 : atoi(argv[1]);
	if (errno) perror("atoi");
	
	pthread_t tid[MAX_THREADS];
	int i, thread_count = 0;
	clock_t start, end;
	
	start = clock();
	for (i = 0; i < threads_num; i++) {
		pthread_create(&tid[i], NULL, thread_func, /*args*/);		
	} 
	
	for (i = 0; i < threads_num; i++) {
		pthread_join(&tid[i],NULL);		
	}
	end = clock();
	
	const double time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Elapsed time %f", time_used);
	return 0;
}

p