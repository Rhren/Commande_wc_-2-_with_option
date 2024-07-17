#include <stdio.h>

void wc_option_help();
void wcNoOption(FILE *fichier,char *file);
int wcOption_c(FILE *fichier);
int wcOption_l(FILE *fichier,char *file,char *chaine,int nbr);
int wcOption_w(FILE *fichier,char *file,char *chaine,int nbr);
int wcOption_L(FILE *fichier);
void all_option(char *file,char *argm);
///void more_option4(char *opt,char *file);
void optUn(FILE *fichier,char *opt,char *file);
/*void opt2(FILE *fichier,char *opt,char *file);
void opt3(FILE *fichier,char *opt,char *file);
void opt4(FILE *fichier,char *opt,char *file);*/
void error();
