#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 600

int main(int argc, char* argv[])
{
  //defined variables
  char buff[MAX_SIZE];
  int p[2];
  char *farg = argv[1]; 
  char *sarg = argv[2]; 
  FILE *file;
  
  //argument error handling
  if(argc<3)
  {
    printf("Error, must input 3 arguments.\n");
    exit(1);
  }
  //pipe error handling
  if(pipe(p) == -1)
  {
    exit(1);
  }
  //fork 
  switch(fork())
  {
    case -1:
      perror("Fork Error"); //error handling for fork
      exit(1);
    case 0:
      dup2(p[1],1);  //call dup2
      close(p[0]);
      execl("/bin/cat", "cat", "-b", farg, NULL); //execute cat -b
      exit(1);
    default:
      close(p[1]);
      if((file=fopen(sarg, "w")) == NULL)
      {
        perror(sarg);
        exit(1);
      }
      while(read(p[0], buff, sizeof(buff)) != 0)  //loop
      {
      }
      fprintf(stdout, "%s", buff); //write to stdout
      fprintf(file, "%s", buff); //write to file
      fclose(file); 
    }
    printf("\n");
    return 0;
  }