#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <time.h>
#include <pthread.h>
#include <stddef.h>
#include <signal.h>
int main(void) {
  // long unsigned int
  size_t size;

  // long
  clock_t ticks;

  // 没有定义
  // comp_t compressed_ticks;

  // unsigned long
  dev_t dev_nums;

  // fd_set t;
  // 结构体
  fpos_t file_position;

  // unsigned int
  gid_t group_id;

  // unsigned long
  ino_t inode_nums;

  // unsigned int
  mode_t file_type;

  // unsigned long
  nlink_t link_counts;

  // long
  off_t filesize_and_offsets;

  // int
  pid_t progess_id;

  // unsigned long
  pthread_t thread_id;

  // long
  ptrdiff_t subtract_ptrs;

  // unsigned long
  rlim_t resource_limits;

  // int
  sig_atomic_t accessed_atomically;

  // struct
  sigset_t signal_set;

  // unsigned long
  size_t size_of_objects;

  // long
  ssize_t signed_size; 

  // long
  time_t time;

  // unsigned int
  uid_t uid;

  // int
  wchar_t wide_char;
}