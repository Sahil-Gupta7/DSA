#include <stdio.h>
#include <stdlib.h>
#define QUEUE_EMPTY_MAGIC 0xdeadbeef
typedef struct _queue_t
{
    int *arr;
    int rear, front, count, max;
} queue_t;
queue_t *queue_allocate(int n);
void queue_insert(queue_t *q, int v);
int queue_remove(queue_t *q);
int queue_count(queue_t *q);
int queue_is_empty(queue_t *q);
void stack_push(queue_t *q, int v)
{
    queue_insert(q, v);
}
int stack_pop(queue_t *q)
{
    int i, n = queue_count(q);
    int removed_element;
    for (i = 0; i < (n - 1); i++)
    {
        removed_element = queue_remove(q);
        queue_insert(q, removed_element);
    }
    removed_element = queue_remove(q);
    return removed_element;
}
int stack_is_empty(queue_t *q)
{
    return queue_is_empty(q);
}
int stack_count(queue_t *q)
{
    return queue_count(q);
}
int queue_count(queue_t *q)
{
    return q->count;
}
queue_t *
queue_allocate(int n)
{
    queue_t *queue;
    queue = malloc(sizeof(queue_t));
    if (queue == NULL)
        return NULL;
    queue->max = n;
    queue->arr = malloc(sizeof(int) * n);
    queue->rear = n - 1;
    queue->front = n - 1;
    return queue;
}
void queue_insert(queue_t *q, int v)
{
    if (q->count == q->max)
        return;
    q->rear = (q->rear + 1) % q->max;
    q->arr[q->rear] = v;
    q->count++;
}
int queue_remove(queue_t *q)
{
    int retval;
    if (q->count == 0)
        return QUEUE_EMPTY_MAGIC;
    q->front = (q->front + 1) % q->max;
    retval = q->arr[q->front];
    q->count--;
    return retval;
}
int queue_is_empty(queue_t *q)
{
    return (q->count == 0);
}
void queue_display(queue_t *q)
{
    int i = (q->front + 1) % q->max, elements = queue_count(q);
    while (elements--)
    {
        printf("[%d]  ", q->arr[i]);
        i = (i >= q->max) ? 0 : (i + 1);
    }
}
#define MAX 128
int main(void)
{
    queue_t *q;
    int x, select;
    q = queue_allocate(MAX);
    printf("\n 1 -> PUSH\n 2 -> POP\n 3 -> EXIT\n");
    do
    {
        printf("\n\t Enter your Choice : ");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            printf(" Enter the Value to be PUSHED : ");
            scanf("  %d", &x);
            stack_push(q, x);
            printf(" PUSHED Value : %d\n", x);
            printf(" CURRENT QUEUE : ");
            queue_display(q);
            printf("\n");
            break;
        case 2:
            x = stack_pop(q);
            if (x == QUEUE_EMPTY_MAGIC)
                printf("\n NO VALUES REMOVED...\n");
            else
                printf(" POPPED VALUE : %d\n", x);
            printf(" CURRENT QUEUE : ");
            queue_display(q);
            printf("\n");
            break;
        case 3:
            printf(" EXITING...\n");
            return 0;
        default:
            printf(" INVALID CHOICE");
            return 0;
        }
    } while (1);
    return 0;
}