### The trafic light problem

The program reads numbers that represent how long each traffic light stays green. It stops reading when it sees a zero. It finds the traffic light that changes the quickest. The program then checks, second by second, if there's a time when all the traffic lights are green at the same time. This check starts from twice the time of the shortest light cycle and continues up to 5 hours. If it finds a time when all lights are green together, it shows this time. If not, it says that the lights can't be synchronized within 5 hours.
