# Atividade Avaliativa 02 — Criptografia em C

Projeto desenvolvido para a disciplina de **Algoritmo e Pensamento Computacional**, sob orientação do **Prof. Francisco de Assis Cavallaro**.

---

## Integrantes do grupo
Andrey Azevedo Veloso RGM 500611944

Brenno Lima do Vale RGM 50065149

---

## Sobre o Projeto
O objetivo da aplicação é realizar a criptografia de uma palavra secreta (de até 15 letras) unindo conceitos de programação em C e matemática aplicada através de duas camadas de proteção:

1. **Camada 1 (Cifra de César):** Deslocamento fixo (*SHIFT*) inserido pelo usuário.
2. **Camada 2 (Deslocamento Dinâmico):** Deslocamento variável calculado com base em uma sequência matemática escolhida.

---

## Sequências Matemáticas Suportadas
O usuário pode escolher entre 4 opções de progressões e séries:
* **PA (Progressão Aritmética):** Termos incrementados linearmente ($1, 2, 3, 4, \dots$).
* **PG (Progressão Geométrica):** Termos multiplicados por razão 2 ($1, 2, 4, 8, \dots$).
* **Série de Fibonacci:** Cada termo é a soma dos dois anteriores ($1, 1, 2, 3, 5, 8, 13, \dots$).
* **Números Primos:** Sequência com os primeiros números primos ($2, 3, 5, 7, 11, \dots$).

---

## Download dos Arquivos

* **[Baixar Projeto Completo em .ZIP](https://github.com/brennovale/Atividade-Avaliativa-02_-Algoritmo-e-Pensamento-Computacional/archive/refs/heads/main.zip)**
* **[Visualizar `main.c`](https://github.com/brennovale/Atividade-Avaliativa-02_-Algoritmo-e-Pensamento-Computacional/blob/main/main.c)**
* **[Visualizar `resultado_criptografia.txt`](https://github.com/brennovale/Atividade-Avaliativa-02_-Algoritmo-e-Pensamento-Computacional/blob/main/resultado_criptografia.txt)**

---

##  Como Executar o Programa 

1. Acesse o compilador online [Online GDB Debugger](https://www.onlinegdb.com/).
2. No canto superior direito, na opção **Language**, selecione **C**.
3. Copie o conteúdo do arquivo [`main.c`](https://github.com/brennovale/Atividade-Avaliativa-02_-Algoritmo-e-Pensamento-Computacional/blob/main/main.c) e cole na área de código do editor online.
4. Clique no botão verde **Run** (ou pressione a tecla `F9`).
5. Digite as entradas solicitadas no terminal na parte inferior do site (palavra secreta, SHIFT e opção da sequência).
6. Após a execução, o arquivo `resultado_criptografia.txt` será criado na aba de arquivos ao lado do código no próprio Online GDB.

  
