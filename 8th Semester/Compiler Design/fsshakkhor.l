%{
#include<stdio.h>
int Vowel=0;
int Cons=0;
int Num=0;

#undef yywrap 
%}

word [^ \t\n]+
eol \n
%%
"a"|"e"|"i"|"o"|"u"|"A"|"E"|"I"|"O"|"U" {printf("%s : Vowel\n",yytext);Vowel++;}
[a-zA-Z] {printf("%s : Consonent\n",yytext);Cons++;}
[0-9] {printf("%s : Numeric\n",yytext);Num++;}
{eol} {; }
.	{;}

%%

char **fileList;
unsigned currentFile = 0;
unsigned nFiles;


main(argc, argv)
int argc;
char **argv;
{
	FILE *file;

	fileList = argv+1;
	nFiles = argc-1;

	if (argc == 2){
		
		currentFile = 1;
		
		file = fopen(argv[1], "r") ;
		if (!file) {
			fprintf(stderr,"couldnot open %s\n",argv[1]);
			exit(1);
		}
		
		yyin = file;
		
	}
	if (argc > 2){
		yywrap();
	}
	yylex();

	if (argc > 2){
		printf("\nVowel=%d\nConsonent=%d\nNumeric=%d\n\n",Vowel,Cons,Num);
		Vowel = Cons = Num = 0;
	}else{

	}

	return 0;
}

yywrap(){
	if(nFiles==1){
		return 1;
	}
	else{
		FILE *file;
		if ((currentFile != 0) && (nFiles > 1) && (currentFile <= nFiles)){
			if(currentFile==nFiles){
				return;
			}
			printf("\nVowel=%d\nConsonent=%d\nNumeric=%d\n\n",Vowel,Cons,Num);
			Vowel = Cons = Num = 0;
			fclose(yyin);
		
		}
		while (nFiles!=0) {
			file = fopen(fileList[currentFile++], "r");
			if (file != NULL) {
				yyin = file;
				break;
			}
			fprintf(stderr,"could not open %s\n",fileList[currentFile-1]);
			
		}
		return 0;
	}
}
