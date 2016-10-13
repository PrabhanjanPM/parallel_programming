#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int n;
	int *points;
	int *id;
} UnionFind;

void unite(UnionFind first, int p, int q);
int find(UnionFind first, int p, int q);

int main(int argc, char **argv){
	if(argc!=2){
		printf("Usage- %s <filename>\n", argv[0]);
		exit(0);
	}
	
	FILE *file = fopen(argv[1], "r");
	int n, i;
	fscanf(file, "%d\n", &n); 
	UnionFind first;
	first.n = n;
	first.points = (int *)malloc(sizeof(int)*3*n);
	first.id = (int *)malloc(sizeof(int)*n);
	for(i=0;i<3*n;i=i+3){
		fscanf(file, "%d,%d,%d\n", (first.points+i),(first.points+i+1),(first.points+i+2));
		//printf("%d,%d,%d\n",*(first.points+i),*(first.points+i+1),*(first.points+i+2));
	}
	for(i=0;i<n;i++){
		int j;
		*(first.id+i) = i;
		printf("Points- ");
		for(j=0;j<3;j++){
			printf("%d ", *(first.points+3*i+j));
		}
		printf("with id- %d\n",*(first.id+i));
	}
	printf("\n\n");

	for(i=0;i<n;i++){
		int j;
		for(j=i+1;j<n;j++){
			if(!find(first,i,j)){
				//Consider the case that both points are the same
				
				int condition1 = ((abs(*(first.points+3*i+0)-*(first.points+3*j+0))==1)&&
						  (*(first.points+3*i+1)==*(first.points+3*j+1))&&
						  (*(first.points+3*i+2)==*(first.points+3*j+2)));

				int condition2 = ((*(first.points+3*i+0)==*(first.points+3*j+0))&&
						  ((abs(*(first.points+3*i+1)-*(first.points+3*j+1))==1))&&
						  (*(first.points+3*i+2)==*(first.points+3*j+2)));
				
				int condition3 = ((*(first.points+3*i+0)==*(first.points+3*j+0))&&
						  (*(first.points+3*i+1)==*(first.points+3*j+1))&&
						  (abs(*(first.points+3*i+2)-*(first.points+3*j+2))==1));
	
				/*printf("Points- (%d,%d,%d) (%d,%d,%d)\n",*(first.points+3*i+0),*(first.points+3*i+1),
						  			 *(first.points+3*i+2),*(first.points+3*j+0),
						  			 *(first.points+3*j+1),*(first.points+3*j+2));
				  printf("Condition 1- %d\n",condition1);
				  printf("Condition 2- %d\n",condition2);
				  printf("Condition 3- %d\n",condition3); */
				
				if(condition1 || condition2 || condition3){
					unite(first,i,j);
				}
			}
		}
	}
	for(i=0;i<n;i++){
		int j;
		printf("Points- ");
		for(j=0;j<3;j++){
			printf("%d ", *(first.points+3*i+j));
		}
		printf("with id- %d\n",*(first.id+i));
	}
	
	return 0;
}

int find(UnionFind first, int p, int q){
	int x=0;
	if(*(first.id+p) == *(first.id+q)){
		x=1;
	}
	return x;
	//Use return (*(first.id+p) == *(first.id+q)); instead ?
}

void unite(UnionFind first, int p, int q){
	int idp = *(first.id+p);
	int idq = *(first.id+q);
	// Sort this out initially itself
	if(idp<idq){
		int temp = idp;
		idp = idq;
		idq = temp;
	}
	int i;
	for(i=0;i<first.n;i++){
		if(*(first.id+i) == idp){
			*(first.id+i) = idq;
		}
	}
}
