# PCC104
## Projeto e análise de algoritmos

Complemento das questões práticas:

<p align="justify">
1)	Bubble Sort é a técnicas de ordenação mais simples. Cada um dos elementos de um array é comparado ao seu elemento adjacente. Assim, se houver n elementos na lista A, então A[0] é comparado com A[1], A[1] com A[2] e assim por diante. Caso o primeiro elemento seja maior que o segundo, os dois são trocados.  
</p>

Algorthm _Bubble Sort (A[0...n-1])_  
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

Algorthm _Selection Sort (A[0...n-1])_  
//Input: array qualquer  
//Output: array ordenado  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** k = 0 **to** n-1 **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[initialize] smallElem = A[k]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[initialize] pos = K  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** j = k+1 **to** n-1 **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** smallElem > A[j]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;smalElem = A[j]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pos = j  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Troque A[k] e A[pos]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** A[0...n-1]

![Imagem2](https://user-images.githubusercontent.com/81366236/112498924-bdc5c400-8d65-11eb-865f-f2a83204731b.png)

<p align="justify">
3)	É a técnica de pesquisa mais básica, a chave a ser pesquisada é comparada sequencialmente com cada elemento.
</p>

Algorthm _Sequential Search (A[0...n-1],K)_  
// Input: um array qualquer e uma chave de pesquisa K  
// Output: o índice do primeiro elemento do array cujo valor é igual a K ou -1 se nenhum elemento //for encontrado  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** i = 0 **to** n-1 **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** K == A[i]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** i  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** -1  

<p align="justify">
4)	Quando fazemos uma busca por uma string, algoritmos para pesquisa de padrões são usados. Percorra o padrão sobre o texto caractere por caractere e verifique se há uma correspondência. Se uma correspondência for encontrada, verifique as correspondências subsequentes.
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/81366236/112500967-9b34aa80-8d67-11eb-9db8-2c67fa736cd9.png">
</p>

<p align="center">
Padrão encontrado em 0, 9 e 12
</p>

Algorthm _BruteForceStringMatch (A[0...n-1], P[0...m-1])_  
// Input: um array qualquer representando um texto e um array qualquer representando uma palavra  
// Output: o índice do primeiro caractere do texto que inicia a palavra correspondente ou -1 se a pesquisa não for bem-sucedida  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** i = 0 **to** n-m **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;j = 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** j = 0 **to** j < m **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** A[i+j] != P[j]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** i  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** -1  

<p align="justify">
5)	Recebe um array de n pontos no plano, e o problema é descobrir o par de pontos mais próximo no array. Esse problema simula aplicações como controle de tráfego aéreo, onde monitorar aviões que se aproximam muito pode indicar uma possível colisão.
</p>

Algorthm _BruteForceClosestPair (P0(x0,y0)... Pn(xn,yn))_  
// Input: uma lista de pontos qualquer  
// Output: distância entre o par de pontos mais próximo  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** i = 0 **to** n-1 **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** j = i+1 **to** n-1 **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;d = min(d, sqrt((xi - xj)2 + (yi - yj)2);  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** d

<p align="justify">
6)	Suponha que haja 13 pontos (p0 - p12) no plano. Se alguns pontos podem ser transformados em um polígono que contêm o restante dos pontos, esse polígono é uma casca convexa. 
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/81366236/112630578-895d1100-8e14-11eb-8dbe-2e6dca19c238.png">
</p>

<p align="justify">
Em um sistema de coordenadas bidimensional, dois pontos determinam uma linha. Se os pontos restantes estão do mesmo lado da linha eles são pontos do casco convexo, caso contrário, não são:
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/81366236/112630910-02f4ff00-8e15-11eb-81cd-88c511d0f6a2.png">
</p>

<p align="justify">
Quando o resultado da fórmula acima é positivo, p3 está à esquerda da linha p1p2; quando o resultado é negativo, p3 está à direita da linha p1p2.
</p>

Algorthm _Convex Hull (P0(x0,y0)... Pn(xn,yn))_  
// Input: uma lista de pontos qualquer  
// Output: Pontos que pertencem ao casco convexo
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** i = 0 **to** n-1 **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** j = 0 **to** n-1 **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** k = 0 **to** n-1 **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;det(i,j,k)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** det (i,j,k) < 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** det(i,j,k)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** -1  

