#include <sys/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SLEEPTIME 1000000

int main(int argc, char *argv[])
{

	int perm=ioperm(0x378,8,1);
	
	if(perm==-1) 
	{
		fprintf(stderr,"Permisson error!\n");
		exit(1);
	}

	if(argc!=2)
	{
		fprintf(stderr,"Syntax error! [Outb value]\n"); 
		exit(1);
	}

	int value;
	if(!sscanf(argv[1],"%d",&value))
	{
		fprintf(stderr,"Please enter number!\n");
		exit(1);
	}

	value=value%256;

	outb(value,0x378);

	
	return 0;

}
