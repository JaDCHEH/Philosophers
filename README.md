# Philosophers

In this project, we will learn the basics of `threading a process`.

You will see how to create `threads` and we will discover `mutexes`.

This project is also a good lesson in `C` optimization as we need to save every

bit of `CPU` usage we can to ensure the survival of our philosophers.


## Score (100/125)

Mandatory (100/100)

Bonus (0/25)

## Explanation of the project

One or more philosophers sit at a round table.

There is a large bowl of spaghetti in the middle of the table.

• The philosophers alternatively eat, think, or sleep.

While they are eating, they are not thinking nor sleeping;

while thinking, they are not eating nor sleeping;

and, of course, while sleeping, they are not eating nor thinking.


• There are also forks on the table. There are as many forks as philosophers.


• Because serving and eating spaghetti with only one fork is very inconvenient, a

philosopher takes their right and their left forks to eat, one in each hand.


• When a philosopher has finished eating, they put their forks back on the table and

start sleeping. Once awake, they start thinking again. The simulation stops when

a philosopher dies of starvation.


• Every philosopher needs to eat and should never starve.


• Philosophers don’t speak with each other.


• Philosophers don’t know if another philosopher is about to die.


• No need to say that philosophers should avoid dying!
