#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
	int fd;
	size_t size;
	char string[17];
	if((fd = open("file1.txt", O_RDONLY))<0) {
		printf("Ошибка при открытии файла на чтение\n");
		exit(-1);
	}
	size = read(fd, string, 17);
	printf("%s\n", string);
	if (size != 17) {
		printf("Не удалось прочитать все строку в файл\n");
		exit(-1);
	}
	if(close(fd) < 0) {
		printf("Не удалось закрыть файл\n");
                exit(-1);
	}
	return 0;
}
