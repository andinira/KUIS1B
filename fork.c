#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void *myThread(void *vargp){
    sleep(1);
    data("data1.txt");
    return NULL;
} 

void fork(){

    int pid;
    data("data.text");

    switch (pid = fork())
    {
    case 0:
        data("data1.text");
        break;
    default:
        printf("proses orangtua: pid=%d, anak pid=%d\n", getpid(), pid);
        break;
    case -1:
        perror("fork");
        exit(1);
    }
    exit(0);
}

void data(){

    //mendeklarasikan yang ada dalam file

    FILE * file; 
    
    char ch; //variabel untuk huruf

    int kata; //untuk menampung jumlah kata

    //membuka file data yang telah terisi kata

    file = fopen("data.txt", "r");

    //untuk menghitung kata dalam file

    kata = 0;

    //selama huruf tidak sama dengan EOF (end of file) maka dia akan terus looping

    while ((ch = fgetc(file)) != EOF){



        // Check huruf bukan spasi 

        if (ch == '\0' || ch == '\n' || ch == '\t' || ch == ' '){

            kata++; //maka kata akan bertambah 1

	    }

    }

    printf("\n");

    //menampilkan total kata dalam file

    printf("Total kata: %d\n", kata);

   //close file

    fclose(file);
}
  
int main (int argc, char **argv){

    int n;
    printf("Ingin apa? \n");
    printf("1. Fork \n");
    printf("2. Thread \n");
    scanf("%d", &n);

    if(pilihan == 1){
        fork();
    }else if(pilihan == 2){
        pthread_t thread_id;

        printf("Sebelum dilakukan Thread \n");
        data(data2.txt);

        pthread_create(&thread_id, NULL, myThread, NULL);

        pthread_join(thread_id, NULL);
        printf("Sesudah Thread");

        exit(0);
    }else{
        printf("Maaf pilihan tida ada");
    }


    return 0;
}