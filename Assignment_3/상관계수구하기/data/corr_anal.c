#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct vector {
float label;
float feature[12];
} vector_t;

vector_t *test;		// input data read from the input file
int LENGTH;

int main(int argc, char* argv[])
{
	FILE *fp1;
	int i;
	float dummy_float;
	int num_vectors=0;


	if (argc!=2)
	{
		printf("USAGE:  %s  <input file name>\n", argv[0]);
		return 1;
	}
	else
	{
		fp1=fopen(argv[1],"r");
	}


	// count the number of vectors in the test file
	while(!feof(fp1)) {
		fscanf(fp1,"%f 1:%f 2:%f 3:%f 4:%f 5:%f 6:%f 7:%f 8:%f 9:%f 10:%f 11:%f 12:%f", &dummy_float, &dummy_float, \
		&dummy_float, &dummy_float, &dummy_float, &dummy_float, &dummy_float, &dummy_float, \
		&dummy_float, &dummy_float, &dummy_float, &dummy_float, &dummy_float);

		num_vectors++;
	}
	fseek(fp1, 0, SEEK_SET);

	LENGTH=num_vectors-1;

	// data structure creation & initialization
	test=(vector_t *)calloc(LENGTH, sizeof(vector_t));


	// reading from the input file
	for (i=0;i<LENGTH;i++) {
		fscanf(fp1,"%f 1:%f 2:%f 3:%f 4:%f 5:%f 6:%f 7:%f 8:%f 9:%f 10:%f 11:%f 12:%f", &test[i].label, &test[i].feature[0], \
		&test[i].feature[1], &test[i].feature[2], &test[i].feature[3], &test[i].feature[4], &test[i].feature[5], &test[i].feature[6], \
		&test[i].feature[7], &test[i].feature[8], &test[i].feature[9], &test[i].feature[10], &test[i].feature[11]);

	}

















	fclose(fp1);

	return 0;

}
