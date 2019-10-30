/**
 * This function displays the pinfo of the process using the pid given
 */

#include "shell.h"

int debug_exec_pinfo = 0;

void exec_pinfo(char *arg, char **args)
{
    char *path = memalloc_str(MAX_CURRENT_DIR);
    char *buffer = memalloc_str(MAX_BUFFER_LENGTH);
    char *ex_path = memalloc_str(MAX_CURRENT_DIR);
    char *spid = memalloc_str(MAX_SPID_LENGTH);
    char *line = memalloc_str(MAX_LINE_LENGTH);
    if (is_emptystr(args[1]))                             // if no arguments consider the current shell
        sprintf(spid, "%d", isbg ? getppid() : getpid()); //get pid of the parent in case this is a child or that process itself
    else
        strcpy(spid, args[1]);
    if (debug_exec_pinfo)
        printn_debug(spid);
    sprintf(path, "/proc/%s/status", spid);
    FILE *file = fopen(path, "r"); //open the file given by the path and then, just print those lines of information
    if (file == NULL)
    {
        print_err("PID does not exist");
        return;
    }
    sprintf(buffer, "pid -- %s\n", spid);
    print(buffer);
    size_t sz = 0;
    while (getline(&line, &sz, file) != -1)
    {
        if (strncmp("State", line, 5) == 0)
        {
            if (debug_exec_pinfo)
                printn_debug(line);
            print("Process Status -- ");
            int cur = 0;
            for (int i = 7; line[i] != '\0'; i++, cur++)
                buffer[cur] = line[i];
            buffer[cur] = '\0';
            print(buffer);
        }
        else if (strncmp("VmSize", line, 6) == 0)
        {
            if (debug_exec_pinfo)
                printn_debug(line);
            print("memory -- ");
            int cur = 0;
            for (int i = 8; line[i] != '\0'; i++, cur++)
                buffer[cur] = line[i];
            buffer[cur] = '\0';
            print(buffer);
        }
    }
    fclose(file);

    //find executable path
    sprintf(path, "/proc/%s/exe", spid);
    int s = readlink(path, line, MAX_LINE_LENGTH);
    print("Executable path -- ");
    if (s < 0)
    {
        perror("Error");
        return;
    }
    line[s] = '\0';
    print_n(line);
    free(line);
}
