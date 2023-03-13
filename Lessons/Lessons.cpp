
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include "VectorTemplates.h"

using namespace std;
using namespace std::placeholders;

bool isMaxEqual(int x, int max, int min)
{
    return x <= max && x >= min;
}

int rnd()
{
    return rand() % 100;
}
 void CreateMatrix(vector<vector<int>>& in, int N, int M)
{
	for (int i = 0; i < N; ++i)
	{
        vector<int> str(M);
        generate(str.begin(), str.end(), rnd);
        in.push_back(str);
	}
}

void main()
{
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned>(time(nullptr)));

    vector<int> i_vec(10);
    vector<vector<int>> mat;

    CreateMatrix(mat, 3, 5);
    PrintMatrix(mat);

    /*for (int i = 0; i < 10; ++i) {
    	//i_vec.push_back(rand() % 100);
        i_vec.push_back(i);
    }*/

    generate(i_vec.begin(), i_vec.end(), rnd);

	i_vec.insert(i_vec.begin() + 3, 9);

    PrintVector(i_vec);

    const auto min_iter = min_element(i_vec.begin(), i_vec.end());
    const auto max_iter = max_element(i_vec.begin(), i_vec.end());

    cout << "Min = " << *min_iter << endl;
    cout << "Max = " << *max_iter << endl;

    //min max range sum
	/*if (min_iter < max_iter) {
        cout << "Min before Max" << endl;
        return;
    }

    auto sum = accumulate(max_iter + 1, min_iter, 0);
    */

	//const auto removed = remove_if(i_vec.begin(), i_vec.end(), [max](const int x) { return x == max;});
    /*const auto removed = remove_if(i_vec.begin(), i_vec.end(), bind(isMaxEqual, _1, 50, 20));
	i_vec.erase(removed, i_vec.end());

    cout << "After deleting: " << endl;
    PrintVector(i_vec);
    */
    cout << "Size: " << i_vec.size() << endl;
    cout << "Cap: " << i_vec.capacity() << endl;
}

