#ifndef __lEVENT_LOOP_SDK__
#define __lEVENT_LOOP_SDK__
#include <string.h>
#include <stdint.h>


/* ------------------------------------------------------------------
 * Constants of status block definition
 ----------------------------------------------------------------- */ 
// Event loop status (byte 3, bit 4 ~ 7)
#define _lEVENT_LOOP_STATUS_IDLE  0x0fffffffU
#define lEVENT_LOOP_STATUS_IDLE   0x00000000U
#define lEVENT_LOOP_STATUS_TODO   0x10000000U
#define lEVENT_LOOP_STATUS_BUSY   0x20000000U
#define lEVENT_LOOP_STATUS_DONE   0x40000000U

// Common exit codes (byte 3, bit 5~6)
#define _lEVENT_LOOP_EXIT_IDLE      0xf0ffffffU
#define lEVENT_LOOP_EXIT_IDLE       0x00000000U
#define lEVENT_LOOP_EXIT_SUCCEED    0x01000000U
#define lEVENT_LOOP_EXIT_FAILED     0x02000000U

/* ------------------------------------------------------------------
 * Constants of control block definition
 ----------------------------------------------------------------- */
#define _lEVENT_LOOP_FUNC_NONE       0xffff00ffU
#define lEVENT_LOOP_FUNC_NONE        0x00000000U

/* ------------------------------------------------------------------
 * SDK internal functions
 ----------------------------------------------------------------- */
#define lEVENT_LOOP_WRITE_SIZE  80
#define lEVENT_LOOP_READ_SIZE   80
#define lEVENT_LOOP_DEBUG_SIZE   80

#define lEVENT_LOOP_RW_FULLED -1
#define lEVENT_LOOP_RW_NONE   0
#define lEVENT_LOOP_RW_OK     1
#define lEVENT_LOOP_RW_DONE   2

static char levent_loop_read_buf[lEVENT_LOOP_READ_SIZE]; 
static char levent_loop_write_buf[lEVENT_LOOP_WRITE_SIZE];
static char levent_loop_debug_buf[lEVENT_LOOP_DEBUG_SIZE];

static int levent_loop_read_tail = 0;
static int levent_loop_write_tail = 0;


int levent_loop_read_line();
int levent_loop_write_line(char);

/* ------------------------------------------------------------------
 * SDK external functions
 ----------------------------------------------------------------- */
void lEvent_loop(uint32_t *status,
                  char (*read_callback)(),
                  void (*write_callback)(char data),
                  void (*debug_msg_callback)(char *msg, size_t size));
                  
void lEvent_loop_abort(uint32_t *status);
#endif
