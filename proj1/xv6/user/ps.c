#include "types.h"
#include "stat.h"
#include "user.h"
#include "ProcessInfo.h"
#include "param.h"

int main(int argc, char **argv)
{
  int stdout = 1; 
  struct ProcessInfo processInfoTable[NPROC];
  char* states[6];
    states[0] = "UNUSED";
    states[1] = "EMBRYO";
    states[2] = "SLEEPING";
    states[3] = "RUNNABLE";
    states[4] = "RUNNING";
    states[5] = "ZOMBIE";
   
  if (argc > 1){
    printf(stdout, "ps should have no input");
    exit();
  }
  
  int procNum = getprocs(processInfoTable);
  //printf(stdout, "%d\n", procNum);
  int i;
  for (i = 0; i < procNum; i++){
    int pid = processInfoTable[i].pid;
    int ppid = processInfoTable[i].ppid;
    char* state = states[processInfoTable[i].state];
    unsigned int sz = processInfoTable[i].sz;
    printf(stdout, "%d  %d  %s  %d  %s\n", pid, ppid, state, sz, processInfoTable[i].name);   
  }
  exit();
}

