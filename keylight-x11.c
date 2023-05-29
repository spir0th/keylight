#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>

#define VER "1.0.4-x11"

static void help();
static void version();

static unsigned long get_led(Display *d);
static void set_led(Display *d, int led, int mode);

static void error(const char *format, ...);
static void verbose(const char *format, ...);

static char *p_name; // Program name
static char *d_name; // Display name of the running X11 session
static int led = -1; // LED to set with (3 = Scroll Lock, -1 = All)
static int toggle = 1; // Whether toggling between on and off states for each run (0 = no, 1 = yes)
static int vbose = 0; // Whether verbose logging is enabled (0 = no, 1 = yes)

int main(int argc, char *argv[]) {
  // Handle command-line arguments
  p_name = argv[0];
  
  for (int i = 1; i < argc; i++) {
    const char *arg = argv[i];
    
    if (strcmp(arg, "--display") == 0 || strcmp(arg, "-d") == 0)  {
      if (++i >= argc) {
        error("%s: No display name specified.\n", p_name);
      }
      
      p_name = argv[i];
    } else if (strcmp(arg, "--led") == 0 || strcmp(arg, "-l") == 0) {
      if (++i >= argc) {
        error("%s: No LED specified.\n", p_name);
      }
      
      led = atoi(argv[i]);
    } else if (strcmp(arg, "--no-toggle") == 0) {
      toggle = 0;
      
      if (vbose != 1) {
        // Verbose logging must be enabled in order to see what's going on
        vbose = 1;
      }
    } else if (strcmp(arg, "--verbose") == 0) {
      vbose = 1;
    } else if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
      help();
    } else if (strcmp(arg, "-v") == 0 || strcmp(arg, "--version") == 0) {
      version();
    }
  }

  // Open X11 display
  Display *d = NULL;
  d = XOpenDisplay(d_name);
  
  if (d == NULL) {
    error("%s: Cannot open display \"%s\"\n", p_name, d_name);
  } else {
    verbose("%s: Display opened: \"%s\"\n", p_name, d_name);
  }
  
  // Search for environment variables KEYLIGHT_LED_MASK_ON and KEYLIGHT_LED_MASK_OFF
  // LED masks are important because they can be used to get the indicator's current state
  int led_mask_on = 0;
  int led_mask_off = 2;
  char *led_mask_env_on = getenv("KEYLIGHT_LED_MASK_ON");
  char *led_mask_env_off = getenv("KEYLIGHT_LED_MASK_OFF");
  
  if (led_mask_env_on != NULL) {
    led_mask_on = atoi(led_mask_env_on);
  }
  if (led_mask_env_off != NULL) {
    led_mask_off = atoi(led_mask_env_off);
  }
  
  verbose("%s: LED mask value for ON state is %d\n", p_name, led_mask_on);
  verbose("%s: LED mask value for OFF state is %d\n", p_name, led_mask_off); 
  
  // Get the LED indicator's current mask
  unsigned long led_mask = get_led(d);
  verbose("%s: LED indicator index: %d\n", p_name, led);
  verbose("%s: LED indicator mask: %lu\n", p_name, led_mask);
    
  // Toggle LED indicator by turning on or off
  // Note that if --no-toggle is passed, this code won't happen.
  if (toggle == 1) {
    printf("%s: Changing LED indicator state to %s.\n", p_name, (led_mask == led_mask_off) ? "ON" : "OFF");
    set_led(d, led, (led_mask == led_mask_off) ? 1 : 0);
  }
  
  XCloseDisplay(d);
  return 0;
}

static void help() {
  printf("Usage: %s [OPTIONS] ...\n\n", p_name);
  printf("Options:\n");
  printf("  -d / --display     Specify the display name of the X11 session.\n");
  printf("  -l / --led         Specify the LED indicator (if not set, LED is set to -1 for all)\n");
  printf("  --no-toggle        Do not toggle the LED state (also enables verbose logging)\n");
  printf("  --verbose          Enables verbose logging\n");
  printf("  --help             Prints this message\n");
  printf("  --version          Prints the program version\n");
  exit(0);
}

static void version() {
  printf("%s\n", VER);
  exit(0);
}

static unsigned long get_led(Display *d)
{
  XKeyboardState xlib_key_state;
  XGetKeyboardControl(d, &xlib_key_state);
  return xlib_key_state.led_mask; // The LED mask is used to retrieve whether it's turned on or not.
}

static void set_led(Display *d, int led, int mode)
{
  XKeyboardControl values = { .led_mode = mode };
  
  if (led != -1) {
    values.led = led;
    XChangeKeyboardControl(d, KBLed | KBLedMode, &values);
  } else {
    XChangeKeyboardControl(d, KBLedMode, &values);
  }
}

static void error(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  vfprintf(stderr, format, args);
  va_end(args);
  exit(1);
}

static void verbose(const char *format, ...)
{
  if (vbose == 0) {
    // The verbose command-line option is not passed.
    return;
  }
  
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
}
