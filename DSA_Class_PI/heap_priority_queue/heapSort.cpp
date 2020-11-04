//Implementation of Heap sort algorithm

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>v;
int left(int i)
{
    return 2 * i;//((2 * i )+ 1);
}

int right(int i)
{
    return 2 * i + 1;//((2 *i )+ 2);
}

void max_heapify(int i, int size)
{
    int left_child = left(i);
    int right_child = right(i);
    int largest;
    if(left_child < size && v[left_child] > v[i])largest = left_child;
    else largest = i;
    if(right_child < size && v[right_child] > v[largest])largest = right_child;
    if(largest != i)
    {
        swap(v[i], v[largest]);
        max_heapify(largest, size);
    }
}

void build_maxheap()
{
    for(int i = v.size()/2; i >= 0; i--)
    {
        max_heapify(i, v.size());
    }
}
void heapsort()
{
    
    build_maxheap();  
    int size = v.size();
    for(int i = v.size() - 1; i > 0; i--)
    {
        swap(v[0], v[i]);
        size--;
        max_heapify(0, size);
    }
}
int main()
{
    v = {3, 5, 1, 9, 6, 2, 10, 7}; //elements for heap

    heapsort();

    for(int x: v)cout << x << " ";
    cout<< "\n";
}
