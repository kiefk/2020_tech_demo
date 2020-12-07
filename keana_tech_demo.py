#Author: Keana Kief
#Title: ECE 441 - Tech Demo
#Purpose: Logs the number of button presses per minute printed to serial by the Arduino 
import serial
import time

#Connect to the serial port the Arduino is writing to
ser = serial.Serial('/dev/ttyACM0', 9600)
ser.reset_input_buffer()

#Get the time the program started and the current time
start = time.time() 
current = time.time()

#Open demo_data.csv to log the data
with open("demo_data.csv", "w") as f:
    
    #Log data for an hour
    while(current - start <= 3600):
        current = time.time()
        if(ser.in_waiting):
            bCount = ser.readline()
            decoded_bCount = bCount.decode("utf-8").strip('\r\n')
            timeStruct = time.localtime(current)
            #Write the number of button presses and the time to the data logging file
            f.write("{},{}:{}:{}\n".format(decoded_bCount,
                                        timeStruct.tm_hour,
                                        timeStruct.tm_min,
                                        timeStruct.tm_sec))



