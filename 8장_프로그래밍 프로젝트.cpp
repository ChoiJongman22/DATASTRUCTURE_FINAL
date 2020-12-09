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
            cout << "큐가 포화상태입니다." << endl;
        }
        else {
            rear = (rear + 1) % MAX;
            data[rear] = n;
        }
    }

    BinaryNode* dequeue() {
        if (isEmpty()) {
            cout << "큐가 비어있습니다." << endl;
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

            //재귀

            reverse(node->getLeft());

            reverse(node->getRight());

            //leftNode와 rightNode를 서로 바꾼다

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



           //왼쪽 서브트리와 오른쪽서브트리의 높이차가 2이상 나지 않고 둘 다 균형이 잡혀있을 경우 참

           if ((leftHeight - rightHeight) <= 1 && (leftHeight - rightHeight) >= -1 && isBalanced(node->getLeft()) && isBalanced(node->getRight()))

                   return true;



           return false;

    }

    int level(BinaryNode *node1, BinaryNode *node2, int lev = 1) //node2가 우리가 찾고자 하는 node

    {

           if (node1 == NULL)

                   return 0;

           if (node1 == node2)

                   return lev;



           if (node1->getLeft() == NULL && node1->getRight() == NULL)

                   return 0;

           //재귀

           int left = level(node1->getLeft(), node2, lev + 1); //왼쪽으로

           int right = level(node1->getRight(), node2, lev + 1); //오른쪽으로



           if (!left) //왼쪽 노드가 존재하지 않는다면

                   return right; //오른쪽 노드 반환

           else //반대

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

    //순환 호출에 의해 node를 루트로 하는 트리의 전체 용량 계산 함수

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

    bool isFull() //이진트리가 완전 이진트리인지 검사하는 함수

    {

        if (!isEmpty())

        {

            CircularQueue q;

            q.enqueue(root);

            while (!q.isEmpty())

            {

                BinaryNode* n = q.dequeue();

                //말단노드가 아니고 왼쪽 오른쪽 자식 중 하나라도 없으면 완전이진트리 X

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

    bool isBalanced() //균형이 잡혀있는가?

    {

           return isBalanced(root);

    }

    //뒤바꾼다

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

    //디렉터리 용량 계산 함수

    int calcSize()

    {

           return calcSize(root);

    }

    //레벨을 구하는 연산

    int level(BinaryNode *node)

    {

           return level(root, node);

    }

    //경로의 길이

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

                          sum += level(n) - 1; //각 노드의 레벨-1만큼 더하면 총 경로

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

    //이진 탐색 트리의 탐색 연산

    BinaryNode* search(int key)

    {

        BinaryNode* node = searchRecur(root, key);

        if (node != NULL)

        {

            cout << "탐색 성공:키 값이 " << node->getData();

            printf("인 노드=0x%x\n", node);

        }

        else

            cout << "탐색 실패: 키값이 " << key << "인 노드 없음" << endl;

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

    //이진 탐색 트리의 삽입 연산

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

    //이진 탐색 트리의 삭제 연산

    void remove(int key)

    {

        if (isEmpty())

            return;

        //없앨 노드와 그 노드의 부모 노드를 찾는다

        BinaryNode* parent = NULL; //없앨 노드의 부모

        BinaryNode* node = root; //없앨 노드

        while (node != NULL && node->getData() != key)

        {

            parent = node;

            node = (key < node->getData()) ? node->getLeft() : node->getRight();

        }

        //없앨 노드가 트리에 없음

        if (node == NULL)

        {

            cout << "Error: key is not in the tree!" << endl;

            return;

        }

        //없앨 노드가 트리에 있음

        else

            remove(parent, node);

    }

    //parent를 부모로 갖는 노드 node를 이진탐색 트리에서 삭제하는 함수

    void remove(BinaryNode* parent, BinaryNode* node)

    {

        //case1:삭제하려는 노드가 단말노드일 경우

        if (node->isLeaf())

        {

            if (parent == NULL)

                root = NULL; //상속을 받은 변수를 접근해야하므로 BinaryTree.h의 멤버 변수 BinaryNode *root를 protected로 선언

            else

            {

                if (parent->getLeft() == node)

                    parent->setLeft(NULL);

                else

                    parent->setRight(NULL);

            }

        }

        //case2: 삭제하려는 노드가 왼쪽이나 오른쪽 자식만 갖는 경우

        else if (node->getLeft() == NULL || node->getRight() == NULL)

        {

            //삭제할 노드의 유일한 자식노드=>child

            BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();

            //삭제할 노드가 루트이면==>child가 새로운 root가 됨

            if (node == root)

                root = child;

            //아니면==>부모노드의 자식으로 자식 노드 child를 직접 연결

            else

            {

                if (parent->getLeft() == node)

                    parent->setLeft(child);

                else

                    parent->setRight(child);

            }

        }

        //case3: 삭제하려는 노드가 두개의 자식이 모두 있는 경우

        else

        {

            //삭제하려는 노드의 오른쪽 서브트리에서 가장 작은 노드를 탐색

            //succ=>후계 노드:오른쪽 서브트리에서 가장 key가 작은 노드

            //succp=>후계 노드의 부모 노드

            BinaryNode* succp = node;

            BinaryNode* succ = node->getRight();

            while (succ->getLeft() != NULL)

            {

                succp = succ;

                succ = succ->getLeft();

            }

            //후계 노드의 부모와 후계 노드의 오른쪽 자식을 직접 연결

            if (succp->getLeft() == succ)

                succp->setLeft(succ->getRight());

            else //후계노드가 삭제할 노드의 바로 오른쪽 자식인 경우

                succp->setRight(succ->getRight());

            //후계 노드 정보를 삭제할 노드에 복사

            node->setData(succ->getData());

            //삭제할 노드를 후계 노드로 변경: 실제로는 후계 노드가 제거됨

            node = succ;

        }

        delete node; //메모리 동적해제

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

           cout << "tree는 완전 이진트리이다" << endl;

    else

           cout << "tree는 완전 이진트리가 아니다" << endl;

    cout << "d의 레벨은 " << tree.level(d) << endl;

    if (tree.isBalanced())

           cout << "tree는 균형이 잡혀있다" << endl;

    else

           cout << "tree는 균형이 잡혀있지 않다" << endl;

    cout << "총 경로의 길이: " << tree.pathLength() << endl;

    if (tree.reverse())

           cout << endl << "tree reverse 완료" << endl;

    else

           cout << endl << "tree reverse 실패" << endl;

    tree.inorder();

    cout << endl;

    */

    cout << "노드의 개수= " << tree.getCount() << endl;

    cout << "단말의 개수= " << tree.getLeafCount() << endl;

    cout << "트리의 높이= " << tree.getHeight() << endl;

    /*

    BinaryNode *n1 = new BinaryNode(3, NULL, NULL);

    BinaryNode *n2 = new BinaryNode(2, NULL, NULL);

    BinaryNode *n3 = new BinaryNode('*',n1, n2);

    BinaryNode *n4 = new BinaryNode(5, NULL, NULL);

    BinaryNode *n5 = new BinaryNode(6, NULL, NULL);

    BinaryNode *n6 = new BinaryNode('-', n4, n5);

    BinaryNode *n7 = new BinaryNode('+', n3, n6);

    tree2.setRoot(n7);

    cout << "계산 결과= " << tree2.evaluate() << endl;

    BinaryNode *m4 = new BinaryNode(200, NULL, NULL);

    BinaryNode *m5 = new BinaryNode(500, NULL, NULL);

    BinaryNode *m3 = new BinaryNode(100, m4, m5);

    BinaryNode *m2 = new BinaryNode(50, NULL, NULL);

    BinaryNode *m1 = new BinaryNode(0, m2, m3);

    tree3.setRoot(m1);

    cout << "디렉터리 용량 계산 결과 = " << tree3.calcSize() << endl;

    */

    return 0;

}
