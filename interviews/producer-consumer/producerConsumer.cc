#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<pthread.h>

#include <iostream>
#include <queue>

#define MAX_SIZE	3			/* Max Size */
std::queue<int> q;				/* shared buffer */
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;	/* mutex lock for buffer */
pthread_cond_t ccv=PTHREAD_COND_INITIALIZER;    /* consumer waits on this cond var */
pthread_cond_t pcv=PTHREAD_COND_INITIALIZER;    /* producer waits on this cond var */

void *producer(void *param);
void *consumer(void *param);

int main (int argc, char *argv[])
{
	pthread_t tid1, tid2;		/* thread identifiers */

	/* create the threads; may be any number, in general */
	if (pthread_create(&tid1,NULL,producer,NULL) != 0) {
		fprintf (stderr, "Unable to create producer thread\n");
		exit (1);
	}
	if (pthread_create(&tid2,NULL,consumer,NULL) != 0) {
		fprintf (stderr, "Unable to create consumer thread\n");
		exit (1);
	}
	/* wait for created thread to exit */
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	printf ("Parent quiting\n");
}

void *producer(void *param)
{
	for (int i = 0; i < 20; i++) {
		pthread_mutex_lock (&m);
		while(q.size() == MAX_SIZE)
			pthread_cond_wait (&pcv, &m);
		q.push(i);
		pthread_mutex_unlock (&m);
		pthread_cond_signal (&ccv);
		printf ("producer: inserted %d\n", i);  fflush (stdout);
		sleep(.2);
	}
	printf ("producer quiting\n");  fflush (stdout);
}
void *consumer(void *param)
{
	while(1) {
		pthread_mutex_lock (&m);
		while(q.empty())
			pthread_cond_wait (&ccv, &m);
		int data = q.front();
		q.pop();
		pthread_mutex_unlock (&m);
		pthread_cond_signal (&pcv);
		printf ("Consume value %d\n", data);  fflush(stdout);
		sleep(1);
	}	
}
