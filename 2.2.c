#include <stdio.h>           // Include standard input/output library
#include <stdint.h>          // Include standard integer types library
#include "eecs388_lib.h"     // Include custom eecs388 library
#include "metal/i2c.h"       // Include I2C interface library

struct metal_i2c *i2c;        // Declare a pointer to a metal_i2c structure
uint8_t bufWrite[9];          // Declare a buffer for writing, with 9 elements
uint8_t bufRead[1];           // Declare a buffer for reading, with 1 element

// The entire setup sequence
void set_up_I2C()
{
    uint8_t oldMode;
    uint8_t newMode;
    _Bool success;

    bufWrite[0] = PCA9685_MODE1;
    bufWrite[1] = MODE1_RESTART;
    printf("%d\n", bufWrite[0]);

    i2c = metal_i2c_get_device(0);  // Get I2C device with index 0

    if (i2c == NULL)                // If the I2C device is not found
    {
        printf("Connection Unsuccessful\n");
    }
    else                            // If the I2C device is found
    {
        printf("Connection Successful\n");
    }

    // Setup Sequence
    metal_i2c_init(i2c, I2C_BAUDRATE, METAL_I2C_MASTER);  // Initialize the I2C device
    success = metal_i2c_write(i2c, PCA9685_I2C_ADDRESS, 2, bufWrite, METAL_I2C_STOP_DISABLE); // reset
    delay(100);
    printf("resetting PCA9685 control 1\n");

    // Initial Read of control 1
    bufWrite[0] = PCA9685_MODE1;                                                     // Address
    success = metal_i2c_transfer(i2c, PCA9685_I2C_ADDRESS, bufWrite, 1, bufRead, 1); // initial read
    printf("Read success: %d and control value is: %d\n", success, bufWrite[0]);
    // Configuring Control 1
    oldMode = bufRead[0];                               // Store the current value of MODE1 register
    newMode = (oldMode & ~MODE1_RESTART) | MODE1_SLEEP; // Clear the RESTART bit and set the SLEEP bit in the MODE1 register
    printf("sleep setting is %d\n", newMode);
    bufWrite[0] = PCA9685_MODE1;                        // Address
    bufWrite[1] = newMode;                              // Writing to register
    success = metal_i2c_write(i2c, PCA9685_I2C_ADDRESS, 2, bufWrite, METAL_I2C_STOP_DISABLE); // sleep
    bufWrite[0] = PCA9685_PRESCALE;                     // Setting PWM prescale
    bufWrite[1] = 0x79;
    success = metal_i2c_write(i2c, PCA9685_I2C_ADDRESS, 2, bufWrite, METAL_I2C_STOP_DISABLE); // sets prescale
    bufWrite[0] = PCA9685_MODE1;
    bufWrite[1] = 0x01 | MODE1_AI | MODE1_RESTART;
    printf("on setting is %d\n", bufWrite[1]);
    success = metal_i2c_write(i2c, PCA9685_I2C_ADDRESS, 2, bufWrite, METAL_I2C_STOP_DISABLE); // awake
    delay(100);
    printf("Setting the control register\n");
    bufWrite[0] = PCA9685_MODE1;
    success = metal_i2c_transfer(i2c, PCA9685_I2C_ADDRESS, bufWrite, 1, bufRead, 1); // initial read
    printf("Set register is %d\n", bufRead[0]);
}


void breakup(int bigNum, uint8_t *low, uint8_t *high)
{
    *low = (uint8_t)bigNum;                 // Assign the lower 8 bits of bigNum to the variable pointed by low
    *high = (uint8_t)(bigNum >> 8);         // Assign the upper 8 bits of bigNum to the variable pointed by high
}

void steering(int angle)
{
    uint8_t lowOffset = 3;
    uint8_t highOffset = 4;
    uint8_t code;
    int angleCycle = getServoCycle(angle); // Convert angle to pulse width (duty cycle)
    bufWrite[0] = PCA9685_LED0_ON_L + 0x04;
    bufWrite[1] = 0x00;
    bufWrite[2] = 0x00;
    printf("Steering %d %d\n", bufWrite[highOffset], bufWrite[lowOffset]);
    breakup(angleCycle, &bufWrite[lowOffset], &bufWrite[highOffset]); // Break up angleCycle into low and high bytes
    code = metal_i2c_transfer(i2c, PCA9685_I2C_ADDRESS, bufWrite, 5, bufRead, 1); // Write steering data to PCA9685
    printf("Steering transfer code %d\n", code);
}


void stopMotor()
{
    uint8_t lowOffset = 3;
    uint8_t highOffset = 4;
    uint8_t code;
    bufWrite[0] = PCA9685_LED0_ON_L;
    bufWrite[1] = 0x00;
    bufWrite[2] = 0x00;
    breakup(280, &bufWrite[lowOffset], &bufWrite[highOffset]); // Break up 280 into low and high bytes
    printf("StopMotor %d %d\n", bufWrite[highOffset], bufWrite[lowOffset]);
    code = metal_i2c_transfer(i2c, PCA9685_I2C_ADDRESS, bufWrite, 5, bufRead, 1); // Write stop motor data to PCA9685
    printf("Stopmotor transfer code %d\n", code);
}

