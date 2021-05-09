/*Atividade 1: A1
* Atividade 4: A4
* Atividade 5: A5
* Atividade 6: A6
* Atividade 9: A9
* Atividade 10: A10
* Atividade 12: A12
* Atividade 13: A13
* Atividade 14: A14
*/
#define A14

#ifdef A1
#include <iostream>
#include <vector>

using namespace std;

template <typename T> void merge(vector<T>& v, size_t l, size_t m, size_t r)
{
    vector<T> L, R;
    size_t n1 = m - l + 1;
    size_t n2 = r - m;

    //Divide o vector em duas partes
    for (int i = 0; i < n1; i++) L.push_back(v[l + i]);
    for (int j = 0; j < n2; j++) R.push_back(v[m + 1 + j]);       

    //Mescla L e R ao vector original
    int i = 0; //Indice inicial de L
    int j = 0; //Indice inicial de R
    size_t k = l; //Indice inicial do subvector mesclado

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    //Copia os elementos restantes de L (se houver)
    while (i < n1)
    {
        v[k] = L[i];
        i++;
        k++;
    }

    //Copia os elementos restantes de R (se houver)
    while (j < n2)
    {
        v[k] = R[j];
        j++;
        k++;
    }
}

template <typename T> void mergeSort(vector<T>& v, size_t l, size_t r)
{
	if (l >= r) return; //Caso base
    
    size_t m = l + (r - l) / 2;
	mergeSort(v, l, m);
	mergeSort(v, m + 1, r);
	merge(v, l, m, r);
}

