// [SEA]기초 Single Linked List 연습 / ??? / 2시간
#define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
    nodeCnt = 0;
    head = getNode(-1); // head->next = nullptr;로 하면 Segfault 발생
}

void addNode2Head(int data) 
{
    Node* nodeAdd = getNode(data);
    nodeAdd->next = head->next;
    head->next = nodeAdd;
}

void addNode2Tail(int data) 
{
    
    Node* ptr = head;
    while(ptr->next != nullptr) 
        ptr = ptr->next;
    
    ptr->next = getNode(data);
}

void addNode2Num(int data, int num) 
{
    Node* ptr = head;
    int i = 1;
    while(i < num){
        ptr = ptr->next;
        i++;
    }

    Node* nodeAdd = getNode(data);
    nodeAdd->next = ptr->next;
    ptr->next = nodeAdd;
}

void removeNode(int data) 
{
    Node* ptr = head;
    while(ptr->next != nullptr && ptr->next->data != data)
        ptr = ptr->next;
    if(ptr->next != nullptr && ptr->next->data == data) // ptr->next가 nullptr일때 nullptr->data를 참조하지 않도록
        ptr->next = ptr->next->next;
}

int getList(int output[MAX_NODE]) 
{
    Node* ptr = head;
    int i = 0;
    while(ptr->next != nullptr){
        output[i++] = ptr->next->data;
        ptr = ptr->next;
    }

    return i;
}