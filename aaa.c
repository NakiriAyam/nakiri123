#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define Maxsize 105
typedef struct {
    char data[Maxsize];
    int top;
} SqStack;
void InitStack(SqStack *&s) {
    s = (SqStack *) malloc (sizeof(SqStack));
    s->top = -1;
}
void DestroyStack(SqStack *&s) {
    free(s);
}
bool StackEmpty(SqStack *&s) {
    return (s->top == -1);
}
bool Push(SqStack *&s, char e) {
    if (s->top == Maxsize - 1) {
        return false;
    }
    s->top++;
    s->data[s->top] = e;
    return true;
}
char Pop(SqStack *&s) {
    char e;
    if (s->top == -1) {
        return ' ';
    } 
    e = s->data[s->top];
    s->top--;
    return e;
}
char GetTop(SqStack *&s) {
    char e;
    if (s-> top == -1) {
        return ' ';
    }
    e = s->data[s->top];
    return e;
}
void func(char str[]) {
    char e;
    char exp[Maxsize];
    SqStack *Optr;
    InitStack(Optr);
    int i = 0;
    int count = 0;
    bool judge = true;
    while (str[i] != 0) {
        switch (str[i]) {
            case '\\' :  
            case '/' :
                if (GetTop(Optr) == '.'){
                    e = Pop(Optr);
                }
                if (GetTop(Optr) != '/') {
                    Push(Optr, '/');
                }
                break;
            case '.' :
                if (GetTop(Optr) != '.') {
                    if (GetTop(Optr) == ' ') {
                        judge = false;
                    }
                    Push(Optr, '.');
                }
                else {
                    e = Pop(Optr);
                    if (!StackEmpty) {
                        e = Pop(Optr);
                    }
                    else {
                        printf("Value Error\n");
                        return;
                    }
                    while (GetTop(Optr) != '/') {
                        e = Pop(Optr);
                    }
                }
                break;
            default :
                if (GetTop(Optr) == '.'){
                    e = Pop(Optr);
                }

                Push(Optr, str[i]);
                break; 
        }
        i++;
    }
    i=0;
    while(GetTop(Optr) != ' ') {
        switch (GetTop(Optr)) {
            case '.' :
                e = Pop(Optr);
                break;
            case '/' :
                if (i != 0) {
                    exp[i] = Pop(Optr);
                    i++;
                }
                break;
            default :
                exp[i] = Pop(Optr);
                i++;
        }
    }
    count = strlen(exp);
    for(i = count-1; i > 0; i--) {
        printf("%c", exp[i]);
    }
    if (judge) {
        printf("%c", exp[i]);
    }
    printf("\n");
    DestroyStack(Optr);
}

int main() {
	char str[Maxsize];
	int i=0;
	while (scanf("%s",str) != EOF) {
		func(str);
		while (str[i] != ' ') {
			str[i] = ' ';
		}
		i=0;
	}
}    
