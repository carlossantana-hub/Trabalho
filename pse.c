#include <stdio.h>
#include <string.h>

struct Acao {
    int codigo;
    char escola[100];
    char tema[50];
    char data[12];
    char publicoAlvo[50];
    char responsavel[50];
    int quantidadePrevista;
    char situacao[50];
    int quantidadeReal;
};

void exibirMenu(){
    printf("1- Cadastrar Acao\n");
    printf("2- Listar Acoes\n");
    printf("3- Pesquisar Acao\n");
    printf("4- Atualizar Situacao\n");
    printf("5- Gerar Resumo\n");
    printf("6- Sair\n");
    printf("\nEscolha sua acao: ");
}

void cadastrarAcao(struct Acao acoes[], int *quantidadeAcoes){
    int codigoNovo;
    int repetido;
    if (*quantidadeAcoes < 100) {
        printf("Escola onde sera realizada: ");
        fgets(acoes[*quantidadeAcoes].escola, 100, stdin);
        acoes[*quantidadeAcoes].escola[strcspn(acoes[*quantidadeAcoes].escola, "\n")] = '\0';

        printf("Codigo da acao: ");
        scanf("%d", &codigoNovo);
        getchar();
        repetido = 0;
        for (int i = 0; i < *quantidadeAcoes; i++){
            if(acoes[i].codigo == codigoNovo){

                repetido = 1;
            }
        }
        if(repetido == 1){
            printf("Codigo ja cadastrado! Tente novamente! \n");
            return;
        } else{
            acoes[*quantidadeAcoes].codigo = codigoNovo;
        }

        printf("Tema da acao: ");
        fgets(acoes[*quantidadeAcoes].tema, 50, stdin);
        acoes[*quantidadeAcoes].tema[strcspn(acoes[*quantidadeAcoes].tema, "\n")] = '\0';

        printf("Data da acao: ");
        fgets(acoes[*quantidadeAcoes].data, 12, stdin);
        acoes[*quantidadeAcoes].data[strcspn(acoes[*quantidadeAcoes].data, "\n")] = '\0';

        printf("Responsavel: ");
        fgets(acoes[*quantidadeAcoes].responsavel, 50, stdin);
        acoes[*quantidadeAcoes].responsavel[strcspn(acoes[*quantidadeAcoes].responsavel, "\n")] = '\0';
        
        printf("Publico-Alvo: ");
        fgets(acoes[*quantidadeAcoes].publicoAlvo, 50, stdin);
        acoes[*quantidadeAcoes].publicoAlvo[strcspn(acoes[*quantidadeAcoes].publicoAlvo, "\n")] = '\0';

        printf("Quantidade prevista: ");
        scanf("%d", &acoes[*quantidadeAcoes].quantidadePrevista);
        getchar();

        printf("\nAcao cadastrada com sucesso!\n\n");
        
        acoes[*quantidadeAcoes].quantidadeReal = 0;
        strcpy(acoes[*quantidadeAcoes].situacao, "Planejada");

        (*quantidadeAcoes)++;
    } else {
        printf("Acoes lotadas!");
    }
}

void listarAcoes(struct Acao acoes[], int quantidadeAcoes){
    if(quantidadeAcoes > 0){
        for(int i = 0; i < quantidadeAcoes; i++){
            printf("\nEscola: %s\n", acoes[i].escola);
            printf("\nCodigo: %d\n", acoes[i].codigo);
            printf("Tema: %s\n", acoes[i].tema);
            printf("Data: %s\n", acoes[i].data);
            printf("Publico-Alvo: %s\n", acoes[i].publicoAlvo);
            printf("Responsavel: %s\n", acoes[i].responsavel);
            printf("Participantes previstos: %d\n", acoes[i].quantidadePrevista);
            printf("Participantes reais: %d\n", acoes[i].quantidadeReal);
            printf("Situacao: %s\n", acoes[i].situacao);
        }
    }else{
        printf("Nenhuma ação cadastrada!\n");
    }
}

