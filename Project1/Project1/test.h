#include <stdio.h>

void trih(int n){
	int i, j;
	for (i = 0; i<n; i++){
		for (j = 0; j<i + 1; j++){
			putchar('#');
		}
		putchar('\n');
	}
	j = n - 1;

	for (i = n - 1; i>0; i--){
		for (j; j <= i & j>0; j--){
			putchar('#');
		}
		putchar('\n');
		j--;
	}
}

int main(){
	trih(5);
	return 0;
}

