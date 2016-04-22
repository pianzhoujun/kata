#include <cstdlib>
#include <ctime>
#include <iostream>

#define RandomInRange(start, end) rand()%(end - start) + start

using  std::cout;
using  std::endl;

template<typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

void bubble_sort(int data[], int len)
{
    if (data == NULL || len <= 1)
        return ;

    for (int i = 0; i < len; ++i){
        bool flag = true;
        for (int j = 0; j < len-i-1; ++j){
            if (data[j] > data[j+1]){
                swap(data[j], data[j+1]);
                flag = false;
            }
        }
        if (flag == true)
            break;
    }
    return;
}

int Partition(int data[], int start, int end)
{
    if (data == NULL || start > end || start < 0 || end < 0)
        cout << "Invalid Parameter List";
        //throw new runtime_error ("Invalid Parameter List");

    int index = RandomInRange(start, end);
    swap(data[index], data[end]);

    int small = start - 1;
    for (index = start; index < end; ++ index) {
        if (data[index] < data[end]){
            ++small;
            if (small != index)
                swap(data[index],data[small]);
        }
    }
    ++small;
    swap(data[small], data[end]);
    return small;
}

int quickSort(int data[], int start, int end)
{
    if (start == end)
        return 0;
    int index = Partition(data, start, end);
    if (index > start)
        quickSort(data, start, index - 1);
    if (index < end)
        quickSort(data, index + 1, end);
    return 0;
}


int main(int argc, char *argv[])
{
    int len = RandomInRange(5, 15);
    int *data = new int[len];
    srand(time(0));

    for (int i = 0; i < len; ++i) {
        data[i] = RandomInRange(0, 100);
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    bubble_sort(data, len);

    for (int i = 0; i < len; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    delete []data;
}
