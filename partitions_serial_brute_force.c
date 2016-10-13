/*Wrong logic used xP
 *Do not use this program*/
#include <stdio.h>
#include <stdlib.h>

int points[100000][4];

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
		fscanf(input_file, "%d,%d,%d\n", &points[i][0], &points[i][1], &points[i][2]);
		points[i][3]=i;
	}
	printf("List of points- \n");
	for(i=0;i<number_of_points;i++){
		printf("Point- (%d,%d,%d)\n", points[i][0], points[i][1], points[i][2]);
	}
	printf("\n\n");
	for(i=0;i<number_of_points;i++){
		int j;
		//int x1 = points[i][0];
		//int y1 = points[i][1];
		//int z1 = points[i][2];
		for(j=i+1;j<number_of_points;j++){
			//int x2 = points[j][0];
			//int y2 = points[j][1];
			//int z2 = points[j][2];
			
			int condition1 = ((abs(points[i][0]-points[j][0])==1)&&
					 (points[i][1]==points[j][1])&&
					 (points[i][2]==points[j][2]));

			int condition2 = ((points[i][0] == points[j][0])&&
					 ((abs(points[i][1]-points[j][1])==1))&&
					 (points[i][2]==points[j][2]));
				
			int condition3 = ((points[i][0]==points[j][0])&&
					 (points[i][1]==points[j][1])&&
				   	 (abs(points[i][2]-points[j][2]==1)));

				
		 	printf("Points- (%d,%d,%d) (%d,%d,%d)\n",points[i][0],points[i][1],
							 points[i][2],points[j][0],
							 points[j][1],points[j][2]);
		  	printf("Condition 1- %d\n",condition1);
		  	printf("Condition 2- %d\n",condition2);
		  	printf("Condition 3- %d\n",condition3); 
			if(condition1 || condition2 || condition3){
				points[j][3] = points[i][3];
			}
		}

	}
	printf("Partitions- \n");
	for(i=0;i<number_of_points;i++){
		printf("Point- (%d,%d,%d) belongs to partition- %d\n", points[i][0], points[i][1], points[i][2], points[i][3]);
	}


	return 0;
}

