#include <stdio.h>
#include <stdlib.h>

// template.php 
// <?php
// %s yop yop yop %s

int main(void) {
    char* template_path = "./template.cphp";
    // je viens d'appendre que ça prend le répertoire de lancement de l'éxécutable
    // et pas le répertoire de l'éxécutable lui même
    FILE* php_file = fopen(template_path, "r");
    if (!php_file) {
        perror("Failed to open template file");
        fprintf(stderr, "Make sure the file exists at %s\n", template_path);
        return 1;
    }

    char* buffer = (char*) malloc(8000);
    char* written_file = (char*) malloc(10000);

    size_t n = fread(buffer, 1, 8000, php_file);
    buffer[n] = '\0';
    fclose(php_file);

    sprintf(written_file, buffer, "a", "b", "c", "d", "e");
    free(buffer);
    
    printf("%s\n", written_file);

    free(written_file);
    return 0;
}