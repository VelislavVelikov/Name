#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
 
pthread_mutex_t mutex;
 
void* seller_(void* buyer) {
 
    int counter = 0;
    bool car_empty[3] = {true};
 
    long buyer_num = (long)buyer;
 
 
    for(; counter < 3; counter++) {
 
            pthread_mutex_lock(&mutex);
           
   
            printf("Buyer %ld takes car %d.\n", buyer_num, counter + 1);
 
 
            printf("Buyer %ld returns car %d.\n", buyer_num, counter + 1);
 
            pthread_mutex_unlock(&mutex);
 
 
        // if(counter == 2) counter = 0;
    }
 
}
 
int main() {
 
    pthread_t buyers[3];
    long counter = 0;
 
        pthread_mutex_init(&mutex, NULL);
 
   
        for (; counter < 3; counter++) {
 
        pthread_create(&buyers[counter], NULL, seller_, (void*)(counter + 1)); 
        }
 
        for (counter = 0; counter < 3; counter++) {
 
            pthread_join(buyers[counter], NULL);
        }
   
 
    pthread_mutex_destroy(&mutex);
 
    return 0;
}