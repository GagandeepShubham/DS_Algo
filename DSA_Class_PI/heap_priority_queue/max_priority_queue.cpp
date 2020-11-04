/**
* Implementation of Priority queue using max heap, a priority queue has the following functions
* build_heap() - builds a maxheap by repeatedly calling max heapifying starting from non leaf nodes to root. --- O(n)
* max_heapify() - max heapify the nodes, take two args , first is the index of the node to be heapified , second is heap size -- O(logn)
* heap_maximum() - finds and returns the maximum element from the max heap. -- O(1)
* extract_max() - finds and returns the maximum element while also deleting it from the max heap -- O(logn)
* increase_key() - increases the key at a given index. -- O(logn)
* insert() - inserts a key at the end of the max heap and then call increase_key to maintain heap property. -- O(logn)
* print() - prints the priority queue, this is not the part of the priority queue.
**/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> v;
int parent(int i)
{
    return (i >> 1); //dividing by 2;
}
int left(int i)
{
    return ((2*i) + 1);
}
int right(int i)
{
    return ((2 * i) + 2);
}

void max_heapify(int i, int size)
{
    int left_child = left(i);
    int right_child = right(i);
    int max = i;
    if(left_child < size && v[left_child] > v[max])max = left_child;
    if(right_child < size && v[right_child] > v[max]) max = right_child;
    if(max != i)
    {
        swap(v[i], v[max]); //swapping the max and the current node
        max_heapify(max, size); //heapifying the max element
    }
}
void build_heap() //builds a heap by repeatedly calling max heapify for non leaves
{
    for(int i = v.size()/2; i >= 0; i--)
    {
        max_heapify(i, v.size());
    }
}

int heap_maximum() //returns the maximum element from the heap
{
    return v[0]; //maximum element at root always in O(1)
}

int extract_max() //extract the maximum from the heap and returns it, also deletes it from heap
{
    int e_max = v[0];
    swap(v[0], v[v.size() - 1]);
    v.erase(v.begin() + v.size() - 1);
    max_heapify(0, v.size());

    return e_max;
}

void increase_key(int i, int k) //increases the key to k at index i in max heap 
{
    if(k < v[i])
    {
        cout << "New key is smaller than current key!";
        return;
    }
    v[i] = k;
    
    while(i > 0 && v[parent(i)] < v[i]) //till i is greater than 0 and v[i] is still greater than its parent
    {
        swap(v[i], v[parent(i)]);
        i = parent(i);
    }
    //max_heapify(0, i + 1); or we can just do this
}

void insert(int k) //insert a key in the heap , and maintains the max heap order.
{
    int temp = v.size();
    v.push_back(INT_MIN); //insert the -inf at end
    increase_key(temp, k); //call increase key
}

void print()
{
    for(int x: v)cout << x << " ";
    cout << "\n";
}

int main()
{
    v = {12, 9, 1, 4, 6, 8, 5, 10, 7};

    build_heap(); //builds a max heap

    print(); //prints the heap.

    int max = heap_maximum(); //finds the maximum element in the max heap in O(1);
    cout << "Max element in heap:" << max << "\n";

    //extract max function gets the maximum element and also deletes it from the heap.
    int e_max = extract_max();
    cout << "The max element extracted:" << e_max << "\n";

    print();

    //increase key function increase a specified key to a given value
    int k , i;
    cout << "Enter the index of the element to be increased:";
    cin >> i;
    cout << "Enter the value by which to be increased:";
    cin >> k;
    
    increase_key(i, k);
    
    print();

    //insert function takes a key and insert it into the heap and maintains the max heap property
    //by calling the increase_key function on that key
    cout << "Enter the key to be inserted in the max heap:";
    cin >> k;
    insert(k);

    print();
}
