#include <stdio.h>
#include <dirent.h>
int main() {
        DIR *input_dir;
        struct dirent *dir;
        input_dir = opendir("encrypted");
        if (input_dir) {
                while ((dir = readdir(input_dir)) != NULL) {
                        char origin[64];
                        char destin[64];
                        strcpy(origin, "encrypted/");
                        strcpy(destin, "decrypted/");
                        strcat(origin, dir -> d_name);
                        strcat(destin, dir -> d_name);
                        FILE *in_fp;
                        FILE *out_fp;
                        int key = 150;
                        in_fp = fopen(origin, "r");
                        out_fp = fopen(destin, "w");
                        char c = fgetc(in_fp);
                        while (c != EOF) {
                                fputc(((c - key) % 256), out_fp);
                                key = (key - 1) % 256;
                                c = fgetc(in_fp);
                        }

                        fclose(in_fp);
                        fclose(out_fp);
                }
                closedir(input_dir);
        }

}

