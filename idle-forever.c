#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static volatile sig_atomic_t quit = 0;

static void on_term(int signo) {
  (void)signo;
  quit = 1;
}

int main(void) {
  struct sigaction sa = {0};
  sa.sa_handler = on_term;
  sigemptyset(&sa.sa_mask);

  sigaction(SIGTERM, &sa, NULL);
  sigaction(SIGINT,  &sa, NULL);

  while (!quit) pause();
  _exit(0);
}
