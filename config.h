// Biblioteca contendo algumas definições usadas no projeto.

//valor maximo da imagem
#define MAX 512

FILE *foto;

FILE *fotoN;

//Valor máximo que cada pixel pode assumir
int v_max;

//Largura e altura, respectivamente, da imagem em pixels
int linha, coluna;

//Código da imagem .ppm
char code[3];

//Cabeçalho do tipo de imagem
#define header "P3"

// algumas Variaveis de auxilio
int i, j;

//Definindo o Tipo Pixel
typedef struct {
    int r, g, b;
} pixel;
