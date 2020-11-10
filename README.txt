
Behaviors:
	idle
	fly - up/down
	walk - left/right

Controls: 
	move left = left
	move right = right
	move up = up
	move down = down

Collisions:
	Compares whether two GameObjects have collided. 

	Making contact with the "hound" will trigger a hit response. 
	The hound will get hit offscreen then reset somewhere randomly.
	The particle animation only works on the first hit, one must 
	restart the program to see the particle effects again. I'm 
	working on this resetting each time.

ParticleManager added.

Make:
	make clean; make;
	
Run: 
	./assignment4