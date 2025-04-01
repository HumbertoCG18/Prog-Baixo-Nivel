<h1>Conceitos Usados</h1>
<ul>
<li>Structs</li>
</ul>

<h2>O Problema</h2>
<p>Temos um array de strings queries e uma string pattern. Uma query coincide com o padrão se podemos inserir letras minúsculas no padrão para torná-lo igual à query.</p> 
<p>Podemos inserir caracteres em qualquer posição ou não inserir nenhum.</p>

<h3>Por exemplo, com o padrão "FB":</h3>

<ul>
<li>"FooBar" coincide porque podemos inserir "oo" após "F" e "ar" após "B"</li>
<li>"FooBarTest" não coincide porque "T" é maiúscula e não está no padrão</li>
</ul>

<h2>A Solução</h2>
<p>A solução utiliza dois ponteiros para percorrer simultaneamente a query e o padrão:</p>

<h4>Usando uma struct CamelMatcher para organizar os dados</h4>
<p>Para cada query, verificamos:</p>
<ul>
<li>Se o caractere atual da query corresponde ao caractere atual do padrão, avançamos ambos os ponteiros;</li>
<li>Se o caractere atual da query é minúsculo, simplesmente avançamos o ponteiro da query (considerando uma inserção válida);</li>
<li>Se o caractere atual da query é maiúsculo e não corresponde ao caractere atual do padrão, a correspondência falha.</li>
<li>Ao final, a query coincide com o padrão se percorremos todo o padrão.</li>
</ul>
<p>A complexidade de tempo é O(n × m), onde n é o número de queries e m é o comprimento médio das strings.</p>