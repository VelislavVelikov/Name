from __future__ import print_function
from pololu_drv8835_rpi import motors, MAX_SPEED
from multiprocessing import Process 
import logging
import time

"""
Moving 2nd motor of pololu_drv8835_rpi driver
Positive value means clockwise rotation
Negative value means counterclockwise rotation

Time = 1, second(s)
Axle d = 0.3, cm
Rotates 8 times
Rope diameter = 0.1, cm
Distance = 9, cm

"""

def move_sync(duration, speed):
	logger = logging.getLogger(__name__)
	ch = logging.FileHandler("errors.log", 'w')
	ch.setLevel(logging.DEBUG)
	logger.addHandler(ch)

	try:
		motors.motor2.setSpeed(speed);
		time.sleep(duration);
	except Exception as e:
		logger.exception("Error: ")		
	finally:
		motors.motor2.setSpeed(0);

def move(duration = 0.0, clockwise=False, speed=MAX_SPEED, async=True):
	
	print("Duration")
	print(duration)
	if not clockwise:
		speed = speed * -1
	p = Process(target=move_sync, args=[duration, speed])
	p.start()
	if not async:
		p.join()
