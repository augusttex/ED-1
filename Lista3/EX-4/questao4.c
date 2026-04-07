/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 3
Exercício: 4

Vantagens:

Tamanho dinâmico: A estrutura pode crescer e diminuir durante a execução do programa conforme a necessidade. Você só aloca memória quando um novo elemento é criado, evitando desperdício de espaço.

Inserção e remoção eficientes: Adicionar ou remover um elemento no meio da estrutura é rápido. Basta reconfigurar os ponteiros (os endereços que ligam os elementos), sem precisar "empurrar" os outros dados para frente ou para trás.

Aproveitamento de memória fragmentada: Como os elementos não precisam estar juntos (contíguos), o sistema pode alocar cada elemento em qualquer espaço livre que encontrar na memória.

Desvantagens:

Acesso sequencial (lento): Não existe acesso direto por índice. Para acessar o décimo elemento, o programa é obrigado a passar por todos os nove anteriores, o que torna a busca mais demorada.

Consumo extra de memória: Cada elemento da estrutura precisa gastar espaço adicional para armazenar o ponteiro (o endereço) que aponta para o próximo elemento da cadeia.

Baixa localidade de referência (desempenho de cache): Como os dados ficam espalhados pela memória, o processador não consegue otimizar a leitura em bloco, tornando o processamento geral um pouco menos eficiente se comparado a uma estrutura sequencial.



*/

