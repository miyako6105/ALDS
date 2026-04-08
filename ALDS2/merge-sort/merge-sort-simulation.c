/*
マージソート処理のシミュレーション
[問題設定]
N 個の整数をマージソートでソートする過程をシミュレーションする

整数はランダムに生成されるものとする
*/
#include <stdio.h>
#include <stdlib.h> // rand関数を使用するために必要なヘッダファイル
#include <time.h> // time関数を使用するために必要なヘッダファイル
#define N 10 // 配列の要素数

int a[N]; // ソート対象の配列

// 関数のプロトタイプ宣言
// merge関数
void merge(int B[], int left, int half, int right);
// merge_sort関数
void merge_sort(int left, int right);
// 配列をランダムに初期化する関数
void initialize_array(void);
// 配列を表示する関数
void print_array(void);

// main関数
int main(void)
{
    // 配列の初期化
    printf("Initializing array with random values...\n");
    initialize_array();

    // 初期配列の表示
    printf("Initial array: ");
    print_array();
    printf("\n");

    // マージソートの実行
    printf("Start merge sort...\n");
    merge_sort(0, N - 1);
    printf("Merge sort completed!\n");

    // ソート後の配列の表示
    printf("Sorted array: ");
    print_array();
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
        
        print_array(); // ソートの過程を表示
    }
}

// 配列をランダムに初期化する関数
void initialize_array(void)
{
    srand(time(NULL)); // 乱数の初期化
    for (int i = 0; i < N; i++)
    {
        a[i] = rand() % 100; // 0から99のランダムな整数を生成
    }
}

// 配列を表示する関数
void print_array(void)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}