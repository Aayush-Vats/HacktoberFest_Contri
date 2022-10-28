#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f, r;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(struct queue *q)
{
    if (q->f == q->r)
        return 1;
    else
        return 0;
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        q->f++;
        return q->arr[q->f];
    }
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

void printing(struct queue *q)
{
    printf("\nThe follwing elements are in the Queue\n");
    for (int i = q->f + 1; i <= q->r; i++)
    {
        printf("%d\n", q->arr[i]);
    }
}

int main()
{
    struct queue q;
    q.size = 20;
    q.f = -1;
    q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 1);
    enqueue(&q, 11);
    enqueue(&q, 111);
    printing(&q);

    printf("Deleted Element: %d\n", dequeue(&q));
    printing(&q);

    return 0;
}
