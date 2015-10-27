#include "stdio.h"

typedef struct 
{
	int r,g,b;
} pixel;


void ler_arquivo(char nome_arquivo[50], pixel imagem[512][512], int *colunas, int *linhas, int *qualidade)
{

	FILE *Arquivo;
	//definindo algumas variaveis locais
	
	char tipo[50];
	int i,j;
	
	
	//abrindo o Arquivo 
	Arquivo = fopen(nome_arquivo, "r");

	fscanf(Arquivo,"%s", tipo);
	fscanf(Arquivo,"%d", colunas);
	fscanf(Arquivo,"%d", linhas);
	fscanf(Arquivo,"%d", qualidade);

	printf("%d %d %d\n", *colunas,*linhas,*qualidade);

	//Salvando os pixels na matriz
	for (i = 0; i < *linhas; ++i)
	{
		for (j = 0; j < *colunas; ++j)
		{
			fscanf(Arquivo, "%d", &(imagem[i][j].r));
			fscanf(Arquivo, "%d", &(imagem[i][j].g));
			fscanf(Arquivo, "%d", &(imagem[i][j].b));
		}
	}
	fclose(Arquivo);
	
}

void salvar_arquivo(char nome_arquivo[50],pixel imagem[512][512],int colunas,int linhas,int qualidade)
{
	int i,j;
	FILE *Arquivo;
	Arquivo = fopen("Alterado--1--", "w");

	fprintf (Arquivo, "P3\n");
    fprintf (Arquivo, "%d ", colunas);
    fprintf (Arquivo, "%d\n", linhas);
    fprintf (Arquivo, "%d\n", qualidade);
	for (i = 0; i < 512; ++i)
	{
		for (j = 0; j < 512; ++j)
		{
			fprintf(Arquivo,"%d ", imagem[i][j].r);
			fprintf(Arquivo,"%d ", imagem[i][j].g);
			fprintf(Arquivo,"%d\n", imagem[i][j].b);
			
		}
	}
}

int main()
{
	//Definindo Variaveis
	pixel imagem[512][512];
	char tipo[50];
	int colunas,linhas,qualidade;
	char nome_arquivo[50];

	//obtendo o caminho do arquivo
    printf("Informe o Caminho do Arquivo: ");
	scanf("%s", nome_arquivo); 

	ler_arquivo(nome_arquivo, imagem, &colunas, &linhas,&qualidade);
	salvar_arquivo(nome_arquivo,imagem,colunas,linhas,qualidade);
	return 0;
}