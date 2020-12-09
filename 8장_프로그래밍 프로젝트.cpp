#include <iostream>
#define MAX 100
using namespace std;



class BinaryNode

{

protected:

    int data;

    BinaryNode* left;

    BinaryNode* right;

    void inorder(int data)

    {

        if (left != NULL)

            left->inorder();

        cout << (char)data << " ";

        if (right != NULL)

            right->inorder();

    }

    void preorder(int data)

    {

        cout << (char)data << " ";

        if (left != NULL)

            left->preorder();

        if (right != NULL)

            right->preorder();

    }

    void postorder(int data)

    {

        if (left != NULL)

            left->postorder();

        if (right != NULL)

            right->postorder();

        cout << (char)data << " ";

    }

public:

    BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL) :data(val), left(l), right(r)

    {

    }

    BinaryNode* search(int key)

    {

        if (key == data)

            return this;

        else if (key < data && left != NULL)

            return left->search(key);

        else if (key > data && right != NULL)

            return right->search(key);

        else

            return NULL;

    }

    void setData(int val)

    {

        data = val;

    }

    void setLeft(BinaryNode* l)

    {

        left = l;

    }

    void setRight(BinaryNode* r)

    {

        right = r;

    }

    int getData()

    {

        return data;

    }

    BinaryNode* getLeft()

    {

        return left;

    }

    BinaryNode* getRight()

    {

        return right;

    }

    bool isLeaf()

    {

        return left == NULL && right == NULL;

    }

    void inorder()

    {

        inorder(data);

    }

    void preorder()

    {

        preorder(data);

    }

    void postorder()

    {

        postorder(data);

    }

};


class CircularQueue {
private:
    int front;
    int rear;
    BinaryNode* data[MAX];
public:
    CircularQueue() { front = rear = 0; }
    bool isEmpty() { return front == rear; }
    bool isFull() { return (rear + 1) % MAX == front; }
    void enqueue(BinaryNode* n) {
        if (isFull()) {
            cout << "ť�� ��ȭ�����Դϴ�." << endl;
        }
        else {
            rear = (rear + 1) % MAX;
            data[rear] = n;
        }
    }

    BinaryNode* dequeue() {
        if (isEmpty()) {
            cout << "ť�� ����ֽ��ϴ�." << endl;
        }
        else {
            front = (front + 1) % MAX;
            return data[front];
        }
    }
};

class BinaryTree

{

private:

    bool reverse(BinaryNode* node)

    {

        if (node == NULL)

            return false;

        else

        {

            //���

            reverse(node->getLeft());

            reverse(node->getRight());

            //leftNode�� rightNode�� ���� �ٲ۴�

            BinaryNode* temp = node->getLeft();

            node->setLeft(node->getRight());

            node->setRight(temp);

        }

        return true;

    }

    /*

    bool isBalanced(BinaryNode *node)

    {

           int leftHeight;

           int rightHeight;



           if (node == NULL)

                   return true;



           leftHeight = getHeight(node->getLeft());

           rightHeight = getHeight(node->getRight());



           //���� ����Ʈ���� �����ʼ���Ʈ���� �������� 2�̻� ���� �ʰ� �� �� ������ �������� ��� ��

           if ((leftHeight - rightHeight) <= 1 && (leftHeight - rightHeight) >= -1 && isBalanced(node->getLeft()) && isBalanced(node->getRight()))

                   return true;



           return false;

    }

    int level(BinaryNode *node1, BinaryNode *node2, int lev = 1) //node2�� �츮�� ã���� �ϴ� node

    {

           if (node1 == NULL)

                   return 0;

           if (node1 == node2)

                   return lev;



           if (node1->getLeft() == NULL && node1->getRight() == NULL)

                   return 0;

           //���

           int left = level(node1->getLeft(), node2, lev + 1); //��������

           int right = level(node1->getRight(), node2, lev + 1); //����������



           if (!left) //���� ��尡 �������� �ʴ´ٸ�

                   return right; //������ ��� ��ȯ

           else //�ݴ�

                   return left;

    }

    */

