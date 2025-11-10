# get_next_line

> Implementação em C de uma função que lê e devolve **uma linha de cada vez** a partir de um descritor de ficheiro (FD). Preparado para a versão **mandatory** e **bónus** do projeto 42.

---

## Índice

* [Descrição](#descrição)
* [Estrutura do repositório](#estrutura-do-repositório)
* [API](#api)

  * [Protótipos](#protótipos)
  * [Contratos da função](#contratos-da-função)
  * [Erros e retorno](#erros-e-retorno)
* [Compilação](#compilação)

  * [Com Makefile do projeto](#com-makefile-do-projeto)
  * [Compilação manual para testes](#compilação-manual-para-testes)
* [Utilização](#utilização)

  * [Exemplo de `main.c` (mandatory)](#exemplo-de-mainc-mandatory)
  * [Exemplo com múltiplos FDs (bónus)](#exemplo-com-múltiplos-fds-bónus)
* [`BUFFER_SIZE`](#buffer_size)
* [Comportamento e casos-limite](#comportamento-e-casos-limite)
* [Detalhes de implementação](#detalhes-de-implementação)

  * [Armazenamento estático por FD](#armazenamento-estático-por-fd)
  * [Variante com listas ligadas](#variante-com-listas-ligadas)
* [Testes rápidos](#testes-rápidos)
* [Integração noutros projetos](#integração-noutros-projetos)
* [Licença e créditos](#licença-e-créditos)

---

## Descrição

`get_next_line` devolve a próxima linha disponível no fluxo associado a um **descritor de ficheiro** (ficheiro, STDIN, socket, pipe, …). Cada chamada lê o que for necessário do FD, acumula em memória e retorna exatamente **uma linha**, **incluindo o `\n` final** quando existente. Ao chegar ao EOF sem `\n`, devolve a última linha sem `\n`.

> Este comportamento segue os requisitos típicos do projeto 42 *get_next_line*, incluindo o uso de variável(‑eis) estática(s) para manter estado entre chamadas.

## Estrutura do repositório

```
get_next_line/
├─ bonus/                          # ficheiros da versão bónus
├─ get_next_line_with_linked_lists/ # implementação alternativa com listas ligadas
├─ util/                           # auxiliares de teste/apoio (ex.: mains, ficheiros de dados)
├─ Makefile
├─ get_next_line.c / .h / _utils.c # (mandatory)
└─ README.md
```

> As pastas **`bonus/`**, **`get_next_line_with_linked_lists/`** e **`util/`** existem no repositório e organizam os artefactos da solução mandatory/bónus e material de apoio.

## API

### Protótipos

Mandatory:

```c
char *get_next_line(int fd);
```

Bónus (mesmo protótipo; implementação preparada para gerir **vários** FDs em paralelo):

```c
char *get_next_line(int fd);
```

Inclui cabeçalho público:

```c
// get_next_line.h
char *get_next_line(int fd);
```

### Contratos da função

* **Entrada**: `fd` válido e aberto para leitura.
* **Saída**: ponteiro para *string* alocada com a próxima linha lida do `fd`.
* **Formato da linha**:

  * Se a linha no ficheiro termina com `\n`, a *string* devolvida **inclui** esse `\n`.
  * Na última linha, se o ficheiro termina em EOF sem `\n`, a *string* **não** inclui `\n`.
* **Persistência**: entre chamadas, o estado não consumido mantém-se em memória (estático) para concluir linhas seguintes.

### Erros e retorno

* **`NULL`** se:

  * `fd` é inválido;
  * ocorre erro em `read(2)`;
  * não há mais dados a ler (EOF) **e** não existe conteúdo por devolver.
* Em caso de sucesso, retorna uma *string* alocada (depois o utilizador deve chamar `free()`).

## Compilação

### Com Makefile do projeto

Targets habituais:

```bash
make            # compila a versão mandatory (gera .o/.a ou objetos, conforme Makefile)
make bonus      # compila a versão bónus com suporte a múltiplos FDs
make clean      # remove objetos
make fclean     # clean total (incl. binários/arquivos)
make re         # recompila tudo do zero
```

> Ajusta ao teu ambiente se utilizares outra convenção de targets.

### Compilação manual para testes

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line.c get_next_line_utils.c \
   -I . -o gnl_test
```

> Para a versão bónus, compila os ficheiros em `bonus/` (por ex.: `get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, `get_next_line_bonus.h`).

## Utilização

### Exemplo de `main.c` (mandatory)

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int   fd = open("./util/sample.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return perror("open"), 1;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);   // já inclui \n quando existir
        free(line);
    }
    close(fd);
    return 0;
}
```

### Exemplo com múltiplos FDs (bónus)

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int   a = open("a.txt", O_RDONLY);
    int   b = open("b.txt", O_RDONLY);
    char *la, *lb;

    while ((la = get_next_line(a)) || (lb = get_next_line(b)))
    {
        if (la) { printf("A: %s", la); free(la); }
        if (lb) { printf("B: %s", lb); free(lb); }
    }
    close(a); close(b);
    return 0;
}
```

## `BUFFER_SIZE`

Define o tamanho do *buffer* usado em cada chamada a `read(2)`:

* Define-o na linha de compilação: `-D BUFFER_SIZE=42`.
* Quanto maior, menos *syscalls*; quanto menor, menor uso de memória e latência por linha.
* A função deve funcionar corretamente para **qualquer** valor `> 0` e também ser robusta quando `BUFFER_SIZE` é grande.

## Comportamento e casos-limite

* **EOF imediato**: retorna `NULL`.
* **Linhas muito longas**: a função acumula fragmentos até completar a linha, sem limites artificiais.
* **`fd` inválido/fechado**: retorna `NULL`.
* **Erros de `read`**: liberta recursos internos e retorna `NULL`.
* **Última linha sem `\n`**: devolve a linha final sem `\n`.
* **Bónus — múltiplos FDs**: manter um *stash* independente por FD (p.ex., tabela/array/estrutura associativa) para que leituras intercaladas não contaminem entre si.

## Detalhes de implementação

### Armazenamento estático por FD

O projeto recorre a **armazenamento estático** para reter dados lidos que ainda não foram devolvidos ao utilizador (o “resto” após o `\n`). A cada chamada, concatena‑se o que vier de `read(2)` até encontrar `\n` ou EOF.

Passos típicos:

1. Ler para um *buffer* temporário (`BUFFER_SIZE`).
2. Acumular ao *stash* do FD.
3. Extrair a **linha completa**.
4. Atualizar o *stash* para o conteúdo remanescente.
5. Devolver a linha alocada.

### Variante com listas ligadas

Existe uma variante em `get_next_line_with_linked_lists/` que ilustra a mesma lógica usando **listas ligadas** para gerir segmentos de memória sem realocações grandes. Útil para estudar abordagem alternativa ao *stash* baseado em *strings*.

## Testes rápidos

1. **STDIN**:

   ```bash
   ./gnl_test
   # escreve linhas no terminal; termina com Ctrl+D (EOF)
   ```
2. **Ficheiro de amostra**:

   ```bash
   printf "linha1\nlinha2\n" > util/sample.txt
   ./gnl_test
   ```
3. **Bónus (múltiplos FDs)**: cria `a.txt` e `b.txt` com conteúdos diferentes e corre o exemplo de múltiplos FDs.

Dicas:

* Usa ferramentas como `valgrind` para verificar **leaks** e *double free*:

  ```bash
  valgrind --leak-check=full ./gnl_test
  ```
* Testa com `BUFFER_SIZE` variados: `1`, `2`, `42`, `9999`.

## Integração noutros projetos

* Inclui o cabeçalho no teu código: `#include "get_next_line.h"`.
* Adiciona os `.c` ao teu *build* ou cria uma *library* estática (p.ex. `libgnl.a`).
* Não expões funções internas/auxiliares no cabeçalho público.

## Licença e créditos

* Ver `LICENSE` caso exista. Na ausência de licença explícita, trata o código como **todos os direitos reservados** ao autor do repositório.
* Autor: @hroxo

---

### Notas

* Esta documentação descreve o comportamento esperado do projeto *get_next_line* (42) e explica a organização **deste repositório** (mandatory, bónus e variante com listas ligadas), oferecendo exemplos de uso e testes.
