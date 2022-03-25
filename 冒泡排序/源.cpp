#include<stdio.h>
int main()
{
	int i, j;
	float a[10], t;
	for (i = 0; i < 10; i++)
		scanf("%f", &a[i]);
   for(j=0;j<9;j++)
	   for(i=0;i<9-j;i++)
		   if(a[i]<a[i+1])
		   {
			   t = a[i]; a[i] = a[i + 1]; a[i + 1] = t;
		   }
   for (i = 0; i < 10; i++)
	   printf(" %f", a[i]);
   return 0;

}