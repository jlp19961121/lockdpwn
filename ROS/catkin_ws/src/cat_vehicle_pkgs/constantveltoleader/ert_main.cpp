#include <stdio.h>
#include <stdlib.h>
#include "constantVelToLeader.h"
#include "constantVelToLeader_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "linuxinitialize.h"

/* Function prototype declaration*/
void exitTask(int sig);
void terminateTask(void *arg);
void baseRateTask(void *arg);
void subrateTask(void *arg);
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
unsigned long threadJoinStatus[8];
int terminatingmodel = 0;
void baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(constantVelToLeader_M) == (NULL));
  while (runModel) {
    sem_wait(&baserateTaskSem);
    constantVelToLeader_step();

    /* Get model outputs here */
    runModel = (rtmGetErrorStatus(constantVelToLeader_M) == (NULL));
  }

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
}

void exitTask(int sig)
{
  rtmSetErrorStatus(constantVelToLeader_M, "stopping the model");
}

void terminateTask(void *arg)
{
  terminatingmodel = 1;
  printf("**terminating the model**\n");
  fflush(stdout);

  {
    int ret;
    runModel = 0;
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  constantVelToLeader_terminate();
  sem_post(&stopSem);
}

int main(int argc, char **argv)
{
  void slros_node_init(int argc, char** argv);
  slros_node_init(argc, argv);
  printf("**starting the model**\n");
  fflush(stdout);
  rtmSetErrorStatus(constantVelToLeader_M, 0);

  /* Initialize model */
  constantVelToLeader_initialize();

  /* Call RTOS Initialization funcation */
  myRTOSInit(0.2, 0);

  /* Wait for stop semaphore */
  sem_wait(&stopSem);
  return 0;
}