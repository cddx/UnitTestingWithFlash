#include <stdint.h>
#include <string.h>
#include "unity.h"
#include "config.h"
#include "mock_flash.h"

#define FLASH_SIZE 4096
uint8_t simulated_flash[FLASH_SIZE];

static void mock_read(uint8_t *dest_buffer, uint8_t *source_address, size_t count, int num_calls)
{

    if (source_address >= (uint8_t *)FLASH_SIZE)
    {
        TEST_FAIL_MESSAGE("invalid flash memory address");
    }

    memcpy(dest_buffer, &simulated_flash[(int)source_address], count);
}

static void mock_write(uint8_t *source_data, uint8_t *target_address, size_t count, int num_calls)
{
    if (target_address >= (uint8_t *)FLASH_SIZE)
    {
        TEST_FAIL_MESSAGE("invalid flash memory address");
    }
    memcpy(&simulated_flash[(int)target_address], source_data, count);
}

static void config_load(config_t *cfg)
{
    flash_read((uint8_t *)cfg, (FLASH_SIZE - 1), 1); //! configuration bits location
}

void setUp(void)
{
    flash_read_StubWithCallback(mock_read);
    flash_write_StubWithCallback(mock_write);
}

void tearDown(void)
{
}

void test_write_read(void)
{
#define TEST_FLASH_SIZE 1000
    TEST_ASSERT_LESS_OR_EQUAL_MESSAGE(FLASH_SIZE, TEST_FLASH_SIZE, "test_flash_buffer should less FLASH_SIZE");
   
    uint8_t write_data[TEST_FLASH_SIZE];
    for (int i = 0; i < TEST_FLASH_SIZE; i++)
    {
        write_data[i] = i;
    }
    uint8_t *flash_address = (uint8_t *)0;
    flash_write(write_data, flash_address, TEST_FLASH_SIZE);

    uint8_t read_data[TEST_FLASH_SIZE];
    flash_read(&read_data, flash_address, TEST_FLASH_SIZE);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(write_data, read_data, TEST_FLASH_SIZE);
}
void test_when_flash_is_erased_then_the_config_load_count_is_reset(void)
{
    // Erase the flash.
    memset(simulated_flash, 0xff, FLASH_SIZE);
    simulated_flash[FLASH_SIZE - 1] = 0x01; //! configuration bits location

    // Load the config.
    config_t config = {0};

    config_load(&config);

    // Verify the load_count is reset to 1.
    TEST_ASSERT_EQUAL_HEX8(0x01, config.load_count);
}