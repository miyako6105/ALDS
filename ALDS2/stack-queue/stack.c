#include<stdio.h>
#include<stdlib.h>

typedef struct list {
    struct list *next; // 次の要素へのポインタ
    char data; // データを格納するための変数
} List;

void print_list(List *L) {
    printf("[");
    while (L->next != NULL) {
        L = L->next;
        printf("%c, ", L->data);
    }
    printf("]\n");
}

// MARK: prototype
List *create(void); // リストの作成
char access(List *L, int i); // リストのi番目の要素にアクセスするための関数
void insert(List *L, int i, char x); // リストのi番目に要素xを挿入するための関数
void delete_list(List *L, int i); // リストのi番目の要素を削除するための関数
void initialize(List *L); // リストを初期化するための関数
int empty(List *L); // リストが空であるかどうかを判定するための関数

// MARK: function
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
            L->next = L->next->next; // 現在の要素の次のポインタを削除する要素の次の要素に設定
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

// ------------------------------------------------
// スタックの実装
// pushdown, popup関数を実装
// MARK: pushdown
void pushdown(List *L, char x) {
    // pushdownはリストの先頭に要素を挿入する操作
    insert(L, 1, x); // リストの1番目に要素xを挿入
}

// MARK: popup
char popup(List *L) {
    // popupはリストの先頭の要素を削除してその値を返す操作
    char x = access(L, 1); // リストの1番目の要素の値を取得
    delete_list(L, 1); // リストの1番目の要素を削除
    return x; // 削除した要素の値を返す
}

// ------------------------------------------------
// キューの実装
// enqueue, dequeue関数を実装
// MARK: enqueue
void enqueue(List *L, char x) {
    // 末尾への挿入
    int i = 1; // 挿入位置を表す変数
    // 末尾のnextはNULLであるため、次の要素がNULLでない限りiを増やす
    while (L->next != NULL) {
        L = L->next; // 次の要素に移動
        i++; // 挿入位置を増やす
    }
    insert(L, i, x); // リストのi番目に要素xを挿入
}

// MARK: dequeue
char dequeue(List *L) {
    // 先頭の要素を削除してその値を返す操作
    char x = access(L, 1); // リストの1番目の要素の値を取得
    delete_list(L, 1); // リストの1番目の要素を削除
    return x; // 削除した要素の値を返す
}

// ------------------------------------------------
// MARK: main
int main(void) {
    List *L = create(); // リストの作成
    printf("---stack---\n");
    pushdown(L, 'a'); // スタックに'a'をpushdown
    print_list(L); // スタックの内容を表示
    pushdown(L, 'b'); // スタックに'b'をpushdown
    print_list(L); // スタックの内容を表示
    pushdown(L, 'c'); // スタックに'c'をpushdown
    print_list(L); // スタックの内容を表示
    printf("popup: %c -> ", popup(L)); // スタックから要素をpopupして表示
    print_list(L); // スタックの内容を表示
    printf("popup: %c -> ", popup(L)); // スタックから要素をpopupして表示
    print_list(L); // スタックの内容を表示

    printf("---queue---\n");
    enqueue(L, 'a'); // キューに'a'をenqueue
    print_list(L); // スタックの内容を表示
    enqueue(L, 'b'); // キューに'b'をenqueue
    print_list(L); // スタックの内容を表示
    enqueue(L, 'c'); // キューに'c'をenqueue
    print_list(L); // キューの内容を表示
    printf("dequeue: %c -> ", dequeue(L)); // キューから要素をdequeueして表示
    print_list(L); // キューの内容を表示
    printf("dequeue: %c -> ", dequeue(L)); // キューから要素をdequeueして表示
    print_list(L); // キューの内容を表示
}