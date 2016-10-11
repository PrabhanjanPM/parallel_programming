#include <stdio.h>
#include <stdlib.h>

int points[10000000][4];

int main(int argc, char** argv){
	if(argc!=2){
		printf("Usage- %s <input file>\n",argv[0]);
		exit(0);
	}
	FILE* input_file = fopen(argv[1] , "r");
	int number_of_points,i;
	fscanf(input_file, "%d\n", &number_of_points);
	//int points[number_of_points][4];
	for(i=0;i<number_of_points;i++){
		fscanf(input_file, "(%d,%d,%d)\n", &points[i][0], &points[i][1], &points[i][2]);
		points[i][3]=0;
	}
	printf("List of points- \n");
	for(i=0;i<number_of_points;i++){
		printf("Point- (%d,%d,%d)\n", points[i][0], points[i][1], points[i][2]);
	}
	printf("\n\n");
	int present_partition = 0;
	for(i=0;i<number_of_points;i++){
		if(points[i][3] == 0){
			present_partition++;
			points[i][3] = present_partition;
		}
		else{
			continue;
		}
		int j;
		int x1 = points[i][0];
		int y1 = points[i][1];
		int z1 = points[i][2];
		for(j=i+1;j<number_of_points;j++){
			int x2 = points[j][0];
			int y2 = points[j][1];
			int z2 = points[j][2];
			if(abs(x1-x2) == 1 || abs(y1-y2) == 1 || abs(z1-z2) == 1){
				points[j][3] = present_partition;
			}
		}

	}
	printf("Partitions- \n");
	for(i=0;i<number_of_points;i++){
		printf("Point- (%d,%d,%d) belongs to partition- %d\n", points[i][0], points[i][1], points[i][2], points[i][3]);
	}


	return 0;
}

