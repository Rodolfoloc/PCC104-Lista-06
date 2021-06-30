/*Atividade 1b: A1b
* Atividade 1c: A1c
* Atividade 1d: A1d
* Atividade 1e: A1e
* Atividade 1f: A1f
* Atividade 1g: A1g
* Atividade 2b: A2b
* Atividade 2c: A2c
* Atividade 2d: A2d
* Atividade 3b: A3b
* Atividade 3c: A3c
*/

#define A3c

#ifdef A1b
#include <iostream>

using namespace std;

template <typename T> T Fib(T n)
{
    if (n <= 1) return n;
    return Fib(n - 1) + Fib(n - 2);
}

int main()
{
    cout << "Digite o n-esimo numero de Fibonacci: ";
    int n;
    cin >> n;

    int result = Fib(n - 1);

    cout << result;

    return 0;
}
#endif

#ifdef A1c
#include <iostream>
#include <vector>

using namespace std;

template <typename T> T Fib(T n, vector<T>& mem)
{
    if (mem[n] != -1) return mem[n];
    else if (n <= 1) mem[n] = n;
    else mem[n] = Fib(n - 1, mem) + Fib(n - 2, mem);
    return mem[n];
}

int main()
{
    cout << "Digite o n-esimo numero de Fibonacci: ";
    int n;
    cin >> n;

    vector<int> mem(n,-1);

    int result = Fib(n - 1, mem);

    cout << result;

    return 0;
}
#endif

#ifdef A1d
#include <iostream>
#include <vector>

using namespace std;

int minCoins(vector<int>& coins, int V)
{
    //Caso base
    if (V == 0) return 0;

    int res = INT_MAX;

    //Experimenta todas as moedas com valor menor que V
    for (size_t i = 0; i < coins.size(); i++)
    {
        if (coins[i] <= V)
        {
            int sub_res = minCoins(coins, V - coins[i]);

            //Verifica INT_MAX para evitar estouro e ve se o resultado pode ser minimizado
            if (sub_res != INT_MAX && sub_res + 1 < res) res = sub_res + 1;
        }
    }
    return res;
}

int minCoinsP(vector<int>& coins, int V)
{
    vector<int> mem(V + 1, INT_MAX);
    
    //Caso base
    mem[0] = 0;

    //Experimenta todas as moedas com valor menor que V
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < coins.size(); j++)
            if (coins[j] <= i)
            {
                int sub_res = mem[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < mem[i]) mem[i] = sub_res + 1;
            }
    }

    if (mem[V] == INT_MAX) return -1;

    return mem[V];
}

int main()
{
    vector<int> coins = { 9, 6, 5, 1 };
    int V = 11;
    
    //int result = minCoins(coins, V); //Resursivo
    int result = minCoinsP(coins, V); //PD
    
    cout << "Minimo de moedas: " << result;
    
    return 0;
}
#endif

#ifdef A1e
#include <iostream>
#include <vector>

using namespace std;

int maxCoinsRec(vector<vector<int>>& coins, int i, int j)
{
    //Células inválidas
    if(i < 0 || i == coins.size() || j < 0 || j == coins[i].size()) return 0;

    return coins[i][j] + max(maxCoinsRec(coins, i + 1, j), //Abaixo
        maxCoinsRec(coins, i, j + 1)); //Em frente a direita
}

int main()
{
    vector<vector<int>> coins = { {0, 0, 0, 0, 1, 0},
                                  {0, 1, 0, 1, 0, 0},
                                  {0, 0, 0, 1, 0, 1},
                                  {0, 0, 1, 0, 0, 1},
                                  {1, 0, 0, 0, 1, 0} };

    int result = maxCoinsRec(coins, 0, 0);

    cout << "Maximo de moedas coletadas: " << result;
    return 0;
}
#endif

#ifdef A1f
#include <iostream>
#include <vector>

using namespace std;

int maxCoinsRec(vector<vector<int>>& coins, vector<vector<int>>& mem, int i, int j)
{
    if (i < 0 || i == coins.size() || j < 0 || j == coins[i].size()) return 0;

    if (mem[i][j] != -1) return mem[i][j];

    mem[i][j] = coins[i][j] + max(maxCoinsRec(coins, mem, i + 1, j),
            maxCoinsRec(coins, mem, i, j + 1));

    return mem[i][j];
}