    /*

    void inorder(BinaryNode *node)

    {

           if (node != NULL)

           {

                   if (node->getLeft() != NULL)

                          inorder(node->getLeft());

                   cout << "[" << (int)node->getData() << "] ";

                   if (node->getRight() != NULL)

                          inorder(node->getRight());

           }

    }

    void preorder(BinaryNode *node)

    {

           if (node != NULL)

           {

                   cout << "[" << (int)node->getData() << "] ";

                   if (node->getLeft() != NULL)

                          preorder(node->getLeft());

                   if (node->getRight() != NULL)

                          preorder(node->getRight());

           }

    }

    void postorder(BinaryNode *node)

    {

           if (node != NULL)

           {

                   if (node->getLeft() != NULL)

                          postorder(node->getLeft());

                   if (node->getRight() != NULL)

                          postorder(node->getRight());

                   cout << "[" << (int)node->getData() << "] ";

           }

    }

    */

    int getCount(BinaryNode* node)

    {

        if (node == NULL)

            return 0;

        return 1 + getCount(node->getLeft()) + getCount(node->getRight());

    }

    int getHeight(BinaryNode* node)

    {

        if (node == NULL)

            return 0;

        int hLeft = getHeight(node->getLeft());

        int hRight = getHeight(node->getRight());

        return (hLeft > hRight) ? hLeft + 1 : hRight + 1;

    }

    int getLeafCount(BinaryNode* node)

    {

        if (node == NULL)

            return 0;

        if (node->isLeaf())

            return 1;

        else

            return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());

    }

    int evaluate(BinaryNode* node)

    {

        if (node == NULL)

            return 0;

        if (node->isLeaf())

            return node->getData();

        else

        {

            int op1 = evaluate(node->getLeft());

            int op2 = evaluate(node->getRight());

            switch (node->getData())

            {

            case '+':

                return op1 + op2;

            case '-':

                return op1 - op2;

            case '*':

                return op1 * op2;

            case '/':

                return op1 / op2;

            }

            return 0;

        }

    }

    //��ȯ ȣ�⿡ ���� node�� ��Ʈ�� �ϴ� Ʈ���� ��ü �뷮 ��� �Լ�

    int calcSize(BinaryNode* node)

    {

        if (node == NULL)

            return 0;

        return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());

    }

protected:

    BinaryNode* root;

public:

    BinaryTree() :root(NULL)

    {

    }

    void setRoot(BinaryNode* node)

    {

        root = node;

    }

    BinaryNode* getRoot()

    {

        return root;

    }

    bool isEmpty()

    {

        return root == NULL;

    }

    bool isFull() //����Ʈ���� ���� ����Ʈ������ �˻��ϴ� �Լ�

    {

        if (!isEmpty())

        {

            CircularQueue q;

            q.enqueue(root);

            while (!q.isEmpty())

            {

                BinaryNode* n = q.dequeue();

                //���ܳ�尡 �ƴϰ� ���� ������ �ڽ� �� �ϳ��� ������ ��������Ʈ�� X

                if (!(n->isLeaf()) && n->getLeft() == NULL && n->getRight() != NULL)

                    return false;

                else if (!(n->isLeaf()) && n->getLeft() != NULL && n->getRight() == NULL)

                    return false;

                if (n != NULL)

                {

                    if (n->getLeft())

                        q.enqueue(n->getLeft());

                    if (n->getRight())

                        q.enqueue(n->getRight());

                }

            }

            return true;

        }

    }

    /*

    bool isBalanced() //������ �����ִ°�?

    {

           return isBalanced(root);

    }

    //�ڹٲ۴�

    bool reverse()

    {

           return reverse(root);

    }

    void inorder()

    {

           cout << endl << "inorder: ";

           inorder(root);

    }

    void preorder()

    {

           cout << endl << "preorder: ";

           preorder(root);

    }

    void postorder()

    {

           cout << endl << "postorder: ";

           postorder(root);

    }

    */



    int getCount()

    {

        return isEmpty() ? 0 : getCount(root);

    }

    int getHeight()

    {

        return isEmpty() ? 0 : getHeight(root);

    }

    int getLeafCount()

    {

        return isEmpty() ? 0 : getLeafCount(root);

    }

    /*

    int evaluate()

    {

           return evaluate(root);

    }

    //���͸� �뷮 ��� �Լ�

    int calcSize()

    {

           return calcSize(root);

    }

    //������ ���ϴ� ����

    int level(BinaryNode *node)

    {

           return level(root, node);

    }

    //����� ����

    int pathLength()

    {

           int sum = 0;

           if (!isEmpty())

           {

                   CircularQueue q;

                   q.enqueue(root);

                   while (!q.isEmpty())

                   {

                          BinaryNode *n = q.dequeue();

                          sum += level(n) - 1; //�� ����� ����-1��ŭ ���ϸ� �� ���

                          if (n != NULL)

                          {

                                  if(n->getLeft())

                                          q.enqueue(n->getLeft());

                                  if(n->getRight())

                                          q.enqueue(n->getRight());

                          }

                   }

           }

           return sum;

    }

    */

};


