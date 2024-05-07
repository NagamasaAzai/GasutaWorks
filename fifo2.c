#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
        int fd;
        size_t size;
        char resstring[11];
        //Создаем символьный массив где будет хранится имя файла фифо
        char name[] = "fifo.fifo";
	if ((fd = open(name, O_RDONLY)) < 0) {
                        printf("Не удалось открыть FIFO для чтения\n");
                        exit(-1);
                }
                size = read(fd, resstring, 11);
                if (size != 11) {
                        printf("Не удалось прочитать информацию из FIFO\n");
                        exit(-1);
                }
                printf("Процесс-ребенок прочитал информацию: %s\n", resstring);
                if (close(fd) < 0){
                        printf("Не получилось закрыть FIFО, открытый на чтение\n");
                        exit(-1);
                }
}
