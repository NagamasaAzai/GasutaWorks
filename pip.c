#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(){
	int fd[2];
	size_t size;
	char string[] = "Hello, World!";
	char resstring[14];
	//попытаемся создать pipe//
	if(pipe(fd) < 0){
		//Если создать пип не удалось, печатаем сообщение и прекращаем работу//
		printf("Can\'t create pipe\n");
		exit(-1);
	}
	//пробуем записать в пайп 15 байт из нашего массива вместе с признаком конца строки//
	size = write(fd[1], string, 14);
	if(size != 14){
	//Если меньше количества байтов//
		printf("Can\'t write all string\n");
        	exit(-1);
	}
	//Пробуем прочитать из пипа 15 байт в другой массив, т.е. всю строку//
	size = read(fd[0], resstring, 14);
	if (size < 0){
	//Если прочитать не смогли, сообщаем об ошибке//
		printf("Can\'t read string\n");
        	exit(-1);
	}
	//Печаткаем прочитанную строку//
	printf("%s\n", resstring);
	//Закрываем входной поток//
	if (close(fd[0]) < 0){
		printf("Can\'t close input stream\n");
	}
	if (close(fd[1]) < 0){
                printf("Can\'t close output stream\n");
        }
	return 0;
}

