    
   /* 
 * queue_with_two_stacks.h
 * Copyright SPEL Technologies, Inc.
 *
 * This implements a queue using two stacks. A queue is a First-In-First-Out structure, whereas 
 * a stack is a Last-In-First-Out structure.
 */ 
 
#include "queue_with_two_stacks.h"

QueueWithTwoStacks * createQueueWithTwoStacks(int cap) {
	QueueWithTwoStacks *queue = (QueueWithTwoStacks *) calloc(sizeof(QueueWithTwoStacks), 1);
    queue->capacity = cap;
    queue->size = 0;
	queue->stack1 = createStack(cap);
	queue->stack2 = createStack(cap);	
	return queue;
}

// add item (called data) to stack1
void enqueue(QueueWithTwoStacks *queue, int data) {
		   Data data1;
		   data1.value = data;
           if (queue->size == queue->capacity) {
               printf("Error: Queue is full \n");
           }
           else {
             push(queue->stack1, data1);
             ++queue->size;
           }
}
 
// The item at the bottom of stack1 has to be removed and returned: move all the items from stack1 to
// stack2, then return the item at the top of stack2. If stack2 already has items, then
// return the topmost item of stack2.
int dequeue(QueueWithTwoStacks *queue) {
           if (queue->size == 0) {
              printf("Error: Queue is empty \n");
              return -1;
           } 
           else {
               if (isEmpty(queue->stack2)) {
                   while (!isEmpty(queue->stack1)) {
                       Data temp = peek(queue->stack1);
                       pop(queue->stack1);
                       push(queue->stack2, temp);
                   }
               }
           
              Data data = peek(queue->stack2);
              pop(queue->stack2);
              --queue->size;
              return data.value;
           }
}    
        

int main() {
        QueueWithTwoStacks *newqueue = createQueueWithTwoStacks(5);
        enqueue(newqueue, 100);
        enqueue(newqueue, 200);
        enqueue(newqueue, 300);
        enqueue(newqueue, 400);
        enqueue(newqueue, 500);

        int value = dequeue(newqueue);
        printf("%d \n", value);
        value = dequeue(newqueue);
        printf("%d \n", value);
        value = dequeue(newqueue);
        printf("%d \n", value);
        value = dequeue(newqueue);
        printf("%d \n", value);
        value = dequeue(newqueue);
        printf("%d \n", value);
 } 