#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int resultado(void);

typedef struct
{
    char nome[40];
    int dia, mes, ano;
    int partidas;
    int vitorias;
} jogador;


//Declaraçãde variáveis globais

    jogador dados[100];
    int aux, cod;
    float valor;
    int posicao=0;
    char matriz[3][3];
    int linha, coluna, jogador1, jogador2, contador=0;


//Mostrando o tabuleiro

void tabuleiro(void)
{
        for(linha=0; linha<3; linha++)
        {
            printf("\n      %c | %c | %c ", matriz[linha][0], matriz[linha][1], matriz[linha][2]);
        }

}

void zeraMatriz(void)
{
    for(coluna=0;coluna<3;coluna++)
    {
        for(linha=0;linha<3;linha++)
        {
            matriz[linha][coluna] ='-';
        }

    //o contador volta a valer 0
    contador = 0;
    }
}

//Percorrendo cadastro e gravando
void cadastro(void)
{
    printf("\nDigite seu Nome: ");
    fflush(stdin);
    gets(dados[posicao].nome);
    printf("Digite o dia de nascimento: ");
    fflush(stdin);
    scanf("%d", &dados[posicao].dia);
    printf("Digite o mes do seu nascimento: ");
    fflush(stdin);
    scanf("%d", &dados[posicao].mes);
    printf("Digite o ano do seu nascimento: ");
    fflush(stdin);
    scanf("%d",&dados[posicao].ano);

    posicao++;
    aux++;
}

//Apresentando relátorio
void relatorio(void)
{
    for (int i = 0; i < aux ; i ++)
    {
        cod = i + 1;
        printf("\nCodigo do Jogador: %d ", cod);
        printf("\nNome: %s",dados[i].nome);
        printf("\nData de Nascimento: %d/%d/%d",dados[i].dia, dados[i].mes, dados[i].ano);
        printf("\nVitorias: %d ",dados[i].vitorias);
        printf("\nPartidas: %d", dados[i].partidas);
        if (dados[i].partidas == 0)
        {
            printf("\nPorcentagem de Vitorias: 0%%\n\n");
        }
        else
        {
            valor = ((float)dados[i].vitorias / dados[i].partidas) * 100 ;
            printf("\nPorcetagem de Vitorias: %.2f%%\n\n", valor);
        }
    }
    getchar();
}



int partida (void)
{
    int player;

    printf("\n\nLista de jogadores: \n");
    printf("===================\n");
    for (posicao = 0; posicao < aux ; posicao ++)
    {
        cod = posicao + 1;
        printf("\nCodigo %d: %s\n", cod, dados[posicao].nome);
    }

    printf("\n\n+===============+\n");
    printf("| Jogo da Velha |\n");
    printf("+===============+\n");

    printf("\nDigite o codigo do jogador 1: ");
    scanf("%d", &jogador1);
    dados[jogador1-1].partidas++;
    printf("Jogador escolhido: %s", dados[jogador1-1].nome);
    printf("\nDigite o codigo do jogador 2: ");
    scanf("%d", &jogador2);
    dados[jogador2-1].partidas++;
    printf("Jogador escolhido: %s", dados[jogador2-1].nome);
    player = 'X';

    do
    {
        if(player=='X')
        {
            player='O';
            printf("\n\n%s sua vez: ", dados[jogador1-1].nome);
            printf("\nDigite a linha: ");
            scanf("%d", &linha);
            printf("Digite a coluna: ");
            scanf("%d", &coluna);
            contador++;
            if(matriz[linha][coluna]=='O' || matriz[linha][coluna]=='X')
            {
                printf("\n Este lugar ja contem um caracter");
                contador--;
            }
            else
            {
                matriz[linha][coluna]='O';
            }
            tabuleiro();
        }
        else
        {
            player='X';
            printf("\n\n%s sua vez: ", dados[jogador2-1].nome);
            printf("\nDigite a linha: ");
            scanf("%d", &linha);
            printf("Digite a coluna: ");
            scanf("%d", &coluna);
            contador++;
            if(matriz[linha][coluna]=='O' || matriz[linha][coluna]=='X')
            {
                printf("\nEste lugar ja contem um caracter");
                contador--;
            }
            else
            {
                matriz[linha][coluna]='X';
            }
            tabuleiro();
        }
    } while(resultado()==0);

    return 1;
}

