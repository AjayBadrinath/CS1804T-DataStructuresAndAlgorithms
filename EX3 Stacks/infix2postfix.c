/*
 Write a C program to convert an infix expression into a postfix expression using array implementation of stack data structure.
*/

/*
implement stack functions;
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int tos=-1;

char* set_stk(int bytes){
	char* stk=(char*)malloc(sizeof(stk)*bytes);
	return stk;
}
void push(char * stk,char data){
	*(stk+(++tos))=data;

}
char pop(char* stk){
	return *(stk+(tos--));

}

char peek(char* stk){
	return *(stk+tos);
}

void print(char* stk){
	for (int i= tos;i>=0;i--){
		printf("%c\n", *(stk+i));
	}
}

int precedence(char a){
	if (a=='^'){
		return 3;
	}
	else if(a=='/' ||a=='*'){
		return 2;
	}
	else if(a=='+'||a=='-'){
		return 1;
	}
	else if(a=='('||a==')'){
		return 0;
	}
	return -1;
}
int isOperator(char c){
	if (c=='+'||c=='^'||c=='/'||c=='*'||c=='-'||c=='('||c==')'){
		return 1;
	}
	return 0;
}


int main(){
//char arr[]="((A + B) – C * (D / E)) + F";
char arr[]="x^y/(5*z)+2";
char* stk=set_stk(100);
int inb=0;
	for (int i=0;i<strlen(arr);i++){
		
		if(isOperator(arr[i])==0){
			printf("%c",arr[i]);
		}
		else{
			if(tos==-1){
				push(stk,arr[i]);
				continue;
			}
			else {
				if(arr[i]=='('){
					push(stk,arr[i]);
					inb++;
					continue;

				}
				 if(arr[i]==')'){
					while(1){
						if(*(stk+tos)=='('){
							pop(stk);
							break;
						}
						else{
							char ks=pop(stk);
							printf("%c",ks);
						}
					}
					inb--;

					
				}
				else if(inb==0&& precedence(arr[i])<=precedence(stk[tos])){
					char vo=pop(stk);
					printf("%c",vo);
					push(stk,arr[i]);
				}
				else{
					push(stk,arr[i]);
				}

			}
		}
	}
	print(stk);
}