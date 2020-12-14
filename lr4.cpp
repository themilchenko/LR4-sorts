#include <ctime>
#include <iostream>
#include <vector>

void print_vec(std::vector <int>& a)
{
    for (int v : a)
        std::cout << v << " ";
    std::cout << std::endl;
}

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

void bubble_sort(std::vector <int>& a)
{
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a.size() - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

void insertion_sort(std::vector <int>& a)
{
    int j;
    for (int i = 0; i < a.size() - 1; i++)
    {
        j = i + 1;
        if (a[i] > a[j])
        {
            while (j != a.size())
            {
                if (a[i] > a[j])
                {
                    swap(a[i], a[j]);
                    break;
                }
                j++;
            }
            while (j != 0)
            {
                if (a[j] < a[j - 1])
                    swap(a[j], a[j - 1]);
                j--;
            }
        }
    }
}

void merge (std::vector<int>& vec, std::vector<int>& vec1, std::vector<int>& vec2)
{
    int min1 = 0;
    int min2 = 0;
    int min = 0;

    while ((min1 < vec1.size()) && (min2 < vec2.size())) 
    {
        if (vec1[min1] < vec2[min2])
        {
            vec[min] = vec1[min1];
            min1++;
        }
        else
        {
            vec[min] = vec2[min2];
            min2++;
        }
        min++;
    }

    while (min1 < vec1.size())
    {
        vec[min] = vec1[min1];
        min1++;
        min++;
    }

    while (min2 < vec2.size())
    {
        vec[min] = vec2[min2];
        min2++;
        min++;
    }
}

void merge_sort(std::vector<int>& a)
{
    if (a.size() < 2)
        return;
    int middle = a.size() / 2;
    std::vector<int> left(middle);
    std::vector<int> right(a.size() - middle);

    for (int i = 0; i < middle; i++)
        left[i] = a[i];

    for (int i = middle; i < a.size(); i++)
        right[i - middle] = a[i];

    merge_sort(left);
    merge_sort(right);
    merge(a, left, right);
}

int main()
{
    int size;
    std::cout << "Enter the size of vector: ";
    std::cin >> size;

    std::srand(std::time(nullptr));

    std::vector<int> array(size);
    std::cout << "Not sorted array: ";
    for (int i = 0; i < array.size(); i++)
    {
        array[i] = std::rand() % 201 - 100;
        std::cout << array[i] << " ";
    }

    std::cout << std::endl << std::endl << "Merge sort: ";
    merge_sort(array);
    print_vec(array);

    std::cout << std::endl << "Bubble sort: ";
    bubble_sort(array);
    print_vec(array);

    std::cout << std::endl << "Insertion sort: ";
    insertion_sort(array);
    print_vec(array);

    return 0;
}
