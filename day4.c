#include	<stdlib.h>
#include <stdio.h>

struct bingo {
	char board[5][5];
	int marked[5][5];
};


struct bingo makeBingo(char inp[5][5]){
	struct bingo temp;
	int i, j;
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			temp.marked[i][j] = 0;
			temp.board[i][j] = inp[i][j];
		}
	}
	return temp;
}

int main ( int argc, char *argv[] )
{
	FILE *fp;
	if((fp = fopen("data/day4", "r")) == NULL){
		fprintf(stderr, "Error opening file\n");
		return EXIT_FAILURE;
	}

	char *inpLine;
	char *numberDraw[1000];
	int i = 0;
	int j = 0;
	inpLine = malloc(sizeof(char) * 500);
	fgets(inpLine, 500, (FILE*)fp);

	while(*inpLine != '\0'){
		if(*inpLine == ','){
			j = 0;
		} else {
			printf("%c", *inpLine);
			*numberDraw[0] = *inpLine;
		}
		inpLine++;
	}
	printf("%s\n", numberDraw[0]);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
