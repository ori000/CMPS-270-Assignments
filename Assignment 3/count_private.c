


// NOTE: I HAVE DONE THE EXERCISE USING TWO WAYS, PRAGMA AND ASSIGNING THE PRIVATE LOGIC TO EACH VARIABLE, AND THE OTHER WAY IS THROUGH CREATING A PRIVATE ARRAY.
//       I COMMENTED THE OTHER METHOD DUE TO TIME EFFICIENCY AND ITERATION SKIPPING PURPOSES. PLEASE NOTE THAT ON MY LAPTOP, BOTH RESULTED IN THE SAME VALUES SO I AM ASSUMING THAT BOTH ARE CORRECT.






#ifdef _OPENMP
#include <omp.h>
#endif
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>


/*
TEST CASES:

TEST CASE 1: Array of size 100 and 1 Thread => checked
TEST CASE 2: Array of size 10,000 and 1 Thread => checked
TEST CASE 3: Array of size 100,000 and 1 Thread => checked
TEST CASE 4: Array of size 1000,000 and 1 Thread => checked
TEST CASE 5: Array of size 10,000,000 and 1 Thread => checked
TEST CASE 6: Array of size 1,000,000,000 and 1 Thread => checked

TEST CASE 7: Array of size 100 and 2 Threads => checked
TEST CASE 8: Array of size 10,000 and 2 Threads => checked
TEST CASE 9: Array of size 100,000 and 2 Threads => checked
TEST CASE 10: Array of size 1000,000 and 2 Threads => checked
TEST CASE 11: Array of size 10,000,000 and 2 Threads => checked
TEST CASE 12: Array of size 1,000,000,000 and 2 Threads => checked

TEST CASE 13: Array of size 100 and 4 Threads => checked
TEST CASE 14: Array of size 10,000 and 4 Threads => checked
TEST CASE 15: Array of size 100,000 and 4 Threads => checked
TEST CASE 16: Array of size 1000,000 and 4 Threads => checked
TEST CASE 17: Array of size 10,000,000 and 4 Threads => checked
TEST CASE 18: Array of size 1,000,000,000 and 4 Threads => checked

TEST CASE 19: Array of size 100 and 8 Threads => checked
TEST CASE 20: Array of size 10,000 and 8 Threads => checked
TEST CASE 21: Array of size 100,000 and 8 Threads => checked
TEST CASE 22: Array of size 1000,000 and 8 Threads => checked
TEST CASE 23: Array of size 10,000,000 and 8 Threads => checked
TEST CASE 24: Array of size 1,000,000,000 and 8 Threads => checked

TEST CASE 25: Array of size 100 and 16 Threads => checked
TEST CASE 26: Array of size 10,000 and 16 Threads => checked
TEST CASE 27: Array of size 100,000 and 16 Threads => checked
TEST CASE 28: Array of size 1000,000 and 16 Threads => checked
TEST CASE 29: Array of size 10,000,000 and 16 Threads => checked
TEST CASE 30: Array of size 1,000,000,000 and 16 Threads => checked

TEST CASE 31: Array of size 100 and 32 Threads => checked
TEST CASE 32: Array of size 10,000 and 32 Threads => checked
TEST CASE 33: Array of size 100,000 and 32 Threads => checked
TEST CASE 34: Array of size 1000,000 and 32 Threads => checked
TEST CASE 35: Array of size 10,000,000 and 32 Threads => checked
TEST CASE 36: Array of size 1,000,000,000 and 32 Threads => checked

TEST CASE 37: Array of size 100 and 64 Threads => checked
TEST CASE 38: Array of size 10,000 and 64 Threads => checked
TEST CASE 39: Array of size 100,000 and 64 Threads => checked
TEST CASE 40: Array of size 1000,000 and 64 Threads => checked
TEST CASE 41: Array of size 10,000,000 and 64 Threads => checked
TEST CASE 42: Array of size 1,000,000,000 and 64 Threads => checked

TEST CASE 43: Array of size 100,000,000 and 1 Threads => checked
TEST CASE 44: Array of size 100,000,000 and 2 Threads => checked
TEST CASE 45: Array of size 100,000,000 and 4 Threads => checked
TEST CASE 46: Array of size 100,000,000 and 8 Threads => checked
TEST CASE 47: Array of size 100,000,000 and 16 Threads => checked
TEST CASE 48: Array of size 100,000,000 and 32 Threads => checked
TEST CASE 49: Array of size 100,000,000 and 64 Threads => checked

TEST CASE 50: Array of size 0 and 0 Threads => checked
TEST CASE 51: Array of size > 0 and 0 Threads => checked
TEST CASE 52: Out of bounds exception => checked
*/

