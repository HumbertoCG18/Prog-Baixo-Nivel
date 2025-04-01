<h1>Conceitos Usados</h1>
<ul>
<li>Ponteiros</li>
<li>Strings</l1>
</ul>

<h1>Explicação</h1>
<p> problema pede para encontrar a palavra mais longa de um dicionário que pode ser formada removendo caracteres de uma string dada. Uma palavra pode ser formada se seus caracteres aparecerem na string original na mesma ordem sequencial (mesmo que não adjacentes).</p>
<p>Em caso de empate no comprimento, deve-se retornar a palavra lexicograficamente menor.</p>

<h3>Ordem lexicográfica:</h3> 
<p>É a ordenação como em um dicionário, onde as palavras são comparadas caractere por caractere, da 
esquerda para a direita.</p> 

<h3>Por exemplo:</h3>
<ul>
<li>"apple" vem antes de "banana" porque 'a' vem antes de 'b'</li>
<li>"apple" vem antes de "apply" porque, após caracteres iguais, 'e' vem antes de 'y'</li>
<li>"cat" vem antes de "catalog" porque, quando todos os caracteres são iguais, a palavra mais curta vem primeiro</li>
</ul>

