#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//библиотека управления файлами
#include <fcntl.h>
int main() {
	int fd;
	size_t size;
//инициализируем массив символов, чтобы туда записать информацию из файлов
	char string[18];
//открытие файла на чтение
	if((fd = open("file1.txt", O_RDONLY))<0) {
		printf("Ошибка при открытии файла на чтение\n");
		exit(-1);
	}
//чтение информации из файла
	size = read(fd, string, 18);
//проверка количества прочитанных байт
//печать строки
	if (size != 18) {
		printf("Не удалось прочитать все строку в файл\n");
		exit(-1);
	}
	printf("%s\n", string);
	if(close(fd) < 0) {
		printf("Не удалось закрыть файл\n");
                exit(-1);
	}
	return 0;
}
