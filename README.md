## Push Swap

<br>

* **this project is a very simple and a highly straightforward algorithm project**
* **my goal here is to write a program in C, which calculates and displays on the _stdout_ the least amount of moves to sort the stack**
* **these moves are (_push, swap, rotate, reverse rotate_) ! [here's more explanation of these moves](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)**

## Usage

<br>

#### here's the way you can run the program

```shell
./push_swap <random_integers>
```

<br>

#### here's how you can generate random numbers
* **_[python 3](https://www.python.org/downloads/)_ is required !**

```pycon
>>>
>>> import random
>>>
>>>
>>> BOUNDS = (-100, 100) # (MIN, MAX)
>>> AMOUNT = 100         # The Amount Of Numbers (3, 5, 10, 100, 500 ...)
>>> 
>>> print(" ".join(list(map(str, random.sample(range(BOUNDS[0], BOUNDS[1]), AMOUNT)))))
>>>
```

##### note: a tester will be provided soon ...

## Building

<br>

#### just run this command in the main directory of this repo
#### note for now it's using cmake so it wont work until i push this project with a it's makefile

```shell
make
```