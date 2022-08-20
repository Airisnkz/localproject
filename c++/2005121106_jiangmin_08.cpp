#include<iostream>
#include<stdlib.h>
using namespace std;
template<typename DistType> class Edge {
public:
    Edge(int dest, DistType cost) : dest(dest), cost(cost), next(NULL) {}
public:
    int dest;
    DistType cost;
    Edge<DistType> *next;
};
template<typename NameType, typename DistType> class Vertex {
public:
    Vertex() : adj(NULL) {}
    NameType data;
    Edge<DistType> *adj;
    ~Vertex();
};
template<typename NameType, typename DistType> Vertex<NameType, DistType>::~Vertex() {
    Edge<DistType> *pmove = adj;
    while (pmove) {
         adj = pmove->next;
         delete pmove;
         pmove = adj;
    }
}
template<typename NameType, typename DistType> class Graph {
public:
    Graph(int size = DefaultSize); 
    ~Graph();
    bool GraphEmpty() const { 
         return 0 == numvertex;
    }
    bool GraphFull() const { 
         return MaxNum == numvertex;
    }
    int NumberOfVertex() const { 
         return numvertex;
    }
    int NumberOfEdge() const {
         return numedges;
    }
    void intputGraph(DistType maps[][100]);
    NameType GetValue(int u);   
    DistType GetWeight(int u, int v); 
    bool InsertVertex(int u, const NameType Data);   
    bool Removvertex(int u);  
    bool InsertEdge(int v1, int v2, DistType weight = Infinity);  
    bool RemoveEdge(int v1, int v2);   
    void Print2();
    void Print();
    int Getvertexpos(const NameType Data);   
    void DFSprint(int s);    
    void DFS(int s);    
    void BFSprint(int s);   
    void BFS(int s);     
private:
    Vertex<NameType, DistType> *nodetable;   
    int numvertex;                           
    const int MaxNum;                        
    static const int DefaultSize = 10;       
    static const DistType Infinity = -1;  
    int numedges;                            
    bool *flag;                              
    DistType map[100][100];                  
};
template<typename NameType, typename DistType> Graph<NameType, DistType>::Graph(int size) 
: numvertex(0), MaxNum(size), numedges(0) {
    nodetable = new Vertex<NameType, DistType>[size];
    flag = new bool[size];
    for (int i = 0; i < MaxNum; i++)
         nodetable[i].data = NULL;
}
template<typename NameType, typename DistType> Graph<NameType, DistType>::~Graph() { 
    Edge<DistType> *pmove;
    for (int i = 0; i<this->numvertex; i++) {
         pmove = this->nodetable[i].adj;
         if (pmove) {
             this->nodetable[i].adj = pmove->next;
             delete pmove;
             pmove = this->nodetable[i].adj;
         }
    }
    delete[] nodetable;
}
template<typename NameType, typename DistType> NameType Graph<NameType, DistType>::GetValue(int u) { 
    if (u<0 || u >= this->MaxNum) {
         cout << "请输入正确的结点编号" << endl;
         return 0;
    }
    return nodetable[u].data;
}
template<typename NameType, typename DistType> DistType Graph<NameType, DistType>::GetWeight(int u, int v) {
    if (u >= 0 && u<this->numvertex && v >= 0 && v<this->numvertex) {
         if (u == v) {
             return 0;
         }
         Edge<DistType> *pmove = nodetable[u].adj;
         while (pmove) {
             if (pmove->dest == v) {
                  return pmove->cost;
             }
             pmove = pmove->next;
         }
    }
    return Infinity;
}
template<typename NameType, typename DistType> int Graph<NameType, DistType>::Getvertexpos(const NameType Data) {
    for (int i = 0; i<this->numvertex; i++) {
         if (Data == nodetable[i].data) {
             return i;
         }
    }
    return -1;
}
template<typename NameType, typename DistType> bool Graph<NameType, DistType>::InsertEdge(int u, int v, DistType weight) { 
    if (u >= 0 && u<this->numvertex && v >= 0 && v<this->numvertex) {
         Edge<DistType> *pmove = nodetable[u].adj;
         if (NULL == pmove) {
             nodetable[u].adj = new Edge<DistType>(v, weight);
             return 1;
         }
         while (pmove->next) { 
             if (pmove->dest == v) {
                  break;
             }
             pmove = pmove->next;
         }
         if (pmove->dest == v) {
             pmove->cost = weight;
             return 1;
         }
         else {
             pmove->next = new Edge<DistType>(v, weight);
             return 1;
         }
    }
    return 0;
}
template<typename NameType, typename DistType> bool Graph<NameType, DistType>::InsertVertex(int u, const NameType Data) { 
    if (this->GetValue(u) == NULL)
         this->numvertex++;
    this->nodetable[u].data = Data;
    return 1;
}
template<typename NameType, typename DistType> bool Graph<NameType, DistType>::RemoveEdge(int u, int v) {
    if (u >= 0 && u<this->numvertex && v >= 0 && v<this->numvertex) {
         Edge<DistType> *pmove = this->nodetable[u].adj, *pdel;
         if (NULL == pmove) {
             printf("%d和%d之间不存在环\n", u, v);
             return 0;
         }
         if (pmove->dest == v) { 
             this->nodetable[u].adj = pmove->next;
             delete pmove;
             return 1;
         }
         while (pmove->next) {
             if (pmove->next->dest == v) {
                  pdel = pmove->next;
                  pmove->next = pdel->next;
                  delete pdel;
                  return 1;
             }
             pmove = pmove->next;
         }
    }
    printf("%d和%d之间不存在环\n", u, v);
    return 0;
}
template<typename NameType, typename DistType> void Graph<NameType, DistType>::intputGraph(DistType maps[][100]) { 
    for (int i = 0; i < this->MaxNum; i++) {
         this->InsertVertex(i, i);
    }
    for (int i = 0; i < MaxNum; i++) {
         for (int j = 0; j < MaxNum; j++) {
             map[i][j] = maps[i][j];
             if (map[i][j] != this->Infinity) {
                  this->InsertEdge(i, j, map[i][j]);
                  this->InsertEdge(j, i, map[i][j]);
             }
         }
    }
}
template<typename NameType, typename DistType> void Graph<NameType, DistType>::Print2() { 
    Edge<DistType> *pmove;
    for (int i = 0; i<this->MaxNum; i++)
         flag[i] = 0;
    cout << "拓扑排序表示" << endl;
    for (int i = 0; i<this->MaxNum; i++) {
         NameType u = this->nodetable[i].data;
         flag[i] = 1;
         pmove = this->nodetable[i].adj;
         while (pmove) {
             if (flag[pmove->dest] == 0) {
                  NameType v = this->nodetable[pmove->dest].data;
                  DistType Cost = pmove->cost;
                  cout << "(" << u << "," << v << ")=" << Cost << "   ";
             }
             pmove = pmove->next;
         }
    }
    cout << endl;
}
template<typename NameType, typename DistType> void Graph<NameType, DistType>::Print() { 
    Edge<DistType> *pmove;
    for (int i = 0; i<this->MaxNum; i++)
         flag[i] = 0;
    for (int i = 0; i<this->MaxNum; i++) {
         int u = i;
         flag[i] = 1;
         pmove = this->nodetable[i].adj;
         while (pmove) {
             int v = pmove->dest;
             if (flag[v] == 0) {
                  DistType Cost = pmove->cost;
                  map[u][v] = map[v][u] = Cost;
             }
             pmove = pmove->next;
         }
    }
    cout << "图的邻接矩阵表示" << endl;
    for (int i = 0; i<this->MaxNum; i++) {
         for (int j = 0; j<this->MaxNum; j++) {
             cout << map[i][j];
             if (j == this->MaxNum - 1)
                  cout << endl;
             else
                  cout << " ";
         }
    }
}
template<typename NameType, typename DistType> void Graph<NameType, DistType>::DFSprint(int s) {
    for (int i = 0; i <= this->MaxNum; i++)
         flag[i] = false;
    cout << "head-->" << s << "-->";
    flag[s] = 1;
    this->DFS(s);
    cout << "over" << endl;
    for (int i = 0; i < this->MaxNum; i++) {
         if (flag[i] == 0) {
             flag[i] = 1;
             cout << "head-->" << i << "-->";
             this->DFS(i);
             cout << "over" << endl;
         }
    }
    return;
}
template<typename NameType, typename DistType> void Graph<NameType, DistType>::DFS(int s) { 
    Edge<DistType> *pmove = nodetable[s].adj;
    while (pmove != NULL) {
         if (flag[pmove->dest] == 0) {
             flag[pmove->dest] = 1;
             cout << pmove->dest << "-->";
             this->DFS(pmove->dest);
         }
         pmove = pmove->next;
    }
    return;
}
template<typename NameType, typename DistType> void Graph<NameType, DistType>::BFSprint(int s) { 
    for (int i = 0; i <= this->MaxNum; i++)
         flag[i] = false;
    flag[s] = 1;
    BFS(s);
    for (int i = 0; i<this->MaxNum; i++) {
         if (flag[i] == 0) {
             flag[i] = 1;
             BFS(i);
         }
    }
    return;
}
template<typename NameType, typename DistType> void Graph<NameType, DistType>::BFS(int s) {
    int que[100];
    int l = 0, r = 0;
    que[r++] = s;
    flag[s] = 1;
    while (l < r) {
         int u = que[l++];
         Edge<DistType> *pmove = nodetable[u].adj;
         while (pmove != NULL) {
             int v = pmove->dest;
             if (flag[v] == 0) {
                  que[r++] = v;
                  flag[v] = 1;
             }
             pmove = pmove->next;
         }
    }
    cout << "head-->";
    for (int i = 0; i < l; i++) {
         printf("%d%s", que[i], i == l - 1 ? "-->over\n" : "-->");
    }
    return;
}
int main() {
    cout << "请输入图：";
    int n, maps[100][100];
    cin >> n;                    
    for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             cin >> maps[i][j];   
         }
    }
    Graph<int, int> graph(n);   
    graph.intputGraph(maps);     
    graph.Print();               
    graph.Print2();              
    int pos;
    cout << "拓扑排序起始点：";
    cin >> pos;                  
    graph.DFSprint(pos);         
    graph.BFSprint(pos);         
    graph.RemoveEdge(3, 6);      
    graph.InsertEdge(0, 1, 2);   
    graph.InsertEdge(0, 2, 3);   
    graph.InsertEdge(7, 8, 4);   
    graph.Print();               
    graph.Print2();              
    cout << "拓扑排序起始点：";
    cin >> pos;                  
    graph.DFSprint(pos);         
    graph.BFSprint(pos);
    system("pause");       
    return 0;
}