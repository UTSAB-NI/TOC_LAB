#include <stdio.h>
#include <string.h>
#include <ctype.h>

// C keywords
char keywords[32][10] = {
    "auto", "break", "case", "char", "const",
    "continue", "default", "do", "double", "else",
    "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register", "return",
    "short", "signed", "sizeof", "static", "struct",
    "switch", "typedef", "union", "unsigned", "void",
    "volatile", "while"
};

// function to check if a string is a keyword
int is_keyword(char *str) {
    int i;
    for (i = 0; i < 32; i++) {
        if (strcmp(keywords[i], str) == 0) {
            return 1;
        }
    }
    return 0;
}

// function to check if a string is a identifier
int is_identifier(char *str) {
    int i;
    if (!isalpha(str[0]) && str[0] != '_') {
        return 0;
    }
    for (i = 1; i < strlen(str); i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return 0;
        }
    }
    return 1;
}
// main function to test the above functions
int main() {
    char str[50];
    printf("Enter a string: ");
    scanf("%s", str);
    if (is_keyword(str)) {
        printf("%s is a Keyword\n", str);
    }
    else if (is_identifier(str)) {
        printf("%s is a identifier\n", str);
    }
    else {
        printf("%s is not a identifier or keyword\n", str);
    }
    return 0;
}
