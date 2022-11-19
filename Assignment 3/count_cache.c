#ifdef _OPENMP
#include <omp.h>
#endif
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

//L1 CACHE SIZE: 384 KB
struct Cache
{
    int counter;
    char* array;
};

#define numberofThreads 16
#define length 100000
void* cacheFunc (void* threadID);

long iter = 0, countCache = 0; 
int count = 0;
long* array;

/*
REQUIRES: valid threadID (to avoid out of bound)

EFFECTS: check for the number of ones in the array and keep track of the number of iterations
*/
void* cacheFunc (void* threadID)
{
    #pragma omp parallel
    {
        struct Cache cache;
        cache.array = (char*)malloc(384*1000);
        long id= (long) threadID;
        long avgThreadsIter = length/numberofThreads; //in order to iterate over the splitted parts of the array (e.g., 100/2 => 50 , 50 for each thread)
        #pragma omp for private(i)
        for(long i = id*avgThreadsIter; i < id*avgThreadsIter+avgThreadsIter; i++)  //in order to iterate over the splitted parts of the array (e.g., from 0 to 49, from 50 to 100)
        {
            if(array[i] == 1)
            {   
                #pragma omp critical
                cache.counter+=1;
            }
            #pragma omp critical
            iter +=1;
        }
        countCache = cache.counter;
        cache.array = ""+cache.counter;
    }
}

/*
REQUIRES: nothing

EFFECTS: return the actual number of ones in the array
*/
int count1s ()
{
    int i;
    for (i=0; i<length; i++)
    {
        if (array[i] == 1)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    srand(time(NULL));
    clock_t totalTime;
    for(int i = 0; i < 100; i++)
    {
        array = (long*)malloc(sizeof(long)*length);
        pthread_t threadsArray[numberofThreads];

        for(long i = 0; i < length; i++)
        {
            array[i] = rand() % 5;
        }
        for(int i = 0; i < numberofThreads; i++)
        {
            pthread_create(&threadsArray[i], NULL, &cacheFunc,(void*) i);
        }
        for(int k = 0; k < numberofThreads; k++)
        {
            pthread_join(threadsArray[k], NULL);
        }
        totalTime = clock();
        count1s();
    }

    printf("Count of Ones: %d\n", countCache);
    printf("Total Time: %f\n", (double)totalTime/(double)CLOCKS_PER_SEC);
    printf("Count of Iterations: %d\n", iter);
    printf("Actual Count of Ones: %d", count);
}