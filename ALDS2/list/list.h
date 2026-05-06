#include<stdio.h>
#include<stdlib.h>

typedef struct list {
    struct list *next; // 次の要素へのポインタ
    char data; // データを格納するための変数
} List;

List *create(void); // リストの作成
char access(List *L, int i); // リストのi番目の要素にアクセスするための関数
void insert(List *L, int i, char x); // リストのi番目に要素xを挿入するための関数
void delete_list(List *L, int i); // リストのi番目の要素を削除するための関数
void initialize(List *L); // リストを初期化するための関数
int empty(List *L); // リストが空であるかどうかを判定するための関数