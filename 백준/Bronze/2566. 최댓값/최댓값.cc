// 9 x 9 격자판에 쓰여진 81개의 자연수 또는 0이 주어질 때, 최대 값을 찾고 그 최대값이 위치한 행, 열 출력
// vector 혹은 int array 사용해서 이중 반복문으로 하면 될 듯

#include <iostream>

int main()
{
    const int row = 9, col = 9;
    int** matrix = new int*[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int max = matrix[0][0];
    int row_idx=1, col_idx=1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] > max) { 
                max = matrix[i][j];
                row_idx = i+1; col_idx = j+1;
            }
        }
    }

    std::cout << max << '\n' << row_idx << " " << col_idx << std::endl;

    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}