#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    struct list *next;
    int data;
} List;

// プロトタイプ宣言
void print_list(List *);
List *create(void);
int access(List *, int);
void insert(List *, int, int);
void delete_list(List *, int);
void initialize(List *);
int empty(List *);
List *newcell(void);


void print_list(List *L) {
    printf("[");
    while (L->next != NULL) {
        L = L->next;
        printf("%d, ", L->data);
    }
    printf("]\n");
}

List *create(void) {
    List *l;
    l = (List *)malloc(sizeof(List)); // メモリの確保
    l->next = NULL; // 次の要素へのポインタをNULLに初期化
    return l;
}
// リストのi番目の要素にアクセスするための関数
int access(List *L, int i) {
    if (L->next != NULL) {
        if (i > 1) {
            return access(L->next, i-1); // 再帰的に次の要素にアクセス
        } else {
            return L->next->data; // i番目の要素のデータを返す
        }
    } else {
        printf("L ends before arriving at the position: %d\n", i);
        return 0; // エラーの場合は0を返す
    }
}

// リストのi番目に要素xを挿入するための関数
void insert(List *L, int i, int x) {
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

List *newcell(void) {
    List *p;
    p = (List *)malloc(sizeof(List));
    p->next = NULL;
    return p;
}

// MARK: main
int main(void) {
    // リスト構造でグラフを表現し、それを隣接行列に変換するプログラムを作成する
    int i;
    List *V[5]; // 頂点の数は 5 とする
    // 頂点を表すリスト構造体の配列を作成する
    for (i = 0; i < 5; i++) {
        V[i] = newcell();
    }

    // v1にはv2が隣接
    insert(V[0], 1, 2);
    // v2: v3, v4, v5が隣接
    insert(V[1], 1, 5);
    insert(V[1], 1, 4);
    insert(V[1], 1, 3);

    // v3: v2とv4
    insert(V[2], 1, 4);
    insert(V[2], 1, 2);

    // v4: nil
    // v5: v4とv5
    insert(V[4], 1, 5);
    insert(V[4], 1, 4);

    // グラフの表示
    for (i = 0; i < 5; i++) {
        printf("v%d: ", i + 1);
        print_list(V[i]);
    }

    // 隣接行列の作成
    int adj[5][5] = {0}; // 隣接行列を初期化
    for (i = 0; i < 5; i++) {
        List *p = V[i]->next; // 頂点iの隣接リストの先頭を指すポインタ
        while (p != NULL) {
            int j = p->data - 1; // 隣接する頂点の番号を取得（0から始まるインデックスに変換）
            adj[i][j] = 1; // 隣接行列の該当する位置を1に設定
            p = p->next; // 次の隣接頂点に移動
        }
    }

    // 隣接行列の表示
    printf("Adjacency Matrix:\n");
    printf("    v1 v2 v3 v4 v5\n");
    for (i = 0; i < 5; i++) {
        printf(" v%d ", i + 1);
        for (int j = 0; j < 5; j++) {
            printf("%2d ", adj[i][j]);
        }
        printf("\n");
    }
}