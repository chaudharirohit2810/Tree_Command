
// To print the tree in json format
void json_print_normal(node* root, int indent, int start, int size_toggle, int user_toggle, int filelimit, int P_toggle, char* pattern) {
	int i, j;
	if (root == NULL)
		return;
	if (user_toggle && size_toggle) {
		if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
			}else {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
			}
		} else {
			if (root->rec->is_directory) {
				D++;
				for (i = 0; i < indent; i++)
					printf("\t");
				if(root->rec->num_childs <= filelimit) {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"user\":\"%s\",\"size\":%ld,\"contents\":[\n", root->rec->name, root->rec->username, root->rec->size);
				}else {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"user\":\"%s\",\"size\":%ld,\"contents\":[,", root->rec->name, root->rec->username, root->rec->size);
				}
			} else {
				if (root->rec->name[0] != '.') {
					if (P_toggle)
					{
						if(strmatch(root->rec->name, pattern, strlen(root->rec->name), strlen(pattern))) {
							F++;
							for (i = 0; i < indent; i++)
								printf("\t");
							printf("{\"type\":\"file\",\"name\":\"%s\",\"user\":\"%s\",\"size\":%ld},\n", root->rec->name, root->rec->username, root->rec->size);
						}
					}else {					
						F++;
						for (i = 0; i < indent; i++)
							printf("\t");
						printf("{\"type\":\"file\",\"name\":\"%s\",\"user\":\"%s\",\"size\":%ld},\n", root->rec->name, root->rec->username, root->rec->size);
					}
				}
			}
		}
	} else if (user_toggle) {
		if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
			}else {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
			}
		} else {
			if (root->rec->is_directory) {
				D++;
				for (i = 0; i < indent; i++)
					printf("\t");
				if(root->rec->num_childs <= filelimit) {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"user\":\"%s\",\"contents\":[\n", root->rec->name, root->rec->username);
				}else {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"user\":\"%s\",\"contents\":[,", root->rec->name, root->rec->username);
				}
			} else {
				if (root->rec->name[0] != '.') {
					if (P_toggle)
					{
						if(strmatch(root->rec->name, pattern, strlen(root->rec->name), strlen(pattern))) {
							F++;
							for (i = 0; i < indent; i++)
								printf("\t");
							printf("{\"type\":\"file\",\"name\":\"%s\",\"user\":\"%s\"},\n", root->rec->name, root->rec->username);
						}
					}else {
						F++;
						for (i = 0; i < indent; i++)
							printf("\t");
						printf("{\"type\":\"file\",\"name\":\"%s\",\"user\":\"%s\"},\n", root->rec->name, root->rec->username);
					}
				}
			}
		}
	} else if (size_toggle) {
		if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
			}else {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
			}
		} else {
			if (root->rec->is_directory) {
				D++;
				for (i = 0; i < indent; i++)
					printf("\t");
				if(root->rec->num_childs <= filelimit) {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"size\":%ld,\"contents\":[\n", root->rec->name, root->rec->size);
				}else {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"size\":%ld,\"contents\":[,", root->rec->name, root->rec->size);
				}
			} else {
				if (root->rec->name[0] != '.') {
					if (P_toggle)
					{
						if(strmatch(root->rec->name, pattern, strlen(root->rec->name), strlen(pattern))) {
							F++;
							for (i = 0; i < indent; i++)
								printf("\t");
							printf("{\"type\":\"file\",\"name\":\"%s\",\"size\":%ld},\n", root->rec->name, root->rec->size);
						}
					}else {
						F++;
						for (i = 0; i < indent; i++)
							printf("\t");
						printf("{\"type\":\"file\",\"name\":\"%s\",\"size\":%ld},\n", root->rec->name, root->rec->size);
					}
				}
			}
		}
	} else {
		if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
			}else {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
			}
		} else {
			if (root->rec->is_directory) {
				D++;
				for (i = 0; i < indent; i++)
					printf("\t");
				if(root->rec->num_childs <= filelimit) {
					printf("{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
				}else {
					printf("{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
				}
			} else {
				if (root->rec->name[0] != '.') {
					if (P_toggle)
					{
						if(strmatch(root->rec->name, pattern, strlen(root->rec->name), strlen(pattern))) {
							F++;
							for (i = 0; i < indent; i++)
								printf("\t");
							printf("{\"type\":\"file\",\"name\":\"%s\"},\n", root->rec->name);
						}
					}else {
						F++;
						for (i = 0; i < indent; i++)
							printf("\t");
						printf("{\"type\":\"file\",\"name\":\"%s\"},\n", root->rec->name);
					}
				}
			}
		}
 	}

	if(root->rec->num_childs <= filelimit) {
    		for (i = 0; i < root->rec->num_all_childs; i++) {
		    	if (root->pointers[i] != NULL && root->pointers[i]->rec->name[0] != '.')
				    json_print_normal(root->pointers[i], indent + 1, 0, size_toggle, user_toggle, filelimit, P_toggle, pattern);
			if(i == root->rec->num_all_childs - 1) {
				for (j = 0; j < indent; j++)
					printf("\t");
				printf("   ]},\n");
			}
    		}
	}else {
		printf(" \"error\":\"%d entries exceeds filelimit, not opening dir\"\n   ]},\n", root->rec->num_childs);
	}
}

