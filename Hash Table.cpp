#include <iostream>
#include <algorithm>
#include <time.h>
#include <cmath>
using namespace std;
static int NoofFiles = 0;
//----------------------------------------------------Creating AVL TREE-----------------------------------------------------------------
struct AVLTreeNode {
    int TreeData;
    AVLTreeNode* LeftChild;
    AVLTreeNode* RightChild;
};
//----------------------------------------------------Creating AVL TREE-----------------------------------------------------------------
class AVLTree {
public:
    AVLTreeNode* RootNode;
    int File = 0;
    int Line = 0;

    AVLTree() {
        RootNode = NULL;
    }

    int  difference(AVLTreeNode* root)
    {
        int leftheight = height(root->LeftChild);
        int rightheight = height(root->RightChild);
        int Balancefactor = leftheight - rightheight;
        return Balancefactor;
    }
    int  height(AVLTreeNode* root)
    {
        int h = 0;
        if (root != NULL) {
            int leftheight = height(root->LeftChild);
            int rightheight = height(root->RightChild);
            int maxheight = 0;
            if (leftheight > rightheight)
                maxheight = leftheight;
            else
                maxheight = rightheight;
            h = maxheight + 1;
        }
        return h;
    }
    AVLTreeNode* RighttoRight_rotat(AVLTreeNode* root)
    {
        AVLTreeNode* s;
        s = root->RightChild;
        root->RightChild = s->LeftChild;
        s->LeftChild = root;

        return s;
    }
    AVLTreeNode* lefttoleft_rotat(AVLTreeNode* root)
    {
        AVLTreeNode* s;
        s = root->LeftChild;
        root->LeftChild = s->RightChild;
        s->RightChild = root;

        return s;
    }
    AVLTreeNode* lefttoright_rotat(AVLTreeNode* root)
    {
        AVLTreeNode* s;
        s = root->LeftChild;
        root->LeftChild = RighttoRight_rotat(s);

        return lefttoleft_rotat(root);
    }
    AVLTreeNode* righttoleft_rotat(AVLTreeNode* root)
    {
        AVLTreeNode* s;
        s = root->RightChild;
        root->RightChild = lefttoleft_rotat(s);

        return RighttoRight_rotat(root);
    }
    AVLTreeNode* balance(AVLTreeNode* root) {
        int balance_factor = difference(root);
        if (balance_factor > 1)
        {
            if (difference(root->LeftChild) > 0)
                root = lefttoleft_rotat(root);
            else
                root = lefttoright_rotat(root);
        }
        else if (balance_factor < -1)
        {
            if (difference(root->RightChild) > 0)
                root = righttoleft_rotat(root);
            else
                root = RighttoRight_rotat(root);
        }
        return root;
    }

    void  DeleteNode(int data) {
        RootNode = deleteNode(RootNode, data);
        return;
    }

    void  InsertNode(int data) {
        RootNode = insert(RootNode, data);
        return;
    }

    AVLTreeNode* insert(AVLTreeNode* root, int TreeInfo) {
        if (root == NULL) {
            root = new AVLTreeNode;
            root->TreeData = TreeInfo;
            Line++;
            if (Line == 100) {
                File++;
                NoofFiles++;
                Line = 0;
            }
            root->LeftChild = NULL;
            root->RightChild = NULL;
            return root;
        }
        else if (TreeInfo < root->TreeData) {
            root->LeftChild = insert(root->LeftChild, TreeInfo);
            root = balance(root);
        }
        else if (TreeInfo >= root->TreeData) {
            root->RightChild = insert(root->RightChild, TreeInfo);
            root = balance(root);
        } return root;
    }

    AVLTreeNode* minValueNode(AVLTreeNode* Node)
    {
        AVLTreeNode* current = Node;

        while (current->LeftChild != NULL)
            current = current->LeftChild;

        return current;
    }

    AVLTreeNode* deleteNode(AVLTreeNode* root1, int TreeData) {

        if (root1 == NULL)
            return root1;
        else if (TreeData > root1->TreeData)
            root1->RightChild = deleteNode(root1->RightChild, TreeData);



        else if (TreeData > root1->TreeData)
            root1->RightChild = deleteNode(root1->RightChild, TreeData);

        else
        {
            if ((root1->LeftChild == NULL) ||
                (root1->RightChild == NULL))
            {
                AVLTreeNode* temp1 = root1->LeftChild ? root1->LeftChild : root1->RightChild;

                if (temp1 == NULL)
                {
                    temp1 = root1;
                    root1 = NULL;
                }
                else
                    *root1 = *temp1;
                free(temp1);
            }
            else
            {
                AVLTreeNode* temp1 = minValueNode(root1->RightChild);
                root1->TreeData = temp1->TreeData;
                root1->RightChild = deleteNode(root1->RightChild, temp1->TreeData);
            }
        }

        root1 = balance(root1);
        return root1;
    }