int main()
{
    vector<vector<int>> coins = { {0, 0, 0, 0, 1, 0},
                                  {0, 1, 0, 1, 0, 0},
                                  {0, 0, 0, 1, 0, 1},
                                  {0, 0, 1, 0, 0, 1},
                                  {1, 0, 0, 0, 1, 0} };
    vector<vector<int>> mem(coins.size(), vector<int>(coins[0].size(), -1));

    int result = maxCoinsRec(coins, mem, 0, 0);

    cout << "Maximo de moedas coletadas: " << result;
    return 0;
}
#endif

#ifdef A1g
#include <iostream>
#include <vector>

using namespace std;

int knapSack(int W, vector<int>& wt, vector<int>& val, int n)
{
    //Caso base
    if (n == 0 || W == 0) return 0;

    //Se o peso do enésimo item for maior do que a capacidade da mochila, o item não pode ser incluído na solução ideal
    if (wt[n - 1] > W) return knapSack(W, wt, val, n - 1);
    else return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

int knapSackPD(int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& mem, int n)
{
    if (n < 0) return 0;
    
    if (mem[n][W] != -1) return mem[n][W];

    if (wt[n] > W)
    {
        mem[n][W] = knapSackPD(W, wt, val,mem, n - 1);
        return mem[n][W];
    }
    else
    {
        mem[n][W] = max(val[n] + knapSackPD(W - wt[n], wt, val, mem, n - 1),
            knapSackPD(W, wt, val,mem, n - 1));

        return mem[n][W];
    }
}

int main()
{
    vector<int> val = { 60, 100, 120 };
    vector<int> wt = { 10, 20, 30 };
    int W = 50;

    cout << knapSack(W, wt, val, val.size()) << endl;

    vector<vector<int>> mem(val.size(), vector<int>(W + 1, -1));

    cout << knapSackPD(W, wt, val, mem, val.size() - 1);
    
    return 0;
}
#endif

#ifdef A2b
#include <iostream>
#include <vector>

using namespace std;

void printSolution(vector<vector<int>>& board)
{
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board.size(); j++)
            cout << board[i][j] << "  ";
        cout << endl;
    }
}

bool isSafe(vector<vector<int>>& board, size_t row, size_t col)
{
    //Verifica a linha do lado esquerdo
    for (size_t i = 0; i < col; i++)
        if (board[row][i]) return false;

    //Verifique a diagonal superior do lado esquerdo
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    size_t i;
    int j;
    //Verifique a diagonal inferior do lado esquerdo
    for (i = row, j = col; j >= 0 && i < board.size(); i++, j--)
        if (board[i][j]) return false;

    return true;
}

bool solveNQ(vector<vector<int>>& board, size_t col)
{
    //Caso base: Se todas as rainhas forem colocadas, retorne verdadeiro
    if (col >= board.size()) return true;

    //Considere esta coluna e tente colocar esta rainha em todas as filas, uma a uma
    for (size_t i = 0; i < board.size(); i++) {
        // Verifica se a rainha pode ser colocada nesta posição
        if (isSafe(board, i, col)) {
            //Coloca a rainha nesta posição
            board[i][col] = 1;

            //Recursão para colocar o resto das rainhas
            if (solveNQ(board, col + 1)) return true;

            //Se colocar a rainha nesta posição não leva a uma solução, remova a rainha da posição
            board[i][col] = 0; //BACKTRACK
        }
    }

    //Se a rainha não puder ser colocada em qualquer linha em desta coluna retorne falso
    return false;
}

int main()
{
    cout << "Digite o numero de rainhas: ";
    int N;
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQ(board, 0) == true) printSolution(board);
    else cout << "Sem solucao";

    return 0;
}
#endif

#ifdef A2c
#include <iostream>
#include <vector>

using namespace std;

void printSolution(vector<int>& color)
{
    for (int i = 0; i < (int)color.size(); i++) cout << " " << color[i] << " ";

    cout << endl;
}

bool isSafe(int v, vector<vector<bool>>& graph, vector<int>& color, int c)
{
    for (int i = 0; i < (int)graph.size(); i++)
        if (graph[v][i] && c == color[i]) return false;

    return true;
}

