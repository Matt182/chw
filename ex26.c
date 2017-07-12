#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int find_mutch_in_line(char *mutch, char *line)
{
	int i = 0;
	int j = 0;

	int match_len = strlen(mutch);
	int line_len = strlen(line);

	while (i < line_len) {
		if (mutch[j] == line[i]) {
			j++;
			if (j == match_len) {
				return 1;
			}
		} else {
			j = 0;
		}
		i++;
	}
	return 0;
}

int check_log_file(FILE *f, char *word)
{
	int total_matches = 0;
	char *line = NULL;
	int read = 0;
	size_t len = 0;
	
	while ((read = getline(&line, &len, f)) != -1) {	
		if (find_mutch_in_line(word, line)) {
			printf("%s", line);
			total_matches++;
		}
	}
	return total_matches; 
}

void get_words(int argc, char *argv[], char *words[])
{
	int i = 1;
	int j = 0;

	while (i < argc) {
		if (strcmp(argv[i], "-o") != 0) {
			words[j] = argv[i];
			j++;
		}
		i++;
	}
	return words;
}

int is_orb(int argc, char *argv[])
{
	int i = 1;
	while (i < argc) {
		if (strcmp(argv[i], "-o") == 0) return 1;
		i++;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("ERROR: ex26 [word]");
		return 1;
	}

	char *words[argc - 1];
	get_words(argc, argv, words);
	int is_or = is_orb(argc, argv);
	FILE *f;
	FILE *logf;
	int read = 0;
	char *line;
	size_t len = 0;
	int count_words = is_or ? argc - 2 : argc - 1;
	

	int total_matches = 0;

	f = fopen("/vagrant/chw/ex1/test.txt", "r+");
	if (f == NULL) {
		exit(EXIT_FAILURE);
	}

	int j = 0;
	while (j < count_words) {
		while ((read = getline(&line, &len, f)) != -1) {
		
			line[ strlen(line) - 1 ] = 0;
			logf = fopen(line, "r+");
		
			if (logf == NULL) {
				exit(EXIT_FAILURE);
			}
		
			total_matches += check_log_file(logf, words[j]);
			fclose(logf);
		}
		j++;
		rewind(f);
	}

	printf("total macthes is %d, should be 3\n", total_matches);
	fclose(f);
	return 0;
}
