/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_FLASH_H
#define _MOCK_FLASH_H

#include "unity.h"
#include "flash.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_flash_Init(void);
void mock_flash_Destroy(void);
void mock_flash_Verify(void);




#define flash_read_Ignore() flash_read_CMockIgnore()
void flash_read_CMockIgnore(void);
#define flash_read_StopIgnore() flash_read_CMockStopIgnore()
void flash_read_CMockStopIgnore(void);
#define flash_read_Expect(dest_buffer, source_address, count) flash_read_CMockExpect(__LINE__, dest_buffer, source_address, count)
void flash_read_CMockExpect(UNITY_LINE_TYPE cmock_line, uint8_t* dest_buffer, uint8_t* source_address, size_t count);
typedef void (* CMOCK_flash_read_CALLBACK)(uint8_t* dest_buffer, uint8_t* source_address, size_t count, int cmock_num_calls);
void flash_read_AddCallback(CMOCK_flash_read_CALLBACK Callback);
void flash_read_Stub(CMOCK_flash_read_CALLBACK Callback);
#define flash_read_StubWithCallback flash_read_Stub
#define flash_write_Ignore() flash_write_CMockIgnore()
void flash_write_CMockIgnore(void);
#define flash_write_StopIgnore() flash_write_CMockStopIgnore()
void flash_write_CMockStopIgnore(void);
#define flash_write_Expect(source_data, target_address, count) flash_write_CMockExpect(__LINE__, source_data, target_address, count)
void flash_write_CMockExpect(UNITY_LINE_TYPE cmock_line, uint8_t* source_data, uint8_t* target_address, size_t count);
typedef void (* CMOCK_flash_write_CALLBACK)(uint8_t* source_data, uint8_t* target_address, size_t count, int cmock_num_calls);
void flash_write_AddCallback(CMOCK_flash_write_CALLBACK Callback);
void flash_write_Stub(CMOCK_flash_write_CALLBACK Callback);
#define flash_write_StubWithCallback flash_write_Stub

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
