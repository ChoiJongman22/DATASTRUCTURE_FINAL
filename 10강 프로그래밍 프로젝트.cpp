#include <iostream>
#include <time.h>
using namespace std;
#define MAX_ELEMENT 100


class MaxPriorityQueue

{

private:

    int elem[MAX_ELEMENT]; //����� �迭

    int size; //���� ����� ����

public:

    MaxPriorityQueue()

    {

        size = 0;

    }

    int getParent(int i)

    {

        return i / 2;

    }

    int getLeft(int i)

    {

        return i * 2;

    }

    int getRight(int i)

    {

        return i * 2 + 1;

    }

    void insert(int data) //���� �Լ�

    {

        if (size == MAX_ELEMENT)

            return;

        int i = ++size;

        while (i != 1 && data > elem[getParent(i)]) //��Ʈ�� �ƴϰ� �θ��庸�� ���� ũ��

        {

            elem[i] = elem[getParent(i)]; //�θ� �ڽĳ��� �������

            i /= 2; //�� ���� ���

        }

        elem[i] = data;

    }

    int remove() //�ִ� �׸� ���� �� ��ȯ �Լ�

    {

        if (!size)

            return NULL;

        int root = elem[1];

        int last = elem[size--];

        int parent = 1;

        int child = 2;

        while (child <= size)

        {

            if (child < size && elem[getParent(parent)] < elem[getParent(parent)])

                child++;

            if (elem[last] >= elem[child])

                break;

            elem[parent] = elem[child];

            parent = child;

            child *= 2;

        }

        elem[parent] = last;

        child *= 2;

    }

    int find() //�ִ� �׸� ��ȯ �Լ�

    {

        return elem[1];

    }

    void display() //�켱���� ť�� ��� �׸� ���
    {
        int res = 1;
        int square = 2;
        int height = 1;
        int start = 0;
        while (res <= size)
        {
            res *= 2;
            height++;
        }
        for (int i = 1; i <= size; i++)
        {
            if (i == 1 || i == square)
            {
                cout << endl;
                for (int j = start; j < height; j++)
                    cout << "    ";
                if (i != 1)
                    square *= 2;
                start++;
            }
            cout << elem[i];
            for (int j = 0; j < height - start; j++)
            {
                if (i % 2)
                    cout << "  ";
                else
                    cout << "    ";
            }
        }
        cout << endl;
    }
};



int main(void)

{

    MaxPriorityQueue q;

    int arr[10];

    srand((unsigned)time(NULL));

    cout << "���� �ȵ� �迭: ";

    for (int i = 0; i < 10; i++)

    {

        arr[i] = rand() % 100 + 1;

        cout << arr[i] << " ";

    }

    cout << endl;

    cout << "�켱���� ť" << endl;

    for (int i = 0; i < 10; i++)

        q.insert(arr[i]);

    q.display();

    return 0;

}

