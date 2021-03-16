#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Funções
void alocafloat(float **p, int tam);
void mostratabela(float *p,int k);
int main()
{
	int tamanho, i,j,k=0;
	float *coef=NULL, ti, inter[2], precisao, *tabela=NULL,intercopia[2],*soma=NULL, m, flag;
	printf("Digite o grau da equacao:");
	scanf("%i", &tamanho);
	fflush(stdin);
	alocafloat(&coef,tamanho);

	for (i=tamanho,j=0;i>0;i--,j++)
	{
		printf("Digite o coeficiente de x^%i:",i );
		scanf("%f", coef+j);
		fflush(stdin);
	}
	printf("Digite o termo independente:");
	scanf("%f", &ti);
	printf("A sua funcao e: ");
	for(i=0,j=tamanho;i<tamanho;i++,j--)
	{
		if (i==0)
		{
			printf("%.0fx^%i",*(coef+i),j);
		}
		else
		{
				if((*coef+i)>0)
				{
					printf("+%.0fx^%i",*(coef+i),j);
				}
	
				else 
				{
		    	    printf("%.0fx^%i",*(coef+i),j);
				}
		}	
	}
	if(ti>0)
	printf("+%.0f\n", ti);
	else
	printf("%.0f\n", ti);
	printf("Digite o valor do inetervalo(valores entre virgula): ");
	scanf("%f,%f", &inter[0], &inter[1]);
	fflush(stdin);
	printf("Digite o valor da precisao: ");
	scanf("%f", &precisao);
	fflush(stdin);

	alocafloat(&soma,tamanho+1);
	do {
	alocafloat(&tabela,7+(k*7));
	if(k==0)
	{
		intercopia[0]=inter[0];
		intercopia[1]=inter[1];
	}
	
	//printf("%f %f %f %f\n", inter[0], intercopia[0],inter[1], intercopia[1]);

	*(tabela+(k*7))=0;
	*(tabela+(1+k*7))=intercopia[0];
	*(tabela+(3+k*7))=intercopia[1];
	
	m=(intercopia[0]+intercopia[1])/2;
	printf("\n%f----%f---\n------%f------\n",intercopia[0],intercopia[1] ,m);
	*(tabela+(2+k*7))=m;
	for(i=0,j=tamanho;i<tamanho;i++,j--)
	{
		*(soma+i)=(*(coef+i))*pow(intercopia[0],j);		
	}
	*(soma+i)=ti;
	*(tabela+(4+k*7))=0.0;
	for(i=0;i<(tamanho+1);i++)
	{
		*(tabela+(4+k*7))+= *(soma+i);
	}
	printf("%f\n",*(tabela+(4+k*7)));
		
    for(i=0,j=tamanho;i<tamanho;i++,j--)
	{
		*(soma+i)=(*(coef+i))*pow(m,j);		
	}
	*(soma+i)=ti;
	*(tabela+(5+k*7))=0.0;
	for(i=0;i<(tamanho+1);i++)
	{
		*(tabela+(5+k*7))+= *(soma+i);
	}	
	
	printf("%f\n", *(tabela+(5+k*7)));
     for(i=0,j=tamanho;i<tamanho;i++,j--)
	{
		*(soma+i)=(*(coef+i))*pow(intercopia[1],j);		
	}
	*(soma+i)=ti;
	*(tabela+(6+k*7))=0.0;
	for(i=0;i<(tamanho+1);i++)
	{
		*(tabela+6+(k*7))+= *(soma+i);
	}	
	
	printf("%f\n", *(tabela+(6+k*7)));
	if ((*(tabela+(4+k*7)))*(*(tabela+(5+k*7)))<0)
	{
		intercopia[1]=m;
	}
	else
	{
		intercopia[0]=m;
	}
	 flag=*(tabela+(5+k*7));
	printf("---------%f----------flag\n",flag );
	printf("---------%f----------precisao\n",precisao);
	k++;
	
 }while (k<6 );
	mostratabela(tabela,k);	
	system("PAUSE");
	return 0;
}
void alocafloat(float **p, int tam)
{

	if( (*p=(float *)realloc(*p,tam*sizeof(float)) )==NULL)
	{
		printf("Erro na alocação!");
		exit(1);
	}
	printf("Espaco alocado com sucesso! End= %u\n",*p);
}

void mostratabela(float *p, int k)
{
	int i;
	printf("\n----------------------------------------Iteracoes do Metodo da Dicotomia-----------------------------------------\ni\ta\tm\tb\tf(a)\tf(m)\tf(b)\n");
	for(i=0;i<(7+((k-1)*7));i++)
	{
    printf("%.3f\t", *(p+i));
	}
	printf("\n");
}
