<h1>Conceitos Usados</h1>
<ul>
<li>Alocação dinâmica de memória</li>
<li>Ponteiros</li>
<li>Manipulação de strings</li>
<li>Arrays</li>
<li>Variáveis booleanas</li>
</ul>

<br>
<h1>O Problema</h1>
<p>Dadas duas frases, precisamos determinar se elas são "similares". Duas frases são consideradas similares se é possível inserir uma sequência arbitrária de palavras em uma delas para torná-las idênticas.</p> 
<p>A sequência inserida deve estar separada das palavras existentes por espaços.</p>

<h4>Por exemplo:</h4>
<ul>
<li>"Hello Jane" e "Hello my name is Jane" são similares, pois podemos inserir "my name is" entre "Hello" e "Jane".</li>
<li>"of" e "A lot of words" não são similares, pois não é possível inserir uma única sequência para fazer a igualdade.</li>
</ul>

<br>
<h1>A Solução</h1>
<p>O algoritmo funciona assim:</p>
<ul>
<li>Tokenizamos ambas as frases em palavras</li>
<li>Identificamos qual frase tem menos palavras</li>
<li>Tentamos todas as possíveis maneiras de dividir a frase menor em um prefixo e um sufixo</li>
<li>Para cada divisão, verificamos se o prefixo corresponde ao início da frase maior e se o sufixo corresponde ao final</li>
<li>Se encontrarmos uma correspondência válida, as frases são similares</li>
</ul>
<p>A complexidade de tempo é O(n²), onde n é o comprimento da frase mais curta.</p>