#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int d[] = { 6, 5, 3, 1, 4 };
int c[] = { 50, 100, 30, 40, 90 };
int VIP[] = { 0, 1, 0, 0, 0 };
int D;
int maxRevenue = 0, maxRiders;


void knapsack(int index, int totalDist, int revenue, int numRiders, bool isVIP ) {
	if (totalDist > D)
		return;

	if (numRiders > maxRiders)
		return;

	if (numRiders > 1 && isVIP == true)
		return;

	if (revenue > maxRevenue) {
		maxRevenue = revenue;
	}

	if (index == -1) {
		return;
	}


	knapsack(index - 1, totalDist + d[index], revenue + c[index], numRiders+1, isVIP | VIP[index]);
	knapsack(index - 1, totalDist, revenue, numRiders, isVIP);
}

int main() {
	//enumerate(-1, 0, "");
	//cout << knapsack(sizeof(weights)/sizeof(int) - 1, maxAllowedWeight) << endl;
	int numTestCases, i;
	int size;

	freopen("VIP_riders.txt", "r", stdin);
		scanf("%d",  &numTestCases);

		for (i = 0; i < numTestCases; i++) {

			maxRevenue = 0; // reset solution

			scanf("%d", &D); 		  // maximum allowed distance
			scanf("%d", &maxRiders); // max number of riders
                        scanf("%d", &size);		 // number of riders
			for (int i = 0; i < size; i++) {
				scanf("%d", &d[i]);  // read distance of each person
				scanf("%d", &c[i]); // read cost of each ride
				scanf("%d", &VIP[i]); // read if VIP
			}

			knapsack(size-1, 0, 0, 0, false);
			printf("Test case: %d\n" , i+1);
			printf("Max revenue is: %d\n" , maxRevenue );
		}


	return 0;
}
