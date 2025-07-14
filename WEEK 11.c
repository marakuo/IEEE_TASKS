//BOXES THRIUGH A TUNNEL 
#include <stdio.h>

#define TUNNEL_HEIGHT 41

typedef struct {
    int height;
    int width;
    int length;
} box;

int calc_volume(box dim) {
    return dim.height * dim.width * dim.length;
}

int main() {
    box dim;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &dim.length, &dim.width, &dim.height);

        if (dim.height < TUNNEL_HEIGHT) {
            int volume = calc_volume(dim);
            printf("%d\n", volume);
        }
    }

    return 0;
}

//SMALL TRIANGLES, LARGER TRIANGLES 
#include <stdio.h>
#include <math.h>

typedef struct {
    int a;
    int b;
    int c;
} triangle;

double area_calc(triangle tri) {
    double s = (tri.a + tri.b + tri.c) / 2.0;
    return sqrt(s * (s - tri.a) * (s - tri.b) * (s - tri.c));
}

void swap(triangle *a, triangle *b) {
    triangle temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    scanf("%d", &n);

    triangle tri[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &tri[i].a, &tri[i].b, &tri[i].c);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (area_calc(tri[j]) > area_calc(tri[j + 1])) {
                swap(&tri[j], &tri[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", tri[i].a, tri[i].b, tri[i].c);
    }

    return 0;
}

// STRUCTURING THE DOCUMNEMTS 


