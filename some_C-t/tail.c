#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
 

int lines_count(int fd, char buffer[], int new_line) {
 
    int result;
 
    while(result = read(fd, buffer, 1)) {
 
        if(buffer[0] == '\n') new_line++;
 
        if(result < 0) {
                perror("read");
        }
    }
    return new_line;
}
 

int file_open(int argc, char **argv, char *file_name, int file_num) {
 
    file_name = argv[file_num];
    char error[5000] = "tail: cannot open ’", *error_end;
    int fd = open(file_name, O_RDONLY);
 
    if(fd < 0) {
        error_end = "’ for reading";
        strcat(error, file_name);
        strcat(error, error_end);
       
        perror(error);
    }
 
    if (argc > 2 && fd >= 0) {
        write(1 , "==> " , 4);
        write(1 , file_name , strlen(file_name));
        write(1 , " <==" , 4);
        write(1 , "\n" , 1);
    }
    return fd;
}


int Write(int new_line, int lines, char buffer[], int fd, int file_num, int argc) {
 
    int result;
 
    while(result = read(fd, buffer, 1)) {
        if(new_line - lines <= 10)
            write(STDOUT_FILENO, buffer, 1);
 
        if(buffer[0] == '\n') lines++;
 
        if(result < 0) {
            perror("read");
        }
    }
 
    result = close( fd );
 
    if(result < 0) {
        perror("close");
    }
    return lines;
}
 
int input_reading(int argc, char **argv, int file_num) {
 
    char buffer[1], *file_name = "input_file.txt";
    int fd = open(file_name , O_WRONLY | O_CREAT , 0777), result , lines = 0 , new_line = 0;
 
    while(result = read(STDIN_FILENO, buffer, 1)) {
       
        write(fd, buffer, 1);
 
        if(result < 0) {
            perror("read");
            return 1;
        }
    }
        close(fd);
        fd = open(file_name, O_RDONLY);
 
        new_line = lines_count(fd, buffer, new_line);
 
        lseek(fd, 0, SEEK_SET);
 
        lines = Write(new_line, lines, buffer, fd, file_num, argc);
 
        fd = remove("input_file.txt"); 
}


int main(int argc, char **argv) {
   
    if (argc > 1) {
             
        char *file_name, buffer[1], *output = "standart output";
        int file_num = 1, result, new_line = 0, lines = 0, fd, is_error = 0, is_error_first_argument = 0 ;
       
     
        while (file_num < argc) {

            if (file_num != 1 && is_error == 0 && is_error_first_argument == 0)
                write(1 , "\n" , 1);
     
            int is_file = strcmp(argv[file_num], "-");
     
            if (!is_file) {
                if(file_num == 1) is_error_first_argument = 1;
                    is_error = 1;
     
                if (argc > 2) {
                    write(1 , "==> " , 4);
                    write(1 , output , strlen(output));
                    write(1 , " <==" , 4);
                    write(1 , "\n" , 1);
                }
                file_num++;
     
                input_reading(argc , argv, file_num);
            }else {
     
                fd = file_open(argc, argv, file_name, file_num);
                file_num++;
     
                if (fd >= 0) {
                    is_error = 0;
                            new_line = lines_count(fd, buffer, new_line);
     
                    lseek(fd, 0, SEEK_SET);
     
                    lines = Write(new_line, lines, buffer, fd, file_num, argc);
                }
            }
            if (file_num > 2 && is_error == 1)
                        write(1 , "\n" , 1);
                    //if (file_num != argc && is_error == 1) {
                    //  if (is_error_first_argument == 0)
                    //  write(1 , "\n" , 1);
                    //}
        }
    }
    else {
        input_reading(argc , argv, 1);
    }  
 
return 0;
}
 
 
 