int resultado(void)
{
    for(linha=0; linha<=2; linha++)
    {
        for(coluna=0; coluna<=2; coluna++)
        {
            if(matriz[0][coluna]=='O' && matriz[1][coluna]=='O' && matriz[2][coluna]=='O')
            {
                system("clear");
                printf("\n\n%s e o(a) ganhador(a)\n", dados[jogador1-1].nome);
                dados[jogador1-1].vitorias++;
                tabuleiro();
                zeraMatriz();
                return 1;
            }
            if(matriz[0][coluna]=='X' && matriz[1][coluna]=='X' && matriz[2][coluna]=='X')
            {
                system("clear");
                printf("\n\n%s e o(a) ganhador(a)\n", dados[jogador2-1].nome);
                dados[jogador2-1].vitorias++;
                tabuleiro();
                zeraMatriz();
                return 1;

            }
        }

        if(matriz[linha][0]=='O' && matriz[linha][1]=='O' && matriz[linha][2]=='O')
        {
            system("clear");
            printf("\n\n%s e o(a) ganhador(a)\n", dados[jogador1-1].nome);
            dados[jogador1-1].vitorias++;
            tabuleiro();
            zeraMatriz();
            return 1;

        }
        else if(matriz[linha][0]=='X' && matriz[linha][1]=='X' && matriz[linha][2]=='X')
        {
            system("clear");
            printf("\n\n%s e o(a) ganhador(a)\n", dados[jogador2-1].nome);
            dados[jogador2-1].vitorias++;
            tabuleiro();
            zeraMatriz();
            return 1;
        }
    }
    if((matriz[0][0]=='X' && matriz[1][1]=='X' && matriz[2][2]=='X') || (matriz[0][2]=='X' && matriz[1][1]=='X' && matriz[2][0]=='X'))
        {
            system("clear");
            printf("\n\n%s e o(a) ganhador(a)\n", dados[jogador2-1].nome);
            dados[jogador2-1].vitorias++;
            tabuleiro();
            zeraMatriz();
            return 1;

        }
        else if((matriz[0][0]=='O' && matriz[1][1]=='O' && matriz[2][2]=='O')|| (matriz[0][2]=='O' && matriz[1][1]=='O' && matriz[2][0]=='O'))
        {
            system("clear");
            printf("\n\n%s e o(a) ganhador(a)\n", dados[jogador1-1].nome);
            dados[jogador1-1].vitorias++;
            //toda vez que alguem ganhar, vai fazer o vitorias++ e depois vai zerar a mariz
            tabuleiro();
            zeraMatriz();
            return 1;
        }
        else if(contador==9)
        {
            system("clear");
            printf("\n\nDeu velha!!!\n\n");
            zeraMatriz();
            return 1;

        }else
            return 0;
}

int main(void)
{
    int opcao;
    char var;
    setlocale(LC_ALL, "Portuguese");
    printf("+===============+\n");
    printf("| Jogo Da Velha |\n");
    printf("+===============+");
    zeraMatriz();
    tabuleiro();
    printf("\n\nModo de Jogar\n");
    printf("=============\n");
    printf("\nAfim de esclarecer o preenchimento do tabuleiro, acima estar· um molde,\n");
    printf("onde os (-) s„o espaÁos preenchÌveis e (0,1,2) s„o as coordenadas para se\n");
    printf("utilizar...\n\n");

    do
    {
        printf("\n\nMenu de Opções\n");
        printf("==============\n\n");
        printf("[1] Cadastro de Jogadores\n");
        printf("[2] Relatorio de Jogadores\n");
        printf("[3] Realizar Partida\n");
        printf("[4] Sair\n");
        printf("Escolha um opção: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao)
        {
        case 1 :
            do
            {
                cadastro();
                printf("\nGostaria de continuar cadastrando (S/N)? \n");
                fflush(stdin);
                scanf("%s", &var);

            }
            while(var == 'S'|| var == 's');
            break;

        case 2 :
            relatorio();
            break;

        case 3 :
                partida();

            break;

        case 4 :
            printf("\nEncerrando o programa... \n");
            break;

        default:
            printf("\nOpção inválida!!! Tente outro numero...\n");
            break;
        }
    }
    while(opcao != 4);
    return 0;
}
