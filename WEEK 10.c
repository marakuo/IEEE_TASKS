// PROBLEM E 
#include <stdio.h>
#include<stdlib.h>
int main() {
    char string[1000];
    int sum =0, i =0;
    scanf("%s", string);
    while (string[i] != '\0') {
        if (string[i] >= '0' && string[i] <= '9') {
            sum += string[i] - '0';
        }

        i++;

    }
    printf("%d\n", sum);
    return 0;
}

/////////////////////////////////////////////
//PROBLEM G
#include <stdio.h>
#include<stdlib.h>
int main() {
    char string[1000];
    int i =0;
    int diff = 'a'- 'A'; //  a> A
   gets(string);
    while (string[i] != '\0') {
        if (string[i] == ',') {
            printf(" ");
        }

        else if (string[i] >= 'A' && string[i] <= 'Z') {
            putchar(string[i] + diff);
        }
        else if (string[i] >= 'a' && string[i] <= 'z') {
            putchar(string[i] - diff);
        }
        i++;

    }


    return 0;
}


/////////////////////////////////
// PROBLEM I

#include <stdio.h>
#include <string.h>

int main() {
    char string[1000];
    int i =0, ispali =1;
    

   gets(string);


    while (string[i] != '\0') {
        if (string[i] != string[strlen(string)-i-1]) {
            ispali=0;
            break;
        }
        i++;

    }
    if(ispali ==1 ) {
        printf("YES");
    }
    else
        printf("NO");



    return 0;
}

//////////////////////////
//problem O

#include <stdio.h>
#include <string.h>
void storting(char str[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (str[j] > str[j+1]) {
                int temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }

}

int main() {
    int size;
    char string[size];
    scanf("%d", &size);
    fflush(stdin);
    gets(string);

    storting(string, strlen(string));
    puts(string);
    return 0;
}

////////////////////////
//   PROBLEM R

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char string[n + 1];
    scanf("%s", string);

    double score = 0.0;
    int length = n;

    for (int i = 0; i < length; ) {
        char c = string[i];
        if (c == 'V') {
            score += 5;
            i++;
        } else if (c == 'W') {
            score += 2;
            i++;
        } else if (c == 'X') {
            if (i + 1 < length) {

                for (int j = i + 1; j < length - 1; j++) {
                    string[j] = string[j + 1];
                }
                length--;
                i++;
            } else {
                i++;
            }
        } else if (c == 'Y') {
            if (i + 1 < length) {
                char nextChar = string[i + 1];
                for (int j = i + 1; j < length - 1; j++) {
                    string[j] = string[j + 1];
                }
                string[length - 1] = nextChar;
                i++;
            } else {
                i++;
            }
        } else if (c == 'Z') {
            if (i + 1 < length) {
                char nextChar = string[i + 1];
                if (nextChar == 'V' || nextChar == 'W') {
                    if (nextChar == 'V') {
                        score /= 5;
                    } else if (nextChar == 'W') {
                        score /= 2;
                    }
                    for (int j = i + 1; j < length - 1; j++) {
                        string[j] = string[j + 1];
                    }
                    length--;
                }
                i++;
            } else {
                i++;
            }
        } else {
            i++;
        }
    }

    printf("%d\n", (int)score);
    return 0;
}
