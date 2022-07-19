“Talk is cheap. Show me the code.” — Linus Torvalds

We genuinely believe that “The only way to evaluate programmers is through code.”
In this round, we’ll provide you with an elementary coding problem that you need to complete within 6-7 hours of receiving this activity. We expect the activity to take ~3-4 hours of your valuable time.


Guidelines for this activity
Feel free to ask for help when you get stuck or have any questions anywhere.
We expect you to produce a clean, well-documented code following all good programming practices and produce maintainable + production-ready code.
Goes without saying, the submission should cover all edge cases possible.
This is our version of the famous FIZZBUZZ test, so correctness is of paramount importance.
The submission should be shared as a public repl.it environment & also as a Github repo (we need both - you can use repl.it’s ‘Version Control’ feature to sync to github)
When I run the environment, it should read from input.txt from the same environment and print output to the stdout.
You can use any object-oriented programming language that is available on repl.it 
If your code doesn’t run, you’ll be automatically rejected.
Make sure that at least the sample input given in this doc works.


Problem Statement
We own a parking lot that can hold up to ‘n’ cars at any given point in time. Each slot is given a number starting at one increasing with increasing distance from the entry point in steps of one. We want to create an automated ticketing system that allows our customers to use our parking lot without human intervention.
When a car enters the parking lot, we want to have a ticket issued to the driver. The ticket issuing process includes:- 
We are taking note of the number written on the vehicle registration plate and the age of the driver of the car.
And we are allocating an available parking slot to the car before actually handing over a ticket to the driver (we assume that our customers are kind enough to always park in the slots allocated to them).
The customer should be allocated a parking slot that is nearest to the entry. At the exit, the customer returns the ticket, marking the slot they were using as being available.
Due to government regulation, the system should provide us with the ability to find out:-
Vehicle Registration numbers for all cars which are parked by the driver of a certain age,
Slot number in which a car with a given vehicle registration plate is parked. 
Slot numbers of all slots where cars of drivers of a particular age are parked.
We get the input by reading input.txt directly (you’ll have to create it in your environment) .The file will contain a set of commands separated by a newline, we need to execute the commands in order and produce output.
 
Sample Input file (input.txt):-  https://gist.github.com/tarungarg546/6200f936f2208bad5d9d0e053d773489
 
 
 Output (In stdout) :- https://gist.github.com/tarungarg546/697334d7990f758ac77a8accdf3efd98
 
 Project can be run at replit at the following url:-
 https://replit.com/@AvinashRathore/parkinglotdesign#main.cpp
 
 Author:
 Avinash Rathore