#define numberofThreads 8
#define length 1000000
void* private (void* threadID);
long count1s ();

long iter = 0, countAccurate = 0, counter = 0, countAccurate2 = 0; 
long count = 0;
long* array;

/*
REQUIRES: valid threadID (to avoid out of bound)

EFFECTS: check for the number of ones in the array and keep track of the number of iterations
*/
void* private (void* threadID)
{
    #pragma omp parallel private(countPrivate)
    {   

        long id= (long) threadID;   //id is to determine the starting position for each thread (because we split the array where each thread takes a part)
        long countPrivate = 0;
        long avgThreadsIter = length/numberofThreads; //in order to iterate over the splitted parts of the array (e.g., 100/2 => 50 , 50 for each thread)

        //long countPrivate2 = 0;
        // int* privArray = (long*)malloc(sizeof(long)*length);
        // for(long c = id*avgThreadsIter; c < id*avgThreadsIter+avgThreadsIter; c++)
        //     privArray[c] = array[c];
        if(id < numberofThreads - 1) // usual case where we should not have problems splitting the array between threads
        {
        #pragma omp for private(i)
            for(long i = id*avgThreadsIter; i < id*avgThreadsIter+avgThreadsIter; i++)  //in order to iterate over the splitted parts of the array (e.g., from 0 to 49, from 50 to 100)
            {
                if(array[i] == 1)
                {   
                    // #pragma omp critical
                    countPrivate+=1;
                }
                // if(privArray[i] == 1)
                // {
                //     //#pragma omp critical
                //     countPrivate2+=1;
                // }
                // #pragma omp critical
                iter +=1;
            }
        }
        else if(id >= numberofThreads - 1) //to avoid inaccurate counting when we reach the number of threads (e.g., length: 100, threads: 64, without this logic we would have i in the previous for loop greater than the length of the actual array)
        {
            for(long j = numberofThreads * avgThreadsIter - avgThreadsIter; j <= length - 1; j++)
            {
                if(array[j] == 1)
                {   
                    // #pragma omp critical
                    countPrivate+=1;
                }
                // if(privArray[i] == 1)
                // {
                //     //#pragma omp critical
                //     countPrivate2+=1;
                // }
                // #pragma omp critical
                iter +=1;
            }
        }
        counter += countPrivate;
        //counter += countPrivate2;
    }
}
/*
REQUIRES: nothing

EFFECTS: return the actual number of ones in the array
*/
long count1s ()
{
    long i;
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
        pthread_t threadsArray[numberofThreads];    //array of threads

        for(long i = 0; i < length; i++)
        {
            array[i] = rand() % 5;
        }
        for(int j = 0; j < numberofThreads; j++)
        {
            pthread_create(&threadsArray[j], NULL, &private,(void*) j); //creates threads
        }
        for(int k = 0; k < numberofThreads; k++)
        {
            pthread_join(threadsArray[k], NULL); //joins threads (wait to terminate)
        }
        count1s();
        totalTime = clock();    //starts clock
        
        if(count == counter)
        {
            printf("CountPrivate: %d | count: %d \n", counter, count);
            countAccurate += 1;
        }
        // if(count == countPrivate2)
        // {
        //     printf("CountPrivate2: %d | count: %d \n", counter, count);
        //     countAccurate2 += 1;
        // }
    }

    printf("Count of Ones: %d\n", counter);
    printf("Total Time: %f\n", (double)totalTime/(double)CLOCKS_PER_SEC);
    printf("Count of Iterations: %d\n", iter);
    printf("Actual Count of Ones: %d\n", count);
    printf("Count of correct answers using pragma: %d\n", countAccurate);
    // printf("Count of correct answers using privArray: %d\n", countAccurate2);
}

