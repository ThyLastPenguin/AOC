#include <stdio.h>
#include	<stdlib.h>

int main(){
	char *buf[2000];
	FILE *fp;

	if ((fp = fopen("./data/day1", "r")) == NULL){
		printf("File opening failed");
	} else {
		int i;
		for(i = 0; i < 2000; i++){
			buf[i] = malloc(6);
			fgets(buf[i], 255, (FILE*)fp);
		}

		int *threeSum;
		threeSum = (int *) malloc(sizeof(int)*1998);


		for(i = 2; i < 2000; i++){
			*threeSum = (atoi(buf[i-2]) + atoi(buf[i-1]) + atoi(buf[i]));
			threeSum++;
		}

		threeSum -= 1997;

		int higherCount;
		for(i = 0; i<1998; i++){
			higherCount += (*threeSum < *(++threeSum));
		}
		printf("%d\n", higherCount);
	}
}
