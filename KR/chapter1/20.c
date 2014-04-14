/**
 * replace tabs with blanks
 */
#include <stdio.h>
#define TAB 10
int main(){
	int position,blankCount;
	char ch;
	position=0;
	while((ch=getchar())!=EOF){
		if(ch=='\t'){
			blankCount=TAB-(position-1)%TAB;
			while(blankCount>0){
				putchar(' ');
				blankCount--;
				position++;
			}
		}else if(ch=='\n'){
			putchar(ch);
			position=1;
		}else{
			putchar(ch);
			position++;
		}
	}
	return 0;
}
