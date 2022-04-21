#include	<stdlib.h>
#include <stdio.h>

void updateCounts(int count0[], int count1[], char *data[]);
int contains2(char *inp);
void getOCriteria(char oCrit[], int count0[], int count1[]);
void getCCriteria(char cCrit[], int count0[], int count1[]);
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
	char *data2[1000];

	if ((fp = fopen("./data/day3", "r")) == NULL){
		printf("File opening failed");
	} else {
		int i, j;
		for (i = 0; i < 1000; i++){
			data[i] = malloc(sizeof(char)*13);
			data2[i] = malloc(sizeof(char)*13);
			fgets(data[i], 255, (FILE*)fp);
			for(j = 0; j < 13; j++){
				*(data2[i] + j) = *(data[i] + j);
			}
		}

		int count0[12];
		int count1[12];
		char oCriteria[12];
		char cCriteria[12];
		int k;

		for(k = 0; k < 12; k++){
			updateCounts(count0, count1, data);
			getOCriteria(oCriteria, count0, count1);
			updateCounts(count0, count1, data2);
			getCCriteria(cCriteria, count0, count1);
			printf("%s\n", cCriteria);
			for(i = 0; i < 1000; i++){
				if(*(data[i] + k) != oCriteria[k]){
					*(data[i] + k) = '2';
				}
				if(*(data2[i] + k) != cCriteria[k]){
					*(data2[i] + k) = '2';
				}
			}
		}

		for(i = 0; i < 1000; i++){
			if(!contains2(data[i]))
				printf("O2: %s", data[i]);
			if(!contains2(data2[i]))
				printf("CO2: %s", data2[i]);
		}

	}

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

void getOCriteria(char oCrit[], int count0[], int count1[]){
	int i;
	for (i = 0; i < 12; i++){
		count0[i] > count1[i] ? (oCrit[i] = '0') : (oCrit[i] = '1');
	}
}

void getCCriteria(char cCrit[], int count0[], int count1[]){
	int i;
	for (i = 0; i < 12; i++){
		count0[i] > count1[i] ? (cCrit[i] = '1') : (cCrit[i] = '0');
	}
}

void updateCounts(int count0[], int count1[], char *d[]){
	int i, j;
	for(i = 0; i < 12; i++){
		count0[i] = 0;
		count1[i] = 0;
	}
	for(i = 0; i < 1000; i++){
		if(!contains2(d[i])){
			for(j = 0; j < 12; j++){
				*(d[i] + j) == '0' ? count0[j]++ : count1[j]++;
			}
		}
	}
}

int contains2(char *inp){
	int i;
	int res = 0;
	for (i = 0; i < 12; i++){
		if(*(inp + i) == '2'){
			res = 1;
		}
	}
	return res;
}
