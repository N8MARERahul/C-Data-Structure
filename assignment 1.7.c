//7. Write a program that reads two 2D metrices from the console, verifies if metrics ltiplication is possible or not. Then multiplies the metrices and prints the 3rd metrics.

#include<stdio.h>

int main() {
	int row1, row2, column1, column2, i, j, k;
	printf("Enter the row and column of the 1st Matrix-->\n");
	printf("Row: ");
	scanf("%d", &row1);
	printf("Column: ");
	scanf("%d", &column1);
	printf("Enter the row and column of the 2nd Matrix-->\n");
	printf("Row: ");
	scanf("%d", &row2);
	printf("Column: ");
	scanf("%d", &column2);
	
	if (column1 != row2) {
		printf("1st matrix columns is not equal to 2nd matrix row.\nMultiplication Can't possible.");
		return 0;
	} 
	int matrix1 [row1][column1], matrix2 [row2][column2], result [row1][column2]; 
	
	printf("Enter the elements of 1st Matrix-->\n");
	for (i = 0; i < row1; ++i) 
    	for (j = 0; j < column1; ++j) {
        	printf("Enter element at [%d] [%d]: ", i + 1, j + 1);
        	scanf("%d", &matrix1[i][j]);
    	}

	printf("Enter the elements of 2nd Matrix-->\n");
	for (i = 0; i < row2; ++i)
    	for (j = 0; j < column2; ++j) {
        	printf("Enter element at [%d] [%d]: ", i + 1, j + 1);
        	scanf("%d", &matrix2[i][j]);
    	}

	for (i = 0; i < row1; ++i)
    	for (j = 0; j < column2; ++j)
        	result[i][j] = 0;
        	
   for (i = 0; i < row1; ++i) 
    	for (j = 0; j < column2; ++j) 
        	for (k = 0; k < column1; ++k)
            	result[i][j] += matrix1[i][k] * matrix2[k][j];
    	
    printf("Multiplication of two matrices is-->\n");
	for (i = 0; i < row1; i++) {
    	for (j = 0; j < column2; j++)
        	printf("%d  ", result[i][j]);
        printf("\n");
    }
	return 0;
}
