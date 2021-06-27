# PCC104
## Projeto e análise de algoritmos

Complemento das questões práticas:

**1. Programação Dinâmica**
<p align="justify">
a)	A programação dinâmica é um método que busca encontrar a solução de vários subproblemas para, então, encontrar a solução do problema geral. A grande diferença dessa metodologia é que os subresultados são armazenados em memória já que eles são utilizados em diversos momentos durante o processamento da solução. Essa técnica serve para problemas com:
</p>

* Subestrutura ótima - a solução ótima do problema provém das soluções de subproblemas dependentes.
* Sobreposição de soluções - a solução ótima passa pela resolução de subproblemas que aparecem duas ou mais vezes.
  
<p align="justify">
b)	
</p>

Algorthm _Fibonacci (n)_  
//Input: n-ésimo número de Fibonacci  
//Output: seu valor  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** n <= 1 **return** n  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** Fibonacci(n - 1) + Fibonacci(n - 2)  

<p align="justify">
c)	
</p>

Algorthm _Fibonacci (n, mem[1..n])_  
//Input: n-ésimo número de Fibonacci e um array de mémoria
//Output: seu valor  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** mem[n] != -1 **return** mem[n]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else if** n <= 1 mem[n] = n  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else** mem[n] = Fibonacci(n - 1, mem) + Fibonacci(n - 2, mem)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** mem[n]  

<p align="justify">
d)	Dado um valor V, se quisermos fazer a mudança para V centavos, e tivermos um suprimento infinito de moedas com valor C = {C1, C2, .., Cn}, qual é o número mínimo de moedas para fazer a mudança? Se não for possível fazer alterações, imprima -1. Exemplo:  

Entrada: moedas [ ] = {25, 10, 5}, V = 30

Saída: Mínimo 2 moedas necessárias
  
Recursivamente:
</p>

Algorthm _minCoins (coins[0..n-1], V)_  
//Input: array de moedas e o valor que deseja formar  
//Output: número mínimo de moedas para fazer a mudança  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** V = 0 **return** 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;res = INT_MAX  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** i = 0 **to** i < coins.size() **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** coins[i] <= V  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;sub_res = minCoins(coins, V - coins[i])  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** (sub_res != INT_MAX && sub_res + 1 < res) res = sub_res + 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** res 

<p align="justify">
Programação diâmica:	
</p>

Algorthm _minCoins (coins[0..n-1], V)_  
//Input: array de moedas e o valor que deseja formar  
//Output: número mínimo de moedas para fazer a mudança  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mem[ ] = V + 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mem[0] = 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** i = 1 **to** i <= V **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** j = 0 **to** j < coins.size() **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** coins[i] <= i  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;sub_res = mem[i - coins[j]]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** (sub_res != INT_MAX && sub_res + 1 < res) res = sub_res + 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** mem[V] == INT_MAX **return** -1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** mem[V]  

<p align="justify">
e)	Várias moedas são colocadas em células de um tabuleiro n×m (uma moeda por célula). Um robô, localizado na célula superior esquerda, precisa coletar o máximo de moedas possível e trazê-las para célula inferior direita. Em cada etapa, o robô pode mover qualquer uma das células para a direita ou uma célula abaixo de sua localização atual. Quando o robô visita uma célula com uma moeda, ele sempre pega a moeda. O algoritmo encontra o número máximo de moedas que o robô pode coletar e um caminho que ele precisa seguir para fazer isso.
</p>

Algorthm _maxCoinsRec (A[0...n-1]_ _[0...m-1],i,j)_  
//Input: array qualquer e seus tamanhos  
//Output: número máximo de moedas que o robô pode coletar  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** i < 0 **or** i = n **or** j < 0 **or** j = m **return** 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** A[i][j] + max(maxCoinsRec(A, i + 1, j), maxCoinsRec(A, i, j + 1))   

<p align="justify">
f)	
</p>

Algorthm _maxCoinsRec (A[0...n-1]_ _[0...m-1],mem[0...n-1]_ _[0...m-1],i,j)_  
//Input: array qualquer, seus tamanhos e array para mémoria  
//Output: número máximo de moedas que o robô pode coletar  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** i < 0 **or** i = n **or** j < 0 **or** j = m **return** 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** mem[i][j] != -1 **return** mem[i][j]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mem[i][j] = A[i][j] + max(maxCoinsRec(A, mem, i + 1, j), maxCoinsRec(A, mem, i, j + 1))  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** mem[i][j]

