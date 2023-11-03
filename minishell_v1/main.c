#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int lsh_execute(char **args) 
{
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0) 
  {
    // Child process
    if (execve(args[0], args, NULL) == -1) 
    {
      perror("lsh");
      exit(EXIT_FAILURE);
    }
  } 
  else if (pid < 0) 
  {
    // Error forking
    perror("lsh");
  } 
  else 
  {
    // Parent process
    int child_status;
    while (1) 
    {
      pid_t wpid = wait(&child_status); // Wait for any child to change status

      if (wpid == -1) 
      {
        perror("lsh");
        exit(EXIT_FAILURE);
      }

      if (WIFEXITED(child_status) || WIFSIGNALED(child_status)) 
      {
        break; // Child process has terminated or been signaled
      }
    }
  }
  return 1;
}

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

// Include the necessary headers for your custom split function
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char **ft_split(const char *s, char c); // Declare the custom split function

static	char	**ft_mem_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static	int	ft_count_word(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
		i++;
		else
		{
			cnt++;
			while (s[i] && s[i] != c)
			i++;
		}
	}
	return (cnt);
}

static	char	*ft_word_make(char *word, char const *s, int k, int word_len)
{
	int	i;

	i = 0;
	while (word_len > 0)
	{
		word[i] = s[k - word_len];
		i++;
		word_len--;
	}
	word [i] = '\0';
	return (word);
}

static	char	**ft_split2(char **res, char const *s, char c, int num_word)
{
	int	i;
	int	k;
	int	word_len;

	i = 0;
	k = 0;
	word_len = 0;
	while (s[k] && i < num_word)
	{
		while (s[k] && s[k] == c)
			k++;
		while (s[k] && s[k] != c)
		{
			k++;
			word_len++;
		}
		res[i] = (char *) malloc(sizeof(char) * (word_len + 1));
		if (!(res[i]))
			return (NULL);
		ft_word_make(res[i], s, k, word_len);
		word_len = 0;
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	int		num_word;
	char	**res;

	if (s == 0)
		return (NULL);
	num_word = ft_count_word(s, c);
	res = (char **) malloc(sizeof(char *) * (num_word + 1));
	if (!(res))
		return (NULL);
	if (!ft_split2(res, s, c, num_word))
	{
		ft_mem_free(res);
		return (NULL);
	}
	return (res);
}

char **lsh_split_line(char *line) {
  // Use your custom ft_split function with space ' ' as the delimiter
  char **tokens = ft_split(line, ' ');

  if (!tokens) 
  {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  return tokens;
}

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

char *lsh_read_line(void) 
{
  char *line = readline(""); // Use readline to get input

  if (line == NULL) 
  {
    exit(EXIT_SUCCESS); // We received an EOF or an error
  }

  // Add the input to history for command recall
  //add_history(line);

  return line;
}

void lsh_loop(void) 
{
  char *line;
  char **args;
  int status;

  while (1) 
  {
    printf("> ");
    line = lsh_read_line();
    args = lsh_split_line(line);
    status = lsh_execute(args);

    free(line);
    free(args);

    if (status == 0) 
    {
      break; // Exit the loop when status is 0
    }
  }
}

int main(int argc, char **argv)
{
    lsh_loop();
    return EXIT_SUCCESS;
}