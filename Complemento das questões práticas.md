# PCC104
## Projeto e análise de algoritmos

Complemento das questões práticas:

<p align="justify">
1)	Merge Sort é um algoritmo de ordenação que divide o array de entrada em duas metades, chama a si mesmo para as duas metades e, em seguida, mescla as duas metades classificadas.
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

ALGORITHM Mergesort(A[0..n − 1])
//Sorts array A[0..n − 1] by recursive mergesort
//Input: An array A[0..n − 1] of orderable elements
//Output: Array A[0..n − 1] sorted in nondecreasing order
if n > 1
copy A[0..n/2 − 1] to B[0..n/2 − 1]
copy A[n/2..n − 1] to C[0..n/2 − 1]
Mergesort(B[0..n/2 − 1])
Mergesort(C[0..n/2 − 1])
Merge(B, C, A) //see below

ALGORITHM Merge(B[0..p − 1], C[0..q − 1], A[0..p + q − 1])
//Merges two sorted arrays into one sorted array
//Input: Arrays B[0..p − 1] and C[0..q − 1] both sorted
//Output: Sorted array A[0..p + q − 1] of the elements of B and C
i ←0; j ←0; k←0
while i <p and j <q do
if B[i]≤ C[j ]
A[k]←B[i]; i ←i + 1
else A[k]←C[j ]; j ←j + 1
k←k + 1
if i = p
copy C[j..q − 1] to A[k..p + q − 1]
else copy B[i..p − 1] to A[k..p + q − 1]





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
3)	Imprime todas as permutações ordenadas de forma crescente (lexicográfica). Aplicando o Insertion sort a saída do algoritmo Johnson-Trotter, obtém-se uma solução para o Lexicographic Permute com o mesmo custo do livro O(n<sup>2</sup>xn!). Aplicando outros algoritmos de ordenação, seu custo pode ser otimizado para O(nxn!).
</p>

<p align="justify">
4)	O Binary Reflected Gray Code utiliza uma abordagem recursiva para gerar o código Gray. O código de Gray é um sistema binário onde de um número para outro apenas um bit varia. A ideia é anexar recursivamente os bits 0 e 1 até que o número de bits não seja igual a n. 
</p>

<p align="justify">
Condição base: O caso base para este problema será quando o valor de n = 0 ou 1.
</p>

<p align="justify">
Condição recursiva: Para qualquer valor maior que 1, gere recursivamente os códigos Gray dos n - 1 bits e, em seguida, para cada um dos códigos Gray gerados, adicione o prefixo 0 e 1.
</p>

Algorthm _BRGC(n)_  
//Input: Um inteiro positivo qualquer  
//Output: Uma lista de todas as cadeias de bits de comprimento n compondo o código Gray  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** n = 1 faça a lista L contendo cadeias de bits 0 e 1 nesta ordem  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else** gere a lista L1 de sequências de bits de tamanho n - 1 chamando BRGC (n - 1)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;copie a lista L1 para a lista L2 na ordem inversa  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;adicione 0 na frente de cada string de bits na lista L1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;adicione 1 na frente de cada string de bits na lista L2  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;anexe L2 a L1 para obter a lista L  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** L

<p align="justify">
5)	A Binary Search pesquisa um array ordenado dividindo repetidamente o intervalo da pesquisa pela metade. Comece com um intervalo cobrindo todo o array. Se o valor da chave for menor que o item no meio do intervalo, restrinja o intervalo à metade inferior. Caso contrário, estreite-o para a metade superior. Verifique repetidamente até que o valor seja encontrado ou o intervalo esteja vazio. Exemplo :
</p>

![Binary-Search](https://user-images.githubusercontent.com/81366236/114305989-c120b580-9ab0-11eb-9f6e-bb197739fc7c.png)

Algorthm _BinarySearch(A[0..n − 1], K)_  
// Input: Um array qualquer ordenado crescente e uma chave    
// Output: Índice do array é igual a chave ou -1 se não houver tal elemento  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;l = 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;r = n − 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**while** l <= r **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;m = (l + r) / 2  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** K = A[m] **return** m  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else if** K < A[m] r = m − 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else** l = m + 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** -1

<p align="justify">
6)	Interpolation Search é um aprimoramento da Binary Search. A Binary Search sempre vai para o elemento do meio para verificar. Por outro lado, a Interpolation Search pode ir para locais diferentes de acordo com o valor da chave que está sendo pesquisada. O algoritmo imita a maneira como procuramos por um nome em uma lista telefônica: se estivermos procurando por alguém chamado Brown, abrimos o livro não no meio, mas muito perto do início, ao contrário da nossa ação ao procurar alguém chamado, Smith. A posição é calculada da seginte forma:
</p>

<p align="center">
  <img src="https://latex.codecogs.com/svg.latex?\Large&space;pos=l+\frac{(x-arr[l])(r-l)}{arr[r]-arr[l]}">
</p>

<p align="justify">
7)	Fake Coin Problem: Existem n moedas idênticas. Uma moeda é falsa e pesa menos do que as moedas reais. A única maneira de comparar moedas é uma balança. Utilizando a Recursive Binary Search: 
</p>

Algorthm _RecursiveBinarySearch(A[0..n − 1], l, r, K)_  
// Input: Um array qualquer contendo um número para moedas verdadeiras e um número menor para a moeda falsa, a menor e a maior posição do vetor, o número que representa a moeda falsa  
// Output: Índice do array que contém a moda falsa ou -1 se não houver moeda falsa  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;l = 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;r = n − 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** (r >= l)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;m = (l + r) / 2  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** K = A[m] **return** m  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** sum(r) > sum(l) **return** RecursiveBinarySearch(A[0..n − 1], l, m - 1, K)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** RecursiveBinarySearch(A[0..n − 1], l, m + 1, K)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** -1

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
