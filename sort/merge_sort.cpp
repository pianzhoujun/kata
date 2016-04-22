#include <iostream>
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::endl;

void merge (int data_1[], int data_2[], int start, int mid, int end)
{
    int k = start;
    int m = start, n = mid+1;
    while(m <= mid && n <= end) {
       if (data_1[m] <= data_1[n]) {
           data_2[k] = data_1[m];
           ++m;
       }     
       else {
           data_2[k] = data_1[n];
           ++n;
       }
       ++k;
    }
    while (m <= mid)
        data_2[k++] = data_1[m++];
    while (n <= end)
        data_2[k++] = data_1[n++];
    return;
}


void merge_sort_aux (int data_1[], int data_2[], int start, int end, int len)
{
    if (start == end){
        data_2[start] = data_1[start];
        return;
    }

    int mid = (start + end)/2;
    int *data = new int[len];
    merge_sort_aux (data_1, data, start, mid, len);
    merge_sort_aux (data_1, data, mid+1, end, len);
    merge (data, data_2, start, mid, end);
    delete []data;
    return ;
}

void merge_sort (int data[], int len)
{
    if (data == NULL || len <= 1)
        return ;
    merge_sort_aux (data, data, 0, len-1, len);
}


void test()
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

    merge_sort (data, len);
    for (int i = 0; i < len; ++i){
        cout << data[i] << " ";
    }
    cout << endl;
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
    test();
    return 0;
}
