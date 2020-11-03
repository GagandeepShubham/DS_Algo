/**
 * Implementation of a min heap, following procedures are used
 * build_heap() - build a heap, just a simple heap
 * min_heapify(index, heapsize) - min heapify the heap
 * heap_sort() - sorts the heap in decreasing order
**/
#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

int left(int i)
{
    return ((2 * i) + 1);
}

int right(int i)
{
    return ((2 * i) + 2);
}

void min_heapify(int i, int size)
{
    int left_child = left(i);
    int right_child = right(i);
    int minimum = i;
    if(left_child < size && v[left_child] < v[i])minimum = left_child;
    if(right_child < size && v[right_child] < v[minimum])minimum = right_child;
    if(minimum != i)
    {
        swap(v[i], v[minimum]);
        min_heapify(minimum, size);
    }
}
void build_heap()
{
    for(int i = v.size()/2; i >= 0; i--)
    {
        min_heapify(i, v.size());
    }
}

void heap_sort()
{
    int size = v.size();
    for(int i = v.size() - 1; i > 0; i--)
    {
        swap(v[i], v[0]);
        size--;
        min_heapify(0, size);
    }
}
int main()
{
    v = {12, 4, 3, 9, 8, 1, 5, 7};

    build_heap();

    heap_sort(); // will sort in reverse order (descending), because it is a min heap.

    for(int x: v)cout << x << " ";
    cout << "\n";
}