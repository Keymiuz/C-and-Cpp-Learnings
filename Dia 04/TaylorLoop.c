#include <stdio.h>
#include <math.h>
double e(int x, int n)
{
 double s=1;
 int i;
 double num=1;
 double den=1;

 for(i=1;i<=n;i++)
 {
 num*=x;
 den*=i;
 s+=num/den;
 }
 return s;
}
int main()
{
 printf("%lf \n",e(1,10));
 return 0;
}

//versão feita com um loop for(i=1;i<=n;i++), onde ele percorre todo o loop n
// mas ainda gostei mais da versão 1, onde eu declaro o tamanho da variável
// por mais que essa seja a versão mais "correta" entre MUITAS ASPAS