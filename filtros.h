//Biblioteca de Filtros usados na aplicação e funções de manipulação da imagem


//--------------------------FUNCOES DE MANIPULAÇÂO------------------------------
void ler(pixel imagem[MAX][MAX]){
    printf("Nome do arquivo: ");
    char nome_arq[50];
    scanf("%s", nome_arq);

    foto = fopen(nome_arq, "r");

    if (foto == NULL) {
        printf("Arquivo n�o encontrado no diretorio!\n");
        ler(imagem);
    }

    fscanf(foto, "%s", code);
    fscanf(foto, "%d", &coluna);
    fscanf(foto, "%d", &linha);
    fscanf(foto, "%d", &v_max);

    for (i=0; i<linha; i++)
    {
        for (j=0; j<coluna; j++)
        {
            fscanf(foto, "%d", &imagem[i][j].r);
            fscanf(foto, "%d", &imagem[i][j].g);
            fscanf(foto, "%d", &imagem[i][j].b);
        }
    }

    fclose(foto);
}

void salvar(pixel imagem[MAX][MAX]){
    printf("Nome da nova foto: ");
    char nome_arq_salvar[50];
    scanf("%s", nome_arq_salvar);

    fotoN = fopen(nome_arq_salvar, "w");

    fprintf (fotoN, "%s\n", header);
    fprintf (fotoN, "%d\n", coluna);
    fprintf (fotoN, "%d\n", linha);
    fprintf (fotoN, "%d\n", v_max);

    for (i=0; i < linha; i++)
    {
        for (j=0; j < coluna; j++)
        {
            fprintf(fotoN, "%d ", imagem[i][j].r);
            fprintf(fotoN, "%d ", imagem[i][j].g);
            fprintf(fotoN, "%d\n", imagem[i][j].b);
        }
    }

    fclose(fotoN);
}

//---------------------------------FILTROS--------------------------------------

// Filtro de Binarização
void binarizar(pixel imagem[MAX][MAX]){
    float treshhold = 127;

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            int media = (imagem[i][j].r + imagem[i][j].g + imagem[i][j].b)/3;

            if (media > treshhold)
            {
                imagem[i][j].r = 255;
                imagem[i][j].g = 255;
                imagem[i][j].b = 255;
            }
            else
            {
                imagem[i][j].r = 0;
                imagem[i][j].g = 0;
                imagem[i][j].b = 0;
            }
        }
    }
}

//Filtro de Rotacionamento a esquerda
void rotacionando_e(pixel imagem[MAX][MAX]){
    pixel tmp[MAX][MAX];

    int aux;
    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            tmp[i][j] = imagem[i][j];
        }
    }

    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            imagem[coluna-j-1][i] = tmp[i][j];
        }
    }
    aux = linha, linha = coluna, coluna = aux;
}

//Filtro de Rotacionamento a Direita
void rotacionando_d(pixel matriz_foto[MAX][MAX]){
    pixel tmp[MAX][MAX];
    int aux;
    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            tmp[i][j] = matriz_foto[i][j];
        }
    }

    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            matriz_foto[j][linha-i-1] = tmp[i][j];
        }
    }
    aux = linha, linha = coluna, coluna = aux;
}

//Filtro de rotacionamento em 180 Graus
void rotacionando_180(pixel matriz_foto[MAX][MAX]){
    rotacionando_d(matriz_foto);
    rotacionando_d(matriz_foto);
}

void img_rotacionar(pixel matriz_foto[MAX][MAX])
{
  int rotacionar = 0;
    printf("Selecione uma Opção para rotacionar:\n");
    printf("1: Rotacionar para a esquerda\n");
    printf("2: Rotacionar para a direita\n");
    printf("3: Rotacionar 180 graus\n");

    scanf("%i", &rotacionar);

    if(rotacionar == 1)
      rotacionando_e(matriz_foto);
    if(rotacionar == 2)
      rotacionando_d(matriz_foto);
    if(rotacionar == 3)
      rotacionando_180(matriz_foto);
}

//Filtro para ampliação de imagem de acordo com o zoom passado
void img_ampliar(pixel imagem[MAX][MAX]) {
    int k, l;
    int zoom = 0;
    printf("Informe em quantas vezes voçê deseja ampliar: ");
    scanf("%i", &zoom);
    FILE *img_f;
    img_f = fopen("img_amp.ppm", "w");

    fprintf(img_f, "%s\n", header);
    fprintf(img_f, "%i %i\n", linha*zoom, coluna*zoom);
    fprintf(img_f, "%i\n", v_max);
    for (i = 0; i < linha; i++)
        for (k = 0; k < zoom; k++)
            for (j = 0; j < coluna; j++)
                for (l = 0; l < zoom; l++)
                    fprintf(img_f, "%i %i %i\n",
                    (imagem[i][j].r > v_max) ? v_max : imagem[i][j].r,
                    (imagem[i][j].g > v_max) ? v_max : imagem[i][j].g,
                    (imagem[i][j].b > v_max) ? v_max : imagem[i][j].b);

    fclose(img_f);

    printf("A imagem foi salva como 'img_amp.ppm'");

}

//Filtro de Blurring
void img_blurring(pixel imagem[MAX][MAX]) {
    for (i = 1; i < linha - 1; i++)
        for (j = 1; j < coluna - 1; j++)

            imagem[i][j].r = (imagem[i-1][j-1].r + imagem[i-1][j].r + imagem[i-1][j+1].r +
                           imagem[i][j-1].r + imagem[i][j].r + imagem[i][j+1].r +
                           imagem[i+1][j-1].r + imagem[i+1][j].r + imagem[i+1][j+1].r)/9,
            imagem[i][j].g = (imagem[i-1][j-1].g +imagem[i-1][j].g + imagem[i-1][j+1].g +
                           imagem[i][j-1].g + imagem[i][j].g + imagem[i][j+1].g +
                           imagem[i+1][j-1].g + imagem[i+1][j].g + imagem[i+1][j+1].g)/9,
            imagem[i][j].b = (imagem[i-1][j-1].b + imagem[i-1][j].b + imagem[i-1][j+1].b +
                           imagem[i][j-1].b + imagem[i][j].b + imagem[i][j+1].b +
                           imagem[i+1][j-1].b + imagem[i+1][j].b + imagem[i+1][j+1].b)/9;
}

void img_sharpening(pixel img[MAX][MAX]) {

    pixel temporaria[MAX][MAX];

// Criando uma copia da matriz original para auxiliar nas operações
    for (i = 0; i < linha; i++)
        for (j = 0; j < coluna; j++)
            temporaria[i][j] = img[i][j];
// Iniciando a aplicação do Filtro
    for (i = 1; i < linha - 1; i++)
        for (j = 1; j < coluna - 1; j++)
            img[i][j].r = 5*temporaria[i][j].r - temporaria[i-1][j].r - temporaria[i][j-1].r - temporaria[i][j+1].r - temporaria[i+1][j].r,
            img[i][j].g = 5*temporaria[i][j].g - temporaria[i-1][j].g - temporaria[i][j-1].g - temporaria[i][j+1].g - temporaria[i+1][j].g,
            img[i][j].b = 5*temporaria[i][j].b - temporaria[i-1][j].b - temporaria[i][j-1].b - temporaria[i][j+1].b - temporaria[i+1][j].b;



}
