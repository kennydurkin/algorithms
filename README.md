Final Project - CISC 4080
===========

*Part 1*: You are given two sorted lists of size **m** and **n**. Give an **O (log m + log n)** time algorithm for computing the **kth** smallest element in the union of the two lists (assume no duplicate elements). Your program should allow the user to input two lists and the value of **k**.

*Part 2*: A contiguous subsequence of **S** is a subsequence made up of consecutive elements of **S**. For instance, if **S** is 5, 15, -30, 10, -5, 40, 10, then 15, -30, 10 is a contiguous subsequence but 5, 15, 40 is not. Give a linear time algorithm for the following task:
  * Input: A list of numbers, a1, a2, ..., an.
  * Output: The contiguous subsequence of maximum sum (a subsequence of length zero has sum zero).
Your program can use the preceding sequence as input, and the answer should be 10, -5, 40, 10, with a sum of 55.

*Part 3*: Alice wants to throw a party and is deciding whom to call. She has **n** people to choose from, and she has made up a list of which pairs of these people know each other. She wants to pick as many people as possible, but they must know at least **five** other people. Give an efficient algorithm that takes as input the list of **n** people and the list of pairs who know each other and outputs the best choice of party invitees. Give the running time in terms of n.
