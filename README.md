# CS149

HW3
This program simulates ticket sellers simultaneously selling concert tickets during one hour. There are 100 seats available, and 10 ticket sellers: 1 high-priced, 3 medium-priced, and 6 low-priced. High-priced transactions take 1 or 2 minutes, medium-priced transactions take 2, 3, or 4 minutes, low-priced transactions take 4, 5, 6, or 7 minutes. Each seller can expect N customers to arrive at random times during the hour. 


To Do: 
Run your program for N = 5, 10, and 15 customers per ticket seller, where N is a command-line parameter.

Print line when:
	A customer arrives at the tail of a sellers queue.
	A customer is served and is assigned a seat, or is told the concert is sold out,
in which case the customer immediately leaves.
	A customer completes a ticket purchase and leaves.

Start each event print line with a time stamp, such as 0:05, 0:12, etc.

After each ticket sale, also print the concert seating chart as a 10-by-10 matrix that shows which customer was assigned to each seat. Identify ticket seller H’s customers as H001, H002, H003, ...; the customers of ticket sellers M1, M2, ..., as M101, M102, ..., M201, M202, ...; and the customers of ticket sellers L1, L2, ... as L101, L102, ..., L201, L202, ... You can indicate still-unsold seats with dashes.

At the end of one hour, each ticket seller should complete whatever purchase may still be in progress and close the ticket window. Any remaining customers in the queues should leave immediately. Of course, if the concert sells out before the hour is up, all the ticket windows should close after the last seat is taken.

At the end of each run, print how many H, M, and L customers got seats, how many customers were turned away, etc.
