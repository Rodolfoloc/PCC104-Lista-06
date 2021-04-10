# PCC104
## Projeto e análise de algoritmos

Complemento das questões práticas:

<p align="justify">
1)	Insertion sort é um algoritmo de ordenação simples que funciona semelhante à maneira como se classifica as cartas de baralho em mãos. O array é virtualmente dividido em uma parte ordenada e outra não ordenada. Os valores da parte não ordenada são selecionados e colocados na posição correta da parte ordenada. 
</p>

Algorthm _Insertion Sort (A[0...n-1])_  
//Input: array qualquer  
//Output: array ordenado crescente  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** i = 1 **to** n-1 **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;v = A[i]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;j = i - 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**while** j >= 0 **and** A[j] > v **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A[j + 1] = A[j]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;j = j - 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A[j + 1] = v

<p align="center">
  <img src="https://user-images.githubusercontent.com/81366236/114271761-74be7280-99e9-11eb-9045-de41d7c31d41.png">
</p>

<p align="justify">
2)	O algoritmo Johnson-Trotter gera cada permutação trocando apenas dois elementos adjacentes da sequência, da seguinte forma:
</p>

1.	Descobrir o maior número inteiro móvel na sequência. Um inteiro é considerado móvel se for maior que seu vizinho imediato na direção de referência.
2.	Trocar o inteiro móvel e o inteiro adjacente da direção de referência.
3.	Mudar a direção de todos os elementos cujo valor é maior do que o valor inteiro móvel.
4.	Repitir o passo 1 até que não haja nenhum inteiro móvel restante na sequência.

<p align="justify">
Ex: Gerar permutações de tamanho 3.
Imprimir 1 2 3. Inicialmente todas as direções estão da direita para a esquerda <1 <2 <3.

Os números móveis são 2 e 3. O maior número móvel é 3, então troque 2 e 3. Se 3 é maior, não mudar nenhuma direção <1 <3 <2

O maior número móvel é 3. Troque 1 e 3. <3 <1 <2

O maior número móvel é 2. Troque 1 e 2 e mude a direção de elementos maiores. 3> <2 <1

O maior número móvel é 2. Troque 2 e 3. <2 3> <1

O maior número móvel é 1. Troque 1 e 3 e mude a direção de elementos maiores. 2> <1 3>

O maior número móvel é 1. Troque 1 e 2. <1 2> 3>

Algorthm _JohnsonTrotter(n)_  
//Input: Um inteiro positivo qualquer  
//Output: Uma lista de todas as suas permutações  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;inicializar a primeira permutação com <1 <2 ... <n  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**while** a última permutação tem um elemento móvel **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Passo 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Passo 2  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Passo 3  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;adicione a nova permutação à lista  

<p align="justify">
3)	Imprime todas as permutações ordenadas de forma crescente (lexicográfica). Aplicando o Insertion sort a saída do algoritmo Johnson-Trotter, obtém-se uma solução para o Lexicographic Permute com o mesmo custo do livro O(n<sup>2</sup>xn!). Aplicando outros algortmos de ordenação, seu custo pode ser otimizado para O(nxn!).
</p>

<p align="justify">
4)	AQUI
</p>

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

<p align="justify">
7)	Dado um conjunto de pontos e distâncias entre cada par dos pontos, o problema é encontrar a rota mais curta possível que visite todos os pontos exatamente uma vez e retorne ao ponto de partida. O problema pode ser definido encontrar o circuito hamiltoniano mais curto do gráfico. Um circuito hamiltoniano é definido como um ciclo que passa por todos os vértices do gráfico exatamente uma vez.
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/81366236/112662190-2a0ff880-8e36-11eb-87d5-b4f2f5bc0573.png">
</p>


Matriz que representa o grafo acima:  
(00, 10, 15, 20  
 10, 00, 35, 25  
 15, 35, 00, 30  
 20, 25, 30, 00)

<p align="justify">
Assim, podemos obter a distância mais curta entre os pontos gerando todas as permutações de n - 1 cidades intermediárias, calculando a duração do trajeto e encontrando o mais curto entre eles:
</p>

1.	Considere o ponto 1 como ponto inicial e final. Como a rota é cíclica, podemos considerar qualquer ponto como ponto de partida.  
2.	Gere todas as (n-1)! permutações dos pontos.
3.	Calcule o custo de cada permutação e guarde o custo mínimo.
4.	Retorne a permutação com custo mínimo.

<p align="justify">
8)	Dados os pesos e valores de n itens, coloque esses itens em uma mochila com capacidade capacity para obter o valor total máximo na mochila. Dados dois arrays inteiros weights[0..n-1] e values[0..n-1] (representam pesos e valores associados a n itens, respectivamente) e um inteiro capacity que representa a capacidade da mochila, descubra o subconjunto de valor máximo de forma que a soma dos pesos deste subconjunto seja menor ou igual a capacity. Não é possível dividir um item, ou escolha o item completo ou não escolha. Ilustração do problema:
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/81366236/112666897-68f47d00-8e3b-11eb-8303-b533dc7710eb.png">
</p>

<p align="justify">
9)	Busca em largura de uma árvore:
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/81366236/112671905-917f7580-8e41-11eb-97e3-8d4dd7a8efe0.png">
</p>

<p align="center">
A ordem de busca da árvore acima é 1 2 3 4 5
</p>

<p align="justify">
Ao contrário das árvores, os grafos podem conter ciclos, então podemos chegar ao mesmo nó novamente. Para evitar o processamento de um nó mais de uma vez, usamos um array booleano para armazenar os nós visitados. Para simplificar, assume-se que todos os vértices são alcançáveis a partir do vértice inicial. Por exemplo, no grafo a seguir, iniciamos a travessia do vértice 2. Quando chegamos ao vértice 0, procuramos todos os vértices adjacentes dele. 2 também é um vértice adjacente de 0. Se não marcarmos os vértices visitados, então 2 será processado novamente e se tornará um processo sem fim. A ordem em que os vértices são visitados é 2, 0, 3, 1.
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/81366236/112675764-503d9480-8e46-11eb-8297-e190bd291e1b.png">
</p>

Algorthm _BSF (G)_  
// Input: Grafo G = <V,E>  
// Output: Vértices de G na ordem em que são visitados  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;count = 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** cada vértice v em V **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** v é marcado como 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bfs(v)  

Function _bsf (v)_  
// Visita todos os vértices não visitados conectados ao vértice v por um caminho e os numera na ordem em que são visitados por meio de contagem de variável global  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;count = count + 1;  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**while** a fila não estiver vazia **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** cada vértice w em V adjacente ao vértice frontal **do** 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** w é marcado como 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;count = count + 1;  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;adiciona w à fila  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;remove o vértice da frente da fila
