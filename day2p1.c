#include <stdio.h>
#include	<stdlib.h>


int getLine(char s[], int lim);
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
	int x, y, aim;
	x = y = aim = 0;
	char *lines[1000];


	int i;
	for(i = 0; i < 1000; i++){
		lines[i] = (char *) malloc(sizeof(char) * 20);
		getLine(lines[i], 20);
	}
	
	for(i = 0; i < 1000; i++){
		if(*lines[i] == 'f'){
			int fval = (*(lines[i] + 8) - '0');
			x+= fval;
			y+= fval*aim;
		}
		if(*lines[i] == 'd'){
			aim+= (*(lines[i] + 5) - '0');
		}
		if(*lines[i] == 'u'){
			aim-= (*(lines[i] + 3) - '0');
		}
	}

	printf("x: %d\ny: %d\n prod: %d\n", x, y, x*y);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

int getLine(char s[], int lim){
	int c, i;
	for(i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; i++){
		s[i] = c;
	}
	if(c == '\n'){
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return i;
}
