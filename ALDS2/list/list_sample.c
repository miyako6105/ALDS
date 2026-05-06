#include "list.h"

int main(void) {
    List *L; // リストの先頭を指すポインタ
    L = create(); // リストの作成
    insert(L, 1, 'a'); // リストの1番目に'a'を挿入
    insert(L, 1, 'c'); // リストの1番目に'c'を挿入
    insert(L, 2, 'v'); // リストの2番目に'v'を挿入
    delete_list(L, 1); // リストの1番目の要素を削除
    insert(L, 2, 'a'); // リストの2番目に'a'を挿入
    delete_list(L, 3); // リストの3番目の要素を削除
    // リストの要素を順番に表示して削除
    // 処理が正しい場合、va と表示されるはず
    while (!empty(L)) {
        printf("%c", access(L, 1));
        delete_list(L, 1);
    }
    printf("\n");
    free(L); // メモリの解放

    return 0;
}