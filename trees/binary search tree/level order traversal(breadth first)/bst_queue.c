


BstNode *queue[1000];
int front = -1;
int rear = -1;

void push(BstNode *);
void pop();
void front_data();

void push(BstNode *root)
{
    if (front == -1)
        front++;
    queue[++rear] = root;
}

void pop()
{
    front++;
}

int front_data()
{
    return queue[front]->data;
}
