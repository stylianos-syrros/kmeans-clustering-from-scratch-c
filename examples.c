#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void sdtExamples(){  
    FILE *fp = fopen("examplesSDT.txt", "w");
    double x1,x2;
    srand(time(NULL));
    for (int i = 0; i < 8000; i++){
        //double x1 = (double)rand() / RAND_MAX * 2 - 1;
        //double x2 = (double)rand() / RAND_MAX * 2 - 1;
        x1 = -1 + (double)rand() / RAND_MAX * 2;
        x2 = -1 + (double)rand() / RAND_MAX * 2;
        fprintf(fp, "%f %f\n",x1,x2);
    }

    fclose(fp);
}

void sdoExamples(){
    srand(time(NULL));
    FILE *fp = fopen("examplesSDO.txt", "w");
    double x,y; 
    // Generate a random x value between 0.8 and 1.2
    for (int i = 0; i < 150; i++) {
        x = 0.8 + (double)rand() / RAND_MAX * (1.2 - 0.8);
        y = 0.8 + (double)rand() / RAND_MAX * (1.2 - 0.8);
        fprintf(fp,"%f %f\n", x, y);
    }
    //fprintf(fp,"\n");

    // Generate a random x value between 0 and 0.5
    for (int i = 0; i < 150; i++) {    
        x = (double)rand() / RAND_MAX * 0.5;
        y = (double)rand() / RAND_MAX * 0.5;
        fprintf(fp,"%f %f\n", x, y);
    }
    //fprintf(fp,"\n");

    for (int i = 0; i < 150; i++) {
        // Generate a random x value between 0 and 0.5
        x = (double)rand() / RAND_MAX * 0.5;
        // Generate a random y value between 1.5 and 2
        y = 1.5 + (double)rand() / RAND_MAX * (2 - 1.5);
        fprintf(fp,"%f %f\n", x, y);
    }
    //fprintf(fp,"\n");

    for (int i = 0; i < 150; i++) {
        // Generate a random x value between 1.5 and 2
        x = 1.5 + (double)rand() / RAND_MAX * (2 - 1.5);
        // Generate a random y value between 0 and 0.5
        y = (double)rand() / RAND_MAX * 0.5;
        fprintf(fp,"%f %f\n", x, y);
    }
    //fprintf(fp,"\n");

    // Generate a random x value between 1.5 and 2
    for (int i = 0; i < 150; i++) {
        x = 1.5 + (double)rand() / RAND_MAX * (2 - 1.5);
        y = 1.5 + (double)rand() / RAND_MAX * (2 - 1.5);
        fprintf(fp,"%f %f\n", x, y);
    }
    //fprintf(fp,"\n");

    for (int i = 0; i < 75; i++) {
        // Generate a random x value between 0.8 and 1.2
        x = 0.8 + (double)rand() / RAND_MAX * (1.2 - 0.8);
        // Generate a random y value between 0 and 0.4
        y = (double)rand() / RAND_MAX * 0.4;
        fprintf(fp,"%f %f\n", x, y);
    }
    //fprintf(fp,"\n");

    for (int i = 0; i < 75; i++) {
        // Generate a random x value between 0.8 and 1.2
        x = 0.8 + (double)rand() / RAND_MAX * (1.2 - 0.8);
        // Generate a random y value between 1.6 and 2
        y = 1.6 + (double)rand() / RAND_MAX * (2 - 1.6);
        fprintf(fp,"%f %f\n", x, y);
    }
    //fprintf(fp,"\n");

    for (int i = 0; i < 75; i++) {
        // Generate a random x value between 0.3 and 0.7
        x = 0.3 + (double)rand() / RAND_MAX * (0.7 - 0.3);
        // Generate a random y value between 0.8 and 1.2
        y = 0.8 + (double)rand() / RAND_MAX * (1.2 - 0.8);
        fprintf(fp,"%f %f\n", x, y);
    }
    //fprintf(fp,"\n");

    for (int i = 0; i < 75; i++) {
        // Generate a random x value between 1.3 and 1.7
        x = 1.3 + (double)rand() / RAND_MAX * (1.7 - 1.3);
        // Generate a random y value between 0.8 and 1.2
        y = 0.8 + (double)rand() / RAND_MAX * (1.2 - 0.8);
        fprintf(fp,"%f %f\n", x, y);
    }
        //fprintf(fp,"\n");

    for (int i = 0; i < 150; i++) {
        // Generate a random x value between 0 and 2
        x = (double)rand() / RAND_MAX * 2;
        y = (double)rand() / RAND_MAX * 2;
        fprintf(fp,"%f %f\n", x, y);
    }
    //fprintf(fp,"\n");

    fclose(fp);
}

int main() {

    sdtExamples();
    sdoExamples();
    system("python pointSDT.py");
    system("python pointSDO.py");

    return 0;
}