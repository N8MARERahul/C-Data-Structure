#include <stdio.h>
void towerOfHanoi(int n, char source, char aux, char dest) { 
	if (n == 1){
		printf("Move disk 1 from disk %c to disk %c\n", source, dest); 
		return;
	}
	towerOfHanoi(n - 1, source, dest, aux);
	printf("Move disk %d from disk %c to disk %c\n", n, source, dest); 
	towerOfHanoi(n - 1, aux, source, dest);
}
int main() {
	int num_disks;
	printf("Enter the number of disks: "); 
	scanf("%d", &num_disks); 
	towerOfHanoi(num_disks, 'A', 'B', 'C'); 
	return 0;
}

