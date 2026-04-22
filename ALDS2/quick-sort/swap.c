#include "swap.h"

void swap(int *x, int *y) {
    int tmp; // 要素の交換に使用する一時変数

    // xとyの値を交換
    tmp = *x;
    *x = *y;
    *y = tmp;
}