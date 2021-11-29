#include <SoftwareSerial.h>
#include "1event_loop.c"

/* ------------------------------------------------------------------
   SDK users to do:
   Setup I/O driver.
   ---------------------------------------------------------------- */
SoftwareSerial serial_fd(9, 10); //RX, TX

/* ------------------------------------------------------------------
   SDK users to do:
   Implement read callback function.
   ---------------------------------------------------------------- */
char read_callback() {
  char read = EOF;
  if (serial_fd.available()) {
    read = serial_fd.read();
  }
  return read;
}

/* ------------------------------------------------------------------
   SDK users to do:
   Implement write callback function.
   ---------------------------------------------------------------- */
void write_callback(char data) {
  if (data != EOF)
    serial_fd.write(data);
}

/* ------------------------------------------------------------------
   SDK users to do:
   Implement debug message callback function.
   ---------------------------------------------------------------- */
void debug_msg_callback(char *msg, size_t size) {
  for (int i = 0; i < size && msg[i] != EOF; i++)
    Serial.write(msg[i]);
}

/* ------------------------------------------------------------------
   SDK users to do:
   Declare 1-event loop SDK required attributes
   ---------------------------------------------------------------- */
uint32_t status = 0x0;

/* ------------------------------------------------------------------
   SDK user to do:
   Implement your non OS app. 
   ---------------------------------------------------------------- */
void setup()
{
  //Setup debug console
  Serial.begin(4800);
  while (!Serial);
  Serial.println("Debug console OK");

  //Setup I/O driver
  serial_fd.begin(4800);
  while (!serial_fd);
  Serial.println("I/O serial driver OK");

  //Initial variables of 1-event loop SDK
  lEvent_loop_abort(&status);
}

void loop()
{
  //Do something on your app
  //...
  //...
  //Call 1-event loop
  lEvent_loop(&status, read_callback,
                       write_callback,   
                       debug_msg_callback
                       );
}
