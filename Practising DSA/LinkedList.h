/*
========== Linked List ==========

Functions:
    insert
    print
    erase
    reverse
    isEmpty
    size
    getValue
    changeValue
    swap
    getPosition
    sort
    operation==
    
*/

template <class T>
class Node
{

public:
    T label;
    Node *next;

    Node(T value)
        : label(value),
          next(NULL) {}
};

template <class T>
class LinkedList
{

public:
    LinkedList()
        : head(NULL) {}

    void insert(T data)
    {
        Node<T> *newNode = new Node<T>(data);

        if (isEmpty())
        {
            head = newNode;
            return;
        }
        Node<T> *currentNode = head;
        while (currentNode->next != NULL)
            currentNode = currentNode->next;
        currentNode->next = newNode;
    }

    void insert(T data, long long position)
    {
        Node<T> *newNode = new Node<T>(data);

        if (isEmpty())
        {
            head = newNode;
            return;
        }
        if (position == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node<T> *currentNode = locate(position - 1);
        Node<T> *nodeAtPosition = currentNode->next;
        currentNode->next = newNode;
        currentNode = currentNode->next;
        currentNode->next = nodeAtPosition;
    }

    void print(string separator)
    {
        Node<T> *currentNode = head;
        while (currentNode != NULL)
        {
            cout << currentNode->label;
            currentNode = currentNode->next;
            if (currentNode)
                cout << separator;
        }
    }

    void erase()
    {
        while (!isEmpty())
        {
            Node<T> *temp = head->next;
            head = head->next;
            delete temp;
        }
    }

    void erase(long long position)
    {
        if (position == 0)
        {
            Node<T> *newNode = head->next;
            Node<T> *temp = head;
            delete temp;
            head = newNode;
            return;
        }
        Node<T> *currentNode = head;
        Node<T> *prev = head;
        for (int i = 0; i < position; i++)
        {
            prev = currentNode;
            currentNode = currentNode->next;
        }
        prev->next = currentNode->next;
        delete currentNode;
    }

    void reverse()
    {
        Node<T> *tail = NULL, t = new Node<T>;
        Node<T> *currentNode = head;
        while (currentNode != NULL)
        {
            t = currentNode->next;
            currentNode->next = tail;
            tail = currentNode;
            currentNode = t;
        }
        head = tail;
    }

    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    long long size()
    {
        Node<T> *currentNode = head;
        long long counter = 0;
        while (currentNode != NULL)
        {
            currentNode = currentNode->next;
            counter++;
        }
        return counter;
    }

    T getValue(long long position)
    {
        // list.get(3) --> list[3]

        Node<T> *currentNode = locate(position);
        return currentNode->label;
    }

    void changeValue(T data, long long position)
    {
        // list.change(5, 3) --> list[3] = 5

        if (isEmpty())
            return;

        erase(position);
        insert(data, position);
    }

    void swap(long long position1, long long position2)
    {
        /*
            list = 7 -> 8 -> 9 -> 10 -> 11
                   0    1    2     3     4
            
            list.swap(1, 2)
            list = 7 -> 9 -> 8 -> 10 -> 11
            */

        if (size() <= 1)
            return;

        Node<T> *currentNode1 = locate(position1);
        Node<T> *currentNode2 = locate(position2);

        T temporary = currentNode2->label;

        change(currentNode1->label, position2);
        change(temporary, position1);
    }

    long long getPosition(T data)
    {
        /*
            list = {7, 8, 4, 9}
                    0  1  2  3
        
            list.getPos(4) = 2
            */

        long long position = 0;
        Node<T> *currentNode = head;
        while (currentNode != NULL)
        {
            if (currentNode->label = data)
                return position;
            currentNode = currentNode->next;
            position++;
        }
        return -1;
    }

    void sort()
    {
        // Merge sort is preffered way to sort a linked list

        MergeSort(&head);
    }

    bool operator==(LinkedList<T> list2)
    {
        /*
            list1 = {1, 2, 3, 4}
            list2 = {1, 3, 4, 5}

            list1 == list2 --> false
            */

        Node<T> *currentNode1 = head;
        Node<T> *currentNode2 = list2.head;
        while (currentNode1 != NULL && currentNode2 != NULL && currentNode1->label == currentNode2->label)
        {
            currentNode1 = currentNode1->next;
            currentNode2 = currentNode2->next;
        }
        return currentNode1 == currentNode2;
    }

    // -------------- PRIVATE --------------

private:
    Node<T> *head;

    Node<T> *locate(long long position)
    {
        /*
            |head| -> |data, next| -> |data, next| -> |data, next| -> |NULL|
            list.locate(2)                               currentNode
                                                            V
            |head| -> |data, next| -> |data, next| -> |data, next| -> |NULL|

            currentNode points at the node with index 2 (third node)
            */

        Node<T> *currentNode = head;
        int currentPosition = 0;
        while (currentPosition < position && currentNode != NULL)
        {
            currentNode = currentNode->next;
            currentPosition++;
        }
        return currentNode;
    }

    void MergeSort(Node<T> **headRef)
    {
        Node<T> *head = *headRef;
        Node<T> *a;
        Node<T> *b;

        if ((head == NULL) || (head->next == NULL))
            return;

        FrontBackSplit(head, &a, &b);

        MergeSort(&a);
        MergeSort(&b);

        *headRef = SortedMerge(a, b);
    }

    Node<T> *SortedMerge(Node<T> *a, Node<T> *b)
    {
        Node<T> *result = NULL;

        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);

        if (a->label <= b->label)
        {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else
        {
            result = b;
            result->next = SortedMerge(a, b->next);
        }

        return (result);
    }

    void FrontBackSplit(Node<T> *source, Node<T> **frontRef, Node<T> **backRef)
    {
        Node<T> *fast;
        Node<T> *slow;
        slow = source;
        fast = source->next;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
};