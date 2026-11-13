# PSE em Ação

## Sobre o projeto

O **PSE em Ação** é um sistema desenvolvido em linguagem C como parte de uma atividade acadêmica. Seu objetivo é auxiliar no planejamento, no gerenciamento e no acompanhamento de ações coletivas de saúde realizadas em escolas, contribuindo para a organização das atividades do Programa Saúde na Escola (PSE).

O sistema funciona por meio de um menu interativo no terminal, permitindo cadastrar, consultar, listar e atualizar ações, além de gerar um resumo dos resultados obtidos.

## Funcionalidades

- **Cadastrar ações:** permite registrar novas ações, informando código, escola, tema, data, público-alvo, responsável e quantidade prevista de participantes.
- **Listar ações:** apresenta todas as ações cadastradas e suas respectivas informações.
- **Pesquisar ações:** permite localizar ações por código, escola ou tema.
- **Atualizar situação:** possibilita alterar o status de uma ação para planejada, realizada ou cancelada. Quando uma ação é marcada como realizada, também é registrada a quantidade real de participantes.
- **Gerar resumo:** apresenta a quantidade de ações por situação, o total de participantes previstos e efetivos nas ações realizadas e o percentual de participação.

## Tecnologias e conceitos utilizados

O projeto foi desenvolvido utilizando:

- Linguagem C;
- Estruturas condicionais (`if`, `else` e `switch`);
- Estruturas de repetição (`for` e `do while`);
- Vetores;
- Estruturas (`struct`);
- Funções;
- Manipulação de strings;
- Entrada e saída de dados pelo terminal.

## Organização do código

O programa foi dividido em funções com responsabilidades específicas, facilitando a organização, a compreensão e a manutenção do código.

As principais funções são:

- `exibirMenu()`
- `cadastrarAcao()`
- `listarAcoes()`
- `buscarAcao()`
- `alterarSituacao()`
- `gerarResumo()`

## Como executar

1. Clone este repositório:
   ```bash
   git clone https://github.com/carlossantana-hub/Trabalho.git
   ```

2. Acesse a pasta do projeto:
   ```bash
   cd Trabalho
   ```

3. Compile o código utilizando um compilador C, como o GCC:
   ```bash
   gcc pse.c -o pse_em_acao
   ```

4. Execute o programa:
   ```bash
   ./pse_em_acao
   ```

   No Windows, execute:
   ```bash
   pse_em_acao.exe
   ```

## Armazenamento de dados

Nesta versão, os dados são armazenados temporariamente em memória durante a execução do programa. Ao encerrar o sistema, os registros cadastrados não são mantidos.

## Objetivo acadêmico

O projeto tem como finalidade aplicar os conceitos fundamentais da programação em linguagem C na construção de uma solução prática voltada à organização e ao acompanhamento de ações coletivas de promoção da saúde no ambiente escolar.

---

**Projeto acadêmico — Programa Saúde na Escola (PSE).**
