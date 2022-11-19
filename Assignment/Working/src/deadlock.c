#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *function1();
void *function2();
pthread_mutex_t first_mutex;
pthread_mutex_t second_mutex;
int main()
{
    pthread_mutex_init(&first_mutex, NULL);
    pthread_mutex_init(&second_mutex, NULL);
    pthread_t T1, T2;
    pthread_create(&T1, NULL, function1, NULL);
    pthread_create(&T2, NULL, function2, NULL);
    pthread_join(T1, NULL);
    pthread_join(T2, NULL);
    printf("Thread joined\n");
}
void *function1()
{
    printf("T1 Trying to acquire first mutex\n");
    pthread_mutex_lock(&first_mutex);
    printf("T1 acquired first mutex\n");
    sleep(1);
    printf("T1 Trying to acquire second mutex\n");
    pthread_mutex_lock(&second_mutex);
    printf("T1 acquired second mutex\n");
}
void *function2()
{
    printf("T2 Trying to acquire second mutex\n");
    pthread_mutex_lock(&second_mutex);
    printf("T2 acquired second mutex\n");
    sleep(1);
    printf("T2 Trying to acquire first mutex\n");
    pthread_mutex_lock(&first_mutex);
    printf("T2 acquired first mutex\n");
}