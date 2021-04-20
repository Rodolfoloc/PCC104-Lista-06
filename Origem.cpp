/*Atividade Prática 01: AP1
* Atividade Prática 02: AP2
* Atividade Prática 03: AP3
* Atividade Prática 04: AP4
* Atividade Prática 05: AP5
* Atividade Prática 06: AP6
* Atividade Prática 07: AP7
* Atividade Prática 08: AP8
* Atividade Prática 09: AP9
*/
#define AP4

#if (defined AP1) || (defined AP2) || (defined AP3)
#include<iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
#endif*

#if (defined AP1) || (defined AP3)
template <class T>

void Insertion_Sort(vector<T>& vetor) {
	int i, j;
	T key;

	int n = vetor.size();

	for (i = 1; i < n; i++)
	{
		key = vetor[i];
		j = i - 1;

		//Move os elementos do vetor, que são maiores que a chave, para uma posição à frente de sua posição atual
		while (j >= 0 && vetor[j] > key)
		{
			vetor[j + 1] = vetor[j];
			j = j - 1;
		}
		vetor[j + 1] = key;
	}
}
#endif

#ifdef AP1
int main()
{
	int dado;
	vector<int> vetor;

	ifstream fin("InsertionSort.txt ");

	while (!fin.eof()) {
		fin >> dado;
		vetor.push_back(dado);
	}

	int n = vetor.size();

	cout << "Entrada:" << endl;
	for (int i = 0; i < n; i++) cout << vetor[i] << endl; //Somente para testes

	fin.close();

	Insertion_Sort<int>(vetor);

	cout << endl << "Saida:" << endl;
	for (int i = 0; i < n; i++) cout << vetor[i] << endl;

	return 0;
}
#endif

#if (defined AP2) || (defined AP3)
bool LEFT_TO_RIGHT = true;
bool RIGHT_TO_LEFT = false;
#endif

#ifdef AP3
vector<string> per;

string Converte(vector<int>& a) {
	stringstream ss;
	for (int i = 0; i < a.size(); i++)
		ss << a[i];

	return ss.str();
}
#endif

#if (defined AP2) || (defined AP3)
//Passo 1
int getMobile(vector<int>& a, vector<bool>& dir, int n)
{
	int mobile_prev = 0, mobile = 0;

	for (int i = 0; i < n; i++)
	{
		//0 representa a direção RIGHT TO LEFT.
		if (dir[a[i] - 1] == RIGHT_TO_LEFT && i != 0)
		{
			if (a[i] > a[i - 1] && a[i] > mobile_prev)
			{
				mobile = a[i];
				mobile_prev = mobile;
			}
		}

		//1 0 representa a direção LEFT TO RIGHT.
		if (dir[a[i] - 1] == LEFT_TO_RIGHT && i != n - 1)
		{
			if (a[i] > a[i + 1] && a[i] > mobile_prev)
			{
				mobile = a[i];
				mobile_prev = mobile;
			}
		}
	}

	if (mobile == 0 && mobile_prev == 0)
		return 0;
	else
		return mobile;
}

//Passo 2
void Troca(vector<int>& a, vector<bool>& dir, int n, int mobile)
{
	int pos = 0;

	//Encontra a posição do maior número inteiro móvel em a[] 
	for (int i = 0; i < n; i++)
		if (a[i] == mobile)
			pos = i + 1;

	//Passo 2
	if (dir[a[pos - 1] - 1] == RIGHT_TO_LEFT)
		swap(a[pos - 1], a[pos - 2]);

	else if (dir[a[pos - 1] - 1] == LEFT_TO_RIGHT)
		swap(a[pos], a[pos - 1]);
}

//Passo 3
void Muda(vector<int>& a, vector<bool>& dir, int n, int mobile)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > mobile)
		{
			if (dir[a[i] - 1] == LEFT_TO_RIGHT)
				dir[a[i] - 1] = RIGHT_TO_LEFT;
			else if (dir[a[i] - 1] == RIGHT_TO_LEFT)
				dir[a[i] - 1] = LEFT_TO_RIGHT;
		}
	}

	#ifdef AP2
	for (int i = 0; i < n; i++)	cout << a[i];
	cout << " ";
	#endif

	#ifdef AP3
	string teste = Converte(a);
	per.push_back(teste);
	#endif
}

