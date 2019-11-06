#include<unistd.h>
#include<errno.h>
#include "tree.h"
#include "print.c"
#include "file.c"
#include "json.c"
#include "jsonFile.c"
#include<limits.h>
#include<getopt.h>
//Different toggles for different options
int size_toggle = 0, reverse_toggle = 0, user_toggle = 0, time_toggle = 0, a_toggle = 0, d_toggle = 0, file_toggle = 0, json_toggle = 0, flag = 0;
int filelimit = INT_MAX;

char filename[50]; //To store the name 

node* root = NULL;

void normal_print();

void json_print();

void file_print(FILE* );

void file_json_print(FILE* );

int main(int argc, char* argv[]) {
	char* path = malloc(sizeof(char) * 1024);

	//To check if Path is Given or Not, Otherwise give the default path
	if((argc == 2 && argv[1][0] == '-')) {
		strcpy(path, "."); //If Only Flags are given default path is selected
	}else if(argc < 2) {
		strcpy(path, "."); //If only default path is selected
	}else if(argv[1][0] != '-') {
		strcpy(path, argv[1]); // If only directory path is given
	}else {
		strcpy(path, "."); //If directory path and flags are given
	}

	int c;
	struct option longopts[] = {
		{"filelimit", 1, NULL, 'l'},
		{NULL, 0, NULL, 0}
	};
	while( (c = getopt_long(argc, argv, "l:dasurtJo:", longopts, NULL)) != -1) {
		switch(c) {
			case 'l' :
				filelimit = atoi(optarg);
				break;
			case 'd':
				d_toggle = 1;
				break;
			case 'a':
				a_toggle = 1;
				break;
			case 's':
				size_toggle = 1;
				break;
			case 'u':
				user_toggle = 1;
				break;
			case 'r':
				reverse_toggle = 1;
				break;
			case 't':
				time_toggle = 1;
				break;
			case 'J':
				json_toggle = 1;
				break;
			case 'o':
				file_toggle = 1;
				//`printf("filename : %s\n", optarg);
				if(strcmp(optarg, "J") != 0)
					strcpy(filename, optarg);
				else {
					json_toggle = 1;
					for(; optind < argc; optind++) {
						strcpy(filename, argv[optind]);
					}
				}
				break;	

			case '?':
				exit(0);
				break;
		}
	}
	
	root = insert_node(root, path, 1, reverse_toggle, time_toggle); //If default path and Flags are given

	if(file_toggle && json_toggle) {
		FILE* fp = fopen(filename, "w");
		if(fp == NULL) {
			printf("./tree : option requires an arguement -- 'o'\n"); 
			return errno;
		}
		file_json_print(fp);
	}else if(json_toggle) {
		json_print();
	}else if(file_toggle) {
		FILE* fp = fopen(filename, "w");
		if(fp == NULL) {
			printf("./tree : option requires an arguement -- 'o'\n"); 
			return errno;
		}
		file_print(fp);
	}else {
		normal_print();
	}

	free(path);
	return 0;
}

//Utility function to print tree in normal format
void normal_print() {
	if(a_toggle && !d_toggle) {
		print_all(root, -1, 1, size_toggle, user_toggle, filelimit);
		printf("\n%s%d Directories, %d Files\n", NRM, DCount(), FCount());
	}else if(a_toggle && d_toggle) {
		print_all_directory(root, -1, 1, size_toggle, user_toggle, filelimit);
		printf("\n%s%d Directories\n", NRM, DCount());
	}else if(d_toggle) {
		print_normal_directory(root, -1, 1, size_toggle, user_toggle, filelimit);
		printf("\n%s%d Directories\n", NRM, DCount());
	}else {
		print_normal(root, -1, 1, size_toggle, user_toggle, filelimit);
		printf("\n%s%d Directories, %d Files\n", NRM, DCount(), FCount());
	}
}

//Uitlity function to print tree in json format
void json_print() {
	if(a_toggle && !d_toggle) {
		json_print_all(root, 0, 1, size_toggle, user_toggle, filelimit);
		printf("   {\"type\":\"report\",\"directories\":%d,\"files\":%d}\n]\n", DCount(), FCount());
	}else if(a_toggle && d_toggle) {
		json_print_all_directory(root, 0, 1, size_toggle, user_toggle, filelimit);
		printf("   {\"type\":\"report\",\"directories\":%d }\n]\n", DCount());
	}else if(d_toggle) {
		json_print_normal_directory(root, 0, 1, size_toggle, user_toggle, filelimit);
		printf("   {\"type\":\"report\",\"directories\":%d}\n]\n", DCount());
	}else {
		json_print_normal(root, 0, 1, size_toggle, user_toggle, filelimit);
		printf("   {\"type\":\"report\",\"directories\":%d,\"files\":%d}\n]\n", DCount(), FCount());
	}
}

//Utility function to print tree in json format into the specified file
void file_json_print(FILE* fp) {
	if(a_toggle && !d_toggle) {
		file_json_print_all(fp, root, 0, 1, size_toggle, user_toggle, filelimit);
		fprintf(fp, "   {\"type\":\"report\",\"directories\":%d,\"files\":%d}\n]\n", DCount(), FCount());
	}else if(a_toggle && d_toggle) {
		file_json_print_all_directory(fp, root, 0, 1, size_toggle, user_toggle, filelimit);
		fprintf(fp, "   {\"type\":\"report\",\"directories\":%d }\n]\n", DCount());
	}else if(d_toggle) {
		file_json_print_normal_directory(fp, root, 0, 1, size_toggle, user_toggle, filelimit);
		fprintf(fp, "   {\"type\":\"report\",\"directories\":%d}\n]\n", DCount());
	}else {
		file_json_print_normal(fp, root, 0, 1, size_toggle, user_toggle, filelimit);
		fprintf(fp, "   {\"type\":\"report\",\"directories\":%d,\"files\":%d}\n]\n", DCount(), FCount());
	}

}	

//Utility function to print tree in to the specified file
void file_print(FILE* fp) {
	if(a_toggle && !d_toggle) {
		file_print_all(fp, root, -1, 1, size_toggle, user_toggle, filelimit);
		fprintf(fp, "\n%d Directories, %d Files\n", DCount(), FCount());
	}else if(a_toggle && d_toggle) {
		file_print_all_directory(fp, root, -1, 1, size_toggle, user_toggle, filelimit);
		fprintf(fp, "\n%d Directories\n", DCount());
	}else if(d_toggle) {
		file_print_normal_directory(fp, root, -1, 1, size_toggle, user_toggle, filelimit);
		fprintf(fp, "\n%d Directories\n", DCount());
	}else {
		file_print_normal(fp, root, -1, 1, size_toggle, user_toggle, filelimit);
		fprintf(fp, "\n%d Directories, %d Files\n", DCount(), FCount());
	}

}
