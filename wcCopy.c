#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Fonction qui retourne le nombre de caractère du fichier
int wcOption_c(FILE *fichier)
{
	int nbr=0;
	while(fgetc(fichier) != EOF)
	{
		nbr++;
	}
	rewind(fichier);
	return nbr;
}
char *allocation(int nbr)
{
	char *tab=NULL;
	tab=(char*)malloc(nbr*sizeof(char));
	if(tab == NULL)
	{
		printf("Erreur d'allocation");
		exit(1);
	}
	return (tab);
}
//Fonction qui retourne le nombre de ligne du fichier 
int wcOption_l(FILE *fichier,char *file,char *chaine,int nbr)
{
	int i;
	int j=0;
	for(i=0 ; i<nbr;i++)
	{
		fscanf(fichier,"%c",&chaine[i]);
	}
	for(i=0 ; i<nbr; i++)
	{
		if(chaine[i] == '\n')
		{
			j++;
		}
	}
	rewind(fichier);
	return (j);
}
//Fonction qui retourne le nombre de mot du fichier
int wcOption_w(FILE *fichier,char *file,char *chaine,int nbr)
{
	fichier=fopen(file,"r");
	int j=0;
	while(fscanf(fichier,"%s",chaine) == 1)
	{
		j++;
	}
	rewind(fichier);
		return (j);
}
//Fonction qui retourne le nombre de l'affichage maximale
int wcOption_L(FILE *fichier)
{
	int k=0;
	int max=0;
	int c;
	while((c=fgetc(fichier)) != EOF)
	{
		if(c == '\n')
		{
			if(max < k)
			{
				max=k;
			}
			k=0;
		}
		
		else
		{
			k++;
		}	
	}
	
	rewind(fichier);
	return max;
}
void wc_option_help()
{
	FILE *file=fopen("/home/mit/file_help","r");

	int c;
	if(file == NULL)
	{
		printf("Erreur d'ouverture du fichier");
	}
	else
	{
		while((c=fgetc(file)) != EOF)
		{
			printf("%c",c);
		}
		
		fclose(file);
	}
}
void error()
{
	printf("option invalid \n");
	exit(1);
}
void all_option(char *file,char *argm)
{
	FILE *fichier=NULL;
	fichier=fopen(file,"r");
	if(fichier == NULL)
	{
		printf("Erreur d'ouverture du fichier\n");
		exit(1);
	}
	else
	{
		if(strcmp(argm,"-c") == 0 || strcmp(argm,"--bytes") == 0 || strcmp(argm,"-m") == 0 || strcmp(argm,"--chars") == 0 )
		{
			printf("%d %s\n",wcOption_c(fichier),file);
		}
		else if(strcmp(argm,"-l") == 0 || strcmp(argm,"--lines") == 0 )
		{
			int nbr=wcOption_c(fichier);
			char *chaine=allocation(nbr);
				printf("%d %s\n",wcOption_l(fichier,file,chaine,nbr),file);
				free(chaine);
		}
		else if(strcmp(argm,"-w") == 0 || strcmp(argm,"--words") == 0 )
		{
			int nbr=wcOption_c(fichier);
			char *chaine=allocation(nbr);
			printf("%d %s\n",wcOption_w(fichier,file,chaine,nbr),file);
			free(chaine);
		}
		else if(strcmp(argm,"-L") == 0 || strcmp(argm,"--max-line-length") == 0 )
		{
			printf("%d %s\n",wcOption_L(fichier),file);
		}
		else
		{
			error();
		}
	
	fclose(fichier);
	}
}
void wcNoOption(FILE *fichier,char *file)
{
	fichier=fopen(file,"r");
	if(fichier == NULL)
	{
		printf("Erreur d'ouverture du fichier\n");
		exit(1);
	}
	else
	{
		int nbr=wcOption_c(fichier);
		char *chaine=allocation(nbr);
		printf(" %d ",wcOption_l(fichier,file,chaine,nbr));
		printf("%d ",wcOption_w(fichier,file,chaine,nbr));
		printf("%d ",wcOption_c(fichier));
		printf("%s\n",file);
		
		free(chaine);
		fclose(fichier);		
	}	
}
void optUn(FILE *fichier,char *opt,char *file)
{
	int i;
	int j;
	for(i=0 ; opt[i] != '\0'; )
	{
		i++;	
	}
	fichier=fopen(file,"r");
	if(fichier == NULL)
	{
		printf("Erreur d'ouverture du fichier\n");
		exit(1);
	}
	else
	{	
		for(j=1 ; j<i ;j++)
		{
			if(opt[j] == 'l')
			{
				int nbr=wcOption_c(fichier);
				char *chaine=allocation(nbr);
				printf(" %d ",wcOption_l(fichier,file,chaine,nbr));
				free(chaine);
			}
			else if(opt[j] == 'c' || opt[j] == 'm')
			{
				printf(" %d ",wcOption_c(fichier));
			}
			else if(opt[j] == 'w' )
			{
				int nbr=wcOption_c(fichier);
				char *chaine=allocation(nbr);
				printf(" %d ",wcOption_w(fichier,file,chaine,nbr));
				free(chaine);
			}
			else if(opt[j] == 'L' )
			{
				printf(" %d ",wcOption_L(fichier));
			}
			else 
			{
				printf("\n");
				printf("Option invalid '%c'\n",opt[j]);
				exit(1);
			}
		}
		printf("%s\n",file);
	fclose(fichier);
	}
}