void driveForward(uint8_t speedFlag)
{
    uint8_t lowOffset = 3;
    uint8_t highOffset = 4;
    uint8_t code;
    bufWrite[0] = PCA9685_LED0_ON_L;
    bufWrite[1] = 0x00;
    bufWrite[2] = 0x00;
    switch (speedFlag)
    {
    case 1:
        breakup(313, &bufWrite[lowOffset], &bufWrite[highOffset]); // Break up 313 into low and high bytes
        break;
    case 2:
        breakup(315, &bufWrite[lowOffset], &bufWrite[highOffset]); // Break up 315 into low and high bytes
        break;
    case 3:
        breakup(317, &bufWrite[lowOffset], &bufWrite[highOffset]); // Break up 317 into low and high bytes
        break;
    default:
        // If invalid, just stop the motor
        breakup(280, &bufWrite[lowOffset], &bufWrite[highOffset]); // Break up 280 into low and high bytes
    }
    printf("ForwardMotor %d %d\n", bufWrite[highOffset], bufWrite[lowOffset]);
    code = metal_i2c_transfer(i2c, PCA9685_I2C_ADDRESS, bufWrite, 5, bufRead, 1); // Write forward motor data to PCA9685
    printf("ForwardMotor transfer code %d\n", code);
}


void driveReverse(uint8_t speedFlag)
{
    uint8_t lowOffset = 3;
    uint8_t highOffset = 4;
    uint8_t code;
    bufWrite[0] = PCA9685_LED0_ON_L;
    bufWrite[1] = 0x00;
    bufWrite[2] = 0x00;
    switch (speedFlag)
    {
    case 1:
        breakup(267, &bufWrite[lowOffset], &bufWrite[highOffset]); // Break up 267 into low and high bytes
        break;
    case 2:
        breakup(265, &bufWrite[lowOffset], &bufWrite[highOffset]); // Break up 265 into low and high bytes
        break;
    case 3:
        breakup(263, &bufWrite[lowOffset], &bufWrite[highOffset]); // Break up 263 into low and high bytes
        break;
    default:
        // If invalid, just stop the motor
        breakup(280, &bufWrite[lowOffset], &bufWrite[highOffset]); // Break up 280 into low and high bytes
    }
    printf("ReverseMotor %d %d\n", bufWrite[highOffset], bufWrite[lowOffset]);
    code = metal_i2c_transfer(i2c, PCA9685_I2C_ADDRESS, bufWrite, 5, bufRead, 1); // Write reverse motor data to PCA9685
    printf("ReverseMotor transfer code %d\n", code);
}

int parseCommand(char *str)
{
    // Run through the string array

    int parsingType = 0;
    char commandType = '\0';
    char commandValueStr[8] = {'\0'};
    int commandValueStrInt = 0;
    int commandValue = 0;
    int i;
    for (i = 0;; i++)
    {
        if (str[i] == '\0')
        {
            break;
        }
        // If we have terminated the command, go ahead and run it
        if (str[i] == ';')
        {
            // parse commandValueStr
            sscanf(commandValueStr, "%d", &commandValue);
            switch (commandType)
            {
            case 'a':
                // angle
                steering(commandValue);
                break;
            case 's':
                // speed
                if (commandValue > 0)
                {
                    driveForward(commandValue);
                }
                else if (commandValue < 0)
                {
                    driveReverse(commandValue);
                }
                else
                {
                    stopMotor();
                }
                break;
            case 'd':
                delay(commandValue * 1000);
                break;
            // default:
                // Don't pollute with errors
                // printf("Failed to parse command! %c\n", commandType);
            }

            parsingType = 0;
            commandType = '\0';
            commandValueStr[0] = '\0';
            commandValueStrInt = 0;
        }
        else if (str[i] == ':')
        {
            parsingType = 1;
        }
        // Getting commandValue
        else if (parsingType == 1)
        {
            commandValueStr[commandValueStrInt] = str[i];
            commandValueStrInt += 1;
        }
        // Getting commandType
        else if (parsingType == 0)
        {
            commandType = str[i];
        }
        else
        {
            printf('We ended up in an invalid state! What happened?');
        }
    }
}

int main()
{
    set_up_I2C(); // Set up the I2C connection

    stopMotor(); // Stop the motor
    delay(2000); // Wait for 2 seconds

    char buffer[64] = {'\0'};
    int bufferint = 0;
    // initialize UART channels
    ser_setup(0); // uart0 (debug)
    ser_setup(1); // uart1 (raspberry pi)
    printf("Serial connection completed.\n");
    printf("Begin the main loop.\n");
    while (1)
    {
        if (ser_isready(1)) // Check if there's data in the UART1 buffer
        {
            buffer[bufferint] = ser_read(1); // Read the incoming data
            ser_write(0, buffer[bufferint]); // Write the data to UART0 (debug)
            if (buffer[bufferint] == '\r' || buffer[bufferint] == '\n')
            {
                bufferint = -1; // Reset buffer index
                buffer[0] = '\0'; // Clear the first element in buffer
            }
            else if (buffer[bufferint] == ';')
            {
                // If we encounter the end of the command, go ahead 
                // parse the command then
                // reset the bufferint and buffer,
                parseCommand(buffer); // Parse the received command
                bufferint = -1; // Reset buffer index
                buffer[0] = '\0'; // Clear the first element in buffer
            }
            // somehow we ended up using all the buffer before a valid command
            else if (bufferint >= 63)
            {
                // overflow back to start
                bufferint = -1; // Reset buffer index
                buffer[0] = '\0'; // Clear the first element in buffer
            }
            bufferint += 1; // Increment the buffer index
        }
    }
    return 0;
}
