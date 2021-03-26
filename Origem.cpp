/*Atividade Prática 01: AP1
* Atividade Prática 02: AP2
* Atividade Prática 03: AP3
* Atividade Prática 04: AP4
* Atividade Prática 05: AP5
* Atividade Prática 06: AP6
* Atividade Prática 07: AP7
* Atividade Prática 08: AP8
* Atividade Prática 09: AP9
* Atividade Prática 10: AP10
*/
#define AP9

#if (defined AP1) || (defined AP2) || (defined AP3)
#include<iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	int dado;
	vector<int> vetor;

	ifstream fin("dados.txt ");

	while (!fin.eof()) {
		fin >> dado;
		vetor.push_back(dado);
	}

	int n = vetor.size();

	cout << "Entrada:" << endl;
	for (int i = 0; i < n; i++) cout << vetor[i] << endl; //Somente para testes

	fin.close();

	#ifdef AP1
	//Bubble Sort
	int i, j, temp, pass = 0;

	for (i = 0; i < n; i++) {
		for (j = i + 1; j < 10; j++)
		{
			if (vetor[j] < vetor[i]) {
				temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
		pass++;
	}
	
	cout << endl << "Saida:" << endl;
	for (int i = 0; i < n; i++) cout << vetor[i] << endl;
	#endif

	#ifdef AP2
	//Selection Sort
	int temp, pass = 0;

	for (int i = 0; i < n; i++)
	{
		int ele_small, position, j;
		ele_small = vetor[i];
		position = i;

		for (j = i + 1; j < n; j++)
		{
			if (vetor[j] < ele_small)
			{
				ele_small = vetor[j];
				position = j;
			}
		}

		temp = vetor[i];
		vetor[i] = vetor[position];
		vetor[position] = temp;
		pass++;
	}

	cout << endl << "Saida:" << endl;
	for (int i = 0; i < n; i++) cout << vetor[i] << endl;
	#endif

	#ifdef AP3
	//Sequential Search
	int key;
	int loc = -1;

	cout << "Chave: ";
	cin >> key;

	for (int i = 0; i < 10; i++)
	{
		if (vetor[i] == key) loc = i;
	}

	if (loc == -1) cout << "Chave nao encontrada";
	else cout << "Posicao " << loc;
	#endif

	return(0);
}
#endif

#ifdef AP4
#include<iostream>
#include <fstream>
#include <vector>

using namespace std;

char txt;
vector<char> vetor_char;
char* char_arr;

int main()
{
	ifstream fin_char("dadostexto.txt ");

	while (!fin_char.eof()) {
		fin_char >> txt;
		vetor_char.push_back(txt);
	}

	int N = vetor_char.size();

	cout << "Entrada:" << endl;
	for (int i = 0; i < N; i++) cout << vetor_char[i] << endl; //Somente para testes

	fin_char.close();

	//BruteForceStringMatch
   string inputString;

   cout << "Termo: ";
   cin >> inputString;
   char_arr = &inputString[0];

   vector<char> words(strlen(char_arr));
   bool loc = false;

   for (unsigned int i = 0; i < strlen(char_arr); i++) words[i] = char_arr[i];

   int M = words.size();

   //Percorre words um a um
   for (int i = 0; i <= N - M; i++) {
	   int j;

	   //verifica correspondências
	   for (j = 0; j < M; j++)
		   if (vetor_char[i + j] != words[j]) break;

	   if (j == M) { // if words[0...M-1] = vetor_char[i, i+1, ...i+M-1]
		   cout << "Palavra encontrada no indice: " << i << endl;
		   loc = true;
	   }
   }

   if (!loc) cout << "Palavra nao encontrada";
}
#endif

#if (defined AP5) || (defined AP6)
#include<iostream>
#include <fstream>
#include <vector>
#include <string>

#ifdef AP6
	#include <set>
#endif

using namespace std;

struct Point { double x, y; };
vector<Point> poin;
int pNum;

#ifdef AP6
set<pair<int, int>> convex;
#endif

#ifdef AP5
	double calDist(Point p1, Point p2)
	{
		return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
	}
#endif

#ifdef AP6
	int judge(Point p1, Point p2, Point p3)
	{
		double flag = p1.x * p2.y + p3.x * p1.y + p2.x * p3.y - p3.x * p2.y - p2.x * p1.y - p1.x * p3.y;
		if (flag > 0) return 1;
		else if (flag == 0) return 2;
		else return 0;
	}
#endif


int main()
{
	string line;
	ifstream fin_point("Pontos.txt");

	if (fin_point.is_open())
	{
		getline(fin_point, line);
		pNum = stoi(line);
		int i = 0;

		while (getline(fin_point, line))
		{
			double x = stod(line.substr(0, line.find(" ")));
			double y = stod(line.substr(line.find(" ")));
			Point pTemp;
			pTemp.x = x;
			pTemp.y = y;
			poin.push_back(pTemp);
			i++;
		}
		fin_point.close();
	}
	else cout << "Os pontos nao foram lidos" << endl;

	int n = poin.size();

	cout << "Entrada:" << endl;
	for (int i = 0; i < n; i++) cout << "(" << poin[i].x << "," << poin[i].y << ")" << endl; //Somente para testes
	
#ifdef AP5
		//BruteForceClosestPair
		vector<Point> minPoints;

		if (n >= 2)//else
		{
			double min = calDist(poin[0], poin[1]);
			Point p1 = poin[0], p2 = poin[1];
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
				{
					double distpp = calDist(poin[i], poin[j]);

					if (distpp < min) {
						min = distpp;
						p1 = poin[i];
						p2 = poin[j];
					}
				}		
			minPoints.push_back(p1);
			minPoints.push_back(p2);
		}

		double distMin = calDist(minPoints[0], minPoints[1]);
		cout << "Pontos mais proximos: (" << minPoints[0].x << "," << minPoints[0].y << ") (" << minPoints[1].x << "," << minPoints[1].y << ")" << endl;
		cout << "Distancia entre eles: " << distMin << endl;
	#endif

	#ifdef AP6
		//convex hull
		for (int i = 0; i < n; i++)
		{
			int t = 0;

			for (int j = 0; j < n; j++)
			{
				int flag = -1;
				if (i == j) continue;

				for (int k = 0; k < n; k++)
				{
					if (k == i || k == j) continue;

					if (flag == -1) flag = judge(poin[i], poin[j], poin[k]);
					else
					{
						int temp = judge(poin[i], poin[j], poin[k]);
						if (flag == temp || temp == 2) t = 1;
						else
						{
							t = 0;
							break;
						}
					}
				}

				if (t) convex.insert(make_pair(poin[j].x, poin[j].y));
			}

			if (t) convex.insert(make_pair(poin[i].x, poin[i].y));
		}

		set<pair<int, int> >::iterator it = convex.begin();

		cout << "Saida:" << endl;
		while (it != convex.end())
		{
			cout << "(" << it->first << "," << it->second << ")" << endl;
			it++;
		}
	#endif
}
#endif

#ifdef AP7
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define V 4
#define P 4

using namespace std;

int dado;
vector<int> vertex;
int graph[P][V];
int i = 0;
int j = 0;

int main()
{
	ifstream fin("graph.txt ");

	while (!fin.eof()) {
		if (j == V) {
			j = 0;
			i++;
		}

		fin >> dado;
		graph[i][j] = dado;

		j++;	
	}

	cout << "Entrada:" << endl;
	for (int i = 0; i < P; i++) {
		for (int j = 0; j < V; j++) cout << graph[i][j] << endl; //Somente para testes
	}

	fin.close();

	//Traveling Salesman Problem
	int s = 0;

	for (int i = 0; i < V; i++)
		if (i != s) vertex.push_back(i);

	int min_path = INT_MAX;
	do {

		//Armazena peso do caminho atual (custo)
		int current_pathweight = 0;

		//Calcula o peso do caminho atual
		int k = s;
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
		}
		current_pathweight += graph[k][s];

		min_path = min(min_path, current_pathweight);

	} while (next_permutation(vertex.begin(), vertex.end()));

	cout << "Saida:" << endl;
	cout <<endl << min_path << endl;

	return 0;
}
#endif