int main()
{
	cout << "Digite o inteiro positivo da permutacao: ";
	int n;
	cin >> n;

	//Armazena a permutação atual
	vector<int> a(n);

	//Armazena direções atuais
	vector<bool>  dir(n);

	//Armazena os elementos no vetor e imprime a primeira permutação
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	#ifdef AP2
		cout << a[i];
	#endif
	}
	#ifdef AP2
	cout << " ";
	#endif

	#ifdef AP3
	string teste = Converte(a);
	per.push_back(teste);
	#endif

	//Inicialmente todas as direções são definidas como DIREITA->ESQUERDA, ou seja, 0
	for (int i = 0; i < n; i++) dir[i] = RIGHT_TO_LEFT;

	//Parametro de parada
	int fact = 1;
	for (int i = 1; i <= n; i++) fact = fact * i;

	int pos = 0;

	//Gera as permutações
	for (int i = 1; i < fact; i++) {
		int mobile = getMobile(a, dir, n); //Passo 1
		Troca(a, dir, n, mobile); //Passo 2
		Muda(a, dir, n, mobile); //Passo 3
	}

	#ifdef AP3
	cout << endl;

	Insertion_Sort<string>(per);

	cout << endl << "Saida:" << endl;
	for (int i = 0; i < per.size(); i++) cout << per[i] << " ";
	#endif

	return 0;
}
#endif


#ifdef AP4
#include<iostream>
#include <vector>

using namespace std;

//Gera todos os códigos Gray de n bits
vector<string> generateGray(int n)
{
	//Caso base
	if (n <= 0)	return {"0"};

	if (n == 1)	return {"0","1"};

	//Caso recursivo
	vector<string> recAns =	generateGray(n - 1);
	vector<string> mainAns;

	//Anexa 0 à primeira metade
	for (int i = 0; i < recAns.size(); i++)
	{
		string s = recAns[i];
		mainAns.push_back("0" + s);
	}

	//Anexa 1 à segunda metade
	for (int i = recAns.size() - 1; i >= 0; i--)
	{
		string s = recAns[i];
		mainAns.push_back("1" + s);
	}
	return mainAns;
}

int main()
{
	cout << "Digite o inteiro positivo da permutacao: ";
	int n;
	cin >> n;

	vector<string> arr;
	arr = generateGray(n);

	for (int i = 0; i < arr.size(); i++) cout << arr[i] << endl;

	for (int i = 0; i < arr.size(); i++)
	{
		string str = arr[i];
		
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == '1') cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}
#endif

#if (defined AP5) || (defined AP6) || (defined AP7)
#include<iostream>
#include <vector>
#include <fstream>

using namespace std;

#ifdef AP5
int binarySearch(vector<int>& arr,int r, int x)
{
	int l = 0;

	while (l <= r) {
		int m = l + (r - l) / 2;

		//Verifica se x está presente no meio
		if (arr[m] == x) return m;

		//Se x é maior, ignora a metade esquerda
		if (arr[m] < x)	l = m + 1;

		//Se x é menor, ignore a metade direita
		else r = m - 1;
	}

	return -1;
}
#endif

#ifdef AP6
int interpolationSearch(vector<int>& arr, int r, int x)
{
	int pos, l = 0;

	// Since array is sorted, an element present
	// in array must be in range defined by corner
	while (l <= r && x >= arr[l] && x <= arr[r]) {

		// Probing the position with keeping
		// uniform distribution in mind.
		pos = (int)(l + ((((double)r - (double)l) / ((double)arr[r] - (double)arr[l])) * ((double)x - (double)arr[l])));

		// Condition of target found
		if (arr[pos] == x)
			return pos;

		// If x is larger, x is in right sub array
		//if (arr[pos] < x)
		//	return interpolationSearch(arr, pos + 1, hi, x);
		if (arr[pos] < x)	l = pos + 1;

		// If x is smaller, x is in left sub array
		//if (arr[pos] > x)
		//	return interpolationSearch(arr, lo, pos - 1, x);
		else r = pos - 1;
	}
	return -1;
}
#endif

#ifdef AP7
int RecursiveBinarySearch(vector<int>& arr, int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		//Verifica se x está presente no meio
		if (arr[mid] == x) return mid;

		int soma_r = 0, soma_l = 0;

		for (int i = mid + 1; i <= r; i++) soma_r += arr[i];

		for (int i = 0; i < mid; i++) soma_l += arr[i];

		//Se soma_r é maior, ignora a metade esquerda
		if (soma_r > soma_l) return RecursiveBinarySearch(arr, l, mid - 1, x);

		//Se soma_r é menor, ignore a metade direita
		return RecursiveBinarySearch(arr, mid + 1, r, x);
	}

	return -1;
}
#endif

