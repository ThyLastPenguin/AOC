#include <stdio.h>
#include	<stdlib.h>


int main ( int argc, char *argv[] )
{
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
		int higherCount = 0;
		int prev;
		int curr;

		for(i = 1; i < 2000; i++){
			curr = atoi(buf[i]);
			prev = atoi(buf[i-1]);
			if(curr == 0)
				printf("ATOI FAIL");
			if(curr > prev)
				higherCount++;
		}

		printf("%d\n", higherCount);
	
	}


	fclose(fp);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
