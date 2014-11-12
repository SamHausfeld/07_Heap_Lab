07_HeapLab
==============

Implement a heap in C++

Requirements
------------

1. `add` and `remove` should be O(log n), except for `grow` which can be O(n)
2. Do not leak memory

Reading
=======
"Open Data Structures," Chapter 10, just the intro and section 1. http://opendatastructures.org/ods-cpp/10_Heaps.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. roger that, basically implemented what I read in the book
2. I wouldn't dare.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html


10.1 : We start with:

4 9 8 17 26 50 16 19 69 32 93 55

We add 7, it hops on the end.

4 9 8 17 26 50 16 19 69 32 93 55 >7<

It bubbles up to the proper location.

4 9 >7< 17 26 8 16 19 69 32 93 55 50

Next we add 3.

4 9 7 17 26 8 16 19 69 32 93 55 50 >3<

And now, it bubbles up all the way to the front (since it's smaller than 4 -- the current root).

>3< 4 9 7 17 26 8 16 19 69 32 93 55 50




10.2 : We start with :

6 9 8 17 26 50 16 19 69 32 93 55

We begin by removing 6 the current root & swapping in with the end pair

>55< 9 8 17 26 50 16 19 69 32 93 -- [6 is gone] 

Trickle down the 55 properly.  (???)

8 9 17 26 >55< 50 16 19 69 32 93

Now do the same for the 8.

>93< 8 9 17 55 50 16 19 69 32 -- [8 is gone]

8 9 17 55 93 50 16 19 69 32 (???)



(???) means I'm not certain.

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

Huh??


#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Well I thought I was doing okay until Eytzinger was mentioned...so I guess pay attention in class! Haha, but in all seriousness you can never go wrong reading the book.  This seemed a lot easier than the past handful of labs...