class BinSrchTree :public BinaryTree

{

public:

    BinSrchTree(void)

    {

    }

    ~BinSrchTree(void)

    {

    }

    //���� Ž�� Ʈ���� Ž�� ����

    BinaryNode* search(int key)

    {

        BinaryNode* node = searchRecur(root, key);

        if (node != NULL)

        {

            cout << "Ž�� ����:Ű ���� " << node->getData();

            printf("�� ���=0x%x\n", node);

        }

        else

            cout << "Ž�� ����: Ű���� " << key << "�� ��� ����" << endl;

        return node;

    }

    BinaryNode* searchRecur(BinaryNode* n, int key)

    {

        if (n == NULL)

            return NULL;

        if (key == n->getData())

            return n;

        else if (key < n->getData())

            return searchRecur(n->getLeft(), key);

        else

            return searchRecur(n->getRight(), key);

    }

    BinaryNode* searchIter(BinaryNode* n, int key)

    {

        while (n != NULL)

        {

            if (key == n->getData())

                return n;

            else if (key < n->getData())

                n = n->getLeft();

            else

                n = n->getRight();

        }

    }

    //���� Ž�� Ʈ���� ���� ����

    void insert(BinaryNode* n)

    {

        if (n == NULL)

            return;

        if (isEmpty())

            root = n;

        else

            insertRecur(root, n);

    }

    void insertRecur(BinaryNode* r, BinaryNode* n)

    {

        if (n->getData() == r->getData())

            return;

        else if (n->getData() < r->getData())

        {

            if (r->getLeft() == NULL)

                r->setLeft(n);

            else

                insertRecur(r->getLeft(), n);

        }

        else

        {

            if (r->getRight() == NULL)

                r->setRight(n);

            else

                insertRecur(r->getRight(), n);

        }

    }

    //���� Ž�� Ʈ���� ���� ����

    void remove(int key)

    {

        if (isEmpty())

            return;

        //���� ���� �� ����� �θ� ��带 ã�´�

        BinaryNode* parent = NULL; //���� ����� �θ�

        BinaryNode* node = root; //���� ���

        while (node != NULL && node->getData() != key)

        {

            parent = node;

            node = (key < node->getData()) ? node->getLeft() : node->getRight();

        }

        //���� ��尡 Ʈ���� ����

        if (node == NULL)

        {

            cout << "Error: key is not in the tree!" << endl;

            return;

        }

        //���� ��尡 Ʈ���� ����

        else

            remove(parent, node);

    }

    //parent�� �θ�� ���� ��� node�� ����Ž�� Ʈ������ �����ϴ� �Լ�

    void remove(BinaryNode* parent, BinaryNode* node)

