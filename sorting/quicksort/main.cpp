/*
*   Quicksort Algorithm (in-place version)
*
*   Copyright (c) 2013 Guilherme Taschetto
*
*   http://www.github.com/taschetto
*   http://www.github.com/taschetto/algorithms
*
*   This file is subject to the terms and conditions defined in
*   file 'LICENSE', which is part of this source code package.
*
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <tclap/CmdLine.h>

using namespace std;

void swap(int* i, int* j)
{
    int k = *j;
    *j = *i;
    *i = k;
}

void quicksort(int values[], int left, int right)
{
    int pivot = values[left];
    int i = left, j = right;

    while (i <= j)
    {
        while (values[i] < pivot && i < right)
            i++;
        while (values[j] > pivot && j > left)
            j--;

        if (i <= j)
        {
            swap(values[i], values[j]);
            i++;
            j--;
        }
    }

    if (j > left)
        quicksort(values, left, j);

    if (i < right)
        quicksort(values, i, right);
}

void print(int v[], int size)
{
    for (int i = 0; i < size; i++)
        cout << v[i] << " ";

    cout << endl;
}

int main(int argc, char** argv)
{
    vector<int> numbers;

    try
	{
        TCLAP::CmdLine cmd("Quicksort Algorithm", ' ', "0.1", false);
        TCLAP::ValueArg<string> fileArg("f", "file", "File to read", false, "file.txt", "string");
        cmd.add(fileArg);

        TCLAP::UnlabeledMultiArg<int> numbersArg("numbers", "List of numbers", false, "34 12 87", true);
        cmd.add(numbersArg);

        cmd.parse(argc, argv);

        string file = fileArg.getValue();
        if (!file.empty())
        {
            ifstream read(file);
            int n = 0;
            while (read >> n)
                numbers.push_back(n);
        }

        numbers.insert(numbers.end(), numbersArg.getValue().begin(), numbersArg.getValue().end());
    }
    catch(TCLAP::ArgException&e)
    {
        cerr << "Error: " << e.error() << " for arg " << e.argId() << endl;
    }

    quicksort(&numbers[0], 0, numbers.size() - 1);

    print(&numbers[0], numbers.size());

    return 0;
}
