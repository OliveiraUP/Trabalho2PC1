Nome Completo dos Alunos: 
Bruno Gomes da Silva
Fernando Miguel Alcântara de Oliveira
Luciano Lucas de Oliveira Gois


Como Compilar: O arquivo de entrada tem que estar na mesma pasta do programa"extrair_feed.c". Além disso para compilar utilize "gcc -Wall extrair_feed.c -o arquivo", depois de compilar execute com "./arquivo"

Para funcionar é preciso inserir o arquivo de entrada com o nome do arquivo + o formato xml 
Ex: "feed_15_10_2020.xml". E inserir o nome do arquivo de saída que desejar no formato html Ex: "feed_15_10_2020.html". Depois disso é só executar o arquivo html.

O programa primeiramente encontra a tag desejada, em seguida salva numa struct o conteudo desejado após a tag e após isso salva no arquivo html de saída.

A fonte de dados utilizada foi o site: https://www.melhoresdestinos.com.br/feed
