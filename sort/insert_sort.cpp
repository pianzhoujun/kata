#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>

using std::cout;
using std::endl;

void insert_sort(int data[], int size)
{
    // Check Parameter List
    if (data == NULL || size <= 1)
        return;

    for (int i = 1; i < size; ++i) {
        if (data[i-1] <= data[i])
            continue;

        int tmp = data[i];
        int j = i-1;
        while (j >= 0 && data[j] >= tmp){
            data[j+1] = data[j];
            --j;
        }
        data[j+1] = tmp;
    }
    return;
}

void binary_insert_sort (int data[], int len)
{
    if (data == NULL || len <= 1)
        return ;
    
    for (int i = 1; i < len; ++i){
        if (data[i-1] <= data[i])
            continue;

        int low = 0, high = i-1;
        int mid = 0;
        while (low <= high) {
            mid = (low + high)/2;
            if (data[mid] < data[i])
                low = mid + 1;
            else if(data[mid] > data[i])
                high = mid - 1;
            else {
                high = mid - 1;
                break;
            } 
        }
        int tmp = data[i];
        for (int j = i-1; j > high; --j) {
            data[j+1] = data[j];
        }
        data[high+1] = tmp;
    }
    return ;

}


int shellInsert(int data[], int len, int gap)
{    
    if (data == NULL || len <= 1 || gap+1 >= len)
        return 0;

    for (int i = gap; i < len; ++i) {
        if (data[i-gap] <= data[i])
            continue;
        else {
            int tmp = data[i];
            int j   = i - gap;
            while (j >= 0 && data[j] >= tmp) {
                data[j + gap] = data[j];
                j -= gap;
            }
            data[j+gap] = tmp;
        }
    }
    return 0;
}

int shellSort (int data[], int len, int gap[], int gap_len)
{
    for (int i = 0; i < gap_len; ++i)
        shellInsert(data, len, gap[i]);
    return 0;
}

void testShellSort()
{
    int len = rand()%10 + 10;
    int *data = new int[len];
    
    int *tmp =  new int[len];

    for (int i = 0; i < len; ++i){
        data[i] = rand() % 100;
        tmp[i] = data[i];
        cout << data[i] << " ";
    }
    cout << endl;


    int gap[3] = {5, 3, 1};

    shellSort(data, len, gap, 3);

    std::sort(tmp, tmp + len);

    for (int i = 0; i < len; ++i){
        cout << data[i] << " ";
        if (data[i] != tmp[i])
            cout << "error" << endl;
    }
    cout << endl;

    for (int i = 0; i < len; ++i){
        cout << tmp[i] << " ";
    }
    cout << endl;

    delete []data;
    delete []tmp;
    return;

}


void test()
{
    srand (time(0));
    int len = rand()%10 + 10;
    int *data = new int[len];
    
    int *tmp =  new int[len];

    for (int i = 0; i < len; ++i){
        data[i] = rand() % 100;
        tmp[i] = data[i];
        cout << data[i] << " ";
    }
    cout << endl;

    binary_insert_sort (data, len);
    std::sort(tmp, tmp + len);

    for (int i = 0; i < len; ++i){
        cout << data[i] << " ";
        if (data[i] != tmp[i])
            cout << "error" << endl;
    }
    cout << endl;

    for (int i = 0; i < len; ++i){
        cout << tmp[i] << " ";
    }
    cout << endl;

    delete []data;
    delete []tmp;
    return;
}



int main()
{
    srand(time(0));
    testShellSort();
    return 0;
}
