# PCC104
## Projeto e análise de algoritmos

Complemento das questões práticas:

<p align="justify">
1)	Merge Sort é um algoritmo de ordenação que divide o array de entrada em duas metades, chama a si mesmo para as duas metades e, em seguida, mescla as duas metades classificadas.
</p>

Algorthm _mergeSort (A[0...n-1],l,r)_  
//Input: array qualquer e seus índices inicial e final  
//Output: array ordenado crescente  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** l >= r **return**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;m = l + (r - l) / 2  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mergeSort(A, l, m)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mergeSort(A, m + 1, r)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;merge(A, l, m, r)  

Algorthm _merge (A[0...n-1],l,m,r)_  
//Input: array qualquer e seus índices inicial, meio e final  
//Output: subarray ordenado crescente  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;n1 = m - l + 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;n2 = r - m  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;copy A[0...m] to L   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;copy A[0...m + 1] to R   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;i = 0; j = 0; k = l  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**while** i < n1 **and** j < n2  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** L[i] <= R[j]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A[k] = L[i]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;i++  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A[k] = R[j]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;j++  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;k++  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;copy L to A[i...n1 - 1]    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;copy R to A[j...n2 - 1] 

<p align="justify">
2)	
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/81366236/116818820-a9829d00-ab43-11eb-98d1-8c85a75a05c1.png">
</p>

<p align="justify">
3)	O Merge Sort é um algoritmo estável, pois caso existam elementos repetidos, ele coloca o elemento que aparece primeiro antes do elemento que aparece em seguida.
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
a) Quando vários elementos do arranjo tiverem o maior valor a saída do método será o maior índice que contém o maior elemento, pois o algoritmo é estável.
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
6)	
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
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;temp = A[i]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A[i] = A[j]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A[j] = temp  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;++i  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--j  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**while** i <= j  

Algorthm _quicksort (A[0...n-1],l,r)_  
//Input: array qualquer e seus índices inicial e final
//Output: array ordenado  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;i = 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;j = 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;partition(A, l, r, i, j)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** l < j quicksort(A, l, j)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** i < r quicksort(A, i, r)  

<p align="justify">
7)	 
</p>



<p align="justify">
8)	Este algoritmo funciona em duas etapas. A etapa de particionamento escolhe um elemento pivô e, em seguida, reorganiza os elementos da matriz de modo que tudo o que for menor que o pivô fique a esquerda; tudo que for maior que o pivô fique a direita; e o pivô esteja no lugar correto. Para encontrar medianas, basicamente, deve-se chamar recursivamente a função de partição, até que o pivô alcance a posição N / 2. Obs: Usando o algoritmo de seleção, é possível encontrar qualquer K-ésimo menor elemento.
</p>

Algorthm _LomutoPartition(A[0..n − 1], l, r)_  
// Input: Um array qualquer ou um subarray do array  
// Output: A nova posição do pivô  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;p = A[l]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;s = l  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**for** i = l + 1 **to** r **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** A[i] < p  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;s = s + 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;swap(A[s], A[i])  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;swap(A[l], A[s])  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** s  

Algorthm _Quickselect(A[0..n − 1], l, r, k)_  
// Input: Um array qualquer e uma posição do array  
// Output: O valor do k-ésimo menor elemento do array  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;s = LomutoPartition(A, l, r)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** s = k - 1 **return** A[s]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else if** s < k quickselect(A, s + 1, r, k)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else** quickselect(A, l, s - 1, k)

<p align="justify">
9)	Uma árvore de pesquisa binária (BST) é definida como uma árvore binária baseada em nós que possui as seguintes propriedades:  
</p>

+ A subárvore esquerda de um nó contém apenas nós com valores menores que o valor do nó;
+ A subárvore direita de um nó contém apenas nós com valores maiores que o valor do nó.
+ As subárvores esquerda e direita também devem ser árvore de pesquisa binária. 
+ Não deve haver nós duplicados.

Estrutura da árvore:
<p align="center">
  <img src="https://user-images.githubusercontent.com/81366236/114926019-37514f00-9e06-11eb-81e4-60607d89c2aa.png">
</p>

<p align="justify">
Inserir um valor

Sempre inserir na folha. Pesquisar um valor da raiz até um nó folha. Depois que um nó folha adequado é encontrado, o novo nó é adicionado como filho do nó folha.
</p>

Algorthm _Insert Tree (root, value)_  
//Input: O nó raiz e um valor qualquer para ser inserido no novo nó  
//Output: O nó raiz após a inserção  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** root = NULL **return** BST(value)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** value > root.data root.right = Insert Tree(root.right, value)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else** root.left = Insert Tree(root.left, value)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** root  

<p align="justify">
Buscar um valor

Para pesquisar um número, começar pela raiz, comparar o valor a ser pesquisado com o valor da raiz. Se for igual termine a pesquisa. Se for menor, ir para a subárvore esquerda, caso contrário ir para a subárvore direita. Portanto, pesquisar um elemento na árvore é basicamente um percurso em que a cada passo deve-se ir para a esquerda ou para a direita. A cada passo uma das subárvores é descartada até que o espaço de busca seja reduzido a apenas um nó.
</p>

Algorthm _Search Tree (root, key)_  
//Input: O nó raiz e um valor qualquer a ser pesquisado  
//Output: O nó contendo o valor pesquisado ou NULL se o valor não foi encontrado  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** root = NULL **or** root.data = key **return** root  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** root.data < key  **return** Search Tree (root.right, key)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** Search(root.left, key)  