#ifdef AP8
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

typedef unsigned int uint;
int dado;

int main()
{
	uint capacity;
	uint user_in = 0;
	vector<uint> weights;
	vector<uint> values;

	cout << "Digite a capacidade da mochila: ";
	cin >> capacity;
	cout << endl;

	ifstream fin("knapsack.txt ");

	while (!fin.eof()) {
		uint weight;
		uint value;
		fin >> weight >> value;
		
		weights.push_back(weight);
		values.push_back(value);
		user_in++;
	}

	fin.close();

	uint v_size = weights.size();
	uint bit_w = 1;
	uint basic_op = 0;
	uint input_size = weights.size() + values.size();
	//Knapsack Problem
	for (uint i = 0; i < (bit_w << v_size); i++)
	{
		uint sum = 0;
		uint value = 0;
		uint col_size = 0;
		cout.setf(ios::left);
		cout.width(1);
		cout << "{";

		for (uint j = 0; j < v_size; j++)
		{
			basic_op++;
			//Se o item j deve ser incluído no subconjunto i, some o peso e valor
			if (i & (bit_w << j))
			{
				sum += weights[j];
				value += values[j];
				cout.width(2);
				cout << j;
				col_size++;
			}
		}
		cout.setf(ios::right);
		cout.width(2);
		cout << "}";

		//Compara o número de entradas para alinhar as colunas
		for (uint v = 0; v < user_in - col_size; v++)
		{
			cout.setf(ios::left);
			cout.width(2);
			cout << "";
		}
		//Alinha coluna peso e valor
		cout.setf(ios::right);
		cout.width(5);
		cout << sum << " ";
		cout.setf(ios::left);
		cout.width(5);

		if (sum > capacity) cout << "NF" << endl;
		else cout << value << endl;
	}
	cerr << input_size << setw(8) << basic_op << endl;
}
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

	cout << "Ordem de visita: "<< endl;

#ifdef AP9
	g.BFS(VI);
#endif

#ifdef AP10
	g.DFS(VI);
#endif

	return 0;	
}
#endif