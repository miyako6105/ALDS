#include "list.h"

// リストの作成
List *create(void) {
    List *l;
    l = (List *)malloc(sizeof(List)); // メモリの確保
    l->next = NULL; // 次の要素へのポインタをNULLに初期化
    return l;
}
// リストのi番目の要素にアクセスするための関数
char access(List *L, int i) {
    if (L->next != NULL) {
        if (i > 1) {
            return access(L->next, i-1); // 再帰的に次の要素にアクセス
        } else {
            return L->next->data; // i番目の要素のデータを返す
        }
    } else {
        printf("L ends before arriving at the position: %d\n", i);
        return '\0'; // エラーの場合はヌル文字を返す
    }
}

// リストのi番目に要素xを挿入するための関数
void insert(List *L, int i, char x) {
    List *l;
    if (L != NULL) {
        if (i > 1) {
            insert(L->next, i-1, x); // 再帰的に次の要素にアクセス
        } else {
            l = create(); // 新しいリスト要素の作成
            l->data = x; // データを設定
            l->next = L->next; // 新しい要素の次のポインタを現在の次の要素に設定
            L->next = l; // 現在の要素の次のポインタを新しい要素に設定
        }
    } else {
        printf("L end before arriving at the position: %d\n", i);
    }
}

// リストのi番目の要素を削除するための関数
void delete_list(List *L, int i) {
    List *del; // 削除する要素を指すポインタ
    if (L->next != NULL) {
        if (i > 1) {
            delete_list(L->next, i-1); // 再帰的に次の要素にアクセス
        } else {
            del = L->next; // 削除する要素を取得
            L->next = del->next; // 現在の要素の次のポインタを削除する要素の次の要素に設定
            free(del); // メモリの解放
        }
    } else {
        printf("L end before arriving at the position: %d\n", i);
    }
}

// リストを初期化するための関数
void initialize(List *L) {
    while (!empty(L)) {
        delete_list(L, 1);
    }
}

// リストが空であるかどうかを判定するための関数
int empty(List *L) {
    if (L->next == NULL) {
        return 1; // リストが空である場合は1を返す
    } else {
        return 0; // リストが空でない場合は0を返す
    }
}