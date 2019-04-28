/*!
 * \file      sx1272-board.h
 *
 * \brief     Target board SX1272 driver implementation
 *
 * \copyright Revised BSD License, see section \ref LICENSE.
 *
 * \code
 *                ______                              _
 *               / _____)             _              | |
 *              ( (____  _____ ____ _| |_ _____  ____| |__
 *               \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 *               _____) ) ____| | | || |_| ____( (___| | | |
 *              (______/|_____)_|_|_| \__)_____)\____)_| |_|
 *              (C)2013-2017 Semtech
 *
 * \endcode
 *
 * \author    Miguel Luis ( Semtech )
 *
 * \author    Gregory Cristian ( Semtech )
 */
#ifndef __SX1272_BOARD_H__
#define __SX1272_BOARD_H__

#include <stdint.h>
#include <stdbool.h>
#include "sx1272/sx1272.h"

/*!
 * \brief Radio hardware registers initialization definition
 *
 * \remark Can be automatically generated by the SX1272 GUI (not yet implemented)
 */
#define RADIO_INIT_REGISTERS_VALUE                \
{                                                 \
    { MODEM_FSK , REG_LNA                , 0x23 },\
    { MODEM_FSK , REG_RXCONFIG           , 0x1E },\
    { MODEM_FSK , REG_RSSICONFIG         , 0xD2 },\
    { MODEM_FSK , REG_AFCFEI             , 0x01 },\
    { MODEM_FSK , REG_PREAMBLEDETECT     , 0xAA },\
    { MODEM_FSK , REG_OSC                , 0x07 },\
    { MODEM_FSK , REG_SYNCCONFIG         , 0x12 },\
    { MODEM_FSK , REG_SYNCVALUE1         , 0xC1 },\
    { MODEM_FSK , REG_SYNCVALUE2         , 0x94 },\
    { MODEM_FSK , REG_SYNCVALUE3         , 0xC1 },\
    { MODEM_FSK , REG_PACKETCONFIG1      , 0xD8 },\
    { MODEM_FSK , REG_FIFOTHRESH         , 0x8F },\
    { MODEM_FSK , REG_IMAGECAL           , 0x02 },\
    { MODEM_FSK , REG_DIOMAPPING1        , 0x00 },\
    { MODEM_FSK , REG_DIOMAPPING2        , 0x30 },\
    { MODEM_LORA, REG_LR_DETECTOPTIMIZE  , 0x43 },\
    { MODEM_LORA, REG_LR_PAYLOADMAXLENGTH, 0x40 },\
}                                                 \

/*!
 * \brief Initializes the radio I/Os pins interface
 */
void SX1272IoInit( void );

/*!
 * \brief Initializes DIO IRQ handlers
 *
 * \param [IN] irqHandlers Array containing the IRQ callback functions
 */
void SX1272IoIrqInit( DioIrqHandler **irqHandlers );

/*!
 * \brief De-initializes the radio I/Os pins interface.
 *
 * \remark Useful when going in MCU low power modes
 */
void SX1272IoDeInit( void );

/*!
 * \brief Initializes the TCXO power pin.
 */
void SX1272IoTcxoInit( void );

/*!
 * \brief Initializes the radio debug pins.
 */
void SX1272IoDbgInit( void );

/*!
 * \brief Resets the radio
 */
void SX1272Reset( void );

/*!
 * \brief Sets the radio output power.
 *
 * \param [IN] power Sets the RF output power
 */
void SX1272SetRfTxPower( int8_t power );

/*!
 * \brief Set the RF Switch I/Os pins in low power mode
 *
 * \param [IN] status enable or disable
 */
void SX1272SetAntSwLowPower( bool status );

/*!
 * \brief Initializes the RF Switch I/Os pins interface
 */
void SX1272AntSwInit( void );

/*!
 * \brief De-initializes the RF Switch I/Os pins interface
 *
 * \remark Needed to decrease the power consumption in MCU low power modes
 */
void SX1272AntSwDeInit( void );

/*!
 * \brief Controls the antenna switch if necessary.
 *
 * \remark see errata note
 *
 * \param [IN] opMode Current radio operating mode
 */
void SX1272SetAntSw( uint8_t opMode );

/*!
 * \brief Checks if the given RF frequency is supported by the hardware
 *
 * \param [IN] frequency RF frequency to be checked
 * \retval isSupported [true: supported, false: unsupported]
 */
bool SX1272CheckRfFrequency( uint32_t frequency );

/*!
 * \brief Enables/disables the TCXO if available on board design.
 *
 * \param [IN] state TCXO enabled when true and disabled when false.
 */
void SX1272SetBoardTcxo( uint8_t state );

/*!
 * \brief Gets the Defines the time required for the TCXO to wakeup [ms].
 *
 * \retval time Board TCXO wakeup time in ms.
 */
uint32_t SX1272GetBoardTcxoWakeupTime( void );

/*!
 * \brief Writes new Tx debug pin state
 *
 * \param [IN] state Debug pin state
 */
void SX1272DbgPinTxWrite( uint8_t state );

/*!
 * \brief Writes new Rx debug pin state
 *
 * \param [IN] state Debug pin state
 */
void SX1272DbgPinRxWrite( uint8_t state );

/*!
 * Radio hardware and global parameters
 */
extern SX1272_t SX1272;

#endif // __SX1272_BOARD_H__
