#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LibStack.h"
#include "LibQueue.h"

void emptyRunway(Queue *runway) {
	while (!isEmptyQueue(*runway)) {
		printf("%d\n", dequeue(runway));
	}
}
	
void emptyHangar(Stack *hangar, Queue *runway) {
	emptyRunway(runway);

	while (!isEmptyStack(*hangar)) {
		enqueue(pop(hangar), runway);
	}
} 

int main(int argc, char *argv[]) {
	int n, plane;
	char repair[4];
	int countRun = 0;
	int countHang = 0;
  
	scanf("%d", &n);
  
	Queue runway;
	runway = newQueue(n);
  
	Stack hangar;
	hangar = newStack(n);
  
	while (n!=0) {
	  	scanf("%d %s", &plane, repair);
	  
		if (repair[0] == 'n') {
			enqueue(plane, &runway);
			countRun++;

			if (countRun == 7) {
				emptyRunway(&runway);
				countRun = 0;
			}
		}
		
		if (repair[0] == 'y') {
			push(plane, &hangar);
			countHang++;

			if (countHang == 5) {
				emptyRunway(&runway);
				emptyHangar(&hangar, &runway);
				countHang = 0;
				countRun = 5;
			}
		}
	n--;
	}
  
  	emptyRunway(&runway);
  	emptyHangar(&hangar, &runway);
  	emptyRunway(&runway);

  	freeStack(hangar);
  	freeQueue(runway);
	  
  return 0;
}