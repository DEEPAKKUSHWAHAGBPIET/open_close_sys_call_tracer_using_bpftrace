// file_ops_demo.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
     
    const char *filename = "testfile.txt";

   
    int fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    write(fd, "Hello eBPF\n", 11);
    close(fd);
    
    printf("process id: %d\n", getpid());
    
    for (int i = 0; i < 6; i++) {
        fd = open(filename, O_RDONLY);
        if (fd < 0) {
            perror("open");
            return 1;
        }

        char buffer[128];
        read(fd, buffer, sizeof(buffer));
        close(fd);

        sleep(10); 
    }

    printf("Finished file operations demo.\n");
    return 0;
}
