#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c|-w] <input_file_name>\n", argv[0]);
        return 1;
    }

    char *mode = argv[1];
    char *filename = argv[2];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int charCount = 0, wordCount = 0;
    int inWord = 0; // 标记是否在单词内

    int c;
    while ((c = fgetc(file)) != EOF) {
        charCount++; // 统计字符数

        // 判断是否为单词分隔符
        if (c == ' ' || c == ',' || c == '\t' || c == '\n') {
            inWord = 0; // 结束当前单词
        } else if (!inWord) { // 开始新单词
            inWord = 1;
            wordCount++;
        }
    }

    fclose(file);

    // 根据参数输出结果
    if (strcmp(mode, "-c") == 0) {
        printf("Characters: %d\n", charCount);
    } else if (strcmp(mode, "-w") == 0) {
        printf("Words: %d\n", wordCount);
    } else {
        printf("Invalid parameter. Use '-c' for characters or '-w' for words.\n");
        return 1;
    }

    return 0;
}
