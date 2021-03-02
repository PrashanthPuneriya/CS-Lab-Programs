#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

char message[] = "Welcome to linux";

void *thread_fun1(void *arg)
{
	printf("thread_function is running. Arugument was %s \n", (char *)arg);
	sleep(10);
	strcpy(message, "bye1!");
	pthread_exit("thank you thread 1");
}
void *thread_fun2(void *arg)
{
	printf("thread_function is running. Arugument was %s \n", (char *)arg);
	sleep(10);
	strcpy(message, "bye2!");
	pthread_exit("thank you thread 2");
}
void *thread_fun3(void *arg)
{
	printf("thread_function is running. Arugument was %s \n", (char *)arg);
	sleep(10);
	strcpy(message, "bye3!");
	pthread_exit("thank you thread 3");
}

int main()
{
	pthread_t a_thread1;
	pthread_t a_thread2;
	pthread_t a_thread3;

	void *thread_result1;
	void *thread_result2;
	void *thread_result3;

	pthread_create(&a_thread1, NULL, thread_fun1, (void *)message);
	pthread_create(&a_thread2, NULL, thread_fun2, (void *)message);
	pthread_create(&a_thread3, NULL, thread_fun3, (void *)message);
	printf("Waiting for thread to finish \n");

	pthread_join(a_thread1, &thread_result1);
	pthread_join(a_thread2, &thread_result2);
	pthread_join(a_thread3, &thread_result3);

	printf("thread joined it returned %s \n", (char *)thread_result1);
	printf("thread joined it returned %s \n", (char *)thread_result2);
	printf("thread joined it returned %s \n", (char *)thread_result3);

	printf("message is now %s \n", message);
	printf("message is now %s \n", message);
	printf("message is now %s \n", message);

	exit(0);
}

/*
Output
> gcc multithreading.c -lpthread

Waiting for thread to finish 
thread_function is running. Arugument was Welcome to linux 
thread_function is running. Arugument was Welcome to linux 
thread_function is running. Arugument was Welcome to linux 
thread joined it returned thank you thread 1 
thread joined it returned thank you thread 2 
thread joined it returned thank you thread 3 
message is now bye1! 
message is now bye1! 
message is now bye1!
*/