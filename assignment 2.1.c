#include <stdio.h>
#define MAX_ROWS 50
#define MAX_COLS 50
#define MAX_ELEMENTS 1000
struct Element {
    int row;  int col; int value;  
	};
void convertToSparse(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    struct Element sparse[MAX_ELEMENTS];
    int sparseIndex = 0, i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[sparseIndex].row = i;
                sparse[sparseIndex].col = j;
                sparse[sparseIndex].value = matrix[i][j];
                sparseIndex++;
   } } }
    printf("Sparse Matrix Representation:\n");
    printf("Row Col Value\n");
    for (i = 0; i < sparseIndex; i++) {
        printf("%3d %3d %4d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }}
int main() {
    int rows, cols, matrix[MAX_ROWS][MAX_COLS], i, j;
    printf("Enter the number of rows and columns for the 2D array: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter the elements of the 2D array:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);}}
    convertToSparse(matrix, rows, cols);
    return 0;
}