<p align="justify">
g) 
  
Recursivamente:
</p>

Algorthm _knapSack (W,wt[0...m-1],val[0...n-1],n)_  
//Input: capacidade da mochila, pesos e valores associados a n itens  
//Output: número máximo de itens que cabem na mochila  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** n = 0 **or** W = 0 **return** 0   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** wt[n - 1] > W **return** knapSack(W, wt, val, n - 1)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else return** max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));

<p align="justify">
Programação diâmica:	
</p>

Algorthm _knapSack (W,wt[0...m-1],val[0...n-1], mem[0...n-1]_ _[0...W],n)_  
//Input: capacidade da mochila, pesos e valores associados a n itens e array para mémoria   
//Output: número máximo de itens que cabem na mochila  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** n < 0 **return** 0   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** mem[n][W] != -1) **return** mem[n][W]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** wt[n] > W  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mem[n][W] = knapSack(W, wt, val,mem, n - 1)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** mem[n][W]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mem[n][W] = max(val[n] + knapSack(W - wt[n], wt, val, mem, n - 1), knapSack(W, wt, val,mem, n - 1))  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** mem[n][W]

**2. Backtracking**
<p align="justify">
a)	Backtracking é um refinamento de força bruta, no qual boa parte das soluções podem ser eliminadas sem ser explicitamente examinadas. Se aplica em:
</p>

* Problemas cuja solução pode ser definida a partir de uma sequência de decisões.
* Problemas que podem ser modelados por uma árvore que representa todas as possíveis seqüências de decisão. 

<p align="justify">
Se existir mais de uma decisão disponível para cada uma das n decisões, o backtracking será exponencial. A eficiência da estratégia depende da possibilidade de limitar a busca, ou seja, podar a árvore eliminando os ramos que não levam à solução desejada. Para tanto é necessário definir um espaço de solução para o problema que inclua a solução ótima e que possa ser pesquisada de forma organizada (tipicamente como uma árvore). Portanto, é uma técnica com procedimentos de busca que corresponde ao retorno de uma exploração. Ex: Busca em profundidade: Quando chegamos a um nó v pela primeira vez, cada aresta incidente a v é explorada e então o controle volta (backtracks) ao nó a partir do qual v foi alcançado.  
</p>

<p align="justify">
b)	O problema das n-rainhas é colocar N rainhas de xadrez em um tabuleiro de xadrez NxN para que duas rainhas não ataquem uma à outra.
</p>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1) Comece na coluna mais à esquerda  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2) Se todas as rainhas forem colocadas  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;retornar verdadeiro  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3) Experimente todas as linhas da coluna atual.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Faça o seguinte para cada linha experimentada:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;a) Se a rainha puder ser colocada com segurança nesta linha  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;marque esta [linha,coluna] como parte da solução e verifique recursivamente se a posiçãoda rainha leva a uma solução.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;b) Se colocar a rainha em [linha,coluna] leva a uma solução  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;então retorna verdadeiro.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;c) Se a colocação da rainha não levar a uma solução  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;então desmarque esta [linha,coluna] (Backtrack) e vá para etapa (a) para tentar outras linhas.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3) Se todas as linhas foram tentadas e nada funcionou  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;retorna false para acionar o retrocesso.  

<p align="justify">
c)	O algoritmo determina se o grafo pode ser colorido com no máximo m cores, de forma que dois vértices adjacentes do grafo não sejam coloridos com a mesma cor.

Algoritmo:
  
Entrada: Um array [V] [V] onde V é o número de vértices no grafo (matriz de adjacência do grafo) e um inteiro m que é o número máximo de cores que podem ser usadas.

Saída: Um array [V] que deve ter números de 1 a m, representando as cores. O código deve retornar falso se o grafo não puder ser colorido com m cores.
</p>

1 - Crie uma função recursiva que obtém o grafo, o índice atual, o número de vértices e o array de cores.  
2 - Se o índice atual for igual ao número de vértices. Imprima a configuração de cores na matriz de saída.  
3 - Atribua uma cor a um vértice.  
4 - Para cada cor atribuída, verifique se a configuração é segura (ou seja, verifique se os vértices adjacentes não têm a mesma cor) chame recursivamente a função com o próximo índice e número de vértices.  
5 - Se alguma função recursiva retornar true, interrompa o loop e retorne true.  
6 - Se nenhuma função recursiva retornar true, retorne false.

