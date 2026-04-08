/*
マージソートを実装するプログラム
[問題設定]
N 個の整数が代入された配列 A が与えられる。
A をマージソートを用いて昇順にソートする。
*/
#include <stdio.h>
#define N 10 // 配列の要素数

int a[N] = {43, 33, 78, 19, 46, 63, 25, 11, 54, 17}; // ソート対象の配列

// 関数のプロトタイプ宣言
// merge関数
void merge(int B[], int left, int half, int right);
// merge_sort関数
void merge_sort(int left, int right);

// main関数
int main(void)
{
    int i; // ループカウンタ

    // 初期配列の表示
    printf("Initial array: ");
    for (int i = 0; i < N; i++) {printf("%d ", a[i]);}
    printf("\n");

    // マージソートの実行
    printf("Start merge sort...\n");
    merge_sort(0, N - 1);
    printf("Merge sort completed!\n");

    // ソート後の配列の表示
    printf("Sorted array: ");
    for (i = 0; i < N; i++) {printf("%d ", a[i]);}
    printf("\n");

    return 0;
}

// 関数の定義
// merge関数
// ある配列aを「leftからhalfまでの部分」と「half+1からrightまでの部分」に分割、
// マージして、配列Bに昇順で格納する関数
void merge(int B[], int left, int half, int right)
{
    int i = left; // 左側の配列のインデックス
    int j = half + 1; // 右側の配列のインデックス, +1することで半分の次の要素から開始
    int k;

    for (k=left; k <= right; k++) // kはleftからrightまでのループ
    {
        // 左側の配列の要素が右側の配列の要素より小さい場合、または右側の配列が終了している場合
        if (i <= half && (a[i] < a[j]) || j == right + 1)
        {
            B[k] = a[i]; // Bのk番目にaのi番目をコピー
            i++; // iをインクリメント
        }
        else
        {
            B[k] = a[j]; // Bのk番目にaのj番目をコピー
            j++; // jをインクリメント
        }
    }
}

// merge_sort関数
void merge_sort(int left, int right)
{
    int half, k;
    int B[N]; // マージ後の配列
    // leftがrightより小さい場合、つまり配列に要素が2つ以上ある場合にソートを行う
    // 再帰的に配列を半分に分割し、最終的に1つの要素になるまで分割、そこからマージしていくことでソートを完成させる
    if (left < right)
    {
        half = (right + left) / 2; // 配列を半分に分割
        merge_sort(left, half); // 左側の配列を再帰的にソート
        merge_sort(half + 1, right); // 右側の配列を再帰的にソート
        merge(B, left, half, right); // マージ処理
        // マージされた配列Bを元の配列aにコピー
        for (k = left; k <= right; k++)
        {
            a[k] = B[k];
        }
    }
}