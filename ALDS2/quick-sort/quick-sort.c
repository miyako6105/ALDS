#include<stdio.h>

#define N 10 // 配列の要素数

// 配列の宣言と初期化
int a[N] = {42, 33, 78, 19, 46, 63, 25, 11, 54, 17};

int partition(int left, int right); // パーティション関数の宣言
void quick_sort(int left, int right); // クイックソート関数の宣言

// MARK: main
int main(void) {
    int i; // ループ変数
    // 初期配列の表示
    printf("初期配列:");
    for (i = 0; i < N; i++) {
        printf("%3d ", a[i]); // 配列の要素を表示
    }
    printf("\n");

    // クイックソートの実行
    quick_sort(0, N - 1);

    // ソートされた配列の表示
    printf("ソートされた配列:");
    for (i = 0; i < N; i++) {
        printf("%3d ", a[i]); // ソートされた配列の要素を表示
    }
    printf("\n");
    return 0; // プログラムの終了
}

// MARK: partition
int partition(int left, int right) {
    int pivot; // 枢軸
    int i, j; // iは左から、jは右からのインデックス
    int tmp; // 要素の交換に使用する一時変数

    pivot =  a[left];
    i = left + 1;
    j = right;

    while (i <= j) {
        // iが右端に達するか、a[i]がpivot以上になるまでiを進める
        while (i <= right && a[i] < pivot) {
            i++;
        }
        // a[j]がpivot以下になるまでjを進める
        while (a[j] > pivot) {
            j--;
        }
        // iがj以下であれば、i番目とj番目の要素を交換して、iを進め、jを戻す
        if (i <= j) {
            printf("i = %d, j = %d, a[i] = %d, a[j] = %d\n", i, j, a[i], a[j]); // iとjの位置とa[i]とa[j]の値を表示して確認する

            // i番目とj番目の要素を swap
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++; // iを進める
            j--; // jを戻す
        }
    }

    return j; // jは枢軸の最終的な位置を指す
}

// MARK: quick_sort
void quick_sort(int left, int right) {
    int j; // パーティションの結果を格納する変数

    // leftがrightより小さい場合にのみ、クイックソートを実行
    if (left < right) {
        j = partition(left, right); // パーティションの実行
        // jはその位置で確定しているので、その前後をクイックソートする
        quick_sort(left, j - 1); // 左側の部分配列をクイックソート
        quick_sort(j + 1, right); // 右側の部分配列をクイックソート
    }
}