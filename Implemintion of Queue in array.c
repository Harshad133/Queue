#include<stdio.h>

struct Queue
{
    int front,rear;
    int capacity;
    int *array;
};

struct Queue* createQueue(int cap)
{
    struct Queue *Q;
    Q=(struct Queue *) malloc(sizeof(struct Queue));

    if(!Q)
        return(NULL);
    Q->capacity=cap;
    Q->front=-1;
    Q->rear=-1;
    Q->array= (int *) malloc(Q->capacity*sizeof(int));

    if(!Q->array)
        return(NULL);
    return(Q);
}

int isEmpty(struct Queue *Q)
{
    return(Q->front==-1);
}

int isFull(struct Queue *Q)
{
    return((Q->rear+1)%(Q->capacity)==Q->front);
}

int queueSize(struct Queue *Q)
{
    return((Q->capacity-Q->front+Q->rear+1)%Q->capacity);
}

void enQueue(struct Queue *Q,int item)
{
    if(isFull(Q))
        printf("\nQueu is full");
    else
    {
        Q->rear=(Q->rear+1)%Q->capacity;
        Q->array[Q->rear]=item;

        if(Q->front==-1)
            Q->front=Q->rear;
    }
}

int deQueue(struct Queue *Q)
{
    int data=-1;
    if(isEmpty(Q))
    {
        printf("\nQueu is empty");
        return(-1);
    }
    else
    {
        data = Q->array[Q->front];
        if (Q->front==Q->rear)
        {
            Q->front =-1;
            Q->rear=-1;
        }
        else
            Q->front= (Q->front+1) % Q->capacity;
    }
    return(data);
}

void deleteQueue(struct Queue *Q)
{
    if(Q)
    {
        if(Q->array)
            free(Q->array);
        free(Q);
    }
}

int menu()
{
    int ch;

    printf("\n1. inserstion");
    printf("\n2. deletion");
    printf("\n3. delete Queu");
    printf("\n4. size of Queue");
    printf("\n5. exite");
    printf("\nenter value = ");
    scanf("%d",&ch);
    return(ch);
}
int main()
{
    struct Queue *Q;
    int n,v;

    printf("enter size of array = ");
    scanf("%d",&n);
    Q=createQueue(n);

    while(1) {

        switch(menu())
        {
        case 1:
            printf("\n enter data = ");
            scanf("%d",&v);
            enQueue(Q,v);
            break;

        case 2:
            v = deQueue(Q);
            if(v!=-1)
                printf(" \n data = %d",v);
            else
                printf("\nQueue is empty");
            break;

        case 3:
            deleteQueue(Q);
            break;

        case 4:
            v=queueSize(Q);
            printf(" \n size = %d",v);
            break;

        case 5:
            exit(0);
            
         default:
          printf("choise not avelible");
          break;
        }
    }
}