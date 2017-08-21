
#define BUFSIZE 100

int getch(void);
void ungetch(int c);

char buf[BUFSIZE];
int bufp = 0;



int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if (bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    }else{
        buf[bufp++] = c;
    }
}
