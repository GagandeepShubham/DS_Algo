#include<iostream>
#include<vector>
using namespace std;

int left(int index)
{
    return (index << 1);
}
int right(int index)
{
    return ((index << 1) + 1);
}

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void Max_heapify(vector<int> &v, int index)
{
    int left_child = left(index);
    int right_child = right(index);
    int largest = index;
    if(left_child <= v.size()  && v[left_child] > v[index])largest = left_child;
    if(right_child <= v.size()  && v[right_child] > v[index])largest = right_child;
    if(largest != index)
    {
        swap(v[index], v[largest]);
        Max_heapify(v, largest);
    }
}
void Build_heap(vector<int> &v, int n)
{
    for(int i = n/2; i >= 0; i--)
    {
        Max_heapify(v, i);
    }
}

int main()
{
    vector<int> v;
    int n, i , data;
    cout << "Enter the total size for heap:";
    cin >> n;
    cout << "Enter the elements for the heap: ";
    for(i = 0; i < n; i++)
    {
        cin >> data;
        v.push_back(data);
    }

    Build_heap(v, n);

    for(int x: v)cout << x << " ";
    cout << "\n";
}