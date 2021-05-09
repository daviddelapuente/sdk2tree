#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <ftw.h>

static unsigned int total = 0;

int sum(const char *fpath, const struct stat *sb, int typeflag) {
    total += sb->st_size;
    return 0;
}

int main() {
    
    int i=5000000;
    while(i<=550000000){
 	total=0;
	char dirpath[1024];
    	strcpy(dirpath,"./results/sizefiles/");
	char intbuf[100];
	sprintf(intbuf, "%i", i);
	strcat(dirpath,intbuf);
    	
	if (ftw(dirpath, &sum, 1)) {
        	perror("ftw");
        	return 2;
    	}
    	printf("%u,\n", total);	
	i+=5000000;
    	}

    return 0;
}
