#include "1event_loop.h"

int throw_not_yet_implemented(void (*debug_msg_callback)(char *msg, size_t size)) {
  strncpy(levent_loop_debug_buf,
          "Not yet implemented exception\0",
          lEVENT_LOOP_DEBUG_SIZE);
  if (NULL != debug_msg_callback)
    debug_msg_callback(levent_loop_debug_buf,
                       strlen(levent_loop_debug_buf));
  return lEVENT_LOOP_RW_FULLED;
}

void lEvent_loop(uint32_t *status,
                 char (*read_callback)(),
                 void (*write_callback)(char data),
                 void (*debug_msg_callback)(char *msg, size_t size)) {
  throw_not_yet_implemented(debug_msg_callback);
}

void lEvent_loop_abort(uint32_t *status) {
  *status = 0x0;
}


int levent_loop_read_line() {
  return throw_not_yet_implemented(NULL);
}

int levent_loop_write_line(char data) {
  return throw_not_yet_implemented(NULL);
}
