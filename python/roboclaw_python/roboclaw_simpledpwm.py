import time
import roboclaw

#Windows comport name
#roboclaw.Open("COM3",115200)
#Linux comport name
#roboclaw.Open("/dev/ttyACM0",115200)

address = 0x80
overall_speed = 32

while(1):

	#message = '"{}"'.format(input("please enter a colour"))
	message = raw_input("Enter something: ")
	if message == "forward":
		#roboclaw.ForwardM1(address,overall_speed)
		#roboclaw.ForwardM2(address,overall_speed)
		print("Both motors " + message)

	elif message == "reverse":
		#roboclaw.BackwardM1(address,overall_speed)
		#roboclaw.BackwardM2(address,overall_speed)
		print("Both motors " + message)

	elif message == "stop":
		#roboclaw.ForwardM1(address,overall_speed)
		#roboclaw.ForwardM2(address,overall_speed)
		print("Both motors " + message)
	else:
		print("you entered something else")
		#roboclaw.ForwardM1(address,0)

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