    {

        //case1:�����Ϸ��� ��尡 �ܸ������ ���

        if (node->isLeaf())

        {

            if (parent == NULL)

                root = NULL; //����� ���� ������ �����ؾ��ϹǷ� BinaryTree.h�� ��� ���� BinaryNode *root�� protected�� ����

            else

            {

                if (parent->getLeft() == node)

                    parent->setLeft(NULL);

                else

                    parent->setRight(NULL);

            }

        }

        //case2: �����Ϸ��� ��尡 �����̳� ������ �ڽĸ� ���� ���

        else if (node->getLeft() == NULL || node->getRight() == NULL)

        {

            //������ ����� ������ �ڽĳ��=>child

            BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();

            //������ ��尡 ��Ʈ�̸�==>child�� ���ο� root�� ��

            if (node == root)

                root = child;

            //�ƴϸ�==>�θ����� �ڽ����� �ڽ� ��� child�� ���� ����

            else

            {

                if (parent->getLeft() == node)

                    parent->setLeft(child);

                else

                    parent->setRight(child);

            }

        }

        //case3: �����Ϸ��� ��尡 �ΰ��� �ڽ��� ��� �ִ� ���

        else

        {

            //�����Ϸ��� ����� ������ ����Ʈ������ ���� ���� ��带 Ž��

            //succ=>�İ� ���:������ ����Ʈ������ ���� key�� ���� ���

            //succp=>�İ� ����� �θ� ���

            BinaryNode* succp = node;

            BinaryNode* succ = node->getRight();

            while (succ->getLeft() != NULL)

            {

                succp = succ;

                succ = succ->getLeft();

            }

            //�İ� ����� �θ�� �İ� ����� ������ �ڽ��� ���� ����

            if (succp->getLeft() == succ)

                succp->setLeft(succ->getRight());

            else //�İ��尡 ������ ����� �ٷ� ������ �ڽ��� ���

                succp->setRight(succ->getRight());

            //�İ� ��� ������ ������ ��忡 ����

            node->setData(succ->getData());

            //������ ��带 �İ� ���� ����: �����δ� �İ� ��尡 ���ŵ�

            node = succ;

        }

        delete node; //�޸� ��������

    }

};

int main(void)

{

    BinaryTree tree, tree2, tree3;

    BinaryNode* d = new BinaryNode('D', NULL, NULL);

    BinaryNode* e = new BinaryNode('E', NULL, NULL);

    BinaryNode* b = new BinaryNode('B', d, e);

    BinaryNode* f = new BinaryNode('F', NULL, NULL);

    BinaryNode* c = new BinaryNode('C', f, NULL);

    BinaryNode* a = new BinaryNode('A', b, c);

    tree.setRoot(a);

    //tree.inorder();

    //tree.preorder();

    //tree.postorder();

    cout << "INORDER: ";

    a->inorder();

    cout << endl;

    cout << "PREORDER: ";

    a->preorder();

    cout << endl;

    cout << "POSTORDER: ";

    a->postorder();

    cout << endl;

    /*

    tree.levelorder();

    if (tree.isFull())

           cout << "tree�� ���� ����Ʈ���̴�" << endl;

    else

           cout << "tree�� ���� ����Ʈ���� �ƴϴ�" << endl;

    cout << "d�� ������ " << tree.level(d) << endl;

    if (tree.isBalanced())

           cout << "tree�� ������ �����ִ�" << endl;

    else

           cout << "tree�� ������ �������� �ʴ�" << endl;

    cout << "�� ����� ����: " << tree.pathLength() << endl;

    if (tree.reverse())

           cout << endl << "tree reverse �Ϸ�" << endl;

    else

           cout << endl << "tree reverse ����" << endl;

    tree.inorder();

    cout << endl;

    */

    cout << "����� ����= " << tree.getCount() << endl;

    cout << "�ܸ��� ����= " << tree.getLeafCount() << endl;

    cout << "Ʈ���� ����= " << tree.getHeight() << endl;

    /*

    BinaryNode *n1 = new BinaryNode(3, NULL, NULL);

    BinaryNode *n2 = new BinaryNode(2, NULL, NULL);

    BinaryNode *n3 = new BinaryNode('*',n1, n2);

    BinaryNode *n4 = new BinaryNode(5, NULL, NULL);

    BinaryNode *n5 = new BinaryNode(6, NULL, NULL);

    BinaryNode *n6 = new BinaryNode('-', n4, n5);

    BinaryNode *n7 = new BinaryNode('+', n3, n6);

    tree2.setRoot(n7);

    cout << "��� ���= " << tree2.evaluate() << endl;

    BinaryNode *m4 = new BinaryNode(200, NULL, NULL);

    BinaryNode *m5 = new BinaryNode(500, NULL, NULL);

    BinaryNode *m3 = new BinaryNode(100, m4, m5);

    BinaryNode *m2 = new BinaryNode(50, NULL, NULL);

    BinaryNode *m1 = new BinaryNode(0, m2, m3);

    tree3.setRoot(m1);

    cout << "���͸� �뷮 ��� ��� = " << tree3.calcSize() << endl;

    */

    return 0;

}
