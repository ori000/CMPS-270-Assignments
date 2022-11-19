#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

/*
TEST CASES:

TEST CASE 1: Array of size 100 and 1 Thread
TEST CASE 2: Array of size 10,000 and 1 Thread
TEST CASE 3: Array of size 100,000 and 1 Thread
TEST CASE 4: Array of size 1000,000 and 1 Thread
TEST CASE 5: Array of size 10,000,000 and 1 Thread
TEST CASE 6: Array of size 1,000,000,000 and 1 Thread

TEST CASE 7: Array of size 100 and 2 Threads
TEST CASE 8: Array of size 10,000 and 2 Threads
TEST CASE 9: Array of size 100,000 and 2 Threads
TEST CASE 10: Array of size 1000,000 and 2 Threads
TEST CASE 11: Array of size 10,000,000 and 2 Threads
TEST CASE 12: Array of size 1,000,000,000 and 2 Threads

TEST CASE 13: Array of size 100 and 4 Threads
TEST CASE 14: Array of size 10,000 and 4 Threads
TEST CASE 15: Array of size 100,000 and 4 Threads
TEST CASE 16: Array of size 1000,000 and 4 Threads
TEST CASE 17: Array of size 10,000,000 and 4 Threads
TEST CASE 18: Array of size 1,000,000,000 and 4 Threads

TEST CASE 19: Array of size 100 and 8 Threads
TEST CASE 20: Array of size 10,000 and 8 Threads
TEST CASE 21: Array of size 100,000 and 8 Threads
TEST CASE 22: Array of size 1000,000 and 8 Threads
TEST CASE 23: Array of size 10,000,000 and 8 Threads
TEST CASE 24: Array of size 1,000,000,000 and 8 Threads

TEST CASE 25: Array of size 100 and 16 Threads
TEST CASE 26: Array of size 10,000 and 16 Threads
TEST CASE 27: Array of size 100,000 and 16 Threads
TEST CASE 28: Array of size 1000,000 and 16 Threads
TEST CASE 29: Array of size 10,000,000 and 16 Threads
TEST CASE 30: Array of size 1,000,000,000 and 16 Threads

TEST CASE 31: Array of size 100 and 32 Threads
TEST CASE 32: Array of size 10,000 and 32 Threads
TEST CASE 33: Array of size 100,000 and 32 Threads
TEST CASE 34: Array of size 1000,000 and 32 Threads
TEST CASE 35: Array of size 10,000,000 and 32 Threads
TEST CASE 36: Array of size 1,000,000,000 and 32 Threads

TEST CASE 37: Array of size 100 and 64 Threads
TEST CASE 38: Array of size 10,000 and 64 Threads
TEST CASE 39: Array of size 100,000 and 64 Threads
TEST CASE 40: Array of size 1000,000 and 64 Threads
TEST CASE 41: Array of size 10,000,000 and 64 Threads
TEST CASE 42: Array of size 1,000,000,000 and 64 Threads

TEST CASE 43: Array of size 0 and 0 Threads
TEST CASE 44: Array of size > 0 and 0 Threads
TEST CASE 45: Out of bounds exception
*/

#define numberofThreads 2
#define length 10000
void* Mutex (void* threadID);
pthread_mutex_t mutex;
long iter = 0, countMutex = 0; 
int count = 0;
long* array;

/*
REQUIRES: valid threadID (to avoid out of bound)

EFFECTS: check for the number of ones in the array and keep track of the number of iterations
*/
void* Mutex (void* threadID)
{
    long id= (long) threadID;
    long avgThreadsIter = length/numberofThreads; //in order to iterate over the splitted parts of the array (e.g., 100/2 => 50 , 50 for each thread)
    pthread_mutex_lock(&mutex);

    for(long i = id*avgThreadsIter; i < id*avgThreadsIter+avgThreadsIter; i++)  //in order to iterate over the splitted parts of the array (e.g., from 0 to 49, from 50 to 100)
    {
        if(array[i] == 1)
            countMutex+=1;
        iter+=1;
    }
    pthread_mutex_unlock(&mutex);
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
        for(int j = 0; j < numberofThreads; j++)
        {
            pthread_create(&threadsArray[j], NULL, &Mutex,(void*) j);
        }
        for(int k = 0; k < numberofThreads; k++)
        {
            pthread_join(threadsArray[k], NULL);
        }
        totalTime = clock();
        count1s();
    }

    printf("Count of Ones: %d\n", countMutex);
    printf("Total Time: %f\n", (double)totalTime/(double)CLOCKS_PER_SEC);
    printf("Count of Iterations: %d\n", iter);
    printf("Actual Count of Ones: %d", count);
}