void buscarAcao(struct Acao acoes[], int quantidadeAcoes){
    int pesquisaCodigo = 0;
    int encontrado;
    int pesquisa = 0;
    char escolaBusca[100];
    char temaBusca[100];

    printf("Pesquisar por: \n");
    printf("1-Codigo\n");
    printf("2-Escola\n");
    printf("3-Tema\n");
    printf("4-Voltar ao menu\n");
    printf("Escolha sua opcao: ");
    scanf("%d", &pesquisa);
    getchar();
    switch (pesquisa) {
    case 1:
        //pesquisa por codigo
        encontrado = 0;
        printf("Digite o codigo que voce deseja encontrar: ");
        scanf("%d", &pesquisaCodigo);
        getchar();

        for (int i = 0; i < quantidadeAcoes; i++){
            if (acoes[i].codigo == pesquisaCodigo){
                printf("\nEscola: %s\n", acoes[i].escola);
                printf("\nCodigo: %d\n", acoes[i].codigo);
                printf("Tema: %s\n", acoes[i].tema);
                printf("Data: %s\n", acoes[i].data);
                printf("Publico-Alvo: %s\n", acoes[i].publicoAlvo);
                printf("Responsavel: %s\n", acoes[i].responsavel);
                printf("Participantes previstos: %d\n", acoes[i].quantidadePrevista);
                printf("Participantes reais: %d\n", acoes[i].quantidadeReal);
                printf("Situacao: %s\n", acoes[i].situacao);
                encontrado = 1;
            }
        }
        if (encontrado == 0){
            printf("Acao nao encontrada!\n");
        }

        break;
    case 2:
        //pesquisa por escola
        encontrado = 0;
        printf("Digite o nome da escola que deseja encontrar: ");
        fgets(escolaBusca, 100, stdin);
        escolaBusca[strcspn(escolaBusca, "\n")] = '\0';
        for (int i = 0; i < quantidadeAcoes; i++){
            if (strcmp(acoes[i].escola, escolaBusca) == 0){
                printf("\nEscola: %s\n", acoes[i].escola);
                printf("\nCodigo: %d\n", acoes[i].codigo);
                printf("Tema: %s\n", acoes[i].tema);
                printf("Data: %s\n", acoes[i].data);
                printf("Publico-Alvo: %s\n", acoes[i].publicoAlvo);
                printf("Responsavel: %s\n", acoes[i].responsavel);
                printf("Participantes previstos: %d\n", acoes[i].quantidadePrevista);
                printf("Participantes reais: %d\n", acoes[i].quantidadeReal);
                printf("Situacao: %s\n", acoes[i].situacao);
                encontrado = 1;
            }
        }
        if (encontrado == 0){
            printf("Acao nao encontrada!\n");
        }

        break;
    case 3:
        //pesquisa por tema
        encontrado = 0;
        printf("Digite o nome do tema que deseja encontrar: ");
        fgets(temaBusca, 100, stdin);
        temaBusca[strcspn(temaBusca, "\n")] = '\0';
        for (int i = 0; i < quantidadeAcoes; i++){
            if (strcmp(acoes[i].tema, temaBusca) == 0){
                printf("\nEscola: %s\n", acoes[i].escola);
                printf("\nCodigo: %d\n", acoes[i].codigo);
                printf("Tema: %s\n", acoes[i].tema);
                printf("Data: %s\n", acoes[i].data);
                printf("Publico-Alvo: %s\n", acoes[i].publicoAlvo);
                printf("Responsavel: %s\n", acoes[i].responsavel);
                printf("Participantes previstos: %d\n", acoes[i].quantidadePrevista);
                printf("Participantes reais: %d\n", acoes[i].quantidadeReal);
                printf("Situacao: %s\n", acoes[i].situacao);
                encontrado = 1;
            }
        }
        if (encontrado == 0){
            printf("Acao nao encontrada!\n");
        }
        break;
    case 4:
        //Voltar para o menu
        break;
    default:
        printf("Opcao invalida!\n");
        break;
    }

}

