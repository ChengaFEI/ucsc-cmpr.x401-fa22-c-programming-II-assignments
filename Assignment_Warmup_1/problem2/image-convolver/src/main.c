//
//  UCSC Silicon Valley Extension
//  Advanced C Programming
//  Assignment 1 : C Review
//  Problem 2
//
//  main.c
//  image-convolver
//

#include <stdio.h>
#include <stdlib.h>
#include <mth.h>
#include <string.h>
#include <ctype.h> 

// Basic variables settings.
#define MAXROWS 100
#define MAXCOLS 100
#define KERNELSIZE 3
int kernel[KERNELSIZE][KERNELSIZE];
int image[MAXROWS][MAXCOLS];
int result[MAXROWS][MAXCOLS];

/**************************************/
/* Helper function prototype          */
/**************************************/
void convolve(int, int);
void initialize(int);

/**************************************/
/* Main function                      */
/**************************************/
int main(void) {
    // Load data.
	freopen("input.txt", "r", stdin);
	int imageSize, kernelSize, testi;

	for (testi = 0; testi < 10; testi++) {
		printf("\n Test case: %d \n", testi+1);
		scanf("%d", &imageSize);
		scanf("%d", &kernelSize);

        // Initialize an empty result image with all zero-pixels.
		initialize(imageSize);

        // Load initial image's pixels.
		for (int i = 0;i < imageSize; i++) {
			for (int j = 0; j < imageSize; j++) {
				scanf("%d", &image[i][j]);
			}
		}

        // Load weights in the kernel.
		for (int i = 0;i < kernelSize; i++) {
			for (int j = 0; j < kernelSize; j++) {
				scanf("%d", &kernel[i][j]);
			}
		}

        // Convolve the image.
		convolve(imageSize, kernelSize);

        // Output the result image.
		for (int i = 0;i < imageSize; i++) {
			for (int j = 0; j < imageSize; j++) {
				printf("%d ", result[i][j]);
			}
			printf("\n");
		}
	}
    return EXIT_SUCCESS;
}

/**************************************/
/* Helper function Implementation     */
/**************************************/

void convolve(int imageSize, int kernelSize) {
    // Evaluate the distance from the kernel center to the boundary.
    int indexDiff = kernelSize / 2;
    // Declare the result in the current pixel.
    int resultPixel;
    // Declare the boundary index.
    int up = 0, down = 0, left = 0, right = 0;
    // Loop over rows and columns.
    for (int i = 0; i < imageSize; i++) {
        for (int j = 0; j < imageSize; j++) {
            // Refresh the result pixel in the current location.
            resultPixel = 0;
            // Loop over pixels around the kernel center.
            up = i - indexDiff < 0 ? 0 : i - indexDiff;
            left = j - indexDiff < 0 ? 0 : j - indexDiff;
            down = i + indexDiff >= imageSize ? imageSize - 1 : i + indexDiff;
            right = j + indexDiff >= imageSize ? imageSize - 1 : j + indexDiff;
            for (int k = up; k <= down; k++) {
                for (int l = left; l <= right; l++) {
                    resultPixel += image[k][l]*kernel[indexDiff+k-i][indexDiff+l-j];
                }
            }
            // Update the result matrix.
            result[i][j] = resultPixel;
        }
    }
}

// initializeall pixels in the result image to 0.
void initialize(int imageSize) {
	for (int i = 0;i < imageSize; i++) {
		for (int j = 0; j < imageSize; j++) {
			result[i][j] = 0;
		}
	}
}
