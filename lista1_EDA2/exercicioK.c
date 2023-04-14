#include <stdio.h>
#include <stdlib.h>

typedef long long Item;

#define MENOR(a, b) (a < b)
#define MENOR_IGUAL(a, b) (a <= b)

void merge(Item *v, int l, int r) {  // [l,r]
    int mid = l + (r - l) / 2;
    int pl = l;
    int pr = mid + 1;
    int p = 0;
    Item *aux = malloc((r - l + 1) * sizeof(Item));

    while (pl <= mid && pr <= r) {
        if (MENOR(v[pl], v[pr]))
            aux[p++] = v[pl++];
        else
            aux[p++] = v[pr++];
    }

    while (pl <= mid)
        aux[p++] = v[pl++];
    while (pr <= r)
        aux[p++] = v[pr++];

    p = 0;
    for (int i = l; i <= r; ++i)
        v[i] = aux[p++];

    free(aux);
}

void merge_sort(Item *v, int l, int r) {  // [l, r]
    // unitary vector.
    if (l >= r) return;

    int mid = l + (r - l) / 2;
    // sort first and second half.
    merge_sort(v, l, mid);
    merge_sort(v, mid + 1, r);

    // with both sorted just merge it.
    merge(v, l, r);
}

int binary_search(Item *v, int l, int r, int x) {  // [l, r[
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        if (MENOR_IGUAL(v[mid], x))
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main() {
    long long n;
    scanf("%lld", &n);
    Item *v = malloc(n * sizeof(Item));
    for (int i = 0; i < n; ++i)
        scanf("%lld", &v[i]);

    merge_sort(v, 0, n - 1);

    long long x;
    while (scanf("%lld", &x) != EOF) {
        int ans = binary_search(v, 0, n, x);
        printf("%s\n", (v[ans] == x) ? "sim" : "nao");
    }

    free(v);
    return 0;
}
