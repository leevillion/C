/**
 * fold long line
 */
#include <stdio.h>
#define FOLDTAG 10
void print(int i);
char line[FOLDTAG];
int main(){
	int postion;
	char ch;
	postion=0;
	while((ch=getchar())!=EOF){
		line[postion]=ch;
		postion++;
		if(ch=='\n'){
			print(postion);
			postion=0;
		}
		else if(postion==FOLDTAG){
			print(postion);
			postion=0;
		//	postion=newLine(postion);
			
		}
	}
}	

void print(int i){
	int j;
	for(j=0;j<i;j++)
		putchar(line[j]);
	if(line[j]!='\n' && line[j-1]!='\n')
		putchar('\n');
}
/*
int newLine(int i){
	int j;
	for(j=0;j<FOLDTAG;j++)
		line[j]=line[i];
}*/
