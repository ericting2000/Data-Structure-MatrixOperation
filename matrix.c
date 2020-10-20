#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

int insert_matrix(int index)
{
    int n, r, c, k;
    printf("請輸入要新增的矩陣個數\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("正在新增第%d個矩陣\n", i + 1);
        printf("請輸入此矩陣的名稱\n");
        scanf("%s", m[index][0].name);
        printf("請輸入此矩陣的Row、Column以及非0元素個數，格式如下(r c k)\n");
        scanf("%d%d%d", &r, &c, &k);
        for (int j = 0; j <= k; j++)
        {
            if (j == 0)
            {
                m[index][j].row = r;
                m[index][j].col = c;
                m[index][j].value = k;
                continue;
            }
            printf("請輸入各非0元素的Row、Column與Value，格式如下(r c v)[步驟%d/%d]\n", j, k);
            scanf("%d%d%d", &m[index][j].row, &m[index][j].col, &m[index][j].value);
        }
        if (n == 1)
            printf("矩陣輸入完畢\n");
        if (n > 1)
            printf("第%d個矩陣輸入完畢\n", i + 1);
        index++;
    }
    return index;
}

void read_matrix(int numbs)
{
    if (numbs == 0){
        printf("沒有矩陣可供檢視\n");
        return;
    }
    int n;
    printf("現在有%d個矩陣可供檢視，請輸入想檢視的矩陣個數\n", numbs);
    scanf("%d", &n);
    if(n > numbs || n <=0){
        printf("輸入錯誤無法執行\n");
        return;
    }
    char name_of_matrix[100];
    for(int i = 0; i < n; i++){
        printf("請輸入欲顯示的矩陣名稱\n");
        scanf("%s", name_of_matrix);
        print_matrix(name_of_matrix, 'm', numbs);
    }
    return;
}

void submatrix(int numbs){
    char name[100];
    printf("請輸入欲進行submatrix操做的矩陣名稱\n");
    scanf("%s", name);
    print_matrix(name, 's', numbs);
    return;
}

void print_matrix(char name[100], char type, int numbs){
    if(type == 'm'){
        int index=0, cnt = 0;
        while(strcmp(m[index][0].name, name) != 0){
            index++;
            cnt++;
            if(cnt == numbs){
                printf("輸入錯誤，找不到此矩陣\n");
                return;
            }
        }
        int k = 1;
        for(int i = 0; i < m[index][0].row; i++){
            for(int j = 0; j < m[index][0].col; j++){
                if(i == m[index][k].row && j == m[index][k].col){
                     printf("%d ", m[index][k].value);
                     k++;
                }
                else
                    printf("0 ");
            }
            printf("\n");
        }
    }
    if(type == 's'){
        int index=0, cnt = 0, r[20]={}, c[20]={}, p = 1, q = 1;
        char c1, c2;
        while(strcmp(m[index][0].name, name) != 0){
            index++;
            cnt++;
            if(cnt == numbs){
                printf("輸入錯誤，找不到此矩陣\n");
                return;
            }
        }
        printf("請由小到大輸入指定的Row，格式如下(r1 r2...)\n");
        while(scanf("%d%c", &r[p], &c1) == 2){
            if(c1 == '\n'){
                r[0]++;
                break;
            }
            r[0]++;
            p++;
        }
        printf("請由小到大輸入指定Column，格式如下(c1 c2...)\n");
        while(scanf("%d%c", &c[q], &c2) == 2){
            if(c2 == '\n'){
                c[0]++;
                break;
            }
            c[0]++;
            q++;
        }
        for(int i = 1; i <= r[0]; i++){
            for(int j = 1; j <= c[0]; j++){
                int stat = 0;
                for(int k = 1; k <= m[index][0].value; k++){
                    if(r[i] == m[index][k].row && c[j] == m[index][k].col){
                        printf("%d ", m[index][k].value);
                        stat = 1;
                    }
                }
                if(stat == 0)
                    printf("0 ");
            }
            printf("\n");
        }
    }
    if(type == 't'){
        int index = 0;
        while(strcmp(t[index][0].name, name) != 0){
            index++;
        }
        for(int i = 0; i < t[index][0].row; i++){
            for(int j = 0; j < t[index][0].col; j++){
                int stat = 0;
                for(int k = 1; k <= t[index][0].value; k++){
                    if(i == t[index][k].row && j == t[index][k].col){
                        printf("%d ", t[index][k].value);
                        stat = 1;
                    }
                }
                if(stat == 0)
                    printf("0 ");
            }
            printf("\n");
        }
    }
    if(type == 'a'){
        //printf("'A'CHECK\n");
        int k = 1;
        for(int i = 0; i < a[0][0].row; i++){
            for(int j = 0; j < a[0][0].col; j++){
                //printf("i = %d, j = %d\n", i, j);
                //printf("a[0][%d].row = %d,a[0][%d].col = %d\n", k, a[0][k].row, k, a[0][k].col);
                if(i == a[0][k].row && j == a[0][k].col){
                    //printf("check\n");
                    printf("%d ", a[0][k].value);
                    k++;
                }
                else
                    printf("0 ");
            }
            printf("\n");
        }
    }
    return;
}

