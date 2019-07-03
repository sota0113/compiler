#include <stdio.h>

enum Status {
    INSERT,  /* 登録 */
    UPDATE,  /* 更新 */
    DELETE   /* 削除 */
};

enum {
    test_A,
    test_B
};

int main() {
    enum Status status,status1,status2,status3 ;  /* 列挙型statusの変数宣言 */
    status = INSERT;
    status1 = UPDATE;
    status2 = DELETE;
    printf("value of 'status' is : %d\n",status);
    printf("value of 'status1' is : %d\n",status1);
    printf("value of 'status2' is : %d\n",status2);
    printf("value of 'status3' is : %d\n",status3);
    printf("value of 'INSERT' is : %d\n",INSERT);
    printf("value of 'UPDATE' is : %d\n",UPDATE);
    printf("value of 'DELETE' is : %d\n",DELETE);
    printf("value of 'test_A' is : %d\n",test_A);
    printf("value of 'test_B' is : %d\n",test_B);
    switch(status) {
    case INSERT:
        printf("登録します。");
        break;
    case UPDATE:
        printf("更新します。");
        break;
    case DELETE:
        printf("削除します。");
    }

    return 0;
}
