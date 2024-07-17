#include <stdio.h>
#include <string.h>
#include "wcCmdCopy.h"
#include "wcCopy.c"
int main(int argc,char *argv[])
{
	int i=0;
	if(argc == 3)
	{
		for(i=0; argv[1][i] != '\0';)
		{
			i++;	
		}
		if(i == 2)
		{
			all_option(argv[2],argv[1]);
		}
		else
		{
			FILE *fichier=NULL;
			optUn(fichier,argv[1],argv[2]);
		}
	}	
	else if(argc == 2)
	{
		FILE *fichier=NULL;
		if(strcmp(argv[1] ,"--help") == 0)
		{
			wc_option_help();
		}
		else
		{
			wcNoOption(fichier,argv[1]);
		}
	}
	else
	{
		error();
	}
	
	return 0;
}


	


