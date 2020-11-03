/**
 * Implementation of the heap data structure.
**/
#include<iostream>
#include<vector>
using namespace std;
vector<int> v(100);

int parent(int i) //returns index of the parent
{
    return (i)/2; 
}
int left(int i) //returns index of the left child
{
    return (2 * i);
}
int right(int i)//returns index of the right child
{
    return (2 * i + 1);
}
void swap(int *a, int *b) //swaps the elements
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int i, int n) //max heapify the heap
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l <= n && v[l] > v[largest])largest = l;
    if(r <= n && v[r] > v[largest])largest = r;
    if(largest != i)
    {
        swap(v[i], v[largest]);
        max_heapify(largest, n);
    }
}
void build_heap(int n) //builds a heap by calling max heapifying it.
{
    for(int i = n/2; i >= 1; i--)
    {
        max_heapify(i, n);
    }
}

void print_heap(int n)
{
    for(int i = 1; i <= n; i++)cout << v[i] << " ";
    cout << "\n";
}
int main()
{
    //vector<int> v; //vector to store the heap elements
    int i, data, n;
    cout << "Enter the number of elements to be inserted:";
    cin >> n;
    cout << "Enter elements to be inserted in the heap:";
    for(i = 1; i <= n; i++)
    {   
        cin >> data;
        v[i] = data;
    }
    build_heap(n); //building the max heap

    print_heap(n); //printing the heap.
}