bool graphColoring(vector<vector<bool>>& graph, int m, vector<int>& color, int v)
{

    //Caso base: Se todos os vértices forem atribuídos a uma cor, retorne verdadeiro
    if (v == graph.size()) return true;

    //Considera o vértice v para diferentes cores
    for (int c = 1; c <= m; c++)
    {
        //Verifica se a atribuição da cor está correta
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;

            if (graphColoring(graph, m, color, v + 1) == true) return true;

            //Se atribuir a cor c não levar a uma solução, remova-a
            color[v] = 0;
        }
    }

    return false;
}

int main()
{
    /* Exemplo de grafo
      (3)-(2)
       | / |
      (0)-(1)
    */
    //                                    0  1  2  3
    vector<vector<bool>> graph = {/*0*/ { 0, 1, 1, 1 },
                                  /*1*/ { 1, 0, 1, 0 },
                                  /*2*/ { 1, 1, 0, 1 },
                                  /*3*/ { 1, 0, 1, 0 }, };
    vector<int> color(4, 0);

    int m = 3;

    if (graphColoring(graph, m, color, 0) == false) cout << "Nao tem solucao";
    else printSolution(color);

    return 0;
}
#endif

#ifdef A2d
#include <iostream>
#include <vector>

using namespace std;

void printSolution(vector<int>& path)
{
    for (int i = 0; i < (int)path.size(); i++) cout << path[i] << " ";

    cout << path[0] << " ";
    cout << endl;
}

bool isSafe(int v, vector<vector<bool>>& graph, vector<int>& path, int pos)
{
    //Verifica se este vértice é um vértice adjacente do vértice adicionado anteriormente
    if (graph[path[pos - 1]][v] == 0) return false;

    //Verifica se o vértice já foi incluído
    for (int i = 0; i < pos; i++)
        if (path[i] == v) return false;

    return true;
}

bool Ham(vector<vector<bool>>& graph, vector<int>& path, int pos)
{
    //Caso base: se todos os vértices forem incluídos no ciclo hamiltoniano
    if (pos == graph.size())
    { //E se houver uma aresta do último vértice incluído ao primeiro vértice
        if (graph[path[pos - 1]][path[0]] == 1) return true;
        else return false;
    }

    for (int v = 1; v < (int)graph.size(); v++)
    {
        //Verifica se este vértice pode ser adicionado ao Ciclo Hamiltoniano
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            if (Ham(graph, path, pos + 1) == true) return true;

            //Se adicionar o vértice não levar a uma solução, remova-o
            path[pos] = -1;
        }
    }

    return false;
}

int main()
{
    /*Exemplo de grafo
        (0)-(1)-(2)
         | /   \ |
         (3)---(4)  */
    vector<vector<bool>> graph = { {0, 1, 0, 1, 0},
                                   {1, 0, 1, 1, 1},
                                   {0, 1, 0, 0, 1},
                                   {1, 1, 0, 0, 1},
                                   {0, 1, 1, 1, 0} };

    vector<int> path(graph.size(), -1);
    path[0] = 0;
    
    if (Ham(graph, path, 1) == false) cout << "Nao tem solucao";
    else  printSolution(path);

    return 0;
}
#endif

#ifdef A3b
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<vector>

using namespace std;

void printSolution(vector<vector<int>>& Matrix)
{
    for (size_t i = 0; i < Matrix.size(); i++) {
        for (size_t j = 0; j < Matrix.size(); j++)
            cout << Matrix[i][j] << "  ";
        cout << endl;
    }
}

int main()
{
    string line;
    bool isMatrix = false;
    const char delimiter = ':';
    int dimension = 0, counter = 0;
    vector<int> numbers;

    ifstream inputFile("brazil58.tsp");

    while (inputFile) {
        getline(inputFile, line);

        cout << line << endl;

        if (line == "EOF" || line == "DISPLAY_DATA_SECTION") break;

        if (line.find(delimiter) != string::npos) {
            string keyword = line.substr(0, line.find(delimiter));
            string value = line.substr(line.find(delimiter) + 1, line.npos);
            if (keyword == "DIMENSION") dimension = stoi(value);
        }
       
        if (isMatrix) {
            stringstream stream(line);
            int n;
            while (stream >> n) numbers.push_back(n);
        }
        if (line == "EDGE_WEIGHT_SECTION") isMatrix = true;
    }

    vector<vector<int>> matrix(dimension, vector<int>(dimension, 0));

    for (int i = 0; i < dimension - 1; i++) {
        for (int j = i + 1; j < dimension; j++) {
            matrix[i][j] = numbers[counter];
            matrix[j][i] = numbers[counter];
            counter++;
        }
    }

    printSolution(matrix);

    return 0;
}
#endif

