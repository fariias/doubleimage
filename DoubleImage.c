#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "filtros.h"

int main() {
    pixel imagem[MAX][MAX];
    int opcao = 1;
    // Menu da aplicação
    while (opcao != 0)
    {
      printf("Escolha um das opções:\n");
      printf(" 1: binarização da imagem usando thresholding \n");
      printf(" 2: executa blurring \n");
      printf(" 3: executa sharpening \n");
      printf(" 4: rotação da imagem, dado o ângulo \n");
      printf(" 5: ampliar a imagem, dado o zoom. \n");
      printf(" 6: reduzir a imagem, dado o zoom.\n");
      printf(" 0: Sair\n");
      printf("Opção: ");
      scanf("%i", &opcao);
      printf("\n");
      if(opcao == 0)
      break;
      ler(imagem);
        if(opcao == 1)
        {
          binarizar(imagem);
          salvar(imagem);
        }
        else if(opcao == 2)
        {
          img_blurring(imagem);
          salvar(imagem);
        }
        else if(opcao == 3)
        {
          img_sharpening(imagem);
          salvar(imagem);
        }
        else if(opcao == 4)
        {
          img_rotacionar(imagem);
          salvar(imagem);
        }
        else if(opcao == 5)
          img_ampliar(imagem);
          else
          printf("Opção Invalida!\n");

      }
      printf("Fim do programa!");
    return 0;
}
