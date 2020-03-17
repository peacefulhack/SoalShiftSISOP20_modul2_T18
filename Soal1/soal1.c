#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

int main (int argc, char *argv[]) {
  pid_t pid, sid;

  time_t rawtime = time(NULL);
  struct tm ftime = *localtime(&rawtime);

  int d = -1;
  int m = -1;
  int j = -1;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if (argc > 5) {
    printf ("terlalu banyak argumen\n");
    return 0;
  }
  else if(argc < 5){
    printf("terlalu sedikit argumen\n");
    return 0;
  }
  else if(access( argv[4], F_OK ) == -1){
    printf("file tidak terbaca\n");
    return 0;
    exit(EXIT_FAILURE);
  }
  else{
    if ((atoi(argv[1]) > 59 && strcmp(argv[1], "*")!=0) || (atoi(argv[1]) < 0 && strcmp(argv[1], "*")!=0 )) {
      printf("Format Detik Salah\n");return 0;}
    else if(strcmp(argv[1], "*")!=0){d=atoi(argv[1]);}

    if ((atoi(argv[2]) > 59 && strcmp(argv[2], "*")!=0) || (atoi(argv[2]) < 0 && strcmp(argv[2], "*")!=0 )) {
      printf("Format Menit Salah\n");return 0;}
    else if(strcmp(argv[2], "*")!=0){m=atoi(argv[2]);}

    if ((atoi(argv[3]) > 23 && strcmp(argv[3], "*")!=0) || (atoi(argv[3]) < 0 && strcmp(argv[3], "*")!=0 )) {
      printf("Format Detik Salah\n");return 0;}
    else if(strcmp(argv[1], "*")!=0){j=atoi(argv[3]);}
    while (1) {
    rawtime = time(NULL);
    ftime = *localtime(&rawtime);
    if ((ftime.tm_hour == j || j == -1) && (ftime.tm_min == m || m == -1) && (ftime.tm_sec == d || d == -1)) {
      printf("dal\n");
      if (fork()==0){
        execl("/bin/bash", "bash", argv[4], NULL);}
        sleep(1);
      }
    }
  }
}
