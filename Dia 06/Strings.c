#include <stdio.h>

int main() {
  char s[] = "welcome";
  int i;

  for (i = 0; s[i] != '\0'; i++);

  printf("Comprimento é %d", i);

  return 0;
}


// no array s[], qunado inicializamos ele com "welcome", o array no final insere o \0 para ser um identificador de final de string
// esse foi apenas um código simples para achar a lenght de uma string :)