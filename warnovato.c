#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcspn()

//Constantes globais
#define MAX_TERRITORIOS 5
#define TAM_STRING 100

//Struct
struct Territorio{
    char nome[TAM_STRING];
    char cor[TAM_STRING];
    int tropas;
};

//Limpar buffer
void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Main
int main(){
    struct Territorio mapa[MAX_TERRITORIOS];
    int totalTerritorios = 0;
    int opcao;

    do {
        printf("-----------------------\n");
        printf("    MAPA DE TERRITÓRIOS\n");
        printf("-----------------------\n");
        printf("1- Cadastrar Território\n");
        printf("2- Listar Territórios\n");
        printf("0 - Sair\n");
        printf("-----------------------\n");
        printf("Escolha uma opcao: ");


    //Opcao do usuario
    scanf("%d", &opcao);
    limparBufferEntrada();

    //Processamento da opcao
    switch (opcao) {
        case 1: //Cadastro do territorio
            printf("Cadastro de novo território \n\n");

            if (totalTerritorios < MAX_TERRITORIOS){
                printf("Digite o nome do territorio: ");
                fgets(mapa[totalTerritorios].nome, TAM_STRING, stdin);

                printf("Digite a cor: ");
                fgets(mapa[totalTerritorios].cor, TAM_STRING, stdin);

                mapa[totalTerritorios].nome[strcspn(mapa[totalTerritorios].nome, "\n")] = '\0';
                mapa[totalTerritorios].cor[strcspn(mapa[totalTerritorios].cor, "\n")] = '\0';

                printf("Digite a quantia de tropas: ");
                scanf("%d", &mapa[totalTerritorios].tropas);
                limparBufferEntrada();

                totalTerritorios++;

                printf("Território cadastrado com sucesso!\n\n");

            } else {
                printf("Limite de territórios atingido!\n\n");
            }

            printf("Pressione Enter para continuar...");
            getchar();
            break;      

        case 2: //Listar territorios
            printf("Lista de Territórios \n\n");
            if (totalTerritorios == 0){
                printf("Nenhum território cadastrado.\n\n");
            } else {
                for (int i = 0; i < totalTerritorios; i++){
                    printf("------------------------\n");
                    printf("Território %d:\n", i + 1);
                    printf("Nome: %s\n", mapa[i].nome);
                    printf("Cor: %s\n", mapa[i].cor);
                    printf("Tropas: %d\n\n", mapa[i].tropas); 
                }    
                printf("------------------------\n");
            }

            printf("Pressione Enter para continuar...");
            getchar();
            break;

        case 0:
            printf("Saindo do programa...\n");
            break;  
        
            default:
            printf("Opção inválida! Tente novamente.\n\n");
            printf("Pressione Enter para continuar...");
            getchar();
            break;

    }
    } while (opcao != 0);
    return 0;
}