<p align="justify">
d)	Caminho hamiltoniano em um grafo não direcionado é um caminho que visita cada vértice exatamente uma vez.

Algoritmo:

Entrada: Um array [V] [V] onde V é o número de vértices no grafo (matriz de adjacência do grafo).

Saída: Um array [V] que deve conter o Circuito Hamiltoniano. O código deve retornar falso se o grafo não contiver um Circuito Hamiltoniano.
</p>

1 - Criar uma matriz de caminhos e adicionar o vértice 0 a ela.  
2 - Adicionar outros vértices, começando pelo vértice 1. Antes de adicionar um vértice, verifique se ele é adjacente ao vértice adicionado anteriormente e se já não foi adicionado.  
3 - Se encontrar tal vértice, adicionar o vértice como parte da solução. Se não encontrar o vértice, retorne falso.  

**3. Branch and Bound**
<p align="justify">
a)	O método de Branch and bound é um algoritmo para encontrar soluções ótimas para vários problemas de otimização, especialmente em otimização combinatória. Consiste em uma enumeração sistemática de todos os candidatos a solução, através da qual grandes subconjuntos de candidatos que não levam a solução ótima descartados em massa utilizando os limites superior e inferior da quantia otimizada.
O Backtracking retorna a primeira solução encontrada, que na maioria das vezes não é ótima. Enquanto isso, o Branch and bound tenta encontrar soluções ótimas.
</p>

<p align="justify">
b)	O
</p>




<p align="justify">
9)	Uma árvore binária onde cada nó tem no máximo dois filhos. Possui as seguintes propriedades:  
</p>

+ O número máximo de nós no nível l de uma árvore binária é 2<sup>l</sup>. 
+ O número máximo de nós em uma árvore binária de altura h é 2<sup>h</sup> - 1. 
+ Em uma árvore binária com N nós, a altura mínima possível ou o número mínimo de níveis é log<sub>2</sub> (N + 1).   
+ Uma árvore binária com folhas L tem pelo menos |log<sub>2</sub>L| + 1 níveis. 
+ Na árvore binária onde cada nó tem 0 ou 2 filhos, o número de nós folha é sempre um a mais do que nós com dois filhos.

Estrutura da árvore:
<p align="center">
  <img src="https://user-images.githubusercontent.com/81366236/114926019-37514f00-9e06-11eb-81e4-60607d89c2aa.png">
</p>

<p align="justify">
10)	 
</p>

Algorthm _Height (T)_  
//Input: uma árvore binária  
//Output: a altura da árvore  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** T = NULL **return** -1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else return** max{Height(T<sub>left</sub>), Height(T<sub>right</sub>)} + 1  

<p align="justify">
Relação de recorrência: G(n) = 2G(n/2) + 1

Solução da recorrência utilizando o Wolfram Alpha: G(n) = n
  
Portanto, crescimento linear
</p>

<p align="justify">
11)	 
</p>

+ No percurso preorder, a raiz é visitada antes que as subárvores esquerda e direita sejam visitadas (nessa ordem): a, b, d, e, c, f.
+ No percurso inorder, a raiz é visitada depois de visitar sua subárvore esquerda, mas antes de visitar a subárvore direita: d, b, e, a, c, f.
+ No percurso postorder, a raiz é visitada depois de visitar as subárvores esquerda e direita (nessa ordem): d, e, b, f, c, a.

<p align="justify">
12)	 
</p>

Algorthm _Preorder (node)_  
//Imprime o caminho de nós visitados  
//Input: O nó raiz  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** root = NULL **return**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;print(node)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Preorder(left)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Preorder(right)  

Algorthm _Inorder (node)_  
//Imprime o caminho de nós visitados  
//Input: O nó raiz  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** root = NULL **return**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Inorder(left)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;print(node)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Inorder(right)  

Algorthm _Postorder (node)_  
//Imprime o caminho de nós visitados  
//Input: O nó raiz  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** root = NULL **return**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Preorder(left)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Preorder(right)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;print(node)  

<p align="justify">
Relação de recorrência: G(n) = 2G(n/2) + 1

Solução da recorrência utilizando o Wolfram Alpha: G(n) = n
  
Portanto, crescimento linear
</p>


<p align="justify">
13)	 O método de Strassen divide matrizes em submatrizes de tamanho N/2 x N/2, as quatro submatrizes calculadas usando as seguintes fórmulas:
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/81366236/117191901-7cd6bb80-adb7-11eb-864b-b226253b6e51.png">
</p>

