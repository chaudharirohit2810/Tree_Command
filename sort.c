
//To sort the files according to alphabetical order
int sort(const struct dirent **a, const struct dirent **b) {
        if((*a)->d_name[0] == '.')
                return strcasecmp(((*a)->d_name + 1) , (*b)->d_name);
        else if((*b)->d_name[0] == '.')
                return strcasecmp((*a)->d_name, ((*b)->d_name + 1));
        else
                return strcasecmp((*a)->d_name, (*b)->d_name);
}

//To sort the files according to reverse alphabetical ordder
int reversesort(const struct dirent **a, const struct dirent **b) {
        if((*b)->d_name[0] == '.')
                return strcasecmp(((*b)->d_name + 1) , (*a)->d_name);
        else if((*a)->d_name[0] == '.')
                return strcasecmp((*b)->d_name, ((*a)->d_name + 1));
        else
                return strcasecmp((*b)->d_name, (*a)->d_name);

}

//To get the modified time for particular file
long int get_modified_time(char* name) {
	struct stat sb;
	stat(name, &sb);
	return sb.st_mtim.tv_sec;
}

//Utility function for quicksort used in time_Sort function
int time_partition(struct dirent** a, int start, int end, char* name) {
	char* path = (char*) malloc(1024);
	strcpy(path, name);
        long int pivot = get_modified_time(strcat(strcat(path, "/"), a[end]->d_name));
	strcpy(path, name);
        int pIndex = start;
	struct dirent* temp;
        int i;
        for(i = start; i < end ; i++) {
                if(get_modified_time(strcat(strcat(path, "/"), a[i]->d_name)) <= pivot) {
                        temp = a[pIndex];
                        a[pIndex] = a[i];
                        a[i] = temp;
                        pIndex++;
                }
		strcpy(path, name);
        }
        temp = a[pIndex];
       	a[pIndex] = a[end];
        a[end] = temp;
	free(path);
        return pIndex;
}

//Utility function used in time_Sort function for reverse
int reverse_time_partition(struct dirent** a, int start, int end, char* name) {
        char* path = (char*) malloc(1024);
        strcpy(path, name);
        long int pivot = get_modified_time(strcat(strcat(path, "/"), a[end]->d_name));
        strcpy(path, name);
        int pIndex = start;
        struct dirent* temp;
        int i;
        for(i = start; i < end ; i++) {
                if(get_modified_time(strcat(strcat(path, "/"), a[i]->d_name)) > pivot) {
                        temp = a[pIndex];
                        a[pIndex] = a[i];
                        a[i] = temp;
                        pIndex++;
                }
                strcpy(path, name);
        }
        temp = a[pIndex];
        a[pIndex] = a[end];
        a[end] = temp;
        free(path);
        return pIndex;
}

//To sort the files according to last time modification of file
//Reverse is used to check if files are to be sorted in reverse order or not
void time_Sort(struct dirent** a, int start, int end, char* name, int reverse) {
	//printf("%s\n", name);
	int pIndex;
        if(start >= end)
                return;
	if(reverse) {
		pIndex = reverse_time_partition(a, start, end, name);
	}else {
		pIndex = time_partition(a, start, end, name);
	}
        time_Sort(a, start, pIndex - 1, name, reverse);
        time_Sort(a, pIndex + 1, end, name, reverse);
}

