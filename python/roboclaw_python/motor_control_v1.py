import time
import roboclaw

#Windows comport name
#roboclaw.Open("COM3",115200)
#Linux comport name
roboclaw.Open("/dev/ttyACM0",115200)

address = 0x80
overall_speed = 10
direction1 = ""
direction2 = ""

def forward(motor, speed):
    if motor == 1:
        roboclaw.ForwardM1(address, speed)
        global direction1
        direction1 = "forward"

    else:
        roboclaw.ForwardM2(address, speed)
        global direction2
        direction2 = "forward"

def reverse(motor, speed):
    if motor == 1:
        roboclaw.BackwardM1(address, speed)
        global direction1
        direction1 = "reverse"
    else:
        roboclaw.BackwardM2(address, speed)
        global direction2
        direction2 = "reverse"

def stop(motor):
    if motor == 1:
        roboclaw.ForwardM1(address, 0)
        global direction1
        direction1 = "stop"
    else:
        roboclaw.ForwardM2(address, 0)
        global direction2
        direction2 = "stop"

def turn_left(speed):
    roboclaw.ForwardM1(address, speed)
    roboclaw.BackwardM2(address, speed)

def turn_right(speed):
    roboclaw.BackwardM1(address, speed)
    roboclaw.ForwardM2(address, speed)

def change_speed(change):
    global overall_speed
    if change == "faster":
        overall_speed += 5
    else:
        overall_speed -= 5
    print overall_speed
    global direction1
    global direction2

    if direction1 == "forward":
        forward(1, overall_speed)
    elif direction1 == "reverse":
        reverse(1, overall_speed)
    elif direction1 == "stop":
        stop(1)

    if direction2 == "forward":
        forward(2, overall_speed)
    elif direction2 == "reverse":
        reverse(2, overall_speed)
    elif direction2 == "stop":
        stop(2)


while(1):

        message = raw_input("Enter something: ")
        if message == "forward":
                forward(1, overall_speed)
                forward(2, overall_speed)
                print("Both motors " + message)

        elif message == "reverse":
                reverse(1, overall_speed)
                reverse(2, overall_speed)
                print("Both motors " + message)

        elif message == "stop":
                roboclaw.ForwardM1(address,0)
                roboclaw.ForwardM2(address,0)
                print("Both motors " + message)

        elif message == "left":
                turn_left(overall_speed)
                print("Turn " + message)

        elif message == "right":
                turn_right(overall_speed)
                print("Turn " + message)

        elif message == "faster" or message == "slower":
                change_speed(message)
        else:
                print("you entered something else")
                roboclaw.ForwardM1(address,0)

        # roboclaw.ForwardM1(address,64)
        # roboclaw.BackwardM2(address,64)
        # time.sleep(2)
        #
        # roboclaw.BackwardM1(address,64)
        # roboclaw.ForwardM2(address,64)
        # time.sleep(2)
        #
        # roboclaw.ForwardBackwardM1(address,96)
        # roboclaw.ForwardBackwardM2(address,32)
        # time.sleep(2)
        #
        # roboclaw.ForwardBackwardM1(address,32)
        # roboclaw.ForwardBackwardM2(address,96)
        # time.sleep(2)