template <typename T> void print_vector(vector<T>& v, string x)
{
    cout << x << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

int main()
{
    vector<char> vetor = {'E','X','A','M','P','L','E'};
    print_vector(vetor, "Entrada:");

	mergeSort(vetor, 0, vetor.size() - 1);

	print_vector(vetor, "Saida:");

    return 0;
}
#endif

#ifdef A4
#include <iostream>
#include <vector>

using namespace std;

 template <typename T> size_t max(vector<T>& v, size_t l, size_t r)
{
    if (v[l] > v[r]) return l;
    else return r;
}

template <typename T> size_t mergemax(vector<T>& v, size_t l, size_t r)
{
    if (l < r) {
        size_t m = l + (r - l) / 2;
        size_t maxLeft = mergemax(v, l, m);
        size_t maxRight = mergemax(v, m + 1, r);
        return max(v, maxLeft, maxRight);
    }
    return max(v, l, r);
}


template <typename T> void print_vector(vector<T>& v, string x)
{
    cout << x << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

int main()
{
    vector<char> vetor = { 'E','X','A','M','P','X','L','E' };
    print_vector(vetor, "Entrada:");

    size_t M = mergemax(vetor, 0, vetor.size() - 1);

    cout << endl << "Maior elemento no indice: " << M << " - " << vetor[M];

    return 0;
}
#endif

#ifdef A5
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

template <typename T> void mergemaxmin(vector<T>& v, size_t l, size_t r, T& min, T& max)
{
    //Se o vector contém apenas um elemento
    if (l == r)
    {
        if (max < v[l]) max = v[l];

        if (min > v[r]) min = v[r];

        return;
    }

    //Se o vector contém apenas dois elementos
    if (r - l == 1)
    {
        if (v[l] < v[r])
        {
            if (min > v[l]) min = v[l];
            if (max < v[r]) max = v[r];
        }
        else {
            if (min > v[r]) min = v[r];
            if (max < v[l]) max = v[l];
        }
        
        return;
    }

    //Demais casos
    size_t m = l + (r - l) / 2;

    mergemaxmin(v, l, m, min, max);
    mergemaxmin(v, m + 1, r, min, max);
}

template <typename T> void print_vector(vector<T>& v, string x)
{
    cout << x << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

int main()
{
    vector<char> vetor = { 'E','X','A','M','P','L','E' };
    print_vector(vetor, "Entrada:");

    //Inicializa o mínimo com o menor elemento do dado e o máximo com o maior
    //https://www.cplusplus.com/reference/climits/
    char max = CHAR_MIN, min = CHAR_MAX;

    mergemaxmin(vetor, 0, vetor.size() - 1, min, max);

    cout << "Minimo: " << min << endl;
    cout << "Maximo: " << max;

    return 0;
}
#endif

#ifdef A6
#include <iostream>
#include <vector>

using namespace std;

template <typename T> void partition(vector<T>& v, int l, size_t r, int& i, size_t& j)
{
    int pivot, temp;
    i = l;
    j = r;
    pivot = v[(i + j) / 2];
    
    do
    {
        while (pivot > v[i]) ++i;
        while (pivot < v[j]) --j;

        if (i <= j) {
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            ++i;
            --j;
        }
    } while (i <= j);
}

template <typename T> void quicksort(vector<T>& v, int l, size_t r)
{
    int i;
    size_t j;
    cont++;
    partition(v, l, r, i, j);
    
    if (l < j) quicksort(v, l, j);
    if (i < r) quicksort(v, i, r);
}

template <typename T> void print_vector(vector<T>& v, string x)
{
    cout << x << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

int main()
{
    vector<char> vetor = { 'E','X','A','M','P','L','E' };
    print_vector(vetor, "Entrada:");

    quicksort(vetor, 0, vetor.size() - 1);

    print_vector(vetor, "Saida:");

    return 0;
}
#endif

#if (defined A9) || (defined A10) || (defined A12)
#include <iostream>

using namespace std;


template <typename T> class node
{  
    public:
        char data = NULL;
        unique_ptr<node> left;
        unique_ptr<node> right;
};

template <typename T> unique_ptr<node<T>> newNode(T data)
{
    unique_ptr<node<T>> Node(new node<T>());
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
}

#ifdef A10
template <typename T> int Height(unique_ptr<node<T>>& node)
{
    if (node == NULL) return 0;
    else
    {
        //Calcula a profundidade de cada subárvore
        int lDepth = Height(node->left);
        int rDepth = Height(node->right);

        if (lDepth > rDepth) return(lDepth + 1);
        else return(rDepth + 1);
    }
 }
#endif

#ifdef A12
template <typename T> void Preorder(unique_ptr<node<T>>& node)
{
    if (node == NULL) return;

    cout << node->data << " ";

    Preorder(node->left);
    Preorder(node->right);
}

template <typename T> void Inorder(unique_ptr<node<T>>& node)
{
    if (node == NULL) return;

    Inorder(node->left);

    cout << node->data << " ";

    Inorder(node->right);
}

template <typename T> void Postorder(unique_ptr<node<T>>& node)
{
    if (node == NULL) return;

    Postorder(node->left);
    Postorder(node->right);

    cout << node->data << " ";
}
#endif

int main()
{
    unique_ptr<node<char>> root = newNode('a');

    root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->right = newNode('f');

#ifdef A10
    cout << "Altura: " << Height(root);
#endif

#ifdef A12
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;

    cout << "Inorder: ";
    Inorder(root);
    cout << endl;

    cout << "Postorder: ";
    Postorder(root);

#endif
    return 0;
}
#endif

#ifdef A13
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subtract(vector<vector<int>> A, vector<vector<int>> B)
{
    vector<vector<int>> C;
    vector<int> S;

    for (size_t i = 0; i < A.size(); i++) {
        for (size_t j = 0; j < A.size(); j++) {
            S.push_back(A[i][j] - B[i][j]);
        }
        C.push_back(S);
    }
    return C;
}

vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B)
{
    vector<vector<int>> C;
    vector<int> S;

    for (size_t i = 0; i < A.size(); i++) {
        for (size_t j = 0; j < A.size(); j++) {
            S.push_back(A[i][j] + B[i][j]);
        }
        C.push_back(S);
    }
    return C;
}

template <typename T> void print_vector(vector<T>& v, string x)
{
    cout << x << endl;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
    
vector<vector<int>> Strassen(vector<vector<int>> A, vector<vector<int>> B)
{
    vector<vector<int>> C;

    if (A.size() == 1) //Caso base
    {
        vector<int> temp;
        temp.push_back(A[0][0] * B[0][0]);
        C.push_back(temp);
        return C;
    }
    
    //Divide as matrizes
    size_t k = A.size() / 2;
    
    vector<vector<int>> a, b, c, d, e, f, g, h;
    vector<int> A11, A12, A21, A22, B11, B12, B21, B22;

    for (size_t i = 0; i < k; i++) {
        A11.clear();
        A12.clear(); 
        A21.clear(); 
        A22.clear(); 
        B11.clear(); 
        B12.clear(); 
        B21.clear(); 
        B22.clear();
        for (size_t j = 0; j < k; j++) {
            A11.push_back(A[i][j]);
            A12.push_back(A[i][k + j]);
            A21.push_back(A[k + i][j]);
            A22.push_back(A[k + i][k + j]);
            B11.push_back(B[i][j]);
            B12.push_back(B[i][k + j]);
            B21.push_back(B[k + i][j]);
            B22.push_back(B[k + i][k + j]);
        }
        a.push_back(A11);
        b.push_back(A12);
        c.push_back(A21);
        d.push_back(A22);
        e.push_back(B11);
        f.push_back(B12);
        g.push_back(B21);
        h.push_back(B22);
    }

    //Calcula os 7 produtos
    vector<vector<int>> p1, p2, p3, p4, p5, p6, p7;

    p1 = Strassen(a, subtract(f, h));
    p2 = Strassen(add(a, b), h);
    p3 = Strassen(add(c, d), e);
    p4 = Strassen(d, subtract(g, e));
    p5 = Strassen(add(a, d), add(e, h));
    p6 = Strassen(subtract(b, d), add(g, h));
    p7 = Strassen(subtract(a, c), add(e, f));
    
    //Calcula os valores dos 4 quadrantes da matriz final
    vector<vector<int>> C11, C12, C21, C22;
    C11 = subtract(add(add(p5, p4), p6), p2);
    C12 = add(p1, p2);
    C21 = add(p3, p4);
    C22 = subtract(subtract(add(p1, p5), p3), p7);

    //Junta os 4 quadrantes da matriz final
    vector<int> C1(k*2, 0);
    vector<int> C2(k*2, 0);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C1.insert(C1.begin() + j, C11[i][j]);
            C1.erase(C1.begin() + j + 1);

            C1.insert(C1.begin() + j + k, C12[i][j]);
            C1.erase(C1.begin() + j + k + 1);
        }

        C.push_back(C1);
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C2.insert(C2.begin() + j, C21[i][j]);
            C2.erase(C2.begin() + j + 1);

            C2.insert(C2.begin() + j + k, C22[i][j]);
            C2.erase(C2.begin() + j + k + 1);
        }

        C.push_back(C2);
    }

    return C;
}

int main()
{
    vector<vector<int>> A = { {1,2} , {3,4} };
   vector<vector<int>> B = { {-1,3} , {4,2} };
    //vector<vector<int>> A = { {1,2,3,4} , {5,6,7,8} , {9,10,11,12}, {13,14,15,16} };
    //vector<vector<int>> B = { {1,2,3,4} , {5,6,7,8} , {9,10,11,12}, {13,14,15,16} };
    /*vector<vector<int>> A = { {1,2,3,4,5,0,0,0} , {6,7,8,9,10,0,0,0} , {11,12,13,14,15,0,0,0} , {16,17,18,19,20,0,0,0} ,
        {21,22,23,24,25,0,0,0} , {0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0} };
    vector<vector<int>> B = { {1,2,3,4,5,0,0,0} , {6,7,8,9,10,0,0,0} , {11,12,13,14,15,0,0,0} , {16,17,18,19,20,0,0,0} ,
        {21,22,23,24,25,0,0,0} , {0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0} };*/

    print_vector(A, "A: ");
    print_vector(B, "B: ");

    vector<vector<int>> C = Strassen(A, B);

    print_vector(C, "C: ");

    return 0;
}
#endif

#ifdef A14
#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Point { int x, y; };
vector<struct Point> poin;
set<pair<int, int>> hull;

//Retorna o lado do ponto P em relação à linha que une os pontos P1 e P2
int findSide(struct Point P1, struct Point P2, struct Point P)
{
    int val = (P.y - P1.y) * (P2.x - P1.x) - (P2.y - P1.y) * (P.x - P1.x);

    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

//Retorna um valor proporcional à distância entre o ponto P e a linha que une os pontos P1 e P2
int lineDist(struct Point P1, struct Point P2, struct Point P)
{
    return abs((P.y - P1.y) * (P2.x - P1.x) - (P2.y - P1.y) * (P.x - P1.x));
}

// Os pontos finais da linha L são P1 e P2.
// O lado pode ter valor 1 ou -1 especificando cada uma das partes divididas pela linha L
void quickHull(vector<struct Point>& poin, struct Point P1, struct Point P2, int side)
{
    int ind = -1, max_dist = 0;

    //Encontra o ponto com distância máxima de L e também o lado especificado de L
    for (int i = 0; i < poin.size(); i++)
    {
        int temp = lineDist(P1, P2, poin[i]);
        if (findSide(P1, P2, poin[i]) == side && temp > max_dist)
        {
            ind = i;
            max_dist = temp;
        }
    }

    //Se nenhum ponto for encontrado, adicione os pontos finais de L ao Convex Hull.
    if (ind == -1)
    {
        hull.insert({ P1.x,P1.y });
        hull.insert({ P2.x,P2.y });
        return;
    }

    // Recur for the two parts divided by a[ind]
    quickHull(poin, poin[ind], P1, -findSide(poin[ind], P1, P2));
    quickHull(poin, poin[ind], P2, -findSide(poin[ind], P2, P1));
}

void printHull(vector<struct Point>& poin)
{
    if (poin.size() < 3)
    {
        cout << "Nao e possivel obter o Convex Hull";
        return;
    }

    //Encontra o ponto com coordenada x mínimo e máximo
    int min_x = 0, max_x = 0;
    for (int i = 1; i < poin.size(); i++)
    {
        if (poin[i].x < poin[min_x].x) min_x = i;
        if (poin[i].x > poin[max_x].x) max_x = i;
    }

    //Encontra recursivamente os pontos do Convex Hull em um lado da linha, unindo poin[min_x] e poin[max_x]
    quickHull(poin, poin[min_x], poin[max_x], 1);

    //Encontra recursivamente os pontos do Convex Hull no outro lado da linha, unindo poin[min_x] e poin[max_x]
    quickHull(poin, poin[min_x], poin[max_x], -1);

    cout << "Pontos do Convex Hull: " << endl;
    set<pair<int, int> >::iterator it = hull.begin();
    while (it != hull.end())
    {
        cout << "(" << it->first << "," << it->second << ")" << endl;
        it++;
    }
}

// Driver code
int main()
{
    //poin = { {1, 3}, {2, 1}, {4, 1}, {4, 3}, {3, 4}, {6, 2} };   
    poin = { {0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3} };
    //poin = { {30, 30}, {50, 60}, {60, 20}, {70, 45}, {86, 39}, {112, 60}, {200, 113}, {250, 50},{300, 200},
    //    {130, 240}, {76, 150}, {47, 76}, {36, 40}, {33, 35} };

    printHull(poin);

    return 0;
}
#endif