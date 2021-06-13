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
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** n == 0 || n == 1 **return** n  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** Fib(n - 1) + Fib(n - 2)  

<p align="justify">
c)	
</p>

Algorthm _Fibonacci (n)_  
//Input: n-ésimo número de Fibonacci  
//Output: seu valor  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;f[n + 2]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;f[0] = 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;f[1] = 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** i = 2 **to** i <= n **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;f[n] = Fib(n - 1) + Fib(n - 2)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** f[n] 

<p align="justify">
d)	
</p>

<p align="justify">
4)	
</p>

Algorthm _mergemax (A[0...n-1],l,r)_  
//Input: array qualquer e seus índices inicial e final  
//Output: o índice do maior elemento do array  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** l < r  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;m = l + (r - l) / 2  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;maxLeft = mergemax(A, l, m)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;maxRight = mergemax(A, m + 1, r)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** max(A, maxLeft, maxRight)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** max(A, l, r);  

Algorthm _max (A[0...n-1],l,r)_  
//Input: array qualquer e seus índices inicial e final  
//Output: o índice do maior elemento do subarray  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** A[l] > A[r] **return** l  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else return** r  

<p align="justify">
a) Em um algoritmo estável, quando vários elementos do arranjo tiverem o mesmo valor, a saída do método deve ter em seu menor índice o primeiro elemento que aparece (considerando o intervalo de elementos iguais), e assim em diante até o fim do intervalo.
</p>

<p align="justify">
b) Relação de recorrência: G(n) = G(n/2) + 1
  
  Solução da recorrência utilizando o Wolfram Alpha: G(n) = log<sub>2</sub>n
  
  Portanto, crescimento logarítmico
</p>

<p align="justify">
c)  
</p>

Algorthm _maxA (A[0...n-1],n)_  
//Input: array qualquer e seu tamanho  
//Output: o índice do maior elemento do array  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** n = 1 **return** 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** A[0] > A[1] max = 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else** max = 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** i = 2 **to** n - 1 **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** A[i] >= A[max] max = i  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** max 

<p align="justify">
  A operação básica é executada n - 2 vezes
  
  Solução: G(n) = n
  
  Portanto, crescimento linear 
  
O algoritmo de divisão e conquista é aproximadamente 0,69 vezes mais rápido que o de força bruta.  
 </p>

<p align="justify">
5)	
</p>

Algorthm _mergemaxmin (A[0...n-1],l,r,min,max)_  
//Input: array qualquer, seus índices inicial e final, menor e maior elemento do dado   
//Output: valor mínimo e máximo do array  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** l = r  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** max < A[l] max = A[l]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** min > A[r]) min = A[r]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** r - l = 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** A[l] < A[r])  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** min > A[l]) min = A[l]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** max < A[r]) max = A[r]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else**   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** min > A[r]) min = A[r]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** max < A[l]) max = A[l]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;m = l + (r - l) / 2  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mergemaxmin(A, l, m, min, max)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mergemaxmin(A, m + 1, r, min, max)  

<p align="justify">
a) Relação de recorrência: G(n) = G(n/2) + n - 2
  
  Solução da recorrência utilizando o Wolfram Alpha: G(n) = 2n
  
  Portanto, crescimento linear
</p>

<p align="justify">
b)  
</p>

Algorthm _minmax (A[0...n-1],n,min,max)_  
//Input: array qualquer, seu tamanho, menor e maior elemento do dado     
//Output: o índice do menor e do maior elemento do array  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** n = 1   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;max = A[0]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;min = A[0]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** minmax  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** i = 0 **to** n - 1 **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** A[i] > max max = A[i]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else** A[i] < min min = A[i]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** minmax 
    
<p align="justify">
  A operação básica é executada n - 1 vezes
  
  Solução: G(n) = n
  
  Portanto, crescimento linear 
  
O algoritmo de divisão e conquista tem o mesmo comportamento assintótico que o de força bruta.  
 </p>

<p align="justify">
6)	O quick sort seleciona um elemento como pivô e particiona o array fornecido ao redor do pivô selecionado. Existem muitas versões diferentes do quickSort que selecionam o pivô de maneiras diferentes:
</p>

* Primeiro elemento como pivô.
* Último elemento como pivô
* Elemento aleatório como pivô.
* Mediana como pivô (Implementado).

<p align="justify">
O principal processo no quickSort é a partição. O objetivo das partições é, dado um array e um pivô x, colocar x em sua posição correta na matriz classificada de forma que todos os elementos menores que x fiquem a esquerda e todos os elementos maiores que x fiquem a direita.
</p>

Algorthm _partition (A[0...n-1],l,r,i,j)_  
//Input: array qualquer, seus índices inicial e final, índices dos sub-arranjos após a partição  
//Output: parte do array ordenado  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;i = l  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;j = r  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pivot = A[(i + j) / 2]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**do**   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**while** pivot > A[i] ++i  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**while** pivot < A[j] --j  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** i <= j  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;swap(A[i],A[j])  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;++i  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--j  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**while** i <= j  

Algorthm _quicksort (A[0...n-1],l,r)_  
//Input: array qualquer e seus índices inicial e final
//Output: array ordenado  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;i = 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;j = 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;partition(A, l, r, i, j)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** l < j quicksort(A, l, j)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** i < r quicksort(A, i, r)  

<p align="justify">
Relação de recorrência: G(n) = 2G(n/2) + n

Solução da recorrência utilizando o Wolfram Alpha: G(n) = nlog<sub>2</sub>n
  
Portanto, crescimento logarítmico linear
</p>

<p align="justify">
7)	O algoritmo partition desloca o índice i até encontrar o primeiro elemento A[i] maior ou igual ao pivô e o índice j até encontrar o primeiro elemento A[j] menor ou igual ao pivô. Troca-se a[i] com a[j] enquanto os índices i e j não se cruzarem. As indicações P1 e P2 indicam essas trocas:
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/81366236/117058520-18532800-acf5-11eb-98b7-96c3b9d87c7d.png">
</p>

<p align="justify">
8)	O exemplo da questão anterior mostra que o quick sort não é estável, pois na segunda chamada do método ele troca o primeiro 'E' com o 'A', colocando-o na terceira posição. Desta forma, o primeiro 'E' que aparece ocupa a segunda posição do intervalo, mostrando assim que não é um algoritmo estável.
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
