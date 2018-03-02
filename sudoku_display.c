
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void main(int argc, char**argv){
  FILE* fd;
  if(argc > 1){
    fd=fopen(argv[1], "r");
    int size;
    fscanf(fd, "%d", &size );     
    int board[size*size][size*size];
    char str[30];
    while(!feof(fd)){
	fscanf(fd, "%s", str);
	int len=strlen(str);
	char* scpyf=NULL;
	char* scpy = scpyf = strdup(str);
	if(scpy){
		strncpy(scpy, str, len);
		int args[3];
		int i=0;
		char* token=NULL;
		while ((token = strsep(&scpy, ","))){
			args[i++]=atoi(token);
		}
		//printf("Point (%d,%d)=%d\n",args[0],args[1],args[2]);
		free(scpyf);
		board[args[1]-1][args[0]-1]=args[2];
	}
    }
    fclose(fd);

    int y,x;
    for(y =0; y < size*size; y++){
	if(y % size == 0){
		for(x=0; x < ((size*size)*3)+size+1; x++){
                        printf("-");
                }
                printf("\n");
	}	
	for(x =0; x < size*size; x++){
	   if(x % size == 0){
		printf("|");
	   }
	   printf("%2d ",board[y][x]);
	}
	printf("|\n");
    }
	if(y % size == 0){
                for(x=0; x < ((size*size)*3)+size+1; x++){
                        printf("-");
                }
                printf("\n");
 	}
 }

}
