<h1>Conceitos Usados</h1>
<ul>
<li>Ponteiros</li>
<li>Arrays</l1>
</ul>

<h2>Explicação da Solução</h2>
<p>O código resolve o problema de palavras "elásticas" seguindo estes passos:</p>

<ul>
<li>Para cada palavra no array words, verificamos se ela pode ser esticada para igualar a string s.</li>
<li>Usamos dois ponteiros (sIndex e wIndex) para percorrer simultaneamente a string s e a palavra atual.</li>
<li>Para cada grupo de caracteres idênticos consecutivos:</li>
<ul>
<li>Contamos quantas vezes o caractere aparece em s (sCount)</li>
<li>Contamos quantas vezes o caractere aparece na palavra (wordCount)</li>
<li>Aplicamos as regras de elasticidade:</li>
<ul>
<li>Se sCount < wordCount: inválido (não podemos encurtar grupos)</li>
<li>Se sCount > wordCount e sCount < 3: inválido (só podemos esticar se o resultado tiver 3+ caracteres)</li>
<li>Caso contrário: válido</li>
</ul>
</ul>
<li>Uma palavra é considerada elástica se ambas as strings forem totalmente processadas e todas as regras forem satisfeitas.</li>
<li>Retornamos o total de palavras elásticas encontradas.</li>
</ul>
<p>A solução tem complexidade O(n * m), onde n é o número de palavras e m é o comprimento médio das strings.</p>