    void  display() {
        show(RootNode, 1);
        return;
    }

    void  show(AVLTreeNode* p, int LeftChild) {
        int i;
        if (p != NULL) {
            show(p->RightChild, LeftChild + 1);
            cout << " ";
            if (p == RootNode)
                cout << "Root -> ";
            for (i = 0; i < LeftChild && p != RootNode; i++)
                cout << " ";
            cout << p->TreeData;
            show(p->LeftChild, LeftChild + 1);
        }
    }
    void  inorder(AVLTreeNode* t) {
        if (t == NULL)
            return;
        inorder(t->LeftChild);
        cout << t->TreeData << " ";
        inorder(t->RightChild);
    }
    void  PreOrder(AVLTreeNode* t) {
        if (t == NULL)
            return;
        cout << t->TreeData << " ";
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
    void  PostOrder(AVLTreeNode* t) {
        if (t == NULL)
            return;
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        cout << t->TreeData << " ";
    }
};






//----------------------------------------------------Creating RouteNode1-----------------------------------------------------------------

struct RouteNode1 {
    AVLTree data;
    long ID_Node;
    RouteNode1* Next;



};
//----------------------------------------------------Creating RouteNode2-----------------------------------------------------------------
struct RouteNode2 {
    int data;
    int* Info1;
    RouteNode2* Next;
    RouteNode2* Previous;
    RouteNode1* Connection1;
};

//----------------------------------------------------Creating Routing Table-----------------------------------------------------------------

class RoutingTable {
public:
    RouteNode2* Head;
    RouteNode2* Tail;
    RouteNode2* spare;


    void CreateRoutingTable(int Siz, int* MachineList, int MachineSize, int ActiveMachines) {
        RouteNode2* Pointer = Head;

        for (int k = 0; k < MachineSize; k++) {
            int first = MachineList[k];
            Pointer->Info1 = new int[Siz];
            int temp1 = 0, temp2 = 0;
            for (int i = 0; i < Siz; i++) {
                temp2 = pow(2, i);
                temp1 = (first + temp2) % ActiveMachines;
                cout << "PT" << temp1 << endl;
                for (int j = 0; j < MachineSize; j++)
                {
                    if (temp1 > MachineList[j])
                    {
                        if (temp1 > MachineList[MachineSize - 1])
                        {
                            for (int k = 0; k < MachineSize; k++)
                            {
                                if (temp1 < ActiveMachines)
                                {
                                    Pointer->Info1[i] = MachineList[0];
                                }
                                if (temp1 <= MachineList[k])
                                {
                                    Pointer->Info1[i] = MachineList[k];
                                    k = MachineSize;
                                    j = MachineSize;
                                }
                            }
                        }
                    }
                    else
                        if (temp1 <= MachineList[j]) {
                            Pointer->Info1[i] = MachineList[j];
                            j = MachineSize;
                        }

                }
            }
            Pointer = Pointer->Next;
        }

        RouteNode2* Pointer1 = Head;
        for (int k = 0; k < MachineSize; k++) {
            cout << "k" << k << endl;
            for (int i = 0; i < Siz; i++) {

                cout << Pointer1->Info1[i] << endl;
            }
            cout << "----------------" << endl;
            Pointer1 = Pointer1->Next;
        }
    }

    int search(int nodeid, int Key, int Siz, int* MachineList, int MachineSize) {

        RouteNode2* Pointer = Head;
        int TempID = 0;
        for (int i = 0; i < MachineSize; i++) {
            if (MachineList[i] == nodeid)
                TempID = i;
        }

        for (int i = 0; i < TempID; i++) {
            Pointer = Pointer->Next;
        }
        TempID = nodeid;
        int temp2 = 0;
        cout << "Start from Node " << nodeid << endl;
        for (int j = 0; j < MachineSize; j++) {
            if (TempID == Key) {
                cout << "True" << endl;
                temp2 = TempID;
                return temp2;
            }
            else
                if (TempID < Key && Key <= Pointer->Info1[0]) {
                    temp2 = Pointer->Info1[0];
                    cout << "Jump to RouteNode " << temp2 << endl;
                    j = MachineSize;
                    TempID = temp2;
                }
                else
                    for (int i = 0; i < Siz; i++) {
                        if (Pointer->Info1[i] < Key && Key <= Pointer->Info1[i + 1]) {
                            temp2 = Pointer->Info1[i];
                            cout << "Jump to RouteNode " << temp2 << endl;
                            i = Siz;
                            TempID = temp2;
                        }
                    }
            if (Pointer->Next == NULL) {
                Pointer = Head;
            }
            Pointer = Pointer->Next;
        }
        return temp2;
    }

