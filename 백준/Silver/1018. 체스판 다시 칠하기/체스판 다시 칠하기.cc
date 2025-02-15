// 체스판 칠하기

#include <iostream>

#define MAX 50 

int main()
{
    int N, M;

    std::cin >> N >> M;

    // N x M matrix 동적 할당
    char **matrix = new char*[N];
    for (int n=0; n<N; n++) { matrix[n] = new char[M]; }

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            std::cin >> matrix[n][m];
        }
    }

    int min = 64;
    for (int n = 0; n <= N-8; n++) {
        for (int m = 0; m <= M-8; m++) {
            int count1 = 0;
            int count2 = 0;

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if ((i+j) % 2 == 0) {
                        if (matrix[n+i][m+j] != 'B') count1++;
                        if (matrix[n+i][m+j] != 'W') count2++;
                    } else {
                        if (matrix[n+i][m+j] != 'W') count1++;
                        if (matrix[n+i][m+j] != 'B') count2++;
                    }
                }
            }
            min = std::min(min, std::min(count1, count2));
        }
    }
    std::cout << min << std::endl;

    // 동적할당 메모리 해제
    for (int n = 0; n < N; n++) { delete[] matrix[n]; }
    delete[] matrix;

    return 0;
}