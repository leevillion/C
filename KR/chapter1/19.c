/**
 *reverse the input string
 */
#include <stdio.h>
#define MAX 1000
void reverse(char string[]);
int getLine(char string[],int max);
int main(){
	char line[MAX];
	while(getLine(line,MAX)>0){
		reverse(line);
		printf("%s",line);
	}
	return 0;
}

int getLine(char string[],int max){
	char ch;
	int i;
	for(i=0;(ch=getchar())!=EOF && ch!='\n';i++){
		if(i<max-2)
			string[i]=ch;	
	}
	if(ch=='\n'){
		string[i]=ch;
		i++;
	}
	string[i]='\0';
	return i;

}

void reverse(char string[]){
	int i=0;
	int start;
	char temp;
	while(string[i]!='\n')
		i++;
	i--;
	while(i>0 && (string[i]==' ' || string[i]=='\t'))
		i--;
	string[++i]='\n';
	string[++i]='\0';
	for(start=0;start<i-2;start++,i--){
		temp=string[start];
		string[start]=string[i-2];
		string[i-2]=temp;
	}

}
