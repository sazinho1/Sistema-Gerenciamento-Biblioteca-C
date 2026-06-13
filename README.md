# Sistema de Gerenciamento de Biblioteca em C

**Nome da Equipe:** 
Equipe do gabriel e do rafael

**Integrantes:** 
1. Gabriel Sá - 1804755 
2. Rafael Monteiro - 1804794

---

## 📖 Descrição Resumida do Sistema
Este projeto consiste em um Sistema de Gerenciamento de Biblioteca desenvolvido inteiramente em linguagem C, como requisito prático para a disciplina de Estrutura de Dados. O sistema opera via terminal (modo texto) e permite gerenciar o acervo de livros, controlar empréstimos e devoluções, além de manter um histórico de operações e uma fila de espera para livros indisponíveis.

A solução foi estruturada utilizando Tipos Abstratos de Dados (TADs) e faz uso intenso de ponteiros e alocação dinâmica, integrando três estruturas principais:
* **Árvore Binária de Busca (ABB):** Armazena e organiza os livros pelo código identificador.
* **Fila:** Gerencia as reservas de livros quando não há exemplares disponíveis (política FIFO).
* **Lista Encadeada:** Registra o histórico de todos os empréstimos realizados com sucesso.

---

## ⚙️ Instruções para Compilação
Para compilar o código-fonte, certifique-se de ter o compilador `gcc` instalado em sua máquina. Navegue até o diretório raiz do projeto onde os arquivos `.c` e `.h` estão localizados e execute o seguinte comando no terminal:

```bash
gcc main.c funcoesMain.c livro.c arvore.c fila.c lista.c -o biblioteca
```

Após a compilação bem-sucedida, um arquivo executável chamado `biblioteca` (ou biblioteca.exe no Windows) será gerado. Para iniciar o sistema, execute o comando correspondente ao seu sistema operacional:

- No `Linux` ou `macOS`:

```Bash
./biblioteca
```

- No `Windows`:

```Bash
./biblioteca.exe
```
ou, caso o primeiro não funcione,
```Bash
biblioteca.exe
```

## 🛠️ Observações sobre Funcionalidades Implementadas
O sistema atende a todos os requisitos obrigatórios solicitados, operando através de um menu interativo com as seguintes funcionalidades:

- Cadastro de Livros: Inserção de novos livros na Árvore Binária de Busca sem permitir códigos duplicados.

- Busca: Consulta rápida de informações de um livro utilizando seu respectivo código.

- Listagem: Exibição do acervo em Ordem Crescente, Pré-ordem e Pós-ordem.

- Empréstimo e Devolução: Controle da quantidade de exemplares disponíveis, registrando o empréstimo na Lista de Histórico.

- Fila de Reservas: Enfileiramento de usuários interessados em livros atualmente sem estoque.

## Funcionalidades Extras Implementadas:

Além dos requisitos mínimos, o sistema conta com os seguintes diferenciais:

- Remoção de Livro da ABB: Lógica completa para remover nós da Árvore Binária de Busca mantendo o balanceamento/estrutura.

- Atendimento Automático da Fila: Ao devolver um livro, o sistema verifica automaticamente se há usuários na fila de reserva e já converte a reserva no próximo empréstimo.

- Liberação Adequada de Memória: Implementação da função encerrarSistema(), que varre e desaloca todos os nós da árvore, da fila e da lista antes de finalizar o programa, evitando vazamento de memória (memory leaks).

## ⚠️ Limitações Conhecidas

- Persistência de Dados: O sistema não utiliza salvamento em arquivos (ex: .txt ou .csv). Todos os dados cadastrados (livros, empréstimos e reservas) são armazenados na memória RAM e serão perdidos ao encerrar a aplicação.

- Filtros de Busca: A busca de livros é restrita ao "código identificador". Atualmente não é possível buscar livros por título ou autor.

## 💻 Exemplos de Uso

### Exemplo 1: Cadastrando um Livro

```text
Selecione uma das opcoes a seguir:
1. Cadastrar novo livro

Digite o codigo do livro a ser inserido: 
101
Digite o titulo do livro a ser inserido:
Estrutura de Dados em C
Digite o autor/a autora do livro a ser inserido:
Tenenbaum
Digite o ano de publicacao do livro a ser inserido: 
1995
Digite a quantidade de exemplares do livro a ser inserido: 
3
```

### Exemplo 2: Realizando um Empréstimo
```text
Selecione uma das opcoes a seguir:
6. Realizar emprestimo de livro

Digite o codigo do livro: 
101
Digite o nome do usuario a alugar o livro: 
Joao_Silva

Empréstimo realizado com sucesso!
```