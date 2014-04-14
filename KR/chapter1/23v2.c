/**
 * delete recomment version 2
 */
#include <stdio.h>
void comment(char ch);
void inComment();
int main(){
	char ch;
	while((ch=getchar()) != EOF)
		comment(ch);
	return 0;
}

void comment(char c){
	char ch2;
	if(c=='/'){
		if((ch2=getchar())=='*')
			inComment();
	}
	else{
		putchar(c);
	}
}

void inComment(){
	char a,b;
	a=getchar();
	b=getchar();
	while(a!='*' || b!='/'){
		a=b;
		b=getchar();
	}	
}
