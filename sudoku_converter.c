#include <stdio.h>

void main(int argc, char**argv){
  FILE* fd;
  FILE* fd2;
  if(argc > 1){
    fd=fopen(argv[1], "r");
    fd2=fopen(argv[2], "w");
    int width, height;
    fscanf(fd, "%d %d", &width, &height);
    int y=0;
    for(y = 0; y < height; y++){
	int x = 0;
        for(x = 0; x < width; x++){
	  int num;
	  fscanf(fd, "%d", &num);
	  if(num != 0){
	    fprintf(fd2,"spot(%d,%d,%d).\n", x+1,y+1,num);
	  }
	}
    }
    fclose(fd);
    fclose(fd2);
  }

}
