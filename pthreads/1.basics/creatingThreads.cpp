#include <iostream>
#include <pthread.h>
using namespace std;

char str[100] = "Creating Child thread";


void* fun(void *str)
{
  cout << "Child thread: " << (char*)str <<endl;
  return NULL;
}

int main()
{
  pthread_t td;    
  pthread_create(&td, NULL, &fun, (void*)str);
  cout << "Created Main thread here" << endl;
  pthread_join(td, NULL);
  exit(EXIT_SUCCESS);
  return 0;
}