    RoutingTable() {
        Head = NULL;
        Tail = NULL;
        spare = NULL;
    }
    RouteNode2* GetHead() {
        return Head;
    }
    RouteNode2* GetTail() {
        return Tail;
    }

    void createtwoWayrouteNode(int value, RouteNode1* Connection2) {
        RouteNode2* NewNode = new RouteNode2;
        NewNode->data = value;
        NewNode->Connection1 = Connection2;
        NewNode->Previous = NULL;
        NewNode->Next = NULL;
        if (Head == NULL)
        {
            Head = NewNode;
            Tail = NewNode;
        }
        else
        {
            NewNode->Previous = Tail;
            Tail->Next = NewNode;
            Tail = NewNode;
        }
    }

    void insertAt(int DataN, int Ind) {
        int Counter = 0;
        RouteNode2* NewNode = new RouteNode2;
        NewNode->data = DataN;
        NewNode->Previous = NULL;
        NewNode->Next = NULL;
        Tail = Head;
        while (Tail != NULL) {
            Counter++;
            if (Counter == Ind) {
                NewNode->Previous = Tail;
                NewNode->Next = Tail->Next;
                NewNode->Previous->Next = NewNode;
                NewNode->Next->Previous = NewNode;
                Tail = NewNode;
            }
            Tail = Tail->Next;
        }
    }
    void deleterouteNode(int DeleteData) {
        Tail = Head;
        RouteNode2* DeletePtr = NULL;
        while (Tail != NULL) {
            if (Tail->data == DeleteData) {

                DeletePtr = Tail;
                Tail->Previous->Next = Tail->Next;
                Tail->Next->Previous = Tail->Previous;
            }
            Tail = Tail->Next;
        }
        delete DeletePtr;
    }
    void removeAt(int Ind) {
        RouteNode2* DeletePtr = NULL;
        int Counter = 0;
        Tail = Head;
        while (Tail != NULL) {
            Counter++;
            if (Counter == Ind) {
                DeletePtr = Tail;
                Tail->Previous->Next = Tail->Next;
                Tail->Next->Previous = Tail->Previous;

            }
            Tail = Tail->Next;
        }
        delete DeletePtr;
    }
    void sortlist() {
        int temp1 = 0;
        Tail = Head;
        while (Tail != NULL) {
            spare = Tail->Next;
            while (spare != NULL) {
                if (Tail->data > spare->data) {
                    temp1 = Tail->data;
                    Tail->data = spare->data;
                    spare->data = temp1;
                }
                spare = spare->Next;
            }
            Tail = Tail->Next;
        }

    }

    void printforward(RouteNode2* headd) {
        RouteNode2* Store = headd;
        while (Store != NULL) {
            cout << "The data in the RouteNode2 is:" << Store->data << endl;
            Store = Store->Next;
        }
        cout << endl;
    }
    void printreverse(RouteNode2* taill) {
        RouteNode2* temp1 = taill;
        while (temp1 != NULL) {
            cout << "The data in the RouteNode2 is:" << temp1->data << endl;
            temp1 = temp1->Previous;
        }
    }

};



RoutingTable route;
//----------------------------------------------------Creating Circular LINK list-----------------------------------------------------------------
class CircularLinkedList {
public:
    RouteNode1* Head = NULL;
    int Space = 0;
    int N = 0;
    int CurrentN = 0;
    int NoOfMachines = 0;
    int* M_Arr;


    void createMachineNetwork(int Flag) {
        if (Flag == 0) {
            srand(time(NULL));
            M_Arr = new int[NoOfMachines];
            for (int i = 0; i < NoOfMachines; i++) {
                M_Arr[i] = rand() % N;
            }
        }
        else
            if (Flag == 1) {
                int Pointer = 0;
                M_Arr = new int[NoOfMachines];
                for (int i = 0; i < NoOfMachines; i++) {
                    cout << "Enter Machine ID:";
                    cin >> Pointer;
                    M_Arr[i] = Pointer;
                }
            }

        sortNetwork();
        GenerateRandom();
        route.CreateRoutingTable(Space, M_Arr, NoOfMachines, N);

    }

    void sortNetwork() {
        int temp1 = 0;
        int Compare = 0;
        for (int i = 1; i < NoOfMachines; i++) {
            temp1 = M_Arr[i];
            Compare = i - 1;
            while (temp1 < M_Arr[Compare] && Compare != -1) {
                M_Arr[Compare + 1] = M_Arr[Compare];
                Compare--;
            }
            M_Arr[Compare + 1] = temp1;
        }
        return;
    }

