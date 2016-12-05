#!/usr/bin/env python
"""
Tema 0 la Algoritmi Genetici.
Autor: Micu Matei-Marius
Grupa: B6
"""
from __future__ import print_function
import argparse
import sys

import functions
# import functools
import runner


def get_parser(alg):
    """Get the argument parser."""
    help_string = "Name of a function, this can be: {} ".format(
        ", ".join(alg.get_function_names))
    pars = argparse.ArgumentParser()
    pars.add_argument("-f", "--function", type=alg.check_valid,
                      help=help_string, required=True)

    return pars


def add_functions(alg):
    """Add the function to the algorithm."""
    alg.add_function(functions.BoothFunction)
    alg.add_function(functions.BohachevskyFunction1)
    alg.add_function(functions.BohachevskyFunction2)
    alg.add_function(functions.BohachevskyFunction3)


def main():
    """Main function."""
    algo = runner.Algorithm()
    add_functions(algo)

    parser = get_parser(algo)
    args = parser.parse_args(sys.argv[1:])

    if args.function:
        guess, function = algo.alg(args.function)

        print("We got: {}".format(guess))
        print("The corect values are {}".format(function.correct_values))

if __name__ == "__main__":
    main()
