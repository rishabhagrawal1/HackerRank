#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <cstring>
using namespace std;
#define NMAX 1001

int table[NMAX][NMAX] = {0};

void printList(int distance[], int nodes, int start)
{
    for(int i = 0; i < nodes; i++)
    {
        if(i != start)
        {
            cout << distance[i] << " "; 
        }
    }
}

void doBFS(int start, int nodes)
{
    int visited[nodes];
    list<int> queue;
    int curNode;
    int level = 0;
    
    for(int i = 0; i < nodes; i++)
    {
        visited[i] = -1;
    }
    
    queue.push_back(start);
    queue.push_back(-1);
    visited[start] = 0;
   
    while(!queue.empty())
    {
        curNode = queue.front();
        queue.pop_front();
        if(curNode == -1 && !queue.empty())
        {
            level = level + 1;
            queue.push_back(-1);
            continue;
        }

        if(level > 0)
            visited[curNode] = level * 6;
                
        for(int i = 0; i < nodes; i++)
        {
            if(table[curNode][i] == 6 && visited[i] == -1)
            {
                queue.push_back(i);
                visited[i] = 0; 
            }
        }
    }
    printList(visited, nodes, start);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int tCases = 0;
    int nodes = 0, edges = 0;
    int n1 = 0, n2 = 0;
    int start = 0;
    cin >> tCases;
    for(int i = 0; i < tCases; i++)
    {
        memset(table, 0, sizeof(int)*NMAX*NMAX);
        cin >> nodes;
        cin >> edges;
        for(int j = 0; j < edges; j++)
        {
            scanf("%d %d",&n1, &n2);
            table[n1-1][n2-1] = table[n2-1][n1-1] = 6;
        }
        cin >> start;
        doBFS(start-1, nodes);
        cout << "\n";
    }
    return 0;
}