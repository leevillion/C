#include <stdio.h>
int main(){
	char line[1000];
	char longest[1000];
	int getLine(char[],int);
	void copy(char[],char[]);
	int max=0;
	int lineCount;
	while((lineCount=getLine(line,1000))>0){
		if(lineCount>max){
			max=lineCount;
			copy(longest,line);
		}
	}
	if(max>0)
		printf("%s",longest);
	return 0;
}

int getLine(char str[],int maxc){
	int i;
	char c;
	for(i=0;i<maxc-1&&(c=getchar())!=EOF&&c!='\n';i++){
		str[i]=c;
	}
	if(c=='\n'){
		str[i]=c;
		i++;
	}
	str[i]='\0';
	return i;
}

void copy(char to[],char from[]){
	int i=0;
	while((to[i]=from[i])!='\0')
		i++;
}