void transposition(int numbs){
    int index = 0, cnt = 0;
    char name[100];
    printf("請輸入欲進行transpose操做的矩陣名稱\n");
    scanf("%s", name);
    while(strcmp(m[index][0].name, name) != 0){
        index++;
        cnt++;
        if(cnt == numbs){
            printf("輸入錯誤，找不到此矩陣\n");
            return;
        }
    }
    strcpy(t[index][0].name,m[index][0].name);
    for(int i = 0; i <= m[index][0].value; i++){
        t[index][i].row = m[index][i].col;
        t[index][i].col = m[index][i].row;
        t[index][i].value = m[index][i].value;
    }
    print_matrix(name, 't', numbs);
    return;
}

void addition(int numbs){
    char name[10]={};
    char n1[100], n2[100], index1 = 0, index2 = 0, cnt1 = 0, cnt2 = 0;
    if (numbs == 0){
        printf("沒有矩陣可做加法運算\n");
        return;
    }
    if (numbs == 1){
        printf("目前僅有1個矩陣，請回上頁先輸入至少一個矩陣後再進行加法運算\n");
        return;
    }
    printf("現有%d個矩陣可供進行加法運算，請選擇並輸入兩個矩陣名稱進行加法，格式如下(a b)\n", numbs);
    scanf("%s%s", n1, n2);
    while(strcmp(m[index1][0].name, n1) != 0){
        index1++;
        cnt1++;
        if(cnt1 == numbs){
            printf("有矩陣名稱輸入錯誤，找不到此矩陣\n");
            return;
        }
    }
    while(strcmp(m[index2][0].name, n2) != 0){
        index2++;
        cnt2++;
        if(cnt2 == numbs){
            printf("有矩陣名稱輸入錯誤，找不到此矩陣\n");
            return;
        }
    }
    if(m[index1][0].row == m[index2][0].row && m[index1][0].col == m[index2][0].col){
        int count = 0, k = 1, r = 1, i = 1;
        a[0][0].row = m[index1][0].row;
        a[0][0].col = m[index1][0].col;
        //printf("m[index1][0].value is %d\n", m[index1][0].value);
        //printf("m[index2][0].value is %d\n", m[index2][0].value);
        //printf("row for a is %d, col for a is %d\n", a[0][0].row, a[0][0].col);
        while(i <= m[index1][0].value){
            printf("i = %d\n", i);
            if(m[index1][i].row < m[index2][k].row){
                printf("condition_1\n");
                printf("m[%d][%d].value = %d\n", index1, i, m[index1][i].value);
                a[0][r].row = m[index1][i].row;
                a[0][r].col = m[index1][i].col;
                a[0][r].value = m[index1][i].value;
                printf("a[0][%d].value is %d\n", r, a[0][r].value);
                count++;
                r++;
                i++;
                continue;
            }
            if(m[index1][i].row == m[index2][k].row && m[index1][i].col < m[index2][k].col){
                printf("condition_2\n");
                printf("m[%d][%d].value = %d\n", index1, i, m[index1][i].value);
                a[0][r].row = m[index1][i].row;
                a[0][r].col = m[index1][i].col;
                a[0][r].value = m[index1][i].value;
                printf("a[0][%d].value is %d\n", r, a[0][r].value);
                count++;
                r++;
                i++;
                continue;
            }
            if(m[index1][i].row == m[index2][k].row && m[index1][i].col == m[index2][k].col){
                printf("condition_3\n");
                printf("m[%d][%d].value = %d, m[%d][%d].value = %d\n", index1, i, m[index1][i].value, index2, k, m[index2][k].value);
                a[0][r].row = m[index1][i].row;
                a[0][r].col = m[index1][i].col;
                a[0][r].value = m[index1][i].value + m[index2][k].value;
                printf("a[0][%d].value is %d\n", r, a[0][r].value);
                k++;
                count++;
                r++;
                i++;
                continue;
            }
            if(m[index1][i].row == m[index2][k].row && m[index1][i].col > m[index2][k].col){
                printf("condition_4\n");
                printf("m[%d][%d].value = %d\n", index2, k, m[index2][k].value);
                a[0][r].row = m[index2][k].row;
                a[0][r].col = m[index2][k].col;
                a[0][r].value = m[index2][k].value;
                printf("a[0][%d].value is %d\n", r, a[0][r].value);
                k++;
                count++;
                r++;
                continue;
            }
            if(m[index1][i].row > m[index2][k].row){
                printf("condition_5\n");
                printf("m[%d][%d].value = %d\n", index2, k, m[index2][k].value);
                a[0][r].row = m[index2][k].row;
                a[0][r].col = m[index2][k].col;
                a[0][r].value = m[index2][k].value;
                printf("a[0][%d].value is %d\n", r, a[0][r].value);
                k++;
                count++;
                r++;
                continue;
            }
        }
        a[0][0].value = count;
        printf("count is now %d\n", count);
        print_matrix(name, 'a', numbs);
    }
    else
        printf("此二矩陣無法相加，請重新選擇\n");
    return;
}

void expo(){

}