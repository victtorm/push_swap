![Banner](img/push_swap_banner.jpg "ps banner") <br>

<div>
  Push_swap project is a very simple and highly straighforward algorithm project: data must be sorted
  <div>
<h2> 🏁 Goals </h2>
    
- Writing a sorting algorithm is always a very important step in a developer’s journey. It
is often the first encounter with the concept of complexity.
    
- Sorting algorithms and their complexity are part of the classic questions discussed
during job interviews. It’s probably a good time to look at these concepts since you’ll
have to face them at some point.

- Sorting values is simple. To sort them the fastest way possible is less simple. Especially
because from one integers configuration to another, the most efficient sorting solution can
differ.
<div>

<h2> 📖 Rules </h2>

Have 2 stacks named a and b.

At the beginning: The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
  
The stack b is empty.

The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:

- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.


- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

- ss : sa and sb at the same time.

- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if a is empty.

- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.

- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

- rr : ra and rb at the same time.

- rra (reverse rotate a): Shift down all elements of stack a by 1. The first element becomes the last one.

- rrb (reverse rotate b): Shift down all elements of stack b by 1. The first element becomes the last one.

- rrr : rra and rrb at the same time

<div>
<div align="center">
  
![push_swap](img/push_swap.gif)<br>