int main(void)
{
	int dado;
	vector<int> vetor;

	#ifdef AP5
	ifstream fin("BinarySearch.txt ");
	#endif

	#ifdef AP6
	ifstream fin("InterpolationSearch.txt ");
	#endif

	#ifdef AP7
	ifstream fin("Coin.txt ");
	#endif

	while (!fin.eof()) {
		fin >> dado;
		vetor.push_back(dado);
	}

	int n = vetor.size();

	cout << "Entrada:" << endl;
	for (int i = 0; i < n; i++) cout << vetor[i] << " "; //Somente para testes

	fin.close();

	#if (defined AP5) || (defined AP6)
	cout << endl << "Digite a chave: ";
	int x;
	cin >> x;
	#endif
	
	#ifdef AP5
	int result = binarySearch(vetor, n - 1, x);
	#endif

	#ifdef AP6
	int result = interpolationSearch(vetor, n - 1, x);
	#endif

	#ifdef AP7
	int result = RecursiveBinarySearch(vetor, 0, n - 1, 0);
	#endif

	if (result == -1) cout << "Elemento nao encontrado";
	else cout << "Elemento encontrado no indice " << result;

	return 0;
}
#endif

#ifdef AP8
#include<iostream>
#include <vector>
#include <fstream>

using namespace std;

int LomutoPartition(vector<int>& A, int l, int r)
{
	int p = A[l];
	int s = l;
	for (int i = l + 1; i <= r; i++) {
		if (A[i] < p) {
			s += 1;
			swap(A[s], A[i]);
		}
	}

	swap(A[l], A[s]);

	return s;
}

int quickselect(vector<int>& A, int l, int r, int k)
{
	int s = LomutoPartition(A, l, r);

	if (s == k - 1) return A[s];
	else if (s < k) quickselect(A, s + 1, r, k);
	else quickselect(A, l, s - 1, k);
}

int main()
{
	int dado;
	vector<int> vetor;

	ifstream fin("Dados.txt ");

	while (!fin.eof()) {
		fin >> dado;
		vetor.push_back(dado);
	}

	int n = vetor.size();

	cout << "Entrada:" << endl;
	for (int i = 0; i < n; i++) cout << vetor[i] << " "; //Somente para testes

	fin.close();

	int N = 0;

	if (n % 2 == 0) N = n / 2;
	else N = (int)(n / 2) + 1;

	int r = quickselect(vetor, 0, n - 1, N);

	cout << endl << "Mediana: " << r;

	cout << endl << "Entrada:" << endl;
	for (int i = 0; i < n; i++) cout << vetor[i] << " "; //Somente para testes

	return 0;
}
#endif

#ifdef AP9
#include <iostream>

using namespace std;

class BST
{
	//Componentes dos nós
	int data;
	BST *left;
	BST *right;

	public:
		//Construtores
		BST(); 
		BST(int); 

		BST* Insert(BST*, int); //Inserir um valor
		
		BST* Search(BST*, int); //Buscar um valor
};

BST::BST()
{
	data = 0;
	left = right = NULL;
}

BST::BST(int value)
{
	data = value;
	left = right = NULL;
}

BST* BST::Insert(BST* root, int value)
{
	if (!root) return new BST(value); //Insere a raiz (Se root é NULL)

	//Obs: px -> membro //Retorna o valor do membro apontado por px.
	if (value > root->data) root->right = Insert(root->right, value);
	else root->left = Insert(root->left, value);

	//Retorna o nó 'raiz', após a inserção
	return root;
}

BST* BST::Search(BST* root, int key)
{
	if (!root || root->data == key)	return root;

	if (root->data < key) return Search(root->right, key);

	return Search(root->left, key);
}

int main()
{
	BST Tree; //Cria a árvore
	BST *root = NULL; //Cria um ponteiro para a raiz da árvore
	
	root = Tree.Insert(root, 50);
	Tree.Insert(root, 30);
	Tree.Insert(root, 20);
	Tree.Insert(root, 40);
	Tree.Insert(root, 70);
	Tree.Insert(root, 60);
	Tree.Insert(root, 80);

	BST* M = Tree.Search(root, 5);
	
	if (M) cout << "O elemento esta presente na arvore";
	else cout << "O elemento nao esta presente na arvore";

	return 0;
}
#endif