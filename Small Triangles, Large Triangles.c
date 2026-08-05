#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

// Helper function to calculate the square of the area using Heron's formula
// Storing as a double avoids precision issues, and omitting the sqrt() optimization is skipped here
// because comparing squared areas yields the exact same sorting order as regular areas.
double get_squared_area(triangle t) {
    double p = (t.a + t.b + t.c) / 2.0;
    return p * (p - t.a) * (p - t.b) * (p - t.c);
}

// Comparator function for qsort
int compare_triangles(const void* a, const void* b) {
    triangle* t1 = (triangle*)a;
    triangle* t2 = (triangle*)b;
    
    double area1 = get_squared_area(*t1);
    double area2 = get_squared_area(*t2);
    
    if (area1 < area2) return -1;
    if (area1 > area2) return 1;
    return 0;
}

void sort_by_area(triangle* tr, int n) {
    // Leverage the highly optimized standard library quicksort
    qsort(tr, n, sizeof(triangle), compare_triangles);
}




int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
