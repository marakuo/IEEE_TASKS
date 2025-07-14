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

// STRUCTURING THE DOCUMNEMTS => didn't fully understand the Q
// BOXES
#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 1000
#define MAX_OFFICES 100
#define MAX_TOWNS 100
#define MAX_ID_LENGTH 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char id[MAX_ID_LENGTH];
    int weight;
} Package;

typedef struct {
    int min_weight;
    int max_weight;
    Package packages[MAX_PACKAGES];
    int package_count;
} PostOffice;

typedef struct {
    char name[MAX_NAME_LENGTH];
    PostOffice offices[MAX_OFFICES];
    int office_count;
} Town;

Town towns[MAX_TOWNS];
int town_count = 0;

void print_town_packages(const char* town_name) {
    for (int i = 0; i < town_count; i++) {
        if (strcmp(towns[i].name, town_name) == 0) {
            printf("%s:\n", towns[i].name);
            for (int j = 0; j < towns[i].office_count; j++) {
                printf("    %d:\n", j);
                for (int k = 0; k < towns[i].offices[j].package_count; k++) {
                    printf("        %s\n", towns[i].offices[j].packages[k].id);
                }
            }
            return;
        }
    }
}

void process_transaction(const char* town1_name, int office1_idx, const char* town2_name, int office2_idx) {
    Town *town1 = NULL, *town2 = NULL;
    PostOffice *office1 = NULL, *office2 = NULL;

    for (int i = 0; i < town_count; i++) {
        if (strcmp(towns[i].name, town1_name) == 0) {
            town1 = &towns[i];
        }
        if (strcmp(towns[i].name, town2_name) == 0) {
            town2 = &towns[i];
        }
    }

    if (town1 && town2) {
        office1 = &town1->offices[office1_idx];
        office2 = &town2->offices[office2_idx];

        Package accepted[MAX_PACKAGES];
        Package rejected[MAX_PACKAGES];
        int accepted_count = 0;
        int rejected_count = 0;

        for (int i = 0; i < office1->package_count; i++) {
            if (office1->packages[i].weight >= office2->min_weight &&
                office1->packages[i].weight <= office2->max_weight) {
                accepted[accepted_count++] = office1->packages[i];
            } else {
                rejected[rejected_count++] = office1->packages[i];
            }
        }

        office1->package_count = rejected_count;
        for (int i = 0; i < rejected_count; i++) {
            office1->packages[i] = rejected[i];
        }

        for (int i = 0; i < accepted_count; i++) {
            office2->packages[office2->package_count++] = accepted[i];
        }
    }
}

void find_town_with_most_packages() {
    int max_packages = -1;
    char max_town_name[MAX_NAME_LENGTH] = "";

    for (int i = 0; i < town_count; i++) {
        int total = 0;
        for (int j = 0; j < towns[i].office_count; j++) {
            total += towns[i].offices[j].package_count;
        }
        if (total > max_packages) {
            max_packages = total;
            strcpy(max_town_name, towns[i].name);
        }
    }

    printf("Town with the most number of packages is %s\n", max_town_name);
}

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    for (int i = 0; i < T; i++) {
        fgets(towns[town_count].name, MAX_NAME_LENGTH, stdin);
        towns[town_count].name[strcspn(towns[town_count].name, "\n")] = '\0';

        int N;
        scanf("%d", &N);
        getchar();

        for (int j = 0; j < N; j++) {
            int m, min_w, max_w;
            scanf("%d %d %d", &m, &min_w, &max_w);
            getchar();

            PostOffice office;
            office.min_weight = min_w;
            office.max_weight = max_w;
            office.package_count = 0;

            for (int k = 0; k < m; k++) {
                Package package;
                fgets(package.id, MAX_ID_LENGTH, stdin);
                package.id[strcspn(package.id, "\n")] = '\0';

                scanf("%d", &package.weight);
                getchar();

                office.packages[office.package_count++] = package;
            }

            towns[town_count].offices[towns[town_count].office_count++] = office;
        }

        town_count++;
    }

    int Q;
    scanf("%d", &Q);
    getchar();

    for (int i = 0; i < Q; i++) {
        int query_type;
        scanf("%d", &query_type);
        getchar();

        if (query_type == 1) {
            char town_name[MAX_NAME_LENGTH];
            fgets(town_name, MAX_NAME_LENGTH, stdin);
            town_name[strcspn(town_name, "\n")] = '\0';
            print_town_packages(town_name);
        } else if (query_type == 2) {
            char town1_name[MAX_NAME_LENGTH], town2_name[MAX_NAME_LENGTH];
            int office1_idx, office2_idx;
            scanf("%s %d %s %d", town1_name, &office1_idx, town2_name, &office2_idx);
            getchar();
            process_transaction(town1_name, office1_idx, town2_name, office2_idx);
        } else if (query_type == 3) {
            find_town_with_most_packages();
        }
    }

    return 0;
}


