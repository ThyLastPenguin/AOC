#include	<stdlib.h>
#include <stdio.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
	
	FILE *fp;
	char *data[1000];

	if ((fp = fopen("./data/day1", "r")) == NULL){
		printf("File opening failed");
	} else {
		int i;
		for (i = 0; i < 1000; i++){
			data[i] = malloc(sizeof(char)*13);
			fgets(data[i], 255, (FILE*)fp);
			printf("%s\n", data[i]);
		}
	}

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
