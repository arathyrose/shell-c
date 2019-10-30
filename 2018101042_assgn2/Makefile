shell: \
			main.o \
			signal_handler.o \
			print.o \
			display_shell_prompt.o \
			display_killed_children.o \
			get_status.o \
			exec_cd.o \
			display_shell_prompt.o \
			read_command.o \
			execute_builtin_commands.o \
			execute_builtin_no_output.o \
			check_if_bg.o \
			exec_exit.o \
			exec_pwd.o \
			string_splitter.o \
			interpret_command.o \
			exec_echo.o \
			exec_ls.o \
			exec_cd.o \
			exec_setenv.o \
			exec_unsetenv.o \
			exec_pinfo.o \
			exec_overkill.o \
			exec_jobs.o \
			exec_fg.o \
			exec_bg.o \
			exec_kjob.o \
			exec_cronjob.o \
			display_line_ls.o \
			display_permissions_ls.o \
			exec_nightswatch.o \
			exec_history.o \
			save_to_history.o \
			exec_clearhistory.o \
			exec_help.o \
			isvalid_redirection.o \
			set_ip_op_redirection.o \
			pipe_handler.o
	$(CC) -g -o shell $^  -L/usr/local/lib -I/usr/local/include -lreadline -Wall 

clean:
	@rm -f *.o shell history.txt

main.o: shell.h main.c
	$(CC) -g -c main.c  -L/usr/local/lib -I/usr/local/include -lreadline -Wall 

signal_handler.o: shell.h signal_handler.c
	$(CC) -g -c signal_handler.c 

print.o: shell.h print.c
	$(CC) -g -c print.c

display_killed_children.o: shell.h display_killed_children.c
	$(CC) -g -c display_killed_children.c

display_shell_prompt.o: shell.h display_shell_prompt.c
	$(CC) -g -c display_shell_prompt.c

check_if_bg.o: shell.h check_if_bg.c
	$(CC) -g -c check_if_bg.c

exec_cd.o: shell.h exec_cd.c
	$(CC) -g -c exec_cd.c

exec_echo.o: shell.h exec_echo.c
	$(CC) -g -c exec_echo.c

exec_ls.o: shell.h exec_ls.c
	$(CC) -g -c exec_ls.c

exec_exit.o: shell.h exec_exit.c
	$(CC) -g -c exec_exit.c

exec_pwd.o: shell.h exec_pwd.c
	$(CC) -g -c exec_pwd.c

exec_pinfo.o: shell.h exec_pinfo.c
	$(CC) -g -c exec_pinfo.c

exec_setenv.o: shell.h exec_setenv.c
	$(CC) -g -c exec_setenv.c

exec_unsetenv.o: shell.h exec_unsetenv.c
	$(CC) -g -c exec_unsetenv.c

exec_overkill.o: shell.h exec_overkill.c
	$(CC) -g -c exec_overkill.c

exec_jobs.o: shell.h exec_jobs.c
	$(CC) -g -c exec_jobs.c

exec_fg.o: shell.h exec_fg.c
	$(CC) -g -c exec_fg.c

exec_bg.o: shell.h exec_bg.c
	$(CC) -g -c exec_bg.c

exec_kjob.o: shell.h exec_kjob.c
	$(CC) -g -c exec_kjob.c

exec_help.o: shell.h exec_help.c
	$(CC) -g -c exec_help.c

exec_cronjob.o: shell.h exec_cronjob.c
	$(CC) -g -c exec_cronjob.c

string_splitter.o: shell.h string_splitter.c
	$(CC) -g -c string_splitter.c

read_command.o: shell.h read_command.c
	$(CC) -g -c read_command.c

interpret_command.o: shell.h interpret_command.c
	$(CC) -g -c interpret_command.c

isvalid_redirection.o: shell.h isvalid_redirection.c
	$(CC) -g -c isvalid_redirection.c

set_ip_op_redirection.o: shell.h set_ip_op_redirection.c
	$(CC) -g -c set_ip_op_redirection.c

pipe_handler.o: shell.h pipe_handler.c
	$(CC) -g -c pipe_handler.c

execute_builtin_commands.o: shell.h execute_builtin_commands.c
	$(CC) -g -c execute_builtin_commands.c

execute_builtin_no_output.o: shell.h execute_builtin_no_output.c
	$(CC) -g -c execute_builtin_no_output.c

display_line_ls.o: shell.h display_line_ls.c
	$(CC) -g -c display_line_ls.c

display_permissions_ls.o: shell.h display_permissions_ls.c
	$(CC) -g -c display_permissions_ls.c

exec_nightswatch.o: shell.h exec_nightswatch.c
	$(CC) -g -c exec_nightswatch.c

exec_history.o: shell.h exec_history.c
	$(CC) -g -c exec_history.c

exec_clearhistory.o: shell.h exec_clearhistory.c
	$(CC) -g -c exec_clearhistory.c

save_to_history.o: shell.h save_to_history.c
	$(CC) -g -c save_to_history.c

execute_builtin.o: shell.h execute_builtin.c
	$(CC) -g -c execute_builtin.c

get_status.o: shell.h get_status.c
	$(CC) -g -c get_status.c