This branch contains code for core image processing and augmentation of detected image.

Pyhton version - 2.7 

src contains main source code
models contain a 3D model of images which can be projected on to the screen when a reference object is detected reference contains the image of the object that we consider as target object

src------
	ob_load.py:
		object loader is used as an import in Augmented_Reality.py to get the 3D object projected on to the detected image
	Augmented_Reality.py:
		This module consists of main code which runs our image processing algorithm
	
	Touch_sensor.py:
		This is used to get data from touch sensors to GPIO pins of the RaspberryPi

Hardware Used :
		--RPI Zero W 
		--Touch Sensors(2)
		--Pi-Camera

		RPi zero has to be running raspian os/ any linux kernel and python installed in it.

		Touch Sensors to be connected to GPIO pins of the Pi Zero