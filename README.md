# CIN0203 - Programação Competitiva
Este repositório reúne os códigos dos exemplos feitos em sala, das listas de exercícios (LEs) e dos exercícios práticos (EPs) da disciplina, além de algumas anotações. 

As LEs são atividades para casa, com prazo de alguns dias, e os EPs são provas feitas no laboratório.

A disciplina se baseia no livro **Competitive Programming 3**, de Steven e Felix Halim, e a linguagem de programação utilizada é C++.

## Como compilar e rodar código em C++

### Compilar
No Ubuntu Linux, o compilador ```g++``` já vem instalado por padrão. Para compilar o código, execute no terminal:

```
g++ <nome_do_arquivo>.cpp -o <nome_do_executavel>
```

A flag ```-o``` permite a escolha do nome do executável. Sem ela, o compilador salvará o executável como ```a.out``` (Linux e macOS) ou ```a.exe``` (Windows).

### Rodar
Para rodar o código compilado, execute no terminal:

```
./<nome_do_executavel>
```

Para testar uma entrada sem precisar digitar no terminal ou dar ```Ctrl + C``` e ```Ctrl + V``` a cada execução, salve a entrada em um arquivo e faça o redirecionamento.

```
./<nome_do_executavel> < entrada.txt
```

O programa ```./<nome_do_executavel>``` normalmente lê a entrada padrão ```stdin``` (teclado). No entanto, o operador ```<``` do shell pega o conteúdo de ```entrada.txt``` e redireciona para a entrada padrão do programa.

Para salvar a saída do programa em um arquivo, em vez de exibi-la no terminal, faça o redirecionamento de saída.

```
./<nome_do_executavel> > saida.txt
```

O operador do shell ```>``` redireciona toda a saída que o programa exibiria no terminal para ```saida.txt```. Caso o arquivo já exista, seu conteúdo será substituído; do contrário, um novo arquivo será criado automaticamente.