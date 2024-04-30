#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	//Создаем массив из двух элементов для хранения файловых дескрипторов для чтения и для записи
	int fd1[2], fd2[2];
	pid_t result;
	size_t size;
	char string1[] = "Hello, World!", string2[] = "Hello, parent!";
	char resstring1[13], resstring2[14];
	//попытаемся создать pipe//
	if(pipe(fd1) < 0){
		//Если создать пип не удалось, печатаем сообщение и прекращаем работу//
		printf("Can\'t create pipe\n");
		exit(-1);
	}
	if(pipe(fd2) < 0){
                //Если создать пип не удалось, печатаем сообщение и прекращаем работу//
                printf("Can\'t create pipe\n");
                exit(-1);
        }
	result = fork();
	if (result<0){
		printf("Ошибка выполнения fork()\n");
		exit(-1);
	}
	else if (result>0){
		if (close(fd1[0])<0) {
			printf("Ошибка при закрытии Pipe на чтение\n");
			exit(-1);
		}
		if (close(fd2[1])<0) {
                        printf("Ошибка при закрытии Pipe на запись\n");
                        exit(-1);
                }
		//пробуем записать в пайп 15 байт из нашего массива вместе с признаком конца строки//
		size = write(fd1[1], string1, 13);
		if(size != 13){
		//Если меньше количества байтов//
			printf("Can\'t write all string\n");
        		exit(-1);
		}
		printf("Процесс-родитель записал информацию в pipe\n");
		size = read(fd2[0], resstring2, 14);
                if (size != 14){
                //Если прочитать не смогли, сообщаем об ошибке//
                        printf("Can\'t read string(Parent)\n");
                        exit(-1);
                }
                //Печаткаем прочитанную строку//
                printf("Информация от дочернего процесса: %s\n", resstring2);
		if(close(fd1[1]) <0) {
			printf("Can\'t close output stream\n");
			exit(-1);
		}
		if (close(fd2[0]) < 0){
                        printf("Can\'t close input stream\n");
                	exit(-1);
		}
	}
	else {
		if (close(fd1[1]) < 0){
			printf("Can\'t close output stream\n");
			exit(-1);
		}
		if (close(fd2[0]) < 0){
                        printf("Can\'t close input stream\n");
                exit(-1);
        	}
		//Пробуем прочитать из пипа 15 байт в другой массив, т.е. всю строку//
		size = read(fd1[0], resstring1, 13);
		if (size < 13){
		//Если прочитать не смогли, сообщаем об ошибке//
			printf("Can\'t read string(child)\n");
        		exit(-1);
		}
		//Печаткаем прочитанную строку//
		printf("%s\n", resstring1);
		size = write(fd2[1], string2, 14);
                if(size != 14){
                //Если меньше количества байтов//
                        printf("Can\'t write all string\n");
                        exit(-1);
                }
                printf("Процесс-ребенок записал информацию в pipe\n");
		//Закрываем входной поток//
		if (close(fd1[0]) < 0){
			printf("Can\'t close input stream\n");
			exit(-1);
		}
		if (close(fd2[1]) < 0){
                        printf("Can\'t close input stream\n");
                	exit(-1);
		}
	}
	return 0;
	exit(-1);
}

