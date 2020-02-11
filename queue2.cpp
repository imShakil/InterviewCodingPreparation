#include<stdio.h>

struct queue{
    int f, r, capacity, count;
    int* q;

    queue(int size)
    {
        f = count = 0;
        r = -1;
        capacity = size;
        q = new int[size];
    }

    ~queue()
    {
        delete q;
    }

    void push(int d)
    {
        r = (r+1)%capacity;
        q[r] = d;
        count++;
    }

    int front()
    {
        return q[f];
    }

    void pop()
    {
        f = (f+1)%capacity;
        count--;
    }

    bool empty()
    {
        return size()==0;
    }

    int size()
    {
        return count;
    }

    bool overflow()
    {
        return (size()==capacity);
    }
    void exit(char e[])
    {
        printf("%s\n", e);
    }
};

int main()
{
    int n;
    scanf("%d", &n); /// Initial Size of Queue
    queue q(n); /// initiate queue

    while(!q.overflow())  /// insert all the elements into queue.
    {
        int x;
        scanf("%d", &x);
        q.push(x);
    }

    while(!q.empty())
    {
        printf("%d\n", q.front()); q.pop();   /// display front element & pop element
    }
    return 0;
}
