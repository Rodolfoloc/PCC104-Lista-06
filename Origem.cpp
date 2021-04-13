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
#define AP8

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
AQUI
#endif

#if (defined AP9) || (defined AP10)
#include<iostream>
#include <list>
#include <fstream>

#ifdef AP10
#include <map>
#endif

using namespace std;

#ifdef AP9
//Representa um grafo direcional usando a representação de lista de adjacência
class Graph
{
	int V;    //Número de vértices

	//Matriz de adjacências
	list<int>* adj;
public:
	Graph(int V);

	//Função para adicionar uma borda ao grafo
	void addEdge(int v, int w);

	//Imprime BFS de uma determinada fonte
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	//Marca todos os vértices como não visitados
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	list<int> queue;

	//Marca o nó atual como visitado e o coloca na fila
	visited[s] = true;
	queue.push_back(s);

	//'i' será usado para obter todos os vértices adjacentes de um vértice
	list<int>::iterator i;

	while (!queue.empty())
	{
		//Retira da fila um vértice
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		//Obtem todos os vértices adjacentes desenfileirados
		//Se um vértice adjacente não foi visitado, marque-o como visitado e coloque-o na fila
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}
#endif

#ifdef AP10
class Graph
{
public:
	map<int, bool> visited;
	map<int, list<int>> adj;

	void addEdge(int v, int w);

	void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::DFS(int v)
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}
#endif

int main()
{
#ifdef AP9
	int T;

	cout << "Digite o total de vertices no grafo: ";
	cin >> T;
	cout << endl;

	Graph g(T);
#endif

#ifdef AP10
	Graph g;
#endif

	ifstream fin("BFS.txt ");

	while (!fin.eof()) {
		int Vinicial;
		int Vfinal;
		fin >> Vinicial >> Vfinal;
		g.addEdge(Vinicial, Vfinal);
	}

	fin.close();

	int VI;
	cout << "Digite o vertice inicial: ";
	cin >> VI;
	cout << endl;

	cout << "Ordem de visita: " << endl;

#ifdef AP9
	g.BFS(VI);
#endif

#ifdef AP10
	g.DFS(VI);
#endif

	return 0;
}
#endif