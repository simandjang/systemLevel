#include <stdio.h>
#include <dirent.h>
int main() {
	DIR *input_dir;
    	struct dirent *dir;
    	input_dir = opendir("copies/");
    	if (input_dir) {
		while ((dir = readdir(input_dir)) != NULL) {
           		printf("%s\n", dir -> d_name);
			char *origin;
			char *destin;
			origin = malloc(strlen("copies/")+ strlen(dir -> d_name) + 1);
			destin = malloc(strlen("encrypted/")+ strlen(dir -> d_name) + 1);
			*origin = '\0';
			*destin = '\0';
			strcat(origin, "copies/");
			strcat(destin, "encrypted/");
			strcat(origin, dir -> d_name);
			strcat(destin, dir -> d_name);
			FILE *in_fp;
			FILE *out_fp;
			int key = 150;
			in_fp = fopen(origin, "r");
			out_fp = fopen(destin, "w");
			char c = fgetc(in_fp);
			while (c != EOF) {
				fputc((c + key) % 256, out_fp);
				key = (key - 1) % 256;
				c = fgetc(in_fp);
			}

			fclose(in_fp);
			fclose(out_fp);
			free(origin);
			free(destin);
        	}
        	closedir(input_dir);
  	}

}
