
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include <stddef.h>
#include "lpit_driver.h"
#include "lpit_hw_access.h"
#include "interrupt_manager.h"
#include "lpit0.h"

#define TIMEOUT_SECONDS     5

void init_lipt(void);

uint8_t  wait_timeout;