#ifdef A3c
#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <vector>
#include <functional>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void printv(vector<int> v) {
    for (auto e : v) {
        cout << e << " ";
    }
    cout << endl;
}

vector<vector<int>> getInstance() { //ler aquivo e retornar uma matriz com os dados          
    /*return vector<vector<int>>
        ({ {0,10,15,20},
           {10,0,35,25},
           {15,35,0,30},
           {20,25,30,0} });*/
        
    string line;
    bool isMatrix = false;
    const char delimiter = ':';
    int dimension = 0, counter = 0;
    vector<int> numbers;

    ifstream inputFile("brazil58.tsp");

    while (inputFile) {
        getline(inputFile, line);

        //cout << line << endl;

        if (line == "EOF" || line == "DISPLAY_DATA_SECTION") break;

        if (line.find(delimiter) != string::npos) {
            string keyword = line.substr(0, line.find(delimiter));
            string value = line.substr(line.find(delimiter) + 1, line.npos);
            if (keyword == "DIMENSION") dimension = stoi(value);
        }

        if (isMatrix) {
            stringstream stream(line);
            int n;
            while (stream >> n) numbers.push_back(n);
        }
        if (line == "EDGE_WEIGHT_SECTION") isMatrix = true;
    }

    vector<vector<int>> matrix(dimension, vector<int>(dimension, 0));

    for (int i = 0; i < dimension - 1; i++) {
        for (int j = i + 1; j < dimension; j++) {
            matrix[i][j] = numbers[counter];
            matrix[j][i] = numbers[counter];
            counter++;
        }
    }

    return matrix;
}

int h(vector<int> sol) {
    return 0;
}

int cost(vector<int> sol, vector<vector<int>> cost_matrix) {
    int cost = 0;
    for (size_t i = 0; i < sol.size() - 1; i++) {
        cost += cost_matrix[sol[i]][sol[i + 1]];
    }

    cost += cost_matrix[sol[sol.size() - 1]][sol[0]]; // custo do caminho da ultima para a primeira cidade

    return cost;
}

void search(vector<int>& sol, vector<int>& best_sol, int n, int& bound, vector<vector<int>>& cost_matrix, vector<int> domain) {

    if (cost(sol, cost_matrix) + h(sol) < bound) {
        if (sol.size() == n) { //solução completa
            best_sol = sol;
            bound = cost(sol, cost_matrix);
        }
        else {
            for (auto e : domain) {
                if (find(sol.begin(), sol.end(), e) == sol.end()) {//verifica se o elemento está na solução
                    vector<int> new_sol(sol);
                    new_sol.push_back(e);

                    search(new_sol, best_sol, n, bound, cost_matrix, domain);
                }
            }
        }
    }
}

vector<int> branchAndBound(vector<int>& domain, int n, int bound) {
    vector<int> best_path({});
    vector<int> sol({ 0 });

    vector<std::vector<int>> cost_matrix = getInstance();

    search(sol, best_path, n, bound, cost_matrix, domain);

    return best_path;
}

int main()
{
    vector<vector<int>> cost_matrix = getInstance();
    //vector<int> domain({ 0,1,2,3 });
    //int bound = 100;
    
    vector<int> domain;
    for (size_t i = 0; i < cost_matrix.size(); i++) {
        domain.push_back(i);
    }
    int bound = 17000;
    
    int n = domain.size();

    vector<int> best_path = branchAndBound(domain, n, bound);

    printv(best_path);
    cout << "Custo otimo: " << cost(best_path, cost_matrix);
    //Custo otimo: 16156
    //custo de busca exaustiva = C(n) = (n - 1)!
    //custo de busca branchAndBound pior caso = C(n) = (n - 1)! 
}
#endif