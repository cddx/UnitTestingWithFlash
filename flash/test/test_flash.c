#include <stdint.h>
#include <string.h>
#include "unity.h"
#include "mock_flash.h"

#define FLASH_MAX_SIZE 4096

uint8_t simulated_flash[FLASH_MAX_SIZE];

static void mock_read(uint8_t *dest_buffer, uint8_t *source_address, size_t count, int num_calls)
{

    if (source_address >= (uint8_t *)FLASH_MAX_SIZE)
    {
        TEST_FAIL_MESSAGE("invalid flash memory address");
    }

    memcpy(dest_buffer, &simulated_flash[(int)source_address], count);
}

static void mock_write(uint8_t *source_data, uint8_t *target_address, size_t count, int num_calls)
{
    if (target_address >= (uint8_t *)FLASH_MAX_SIZE)
    {
        TEST_FAIL_MESSAGE("invalid flash memory address");
    }
    memcpy(&simulated_flash[(int)target_address], source_data, count);
}


void setUp(void)
{
    flash_write_Stub(mock_write);
    flash_read_Stub(mock_read);
}

void tearDown(void)
{
}

void test_write_read(void)
{
#define TEST_FLASH_SIZE 4096
    TEST_ASSERT_LESS_OR_EQUAL_MESSAGE(FLASH_MAX_SIZE, TEST_FLASH_SIZE, "TEST_FLASH_SIZE should less FLASH_MAX_SIZE");

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
