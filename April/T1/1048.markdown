<h1>Conceitos Usados</h1>
<ul>
<li>Funções e passagem de parâmetros</li>
</ul>

<h1>O Problema</h1>
<p>Temos um array de palavras e precisamos encontrar a maior sequência possível onde cada palavra é predecessora da próxima.</p> 
<p>Uma palavra A é predecessora de B se pudermos inserir exatamente uma letra em qualquer posição de A para obter B, sem mudar a ordem das outras letras.</p>

<p>Por exemplo, "bda" é predecessora de "bdca" porque podemos inserir "c" para transformar "bda" em "bdca".</p>

<h1>A Solução</h1>
<p>A solução usa programação dinâmica e funções específicas para cada tarefa:</p>
<ul>
<li>Ordenação: Primeiro ordenamos as palavras por comprimento (compareByLength);</li>
<li>Verificação de predecessora: Função isPredecessor que verifica se uma palavra é predecessora de outra usando dois ponteiros;</li>
<li>Programação Dinâmica:</li>
<ul>
<li>Usamos um array dp onde dp[i] representa o tamanho da maior cadeia terminando na palavra words[i];</li>
<li>A função updateDP atualiza o valor de dp[i] olhando para todas as palavras anteriores que podem ser predecessoras;</li>
<li>Passamos o ponteiro maxLength para atualizar o resultado global;</li>
</ul>
<li>Passagem de Parâmetros: Demonstramos diversos tipos de passagem de parâmetros em C:</li>
<ul>
<li>Passagem por valor (compareByLength, max);</li>
<li>Passagem por referência usando ponteiros (updateDP recebe e modifica maxLength);</li>
<li>Arrays como parâmetros (updateDP recebe arrays words e dp);</li>
</ul>
</ul>
<p>A complexidade de tempo é O(n² × m), onde n é o número de palavras e m é o comprimento médio das palavras.</p>