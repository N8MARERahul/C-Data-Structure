//8. Write a program that reads a 2D metrics and checks if the metrics is a symmetric metrics or not.

#include<stdio.h>

int main() {
	int row, column, i, j, flag = 0;
	printf("Enter the row and column of the Matrix-->\n");
	printf("Row: ");
	scanf("%d", &row);
	printf("Column: ");
	scanf("%d", &column);
	int matrix [row][column];
	printf("Enter the elements of the Matrix-->\n");
	for (i = 0; i < row; i++)
    	for (j = 0; j < column; j++) {
        	printf("Enter element at [%d] [%d]: ", i + 1, j + 1);
        	scanf("%d", &matrix[i][j]);
    	}
	
	for (i = 0; i < row; i++)
    	for (j = 0; j < column; j++) 
    		if (matrix [j][i] != matrix [i][j]) {
    			flag = 1;
    			break;
			}
    		
    if (flag == 0)
    	printf("The matrix is a symmetric matrix.");
    else
    	printf("The matrix is not a symmetric matrix.");
	return 0;
}
