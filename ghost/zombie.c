// A C program to demonstrate Zombie Process. 
// Child becomes Zombie as parent is sleeping 
// when child process exits.
/**
* @file zombie.c
* @brief A C program to demonstrate Zombie and Orphan Process.
*
* @author Pulkit Jeph
*
* @date 8/1/2019
*/ 
#include <stdlib.h> 
#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
    /**
* To demonstrate zombie process.
* @author Pulkit
* @param child_pid  Process ID of child process
* @date 8/1/2019
*/
	// Fork returns process id 
	// in parent process
	pid_t child_pid = fork(); 

	// Parent process 
	if (child_pid > 0) 
		sleep(5); 

	// Child process 
	else		
		exit(0); 
/**
* To demonstrate Orphan process.
* @author Pulkit
* @param pid  Process ID of process
* @date 8/1/2019
*/
//To demonstrate Orphan process
    int pid = fork(); 
  
    if (pid > 0) 
        printf("In parent process.\n"); 
  
    // Note that pid is 0 in child process 
    // and negative if fork() fails 
    else if (pid == 0) 
    { 
        sleep(3); 
        printf("In child process."); 
    } 
  
    return 0;
} 
