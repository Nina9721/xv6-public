#include "types.h"
#include "stat.h"
#include "user.h"

//B10415024

int a = 1;

void
test1()
{
//1
  printf(1, "Number of free pages : %d\n", getNumFreePages());
  printf(1, "-Fork-\n");
  int pid = fork();
//1
  if(pid == 0)//code exec by child
  {
//3
    printf(1, "Child:  'a' = %d\n", a);
    printf(1, "Number of free pages : %d\n", getNumFreePages());
    printf(1, "-Change-\n");
    a = 2;
    printf(1, "Child:  'a' = %d\n", a);
    printf(1, "Number of free pages : %d\n", getNumFreePages());
    exit();
//3
  }
//2
  printf(1, "Parent: 'a' = %d\n", a);
  wait();
//2
//4
  printf(1, "-Reaping child-\n");
  printf(1, "Patent: 'a' = %d\n", a);
  printf(1, "Number of free pages : %d\n", getNumFreePages());
  return;
//4
}

void
test2()
{
//1
  printf(1, "Number of free pages : %d\n", getNumFreePages());
  printf(1, "-First time Fork-\n");
  int pid = fork();
//1
  if(pid == 0)
//2.5
    exit();
//2.5
  else
  { 
//2
    printf(1, "Number of free pages : %d\n", getNumFreePages());
    printf(1, "-Second time Fork-\n");
    pid = fork();
//2
    if(pid == 0)
    {
//5
      printf(1, "Child:  'a' = %d\n", a);
      printf(1, "Number of free pages : %d\n", getNumFreePages());
      printf(1, "-Change-\n");
      a = 5;
      printf(1, "Child:  'a' = %d\n", a);
      printf(1, "Number of free pages : %d\n", getNumFreePages());
      exit();
//5
    }
//3
    printf(1, "Number of free pages : %d\n", getNumFreePages());
    wait();
//
    printf(1, "-Reaping child-\n");
//3
  }
//4
  printf(1, "Number of free pages : %d\n", getNumFreePages());
  wait();
//4
//6
  printf(1, "-Reaping child-\n");
  printf(1, "Number of free pages : %d\n", getNumFreePages());
//6
  return;
}

void
test3()
{
//1
  a = 3;
  printf(1, "Number of free pages : %d\n", getNumFreePages());
  printf(1, "-First time Fork-\n");
  int pid = fork();
//1

  if(pid == 0)
  { 
//3
    printf(1, "Child 1 : 'a' = %d\n", a);
    printf(1, "Number of free pages : %d\n", getNumFreePages());
    printf(1, "-Change-\n");
    a = 4;
    printf(1, "Child 1 : 'a' = %d\n", a);
    printf(1, "Number of free pages : %d\n", getNumFreePages());
//3
  }
  else 
  {
//2
    printf(1, "Number of free pages : %d\n", getNumFreePages());
    wait();
//2
//4
    printf(1, "-Reaping child-\n");
    printf(1, "Number of free pages : %d\n", getNumFreePages());
    printf(1, "-Second time Fork-\n");
    pid = fork();
//4
    if(pid == 0)
    { 
//6
      printf(1, "Child 2 : 'a' = %d\n", a);
      printf(1, "Number of free pages : %d\n", getNumFreePages());
      printf(1, "-Change-\n");
      a = 4;
      printf(1, "Child 2 : 'a' = %d\n", a);
      printf(1, "Number of free pages : %d\n", getNumFreePages());
//6
    }
    else 
    {
//5
       printf(1, "Number of free pages : %d\n", getNumFreePages());
       wait();
//5
//7
       printf(1, "-Reaping child-\n");
       printf(1, "Number of free pages : %d\n", getNumFreePages());
//7
    }
  }
  return;
}
int
main(void)
{
  printf(1, "Parent and Child share the global variable 'a'\n");
  printf(1,"---run test1---\n");
  test1();
  printf(1,"---------------\n");
  printf(1,"---run test2---\n");
  test2();  
  printf(1,"---------------\n");
  printf(1,"---run test3---\n");
  test3();  
  printf(1,"---------------\n");
  exit();
}
