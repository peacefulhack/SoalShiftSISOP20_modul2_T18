#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <dirent.h>

int cekfolder(const char *path){
  struct stat pathDir;
  stat(path, &pathDir);
  return S_ISDIR(pathDir.st_mode);
}

int main(){
	pid_t ch_id;
	int cp_a,cp_b;
  ch_id = fork();
  cp_a = fork();
  cp_b = fork();
	int status;

  if (cp_a > 0 && cp_b == 0){execl("/bin/unzip","unzip","-o","jpg.zip",NULL);}

  else if (cp_a == 0 && cp_b > 0){
  	while ((wait(&status)) > 0);
  	if (ch_id == 0){execl("/bin/mkdir","mkdir","-p","indomie",NULL);}

    else{
       while ((wait(&status)) > 0);
        	sleep(5);
  	  	execl("/bin/mkdir","mkdir","-p","sedaap",NULL);
  	   }
  	}
	else if (cp_a > 0 && cp_b > 0){
		while ((wait(&status)) > 0);
		DIR *loc;
		struct dirent *directory;
		chdir("jpg/");
		loc = opendir(".");
	if (loc){
      	while ((directory = readdir(loc)) != NULL){
	          if(strcmp(directory->d_name, ".") == 0 || strcmp(directory->d_name, "..") == 0)
		          continue;
		        if(cekfolder(directory->d_name)){
		          if(fork() == 0){
		            char folder[1000];
		            sprintf(folder,"jpg/%s",directory->d_name);
			          execl("/bin/mv","mv",folder,"indomie", NULL);
              }else{
                while ((wait(&status)) > 0);
                if(fork() == 0){
              	  if(fork() == 0){
              	    char input[1000];
              	    FILE *file_coba1;
  		        	    sprintf(input,"/home/peacefulhack/Documents/Sistem Operasi/modul 2/SoalShiftSISOP20_modul2_T18/Soal3/indomie/%s/coba1.txt",directory->d_name);
  		        	    file_coba1 = fopen(input, "w");
  		        	    fclose(file_coba1);
		              }else{
		                while ((wait(&status)) > 0);
    		            sleep(3);
    		            char input2[1000];
    		            FILE *file_coba2;
    		            sprintf(input2,"/home/peacefulhack/Documents/Sistem Operasi/modul 2/SoalShiftSISOP20_modul2_T18/Soal3/indomie/%s/coba2.txt",directory->d_name);
    		            file_coba2 = fopen(input2, "w");
    		            fclose(file_coba2);
    		            exit(0);
		    	        }
                }else{while ((wait(&status)) > 0);exit(0);}
              }
            }else{
              while ((wait(&status)) > 0);
              if(fork() == 0){
                 while ((wait(&status)) > 0);
                 char sfile[1000];
                 sprintf(sfile,"/home/peacefulhack/Documents/Sistem Operasi/modul 2/SoalShiftSISOP20_modul2_T18/Soal3/jpg/%s",directory->d_name);
			           execl("/bin/mv","mv",sfile,"/home/peacefulhack/Documents/Sistem Operasi/modul 2/SoalShiftSISOP20_modul2_T18/Soal3/sedaap/",NULL);
          	  }
            }
        }
    }
}

	return 0;
}
