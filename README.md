# PCC104
## Projeto e análise de algoritmos

Complemento das questões práticas:

<p align="justify">
1)	Bubble Sort é a técnicas de ordenação mais simples. Cada um dos elementos de um array é comparado ao seu elemento adjacente. Assim, se houver n elementos na lista A, então A[0] é comparado com A[1], A[1] com A[2] e assim por diante. Caso o primeiro elemento seja maior que o segundo, os dois são trocados.  
</p>

Algorthm Bubble Sort (A[0...n-1])  
//Input: array qualquer  
//Output: array ordenado crescente  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** i = 0 **to** n-1 **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** j = i+1 **to** n-1 do  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** A[j] > A[i]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Troque A[j] e A[i]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** A[0...n-1]

![Imagem1](https://user-images.githubusercontent.com/81366236/112496533-94a43400-8d63-11eb-9c08-02300d829019.png)


<p align="justify">
2)	Selection Sort é uma técnica de classificação bastante simples, pois envolve apenas encontrar o menor elemento em cada passagem e colocá-lo na posição correta. É eficiente quando o array é pequeno, mas seu desempenho é gravemente afetado à medida que aumenta. A técnica consiste de selecionar o menor elemento no array e trocar pelo primeiro elemento. Em seguida, ele troca o segundo menor elemento pelo segundo elemento e assim por diante.
</p>

Algorthm Selection Sort (A[0...n-1])
//Input: array qualquer
//Output: array ordenado
**for** k = 0 **to** n-1 **do**
[initialize] smallElem = A[k]
[initialize] pos = K
**for** j = k+1 **to** n-1 **do**
**if** smallElem > A[j]
smalElem = A[j]
pos = j
Troque A[k] e A[pos]
**return** A[0...n-1]
                               

3)	É a técnica de pesquisa mais básica, a chave a ser pesquisada é comparada sequencialmente com cada elemento.
Algorthm Sequential Search (A[0...n-1],K)
// Input: um array qualquer e uma chave de pesquisa K
// Output: o índice do primeiro elemento do array cujo valor é igual a K ou -1 se nenhum elemento //for encontrado
for i = 0 to n-1 do
if K == A[i]
	return i
else
	return -1

4)	Quando fazemos uma busca por uma string, algoritmos para pesquisa de padrões são usados. Percorra o padrão sobre o texto caractere por caractere e verifique se há uma correspondência. Se uma correspondência for encontrada, verifique as correspondências subsequentes.
 
Padrão encontrado em 0, 9 e 12.

Algorthm BruteForceStringMatch (A[0...n-1], P[0...m-1])
// Input: um array qualquer representando um texto e um array qualquer representando uma palavra
// Output: o índice do primeiro caractere do texto que inicia a palavra correspondente ou -1 se a pesquisa não for bem-sucedida
for i = 0 to n-m do
j = 0
for j = 0 to j < m do
if A[i+j] != P[j]
return i
else
return -1

5)	Recebe um array de n pontos no plano, e o problema é descobrir o par de pontos mais próximo no array. Esse problema simula aplicações como controle de tráfego aéreo, onde monitorar aviões que se aproximam muito pode indicar uma possível colisão.
Algorthm BruteForceClosestPair (P0(x0,y0)... Pn(xn,yn))
// Input: uma lista de pontos qualquer
// Output: distância entre o par de pontos mais próximo 
for i = 0 to n-1 do
for j = i+1 to n-1 do
d = min(d, sqrt((xi - xj)2 + (yi - yj)2);
return d
