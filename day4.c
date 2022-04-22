#include	<stdlib.h>

struct bingo {
	char board[5][5];
	int marked[5][5];
};


struct bingo makeBingo(char inp[5][5]){
	struct bingo temp;
	int i, j;
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++)
			temp.marked[i][j] = 0;
	}
}

int main ( int argc, char *argv[] )
{
	



	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