    void displaynetwork() {
        for (int i = 0; i < NoOfMachines; i++) {
            cout << M_Arr[i] << endl;
        }
    }



    void insert(int Comp, int DataN) {
        if (Comp == 1) {
            RouteNode1* NewNode1 = new RouteNode1;
            RouteNode1* Point = Head;
            NewNode1->data.InsertNode(DataN);
            NewNode1->Next = Head;
            if (Head != NULL) {
                while (Point->Next != Head)
                    Point = Point->Next;
                Point->Next = NewNode1;
            }
            else
                NewNode1->Next = NewNode1;
            Head = NewNode1;
            Head->ID_Node = M_Arr[CurrentN];
            route.createtwoWayrouteNode(1, Head);

            CurrentN++;
        }
        else
            if (Comp == 0) {
                Head->data.InsertNode(DataN);
            }
    }
    void display() {
        RouteNode1* Point;
        Point = Head;
        do {
            cout << "RouteNode1 " << Point->ID_Node << endl;
            Point->data.display();
            cout << endl << endl << endl;
            Point = Point->Next;
        } while (Point != Head);
    }

    void SettingNodes(int Pointer) {
        int Pointer1 = pow(2, Pointer);
        N = Pointer1;
    }
    void SettingMachines(int Pointer) {
        NoOfMachines = Pointer;
    }

    void SettingSpace(int Pointer) {
        Space = Pointer;
        SettingNodes(Pointer);
    }



    void GenerateRandom() {
        srand(time(NULL));
        int randspace = 0;
        for (int i = 0; i < NoOfMachines; i++)
        {
            insert(1, rand() % N);
            for (int j = 0; j < Space; j++) 
            {
                insert(0, rand() % N);
            }

        }
    }
    void addpair(int Node, int Key) 
    {
        int Pointer = route.search(Node, Key, Space, M_Arr, NoOfMachines);
        cout << endl << Pointer << endl;
        RouteNode1* Pointer1 = Head;
        for (int i = 0; i < NoOfMachines; i++) 
        {
            if (Pointer == Pointer1->ID_Node) 
            {
                Pointer1->data.InsertNode(Key);
            }
            Pointer1 = Pointer1->Next;
        }
    }

    void RemovePair(int Node, int Key) {
        int Pointer = route.search(Node, Key, Space, M_Arr, NoOfMachines);
        cout << endl << Pointer << endl;
        RouteNode1* Pointer1 = Head;
        for (int i = 0; i < NoOfMachines; i++)
        {
            if (Pointer == Pointer1->ID_Node)
            {
                Pointer1->data.DeleteNode(Key);
            }
            Pointer1 = Pointer1->Next;
        }

    }
    void addMachine(int data) 
    {

        int Pointer = data;
        int* Pointer1 = new int[NoOfMachines];
        for (int i = 0; i < NoOfMachines; i++) 
        {
            Pointer1[i] = M_Arr[i];
        }
        NoOfMachines += 1;
        M_Arr = new int[NoOfMachines];
        M_Arr[NoOfMachines - 1] = Pointer;
        sortNetwork();
        insert(1, rand() % N);
        for (int i = 0; i < Space; i++) 
        {
            insert(0, rand() % N);

        }

        route.CreateRoutingTable(Space, M_Arr, NoOfMachines, N);
        return;

    }

};

int hashkey(string Key) {
    char Array = 'a';
    char Array1 = 'A';
    int Outcome = 0;
    int TwoPower = 1;
   
    for (int j = 0; j < Key.length(); j++)
    {
        for (int i = 0; i < 26; i++) 
        {
            if (Key[j] == Array + i || Key[j] == Array1 + i)
            {
                Outcome += pow(10, j);
                Outcome += j;
            }

        }
    }
    return Outcome;
}

int main() {
    CircularLinkedList Pointer;
    Pointer.SettingSpace(5);
    Pointer.SettingMachines(9);
    cout << "------------------------------------";
    cout << "------------------------------------";
    cout << endl;
    Pointer.createMachineNetwork(1);
    cout << "------------------------------------";
    cout << "------------------------------------";
    cout << endl;
    cout << "The circular linked list is: " << endl;
    Pointer.displaynetwork();
    cout << "------------------------------------";
    cout << "------------------------------------";
    cout << endl;
    Pointer.addpair(28, hashkey("m"));
    cout << "------------------------------------";
    cout << "------------------------------------";
    cout << endl;
    Pointer.display();
    cout << "------------------------------------";
    cout << "------------------------------------";
    cout << endl;

    return 0;
}
