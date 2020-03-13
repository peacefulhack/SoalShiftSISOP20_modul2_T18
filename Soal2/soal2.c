#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include<curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <signal.h>
void sig_handler(int signo)
{ int *a;
  if (signo == SIGINT)
    *a = 1;
}
int main(int argc, char *argv[]) {
  int a;
  signal(SIGINT, sig_handler);
  int b;
  pid_t pid, sid;
  pid_t child_id;
  pid_t child_id2;
  pid_t child_id3;
  pid_t child_id4;
  pid_t child_id5;
  pid_t child_id6;
  pid_t child_id7;
  FILE *fp;

  time_t rawtime;
  struct tm *info;
  char tanggal[80];

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

  if ((chdir("/home/peacefulhack/Documents/Sistem Operasi/modul 2/SoalShiftSISOP20_modul2_T18/Soal2/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
  child_id5 = fork();
  if(child_id5 < 0){exit(EXIT_FAILURE);}
  if(child_id5 == 0){
    if(strcmp(argv[1], "-a") == 0){
      fp = fopen("killer.c","w");
      fprintf(fp, "#include<stdio.h>\n");
      fprintf(fp, "#include<unistd.h>\n");
      fprintf(fp, "#include <sys/types.h>\n");
      fprintf(fp, "#include <sys/wait.h>\n");
      fprintf(fp, "#include <stdlib.h>\n");
      fprintf(fp, "int main(){\n");
      fprintf(fp, "pid_t pid;\n");
      fprintf(fp, "pid = fork();\n");
      fprintf(fp, "if(pid<0){exit(EXIT_FAILURE);}\n");
      fprintf(fp, "else if(pid==0){\n");
      fprintf(fp, "char *argv[5] = {\"pkill\",\"--signal\",\"SIGKILL\", \"soal2\", NULL};\n ");
      fprintf(fp, "execv(\"/bin/pkill\",argv);\n ");
      fprintf(fp, "}\n");
      fprintf(fp, "else{\n");
      fprintf(fp, "pid = wait(NULL);\n");
      fprintf(fp, "char *argv[4] = {\"rm\", \"killer\", NULL};\n");
      fprintf(fp, "execv(\"/bin/rm\",argv);\n");
      fprintf(fp, "}\n");
      fprintf(fp, "}");
      fclose(fp);
      child_id7 = fork();
      if(child_id7<0){exit(EXIT_FAILURE);}
      if(child_id7 == 0){
        char *argv[5] = {"gcc", "killer.c", "-o", "killer", NULL};
        execv("/bin/gcc", argv);
      }
      else{
        child_id7 = wait(NULL);
        char *argv[3] = {"rm", "killer.c", NULL};
        execv("/bin/rm", argv);
      }
    }

  if(strcmp(argv[1],"-b") == 0){
    b = getppid();
    fp = fopen("killer.c","w");
    fprintf(fp, "#include<stdio.h>\n");
    fprintf(fp, "#include<unistd.h>\n");
    fprintf(fp, "#include<sys/types.h>\n");
    fprintf(fp, "#include <signal.h>\n");
    fprintf(fp, "#include <sys/wait.h>\n");
    fprintf(fp, "#include <stdlib.h>\n");
    fprintf(fp, "int main(){\n");
    fprintf(fp, "pid_t pid;\n");
    fprintf(fp, "pid = fork();\n");
    fprintf(fp, "if(pid<0){exit(EXIT_FAILURE);}\n");
    fprintf(fp, "else if(pid==0){\n");
    fprintf(fp, "char *argv[] = {\"pkill\",\"--signal\",\"SIGINT\",\"-P\", \"%d\", \"soal2\", NULL};\n ", b);
    fprintf(fp, "execv(\"/bin/pkill\",argv);\n");
    fprintf(fp, "}\n");
    fprintf(fp, "else{\n");
    fprintf(fp, "pid = wait(NULL);\n");
    fprintf(fp, "char *argv[] = {\"rm\", \"killer\", NULL};\n");
    fprintf(fp, "execv(\"/bin/rm\",argv);\n");
    fprintf(fp, "}\n");
    fprintf(fp, "}");
    fclose(fp);
    child_id7 = fork();
    if(child_id7<0){exit(EXIT_FAILURE);}
    else if(child_id7 == 0){
      char *argv[5] = {"gcc", "killer.c", "-o", "killer", NULL};
      execv("/bin/gcc", argv);
    }
    else{
      child_id7 = wait(NULL);
      //char *argv[3] = {"rm", "killer.c", NULL};
      //execv("/bin/rm", argv);
    }
    }
    }
  if(child_id5 > 0){
  while (1) {
      child_id4 = fork();
      if(child_id4<0){exit(EXIT_FAILURE);}
      if(child_id4==0){
        CURL *curl;
        FILE *fp;
        int result;
        char snum[100];
        char link[100];
        char nama[100];
        time_t seconds;
        int a = 0;
        time_t rawtime2;
        char tanggal2[80];
        struct tm *info2;

        time_t rawtime;
        struct tm *info;
        char tanggal[80];

        time( &rawtime );
        info = localtime( &rawtime );
        strftime(tanggal,80,"%Y-%m-%d_%X", info);

        child_id = fork();
        if (child_id < 0) {
          exit(EXIT_FAILURE);
        }
        if (child_id == 0) {
          char *argv[3] = {"mkdir" , tanggal , NULL};
          execv("/bin/mkdir", argv);
        } else {
          child_id = wait(NULL);
          child_id2 = fork();
          if (child_id2 < 0) {
            exit(EXIT_FAILURE);
          }
          if(child_id2 == 0){
            do{
            time( &rawtime2 );
            info2 = localtime( &rawtime2 );
            strftime(tanggal2,80,"%Y-%m-%d_%X", info2);

            seconds = time(NULL);
            seconds = (seconds%1000)+100;

            sprintf(snum, "%ld", seconds);
            strcpy(link, "https://i.picsum.photos/id/913/");
            strcat(link, snum);
            strcat(link, "/");
            strcat(link, snum);
            strcat(link, ".jpg");

            strcpy(nama, tanggal);
            strcat(nama, "/");
            strcat(nama, tanggal2);
            strcat(nama, ".jpg");

            fp = fopen( nama , "wb");
            curl = curl_easy_init();
            curl_easy_setopt(curl, CURLOPT_URL, link);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
            result = curl_easy_perform(curl);

            if(result == CURLE_OK){a+=1;}
            else{printf("%s\n", curl_easy_strerror(result));exit(EXIT_FAILURE);}
            fclose(fp);
            curl_easy_cleanup(curl);
          }while(a!=20);
          }
          else{
            child_id2 = wait(NULL);
            child_id3 = fork();
            if (child_id3 < 0) {
              exit(EXIT_FAILURE);
            }
            if(child_id3 == 0){
              char nz[100];
              strcpy(nz, tanggal);
              strcat(nz, ".zip");
              char *argv[5] = {"zip", "-r" , nz , tanggal , NULL};
              execv("/bin/zip", argv);
            }
            else{
              child_id3 = wait(NULL);
              char *argv2[4] = {"rm", "-r" , tanggal , NULL};
              execv("/bin/rm", argv2);
            }
          }
        }
      }
      else{
        sleep(30);
        if(a == 1){return 0; exit(EXIT_SUCCESS);}
      }
  }
  }
}
