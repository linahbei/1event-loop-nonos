# **1**-event loop -- Non OS

GitHub: [1event-loop-nonos](https://github.com/linahbei/1event-loop-nonos)

Event loop SDK under non OS platforms to support polling and interrupted I/O drivers.

---

# API Reference

## Event loop status and control flag definitions

Uses 4 bytes unsigned integer to store status of event loop by control flags. i.e.,

```C
uint32_t status;
```

### Field definition

|Field|Feature|Description|
|-----|-------|-----------|
|Byte 3|Status block|Running status and common exit (result) code of event loop|
|Byte 2|*Resvered*|User defined special exit code of function|
|Byte 1|Control block|User defined function code to run|
|Byte 0|*Resvered*|

### Status block

* Bit 4~7: Running status

|Running type|Constant|Description|
|------------|--------|-----------|
|Idle|``lEVENT_LOOP_STATUS_IDLE``|SDK initialized or aborted.|
|Todo|``lEVENT_LOOP_STATUS_TODO``|Function assigned and waiting for execution.|
|Busy|``lEVENT_LOOP_STATUS_BUSY``|Function already running.|
|Done|``lEVENT_LOOP_STATUS_DONE``|Function already done.|

* Bit 0~3: Exit code

|Exit code type|Constant|Description|
|------------|--------|-----------|
|Idle|``lEVENT_LOOP_EXIT_IDLE``|Function initialized, running, or aborted.|
|Succeed|``lEVENT_LOOP_EXIT_SUCCEED``|Function done and returns succeed.|
|Failed|``lEVENT_LOOP_EXIT_FAILED``|Function done and returns failed.|

### Control block

* Bit 0 ~ 7: User defined function code (ID)

|SDK defined|Constant|Description|
|------------|--------|-----------|
|None|``lEVENT_LOOP_FUNC_NONE``|Nothing to run.|
|Clear control block|``_lEVENT_LOOP_FUNC_NONE``|A bitwise tool to clear control block to none function. ex. ``status &= ~_lEVENT_LOOP_FUNC_NONE``|

### Other SDK defined constants

|SDK defined|Constant|Description|
|------------|--------|-----------|
|Size of I/O read buffer|``lEVENT_LOOP_READ_SIZE``||
|Size of I/O write buffer|``lEVENT_LOOP_WRITE_SIZE``||


## Callback functions

SDK users SHOULD implement callback functions to bridge polling, interrupted, etc. I/O driver under non OS platforms and event loop.

### I/O read callback -- *required*

Prototype as the following.

```C
char (*read_callvack)();
```

### I/O write callback -- *required*

Prototype as the following.

```C
void (*write_callvack)(char data);
```

### Debug messages callback -- *optional*

Prototype as the following.

```C
void *(debug_msg_callback(char *msg, szie_t size);
```

## API -- Event main loop

### Prototype

```c
void lEvent_loop(uint32_t *status,
                  char (*read_callback)(),
                  void (*write_callback)(char data),
                  void (*debug_msg_callback)(char *msg, size_t size));
```


## API -- Abort running function

### Prototype

```C
void lEvent_loop_abort(uint32_t *status);
```

