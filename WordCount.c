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
    int inWord = 0; // ����Ƿ��ڵ�����

    int c;
    while ((c = fgetc(file)) != EOF) {
        charCount++; // ͳ���ַ���

        // �ж��Ƿ�Ϊ���ʷָ���
        if (c == ' ' || c == ',' || c == '\t' || c == '\n') {
            inWord = 0; // ������ǰ����
        } else if (!inWord) { // ��ʼ�µ���
            inWord = 1;
            wordCount++;
        }
    }

    fclose(file);

    // ���ݲ���������
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