// To print the tree with hidden files in json format
void json_print_all(node* root, int indent, int start, int size_toggle, int user_toggle, int filelimit, int P_toggle, char* pattern) {
	int i, j;
	if (root == NULL)
		return;
	
	if (size_toggle && user_toggle) {
        	if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
			}else {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
			}
        	} else {
           		if (root->rec->is_directory) {
                		D++;
				for (i = 0; i < indent; i++)
					printf("\t");
				if(root->rec->num_childs <= filelimit) {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"user\":\"%s\",\"size\":%ld,\"contents\":[\n", root->rec->name, root->rec->username, root->rec->size);
				}else {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"user\":\"%s\",\"size\":%ld,\"contents\":[,", root->rec->name, root->rec->username, root->rec->size);
				}
            		} else {
                		if (strcmp(root->rec->name, ".") != 0 && strcmp(root->rec->name, "..") != 0) {
                    			if (P_toggle)
					{
						if(strmatch(root->rec->name, pattern, strlen(root->rec->name), strlen(pattern))) {
							F++;
							for (i = 0; i < indent; i++)
								printf("\t");
							printf("{\"type\":\"file\",\"name\":\"%s\",\"user\":\"%s\",\"size\":%ld},\n", root->rec->name, root->rec->username, root->rec->size);
						}
					}else {					
						F++;
						for (i = 0; i < indent; i++)
							printf("\t");
						printf("{\"type\":\"file\",\"name\":\"%s\",\"user\":\"%s\",\"size\":%ld},\n", root->rec->name, root->rec->username, root->rec->size);
					}
                		}
            		}	
        	}
    	} else if (user_toggle) {
        	if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
			}else {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
			}
        	} else {
           		if (root->rec->is_directory) {
                		D++;
				for (i = 0; i < indent; i++)
					printf("\t");
				if(root->rec->num_childs <= filelimit) {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"user\":\"%s\",\"contents\":[\n", root->rec->name, root->rec->username);
				}else {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"user\":\"%s\",\"contents\":[,", root->rec->name, root->rec->username);
				}
            		} else {
                		if (strcmp(root->rec->name, ".") != 0 && strcmp(root->rec->name, "..") != 0) {
                    			if (P_toggle)
					{
						if(strmatch(root->rec->name, pattern, strlen(root->rec->name), strlen(pattern))) {
							F++;
							for (i = 0; i < indent; i++)
								printf("\t");
							printf("{\"type\":\"file\",\"name\":\"%s\",\"user\":\"%s\"},\n", root->rec->name, root->rec->username);
						}
					}else {
						F++;
						for (i = 0; i < indent; i++)
							printf("\t");
						printf("{\"type\":\"file\",\"name\":\"%s\",\"user\":\"%s\"},\n", root->rec->name, root->rec->username);
					}
                		}
            		}	
        	}
    	} else if (size_toggle) {
        	if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
			}else {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
			}
        	} else {
           		if (root->rec->is_directory) {
                		D++;
				for (i = 0; i < indent; i++)
					printf("\t");
				if(root->rec->num_childs <= filelimit) {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"size\":%ld,\"contents\":[\n", root->rec->name, root->rec->size);
				}else {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"size\":%ld,\"contents\":[,", root->rec->name, root->rec->size);
				}
            		} else {
                		if (strcmp(root->rec->name, ".") != 0 && strcmp(root->rec->name, "..") != 0) {
                    			if (P_toggle)
					{
						if(strmatch(root->rec->name, pattern, strlen(root->rec->name), strlen(pattern))) {
							F++;
							for (i = 0; i < indent; i++)
								printf("\t");
							printf("{\"type\":\"file\",\"name\":\"%s\",\"size\":%ld},\n", root->rec->name, root->rec->size);
						}
					}else {
						F++;
						for (i = 0; i < indent; i++)
							printf("\t");
						printf("{\"type\":\"file\",\"name\":\"%s\",\"size\":%ld},\n", root->rec->name, root->rec->size);
					}
                		}
            		}	
        	}
    	} else {
        	if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
			}else {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
				for (i = 0; i < indent; i++)
					printf("\t");
				if(root->rec->num_childs <= filelimit) {
					printf("{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
				}else {
					printf("{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
				}
            		} else {
                		if (strcmp(root->rec->name, ".") != 0 && strcmp(root->rec->name, "..") != 0) {
                    			if (P_toggle)
					{
						if(strmatch(root->rec->name, pattern, strlen(root->rec->name), strlen(pattern))) {
							F++;
							for (i = 0; i < indent; i++)
								printf("\t");
							printf("{\"type\":\"file\",\"name\":\"%s\"},\n", root->rec->name);
						}
					}else {
						F++;
						for (i = 0; i < indent; i++)
							printf("\t");
						printf("{\"type\":\"file\",\"name\":\"%s\"},\n", root->rec->name);
					}
                		}
            		}
        	}
    	}

	if(root->rec->num_childs <= filelimit) {
    		for (i = 0; i < root->rec->num_all_childs; i++) {
        		if (root->pointers[i] != NULL)
            			json_print_all(root->pointers[i], indent + 1, 0, size_toggle, user_toggle, filelimit, P_toggle, pattern);
			if(i == root->rec->num_all_childs - 1) {
				for (j = 0; j < indent; j++)
					printf("\t");
				printf("   ]},\n");
			}
			
    		}
	}else {
		printf(" \"error\":\"%d entries exceeds filelimit, not opening dir\"\n   ]},\n", root->rec->num_childs);
	}
}