+ A, B e C são matrizes quadradas de tamanho N x N.
+ a, b, c e d são submatrizes de A com tamanho N/2 x N/2.
+ e, f, g e h são submatrizes de B com tamanho N/2 x N/2.
+ p1, p2, p3, p4, p5, p6 e p7 são submatrizes com tamanho N/2 x N/2.

<p align="justify">
Se A e B são duas matrizes N x N, N deve ser uma potência de 2. Se N não for uma potência de 2, as matrizes devem ser preenchidas com linhas e colunas de 0.
</p>

Algorthm _Strassen (A[0...n-1], B[0...n-1])_  
//Input: Dois arrays quaisquer de mesmo tamanho  
//Output: AxB  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** n = 1 **return** AxB  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else** Compute a, e, b, f, c, g, d e h (m = n/2)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;P1 = Strassen(A11, B12 − B22)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;P2 = Strassen(A11 + A12, B22)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;P3 = Strassen(A21 + A22, B11)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;P4 = Strassen(A22, B21 − B11)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;P5 = Strassen(A11 + A22, B11 + B22)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;P6 = Strassen(A12 − A22, B21 + B22)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;P7 = Strassen(A11 − A21, B11 + B12)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;C11 = P5 + P4 − P2 + P6  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;C12 = P1 + P2  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;C21 = P3 + P4  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;C22 = P1 + P5 − P3 − P7  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** C

<p align="justify">
Soma: O(n<sup>2</sup>)

Subtração: O(n<sup>2</sup>)

Insert: O(n)

Erase: O(n) 

Juntar: O(n<sup>3</sup>)

Relação de recorrência: G(n) = 7G(n/2) + n<sup>3</sup>
  
Solução da recorrência utilizando o Wolfram Alpha: G(n) = 8n<sup>3</sup>

Portanto, crescimento cúbico
</p>

Algorthm _matrixmul (A[0...n-1], B[0...n-1])_  
//Input: Dois arrays quaisquer  
//Output: AxB  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** i = 0 **to** n - 1 **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** j = 0 **to** n - 1 **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** k = 0 **to** n - 1 **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;C[i][j] += A[i][k]*B[k][j]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** C

<p align="justify">
  A operação básica é executada n - 1 entre 3 laços de repetição
  
  Solução: G(n) = n<sup>3</sup>
  
  Portanto, crescimento cúbico 
  
O algoritmo de divisão e conquista tem o mesmo comportamento assintótico que o de força bruta. Se for possível otimizar a etapa de juntar da divisão e conquista, pode ocorrer redução do crescimento.  
 </p>

<p align="justify">
14)	 O algoritmo QuickHull é semelhante ao Quick Sort. Seja poin[0 … n-1] o array de pontos de entrada. As etapas para encontrar o Convex Hull desses pontos são:

1 - Encontre o ponto com a coordenada x mínimo (min_x), da mesma forma o ponto com a coordenada x máximo (max_x).

2 - Faça uma linha que une estes dois pontos (L). Esta linha dividirá todo o conjunto em duas partes. Pegue as duas partes uma por uma e prossiga.

3 - Para uma parte, encontre o ponto P com distância máxima da linha L. P forma um triângulo com os pontos min_x e max_x. Os pontos que estiverem dentro desse triângulo não fazem parte do Convex Hull.

4 - A etapa acima divide o problema em dois subproblemas (resolvidos recursivamente). Agora a linha que une os pontos P e min_x e a linha que une os pontos P e max_x são novas linhas e os pontos que estáo fora do triângulo formam um conjunto pontos. Repita o passo 3 até que não haja mais nenhum ponto a esquerda da linha. Adicione os pontos finais deste passo ao Convex Hull.

lineDist: O(1)

findSide: O(1)

set.insert: O(constante amortizada)

quickHull: O(n) 

Relação de recorrência: G(n) = 2G(n/2) + n
  
Solução da recorrência utilizando o Wolfram Alpha: G(n) = nlog<sub>2</sub>n

Portanto, crescimento linear logarítmico.

Da lista 2: Força bruta tem crescimento cúbico.
  
O algoritmo de divisão e conquista fica 10<sup>2</sup> vezes mais rápido que o de força bruta para cada vez que uma entrada de 10 elementos é multiplicada por 10.  
</p>