void alterarSituacao(struct Acao acoes[], int quantidadeAcoes){
    int encontrado;
    int pesquisaCodigo;
    int mudaSituacao;
    int participantesReais;

    encontrado = 0;
    printf("Digite o codigo que voce deseja alterar a situacao: ");
    scanf("%d", &pesquisaCodigo);
    getchar();

    for (int i = 0; i < quantidadeAcoes; i++){
        if (acoes[i].codigo == pesquisaCodigo){
            encontrado = 1;
            printf("Digite a opcao que deseja alterar: ");
            printf("\n1-Planejada \n2-Realizada \n3-Cancelada\n");
            scanf("%d", &mudaSituacao);
            getchar();
            switch (mudaSituacao){
            case 1:
                strcpy(acoes[i].situacao, "Planejada"); 
                acoes[i].quantidadeReal = 0;
                break;
            case 2:
                strcpy(acoes[i].situacao, "Realizada");
                printf("Quantas pessoas participaram do projeto? ");
                scanf("%d", &participantesReais);
                getchar();
                acoes[i].quantidadeReal = participantesReais;
                break;
            case 3:
                strcpy(acoes[i].situacao, "Cancelada");
                acoes[i].quantidadeReal = 0;
                break;
            default:
                printf("Opcao invalida!");
                break;
            }
        }
    }
    if (encontrado == 0){
        printf("Atividade nao encontrada! \n");
    }
}

void gerarResumo(struct Acao acoes[], int quantidadeAcoes){
    int planejadas;
    int realizadas;
    int canceladas;
    int totalParticipantes;
    int totalPrevisto;
    float total;

    planejadas = 0;
    realizadas = 0;
    canceladas = 0;
    totalPrevisto = 0;
    totalParticipantes = 0;
    for (int i = 0; i < quantidadeAcoes; i++){
        if (strcmp(acoes[i].situacao, "Planejada") == 0){
            planejadas++;
        } else if(strcmp(acoes[i].situacao, "Realizada") == 0){
            realizadas++;
            totalParticipantes = totalParticipantes + acoes[i].quantidadeReal;
            totalPrevisto = totalPrevisto + acoes[i].quantidadePrevista;
        } else if(strcmp(acoes[i].situacao, "Cancelada") == 0){
            canceladas++;
        }
    }
    if (totalPrevisto > 0){
        total = ((float)totalParticipantes / totalPrevisto) * 100.0;
    } else{
        total = 0;
    }
    printf("===========================\n");
    printf("          RESUMO           \n");
    printf("===========================\n");
    printf("Total de acoes planejadas: %d\n", planejadas);
    printf("Total de acoes realizadas: %d\n", realizadas);
    printf("Total de acoes canceladas: %d\n", canceladas);
    printf("\nparticipantes previstos: %d\n", totalPrevisto);
    printf("\nparticipantes efetivos: %d\n", totalParticipantes);
    printf("\nPercentual de participacao nas acoes realizadas: %.2f%%\n", total);
    
}

int main() {
    int acao = 0;
    struct Acao acoes[100];
    int quantidadeAcoes = 0;

    do {
        exibirMenu();
        scanf("%i", &acao);
        getchar();

        switch (acao) {
        case 1:
            // Lógica para cadastrar ação
            cadastrarAcao(acoes, &quantidadeAcoes);
            break;
        case 2:
            // Lógica para listar ações
            listarAcoes(acoes, quantidadeAcoes);
            break;
        case 3:
            // Lógica para pesquisar ação
            buscarAcao(acoes, quantidadeAcoes);
            break;
        case 4:
            // Lógica para atualizar situação
            alterarSituacao(acoes, quantidadeAcoes);
            break;
        case 5:
            // Lógica para gerar resumo
            gerarResumo(acoes, quantidadeAcoes);
            break;
        case 6:
            // Lógica para sair
            break;
        default:
            printf("Opcao invalida!\n");
        }

    } while (acao != 6);

    return 0;
}