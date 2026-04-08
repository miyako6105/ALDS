/* 
マージ処理を実装するプログラム
[問題設定]
N個の要素を持つ配列A1とM個の要素を持つ配列A2が与えられる。
A1・A2はともに昇順にソートされている。
A1とA2をマージして、昇順にソートされた配列Bを作成する。
*/
#include <stdio.h>

#define M 10 // 配列の要素数
#define N 5 // 配列の要素数

// 配列の初期化
int a1[M] = {2, 4, 5, 7, 8, 10, 15, 20, 30, 40};
int a2[N] = {6, 11, 25, 33, 35};
int b[M + N]; // マージ後の配列

// 関数のプロトタイプ宣言
void merge(int b[], int n, int m);

int main(void)
{
    // 初期配列の表示
    printf("A1: ");
    for (int i = 0; i < M; i++) {printf("%d ", a1[i]);}
    printf("\n");
    printf("A2: ");
    for (int i = 0; i < N; i++) {printf("%d ", a2[i]);}
    printf("\n");

    // マージ処理
    printf("Start merging...\n");
    merge(b, M, N);
    printf("Merging completed!\n");

    // マージ後の配列の表示
    printf("B: ");
    for (int i = 0; i < M + N; i++) {printf("%d ", b[i]);}
    printf("\n");

    return 0;
}

// マージ処理を行う関数
void merge(int b[], int n, int m)
{
    int i = 0; // a1のインデックス
    int j = 0; // a2のインデックス
    int k = 0; // bのインデックス

    // a1とa2を比較しながらbにマージする
    while (i < M && j < N) // iとjがそれぞれの配列の範囲内である限り続ける
    {
        // a1 <= a2の場合、a1の要素をbにコピーし、iとkをインクリメント
        if (a1[i] <= a2[j]) {b[k++] = a1[i++];}
        // a1 > a2の場合、a2の要素をbにコピーし、jとkをインクリメント
        else {b[k++] = a2[j++];}
    }
    // どちらかの配列が残っている場合、残りの要素をbにコピーする
    while (i < M) {b[k++] = a1[i++];}
    while (j < N) {b[k++] = a2[j++];}
}