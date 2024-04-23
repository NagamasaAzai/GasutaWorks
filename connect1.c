#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//подключение библиотеки для управления файлами
#include <fcntl.h>
int main() {
	int fd; //файловый дискриптор
	size_t size; //размер строки в байтах
	char string[]="3.120.2.21 Gasuta";
//открытие файла на запись, если файла не существует, то он будет создан с правилами доступа 0666
	if((fd = open("file1.txt", O_WRONLY|O_CREAT, 0666))<0) {
		printf("Ошибка\n");
		exit(-1);
	}
//чтение файла в строку string 
	size = write(fd, string, 18);
	if (size != 18) {
		printf("Не удалось записать все строку в файл\n");
		exit(-1);
	}
	if(close(fd) < 0) {
		printf("Не удалось закрыть файл\n");
                exit(-1);
	}
	return 0;
}
