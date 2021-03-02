#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty; // binary and counting semaphores
int in = 0, out = 0; // producer and consumer buffer pointers
int item, buffer[100], buffer_size;

void wait(int *s)
{
    *s -= 1;
}

void signal(int *s)
{
    *s += 1;
}

void producer()
{
    wait(&empty);
    wait(&mutex);
    
    printf("Enter an item to produce: ");
    scanf("%d", &item);
    buffer[in] = item;
    printf("Producer produces the item %d\n", buffer[in]);
    in = (in+1)%buffer_size;

    signal(&mutex);
    signal(&full);
}

void consumer()
{
    wait(&full);
    wait(&mutex);
    
    printf("Consumer consumes item %d\n", buffer[out]);
    out = (out+1)%buffer_size;
    
    signal(&mutex);
    signal(&empty);
}

int main()
{
    int choice;
    printf("Enter buffer size: ");
    scanf("%d", &buffer_size);
    empty = buffer_size;

    printf("1.Producer 2.Consumer 3.Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("Buffer is full!!\n");
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("Buffer is empty!!\n");
            break;
        case 3:
            exit(0);
            break;
        }
    }

    return 0;
}