// To print only directories in json format 
void json_print_normal_directory(node* root, int indent, int start, int size_toggle, int user_toggle, int filelimit)
{
    	int i, j;
    	if (root == NULL)
        	return;

	if (size_toggle && user_toggle) {
        	if (start == 1) {
            		if(root->rec->num_directories <= filelimit) {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
			}else {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
				for (i = 0; i < indent; i++)
					printf("\t");
				if(root->rec->num_directories <= filelimit) {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"user\":\"%s\",\"size\":%ld,\"contents\":[\n", root->rec->name, root->rec->username, root->rec->size);
				}else {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"user\":\"%s\",\"size\":%ld,\"contents\":[,", root->rec->name, root->rec->username, root->rec->size);
				}
            		}
        	}	
    	} else if (user_toggle) {
        	if (start == 1) {
            		if(root->rec->num_directories <= filelimit) {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
			}else {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
				for (i = 0; i < indent; i++)
					printf("\t");
				if(root->rec->num_directories <= filelimit) {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"user\":\"%s\",\"contents\":[\n", root->rec->name, root->rec->username);
				}else {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"user\":\"%s\",\"contents\":[,", root->rec->name, root->rec->username);
				}
            		}
        	}	
    	} else if (size_toggle) {
        	if (start == 1) {
            		if(root->rec->num_directories <= filelimit) {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
			}else {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
				for (i = 0; i < indent; i++)
					printf("\t");
				if(root->rec->num_directories <= filelimit) {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"size\":%ld,\"contents\":[\n", root->rec->name, root->rec->size);
				}else {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"size\":%ld,\"contents\":[,", root->rec->name, root->rec->size);
				}
            		}
        	}	
    	} else {
        	if (start == 1) {
            		if(root->rec->num_directories <= filelimit) {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
			}else {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
				for (i = 0; i < indent; i++)
					printf("\t");
				if(root->rec->num_directories <= filelimit) {
					printf("{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
				}else {
					printf("{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
				}
            		}
        	}
    	}

	if(root->rec->num_directories <= filelimit) {
    		for (i = 0; i < root->rec->num_all_childs; i++) {
        		if (root->pointers[i] != NULL && root->pointers[i]->rec->name[0] != '.')
            			json_print_normal_directory(root->pointers[i], indent + 1, 0, size_toggle, user_toggle, filelimit);
			if(i == root->rec->num_all_childs - 1) {
				for (j = 0; j < indent; j++)
					printf("\t");
				printf("   ]},\n");
    			}
		}
	}else {
		printf(" \"error\":\"%d entries exceeds filelimit, not opening dir\"\n   ]},\n", root->rec->num_directories);
	}
}


// To print directories including hidden directories in json format
void json_print_all_directory(node* root, int indent, int start, int size_toggle, int user_toggle, int filelimit)
{
    	int i, j;
    	if (root == NULL)
        	return;
	if (size_toggle && user_toggle) {
        	if (start == 1) {
            		if(root->rec->num_all_directories <= filelimit) {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
			}else {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
				for (i = 0; i < indent; i++)
					printf("\t");
				if(root->rec->num_all_directories <= filelimit) {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"user\":\"%s\",\"size\":%ld,\"contents\":[\n", root->rec->name, root->rec->username, root->rec->size);
				}else {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"user\":\"%s\",\"size\":%ld,\"contents\":[,", root->rec->name, root->rec->username, root->rec->size);
				}
            		}
        	}
    	} else if (user_toggle) {
        	if (start == 1) {
            		if(root->rec->num_all_directories <= filelimit) {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
			}else {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
				for (i = 0; i < indent; i++)
					printf("\t");
				if(root->rec->num_all_directories <= filelimit) {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"user\":\"%s\",\"contents\":[\n", root->rec->name, root->rec->username);
				}else {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"user\":\"%s\",\"contents\":[,", root->rec->name, root->rec->username);
				}
            		}
        	}
    	} else if (size_toggle) {
        	if (start == 1) {
            		if(root->rec->num_all_directories <= filelimit) {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
			}else {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
				for (i = 0; i < indent; i++)
					printf("\t");
				if(root->rec->num_all_directories <= filelimit) {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"size\":%ld,\"contents\":[\n", root->rec->name, root->rec->size);
				}else {
					printf("[{\"type\":\"directory\",\"name\":\"%s\",\"size\":%ld,\"contents\":[,", root->rec->name, root->rec->size);
				}
            		}
        	}
    	} else {
        	if (start == 1) {
            		if(root->rec->num_all_directories <= filelimit) {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
			}else {
				printf("[{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
				for (i = 0; i < indent; i++)
					printf("\t");
				if(root->rec->num_all_directories <= filelimit) {
					printf("{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[\n", root->rec->name);
				}else {
					printf("{\"type\":\"directory\",\"name\":\"%s\",\"contents\":[,", root->rec->name);
				}
            		}
        	}
    	}
	if(root->rec->num_all_directories <= filelimit) {
    		for (i = 0; i < root->rec->num_all_childs; i++) {
        		if (root->pointers[i] != NULL)
            			json_print_all_directory(root->pointers[i], indent + 1, 0, size_toggle, user_toggle, filelimit);
			if(i == root->rec->num_all_childs - 1) {
				for (j = 0; j < indent; j++)
					printf("\t");
				printf("   ]},\n");
    			}
		}
	}else {
		printf(" \"error\":\"%d entries exceeds filelimit, not opening dir\"\n   ]},\n", root->rec->num_all_directories);
	}
}

