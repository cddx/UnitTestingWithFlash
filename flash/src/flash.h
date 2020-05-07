#ifndef FLASH_H
#define FLASH_H
#include <stdint.h>
void flash_read(uint8_t *dest_buffer, uint8_t *source_address, size_t count);
void flash_write(uint8_t *source_data, uint8_t *target_address, size_t count);

#endif // FLASH_H
