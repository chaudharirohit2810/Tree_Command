#include "tree.h"
#include "sort.c"

//To store all the information regarding particular file
record* make_record(char* name, int level, char* path) {
	record* rec = (record*) malloc(sizeof(record));
	strcpy(rec->name, name);
	rec->num_childs = 0;
	rec->num_all_childs = 0;
	rec->num_directories = 0;
	rec->num_all_directories = 0;
	rec->is_directory = 0;
	rec->size = get_file_size(path);
	get_username(rec->username, path);
	rec->level = level;
	return rec;
}

//To create particular node of tree
node* createNode(char* v, int level, char* path) {
	node* temp = malloc(sizeof(node));
	temp->rec = make_record(v, level, path);
	return temp;
}


//Create new tree
node* start_new_tree(char* v, int level) {
	return createNode(v, level, v);
}

//Insert node to tree
node* insert_node(node* root, char* name, int level, int reverse_toggle, int time_toggle) {
	if(root == NULL) {
		root = start_new_tree(name, level);
		root->rec->is_directory = 1;
	}
        int n, i;
        char* path = (char*)malloc(1024);
	//Struct dirent contains all the information regarding file
        struct dirent **dr; 
	
	//To sort according to different flags given
	if(reverse_toggle && time_toggle) {
        	n = scandir(name, &dr, NULL, sort);
		time_Sort(dr, 0, n - 1, name, 1);
	}else if(reverse_toggle) {
		n = scandir(name, &dr, NULL, reversesort);
	}else if(time_toggle) {
		n = scandir(name, &dr, NULL, sort);
		time_Sort(dr, 0, n - 1, name, 0);
	}else {
		n = scandir(name, &dr, NULL, sort);
	}

	//File address is incorrect
	if(n == -1) {
		perror("Open Failed ");
	}
	
	//Malloc the memory to all root pointes and make them NULL
	if(n > 1) {
		root->pointers = malloc(sizeof(node*) * n);
		if(root->pointers == NULL)
			printf("Allocation Failed\n");
		
		for(i = 0; i < n; i++)
			root->pointers[i] = NULL;
	}

	//Create the tree
	for(i = 0 ; i < n; i++) {
		if(root->pointers[i] == NULL ) {
			strcpy(path, name);
			strcat(strcat(path, "/"), dr[i]->d_name);
			root->pointers[i] = createNode(dr[i]->d_name, level, path);
			if(dr[i]->d_type == DT_DIR && dr[i]->d_name[0] != '.')
				(root->rec->num_directories)++;
			if(dr[i]->d_type == DT_DIR && strcmp(dr[i]->d_name, ".") != 0 && strcmp(dr[i]->d_name, "..") != 0) {
				root->pointers[i]->rec->is_directory = 1;
				(root->rec->num_all_directories)++;
				root->pointers[i] = insert_node(root->pointers[i], path, level + 1, reverse_toggle, time_toggle);
				strcpy(path, name);
			}
			if(dr[i]->d_name[0] != '.')
				(root->rec->num_childs)++;
			(root->rec->num_all_childs)++;
			free(dr[i]);
		}
	}
	return root;
}

node* destroy_tree(node* root, node* parent) {
	int i = 0;
	if(root == NULL) {
		return NULL;
	}	
	int temp = root->rec->num_all_childs;
	for(i = 0; i < temp; i++) {
		root->pointers[i] = destroy_tree(root->pointers[i], root);
	}
	if(root->rec->num_all_childs == 0) {
		if(parent == NULL) {
			free(root);
			return NULL;
		}
		free(root);
		parent->rec->num_all_childs--;
		return NULL;
	}
	return NULL;	
}
//To get the file size
long get_file_size(char* path) {
        struct stat stats;
        stat(path, &stats);
        return stats.st_size;
}

//To get the username of file
void get_username(char* name, char* path) {
	struct stat stats;
	stat(path, &stats);
	struct passwd *pwuser;
	pwuser = getpwuid(stats.st_uid);
	strcpy(name, pwuser->pw_name);
}
