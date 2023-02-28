// Author: SPEL Technologies, Inc.
// Performs convolution
// Warmup assignment Problem 2 solution

/******** DO NOT DISTRIBUTE ***********************/
#include <stdio.h>

#define  MAXROWS 100
#define MAXCOLS 100

int kernel[3][3];
int image[MAXROWS][MAXCOLS];
int result[MAXROWS][MAXCOLS];

// The convolved pixel at result[i][j] is obtained from taking the product of image[i][j] and kernel as follows:
// result[i][j] = image[i-1][j-1] * kernel[0][0] + image[i-1][j] * kernel[0][1] + image[i-1][j+1] * kernel[0][2]
//              + image[i][j-1] * kernel[1][0] + image[i][j] * kernel[1][1] + image[i][j+1] * kernel[1][2]
//              + image[i+1][j-1] * kernel[2][0] + image[i+1][j] * kernel[2][1] + image[i+1][j+1] * kernel[2][2];
// Find a pattern in the above : image[i+l-1][j+m-1] * kernel[l][m]
// Note that the coordinates for image pixels must lie within the bounds 0 and imageSize.
void convolve(int imageSize, int kernelSize) {
	for (int i = 0; i < imageSize; i++) {
		for (int j = 0; j < imageSize; j++) {

			for (int l = 0; l < kernelSize; l++) {  // kernel has coordinates(l,m)
				for (int m = 0; m < kernelSize; m++) {
					// check if the image coordinates lie within bounds
					if ((i+l-1 >= 0) && (i+l -1 < imageSize) && (j+m -1 >= 0) && (j+m -1 < imageSize))
						result[i][j] += image[i+l -1][j+m -1] * kernel[l][m];  // convolve
				}
			}
		}
	}
}

// initialize image to 0
void initialize(int imageSize) {
	for (int i = 0;i < imageSize; i++) {
		for (int j = 0; j < imageSize; j++) {
			result[i][j] = 0;
		}
	}
}

int main() {
	freopen("input_problem_2.txt", "r", stdin);
	int imageSize, kernelSize, testi;

	for (testi = 0; testi < 10; testi++) {
		printf("\n Test case: %d \n", testi+1);
		scanf("%d", &imageSize);
		scanf("%d", &kernelSize);

		initialize(imageSize);

		for (int i = 0;i < imageSize; i++) {
			for (int j = 0; j < imageSize; j++) {
				scanf("%d", &image[i][j]);
			}
		}

		for (int i = 0;i < kernelSize; i++) {
			for (int j = 0; j < kernelSize; j++) {
				scanf("%d", &kernel[i][j]);
			}
		}

		convolve(imageSize, kernelSize);
		for (int i = 0;i < imageSize; i++) {
			for (int j = 0; j < imageSize; j++) {
				printf("%d ", result[i][j]);
			}
			printf("\n");
		}
	}
}



