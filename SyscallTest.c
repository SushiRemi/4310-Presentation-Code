#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *filename = "example.txt";
    const char *content = "Hello from C!";

    // Write to file
    FILE *file = fopen(filename, "w"); //Uses Ubuntu's "open" syscall
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }
    fprintf(file, "%s", content); //Uses Ubuntu's "write" syscall
    fclose(file);
    printf("Written to file: %s\n", filename);

    // Read from file
    file = fopen(filename, "r"); //Uses Ubuntu's "open" syscall
    if (file == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    char buffer[100];
    printf("Reading from file:\n");
    while (fgets(buffer, sizeof(buffer), file)) { //Uses Ubuntu's "read" syscall
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}
