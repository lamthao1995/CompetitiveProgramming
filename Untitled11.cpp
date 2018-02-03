#include <bits/stdc++.h>
using namespace std;
int ans = 0;
struct Node
{
    Node* parent;
    int mat[2][3];
    int x, y;
    int cost;
    int level;
};
int printMatrix(int mat[2][3])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}
Node* newNode(int mat[2][3], int x, int y, int newX,
              int newY, int level, Node* parent)
{
    Node* node = new Node;
 
    // set pointer for path to root
    node->parent = parent;
 
    // copy data from parent node to current node
    memcpy(node->mat, mat, sizeof node->mat);
 
    // move tile by 1 postion
    swap(node->mat[x][y], node->mat[newX][newY]);
 
    // set number of misplaced tiles
    node->cost = INT_MAX;
 
    // set number of moves so far
    node->level = level;
 
    // update new blank tile cordinates
    node->x = newX;
    node->y = newY;
 
    return node;
}
 
// botton, left, top, right
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };
int calculateCost(int initial[2][3], int final[2][3])
{
    int count = 0;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 3; j++)
        if (initial[i][j] && initial[i][j] != final[i][j])
           count++;
    return count;
}

int isSafe(int x, int y)
{
    return (x >= 0 && x < 2 && y >= 0 && y < 3);
}
void printPath(Node* root)
{
    if (root == NULL)
        return;
    ans++;
    printPath(root->parent);
    printMatrix(root->mat);
 
    printf("\n");
}
struct comp
{
    bool operator()(const Node* lhs, const Node* rhs) const
    {
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
    }
};

void solve(int initial[2][3], int x, int y,
           int final[2][3])
{
    priority_queue<Node*, std::vector<Node*>, comp> pq;
    Node* root = newNode(initial, x, y, x, y, 0, NULL);
    root->cost = calculateCost(initial, final);

    pq.push(root);
    while (!pq.empty())
    {
        Node* min = pq.top();
        pq.pop();
        if (min->cost == 0)
        {
            printPath(min);
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            if (isSafe(min->x + row[i], min->y + col[i]))
            {
                Node* child = newNode(min->mat, min->x,
                              min->y, min->x + row[i],
                              min->y + col[i],
                              min->level + 1, min);
                child->cost = calculateCost(child->mat, final);
                pq.push(child);
            }
        }
    }
}
int main()
{
    // Initial configuration
    // Value 0 is used for empty space
    int initial[2][3] =
    {
        {4, 1, 2},
        {5, 0, 3},
    };
    int final[2][3] =
    {
        {1, 2, 3},
        {5, 4, 0},
    };
    int x = 1, y = 2;
    solve(initial, x, y, final);
    cout << ans - 1 << endl;
    return 0;
}
