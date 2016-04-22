#include <iostream>
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::endl;

void select_sort(int data[], int len)
{
    if (data == NULL || len <= 1)
        return ;

    for (int i = 0; i < len - 1; ++i) {
        int min_element = i;
        for (int j = i+1; j < len; ++j){
            if (data[j] < data[min_element]) {
                min_element = j;
            }
        }
        if (min_element != i)
            std::swap(data[i], data[min_element]);
    }
    return ;
}

void test_select_sort()
{
    int len   = rand() % 5 + 10;
    int *data = new int[len];
    int *test_data = new int[len];

    for (int i = 0; i < len; ++i) {
        data[i] = rand() % 100;
        test_data[i] = data[i];
        cout << data[i] << " ";
    }
    cout << endl;

    select_sort(data, len);
    std::sort(test_data, test_data + len);

    for (int i = 0; i < len; ++i) {
        cout << data[i] << " ";
        if (data[i] != test_data[i]){
            cout << "error " << data[i] << " " << test_data[i] << endl;
            return ;
        }
    }
    cout << endl;
    delete []data;
    delete []test_data;
    return ;    
}


void heap_adjust (int data[], int len, int pos)
{
    if (data == NULL || len <= 1 || pos >= len || pos < 0)
        return ;

    for (int node = pos*2 + 1; node < len; node = 2*node + 1){
        if (node+1 < len && data[node] < data[node+1])
            ++node;
        if (data[pos] >= data[node]) {
            break;
        }
        std::swap(data[pos], data[node]);
        pos = node;
    }
    return;
}

void heap_sort (int data[], int len)
{
    if (data == NULL || len <= 1)
        return;

    for (int i = len/2 - 1; i >= 0; --i)
        heap_adjust (data, len, i);

    for (int i = 0; i < len; ++i) {
        std::swap(data[0], data[len-i-1]);
        heap_adjust (data, len-i-1, 0);
    }
    return;
}

void test_heap_sort ()
{
    int len   = rand() % 5 + 10;
    int *data = new int[len];
    int *test_data = new int[len];

    for (int i = 0; i < len; ++i) {
        data[i] = rand() % 100;
        test_data[i] = data[i];
        cout << data[i] << " ";
    }
    cout << endl;

    heap_sort(data, len);
    std::sort(test_data, test_data + len);

    for (int i = 0; i < len; ++i) {
        cout << data[i] << " ";
        if (data[i] != test_data[i]){
            cout << "error " << data[i] << " " << test_data[i] << endl;
            return ;
        }
    }
    cout << endl;
    delete []data;
    delete []test_data;
    return;
}

int main()
{
    srand(time(0));
    test_heap_sort();
    return 0;
}
