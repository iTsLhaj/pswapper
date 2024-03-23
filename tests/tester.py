import os
import random
import argparse

from rich import print


def parse_args() -> None:

    parser = argparse.ArgumentParser(description="Simple argument parsing for min and max values")

    parser.add_argument("--min", type=int, help="Minimum value", required=True)
    parser.add_argument("--max", type=int, help="Maximum value", required=True)
    parser.add_argument("--amount", type=int, help="Amount of digit's", required=True)
    parser.add_argument("--tests", type=int, help="Number of test's", required=True)

    return parser.parse_args()


if __name__ == "__main__":

    args = parse_args()
    bounds = (args.min, args.max)
    amount = args.amount
    tests = args.tests

    os.system('clear')
    print("\n")
    for i in range(tests):
        numbers = random.sample(range(bounds[0], bounds[1]), amount)
        command = " ".join(["bash", "push_swap", " ".join(list(map(str, numbers)))])
        output = os.popen(command)
        result = os.popen(" ".join([command, "|", "./checker", " ".join(list(map(str, numbers)))])).read().rstrip('\n')
        if (result == "OK"):
            print(f" - [[green]{result}[/green]] ", end='')
        else:
            print(f" - [[red]{result}[/red]] ", end='')
        print(f"with {output.readlines().__len__()} moves !")
    print("\n")