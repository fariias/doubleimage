#include "stdio.h"

typedef struct 
{
	int r,g,b;
} pixel;


void ler_arquivo()
{
	//definindo algumas variaveis locais
	char nome_arquivo[50];
	char tipo[50];
	int colunas,linhas,qualidade,i,j;
	FILE *Arquivo;
	pixel imagem[512][512];

	//obtendo o caminho do arquivo
    printf("Informe o Caminho do Arquivo: ");
	scanf("%s", nome_arquivo); 

	//abrindo o Arquivo 
	Arquivo = fopen(nome_arquivo, "r");

	fscanf(Arquivo,"%s", tipo);
	fscanf(Arquivo,"%d", &colunas);
	fscanf(Arquivo,"%d", &linhas);
	fscanf(Arquivo,"%d", &qualidade);

	printf("%d %d %d\n", colunas,linhas,qualidade);

	//Salvando os pixels na matriz
	for (i = 0; i < linhas; ++i)
	{
		for (j = 0; j < colunas; ++i)
		{
			fscanf(Arquivo, "%d", &imagem[i][j].r);
			fscanf(Arquivo, "%d", &imagem[i][j].g);
			fscanf(Arquivo, "%d", &imagem[i][j].b);
		}
	}
	fclose(Arquivo);

}

void salvar_arquivo()
{

}
int main()
{
	//Definindo Variaveis
	pixel imagem[512][512];
	char tipo[50];
	int largura,altura,qualidade;
	ler_arquivo();
	return 0;
}