#include <stdio.h>
int main() {
int size;
char str[size] = 0;

printf("Enter size");
scanf("%d", &size);
for(i=0;i<=size;i++) {
    scanf("%c", &str[i]);
    }
for(i=0; i<=size; i++) {
    printf("%c", str[i]);
    }

for (i=0; i<= size; i++) {
    if (str[i] = '('' || ')'){
char nstr[i] = str[i].pop('(',')');
    }
    else { 
        printf ("Valid input");
        }

for (i=0; i<size; i++) {
    printf ("%c", str[i]);
    }
}



















