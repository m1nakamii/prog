#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert_paths(char delim, const char* dir, const char* paths) {
    const char* home_dir = dir;
    size_t home_dir_len = strlen(home_dir);

    size_t paths_len = strlen(paths);
    char* paths_copy = (char*)malloc(paths_len + 1);
    strcpy(paths_copy, paths);

    char* abs_paths = (char*)malloc(paths_len + 1);
    abs_paths[0] = '\0';

    char* path = strtok(paths_copy, &delim);
    while (path != NULL) {
        if (path[0] == '~') {
            size_t path_len = strlen(path);
            size_t abs_path_len = home_dir_len + path_len;
            char* abs_path = (char*)malloc(abs_path_len + 1);
            strncpy(abs_path, home_dir, home_dir_len);
            strncpy(abs_path + home_dir_len, path + 1, path_len - 1);
            abs_path[abs_path_len] = '\0';
            abs_paths = realloc(abs_paths, strlen(abs_paths) + abs_path_len + 2);
            strcat(abs_paths, abs_path);
            free(abs_path);
        } else if (path[0] != '/') {
            abs_paths = realloc(abs_paths, strlen(abs_paths) + strlen(path) + 2);
            strcat(abs_paths, path);
        } else {
            abs_paths = realloc(abs_paths, strlen(abs_paths) + strlen(path) + 2);
            strcat(abs_paths, path);
        }

        path = strtok(NULL, &delim);
        if (path != NULL) {
            size_t abs_paths_len = strlen(abs_paths);
            abs_paths[abs_paths_len] = delim;
            abs_paths[abs_paths_len + 1] = '\0';
        }
    }

    free(paths_copy);

    return abs_paths;
}

int main() {
    char dir[100];

    char delim = '+';

    printf("Введите директорию с домашними каталогами: ");
    scanf("%s", dir);

    const char* paths = "~/games/packman.cpp+~alex/docs+~/study/Prog/lab4.c+/usr/bin/gcc";

    char* abs_paths = convert_paths(delim, dir, paths);
    printf("new paths: %s\n", abs_paths);
    free(abs_paths);

    return 0;
}
