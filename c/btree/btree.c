#include <stdio.h>
#include <stdlib.h>

int T;
typedef struct BTreeNode {
    int n;                         
    int* keys;           
    struct BTreeNode** children; 
    int isLeaf;                    
} BTreeNode;

BTreeNode* createNode(int isLeaf) 
{
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->isLeaf = isLeaf;
    node->n = 0;
    node->keys = (int*) malloc((2*T-1)*sizeof(int));
    node->children = (BTreeNode**) malloc(2*T*sizeof(BTreeNode*));
    for (int i = 0; i < 2 * T; i++) node->children[i] = NULL;
    return node;
}

void levelOrderTraversal(BTreeNode* root) 
{
    if (!root) return;

    BTreeNode* queue[1000];
    int level[1000];

    int head = 0, tail = 0;

    level[tail] = 0;
    queue[tail++] = root;

    int currLevel = 0;

    while (head < tail) {
        int headLevel = level[head];
        BTreeNode* current = queue[head++];


        if(currLevel<headLevel){
            currLevel = headLevel;
            printf("\n");
        } 

        for (int i = 0; i < current->n; i++) 
            printf("%d ", current->keys[i]);

        if (!current->isLeaf) 
            for (int i = 0; i <= current->n; i++) {
                level[tail] = headLevel+1;
                queue[tail++] = current->children[i];
            }
    }
    printf("\n");
}

void splitChild(BTreeNode* parent, int i, BTreeNode* child) 
{
    BTreeNode* newNode = createNode(child->isLeaf);
    newNode->n = T - 1;

    for (int j = 0; j < T - 1; j++) 
        newNode->keys[j] = child->keys[j + T];

    if (!child->isLeaf) 
        for (int j = 0; j < T; j++) 
            newNode->children[j] = child->children[j + T];

    child->n = T - 1;

    for (int j = parent->n; j >= i + 1; j--) 
        parent->children[j + 1] = parent->children[j];

    parent->children[i + 1] = newNode;

    for (int j = parent->n - 1; j >= i; j--) 
        parent->keys[j + 1] = parent->keys[j];

    parent->keys[i] = child->keys[T - 1];
    parent->n += 1;
}

void insertRecursive(BTreeNode* node, int key) 
{
    int i = node->n - 1;

    for (int j = 0; j < node->n; j++) 
        if (node->keys[j] == key) return; 

    if (node->isLeaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->n += 1;
    } 
    else {
        while (i >= 0 && key < node->keys[i]) i--;
        i++;

        if (node->children[i]->n == 2 * T - 1) {
            splitChild(node, i, node->children[i]);
            if (key > node->keys[i]) i++;
        }
        insertRecursive(node->children[i], key);
    }
}

BTreeNode* insert(BTreeNode* root, int key) 
{
    if (!root) 
    {
        root = createNode(1); 
        root->keys[0] = key;
        root->n = 1;
        return root;
    }

    if (root->n == 2 * T - 1) 
    {
        BTreeNode* newRoot = createNode(0);
        newRoot->children[0] = root;
        splitChild(newRoot, 0, root);
        int i = (key > newRoot->keys[0]) ? 1 : 0;
        insertRecursive(newRoot->children[i], key);
        return newRoot;
    } 
    else {
        insertRecursive(root, key);
        return root;
    }
}

int getSuccessor(BTreeNode* node) 
{
    BTreeNode* current = node;
    while (!current->isLeaf) 
        current = current->children[0];
    return current->keys[0];
}

void merge(BTreeNode* parent, int i) 
{
    BTreeNode* left = parent->children[i];
    BTreeNode* right = parent->children[i + 1];

    // Move parent's and right child's key to left child
    left->keys[T - 1] = parent->keys[i];
    for (int j = 0; j < right->n; j++) 
        left->keys[T + j] = right->keys[j];

    if (!left->isLeaf) {
        for (int j = 0; j <= right->n; j++) 
            left->children[T + j] = right->children[j];
    }
    left->n += right->n + 1;

    // Shift the parent's keys and children to fill the gap
    for (int j = i; j < parent->n - 1; j++) 
        parent->keys[j] = parent->keys[j + 1];
    for (int j = i + 1; j < parent->n; j++) 
        parent->children[j] = parent->children[j + 1];

    parent->n--;
    free(right);
}

void borrowLeft(BTreeNode* parent, int i)
{
    BTreeNode* child = parent->children[i];
    BTreeNode* sibling = parent->children[i - 1];

    for (int j = child->n - 1; j >= 0; j--) 
        child->keys[j + 1] = child->keys[j];

    if (!child->isLeaf) 
        for (int j = child->n; j >= 0; j--) 
            child->children[j + 1] = child->children[j];

    child->keys[0] = parent->keys[i - 1];

    parent->keys[i - 1] = sibling->keys[sibling->n - 1];

    child->n++;
    sibling->n--;
}

void borrowRight(BTreeNode* parent, int i) 
{
    BTreeNode* child = parent->children[i];
    BTreeNode* sibling = parent->children[i + 1];

    child->keys[child->n] = parent->keys[i];

    parent->keys[i] = sibling->keys[0];

    for (int j = 1; j < sibling->n; j++) 
        sibling->keys[j - 1] = sibling->keys[j];
    
    if (!child->isLeaf) {
        child->children[child->n + 1] = sibling->children[0];
        for (int j = 1; j <= sibling->n; j++) 
            sibling->children[j - 1] = sibling->children[j];
    }

    child->n++;
    sibling->n--;
}

void delete(BTreeNode* root, int key) 
{
    if (root == NULL) return;

    int i = 0;
    while (i < root->n && key > root->keys[i]) i++;

    if (i < root->n && root->keys[i] == key) {
        if (root->isLeaf) {
            for (int j = i; j < root->n - 1; j++) 
                root->keys[j] = root->keys[j + 1];
            root->n--;
        } 
        else {
            int succKey = getSuccessor(root->children[i+1]);
            root->keys[i] = succKey;
            delete(root->children[i+1], succKey);
        }
    } 
    else {
        if (root->isLeaf) return; 

        int flag = ((i == root->n) ? 1 : 0);

        if (root->children[i]->n < T) {
            if (i > 0 && root->children[i - 1]->n >= T) 
                borrowLeft(root, i);
            else if (i < root->n && root->children[i + 1]->n >= T) 
                borrowRight(root, i);
            else {
                if (i < root->n) merge(root, i);  
                else merge(root, i - 1);  
            }
        }
        if (flag && i > root->n) delete(root->children[i - 1], key);
        else delete(root->children[i], key);
    }
}

int main() 
{
    BTreeNode* root = NULL;
    scanf("%d", &T);

    for(int x = 1; x != 0; scanf("%d", &x)){
        if(x > 0) root = insert(root, x);
        if(x < 0) delete(root, -x);
    }

    levelOrderTraversal(root);
    return 0;
}
