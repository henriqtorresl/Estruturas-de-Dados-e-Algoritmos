#include <stdio.h>
#include <string.h>

char str[(int)1e5 + 666];

typedef struct{
    int len;
    int pos;
    char ch;
} Item;

int less(Item a, Item b);

int less(Item a, Item b){
    return a.len == b.len ? a.pos < b.pos : a.len >= b.len;
}

void merge(Item *arr, int left, int right){
    int mid = left + (right - left) / 2;
    int left_ptr = left;
    int right_ptr = mid + 1;
    int p = 0;
    Item aux[right - left + 1];

    while(left_ptr <= mid && right_ptr <= right){
        if(less(arr[left_ptr], arr[right_ptr]))
            aux[p++] = arr[left_ptr++];
        else
            aux[p++] = arr[right_ptr++];
    }

    while(left_ptr <= mid)
        aux[p++] = arr[left_ptr++];
    while(right_ptr <= right)
        aux[p++] = arr[right_ptr++];
    
    p = 0;
    for(int i = left; i <= right; ++i)
        arr[i] = aux[p++];
}

void merge_sort(Item *arr, int left, int right){
    if(left >= right) return;

    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1 ,right);
    merge(arr, left, right);
}

int main(){ 
    scanf("%s", str);
    int n = strlen(str);

    char cur_char = str[0];
    int cur_pos = 0;
    Item items[(int)1e5 + 666];
    int num_items = 0;

    for(int i = 0; i < n; ++i){
        if(cur_char != str[i]){
            items[num_items].len = i - cur_pos;
            items[num_items].ch = cur_char;
            items[num_items].pos = cur_pos;
            num_items++;

            cur_pos = i;
            cur_char = str[cur_pos];
        }

        if(i == n-1){
            items[num_items].len = i - cur_pos + 1;
            items[num_items].ch = cur_char;
            items[num_items].pos = cur_pos;
            num_items++;
        }
    }

    merge_sort(items, 0, num_items - 1);

    for(int i = 0; i < num_items; ++i)
        printf("%d %c %d\n", items[i].len, items[i].ch, items[i].pos);
    
    return 0;
}
