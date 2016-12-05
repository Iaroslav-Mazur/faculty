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
import runner


def get_parser():
    """Get the argument parser."""
    help_string_func = "Name of a function, this can be: {} ".format(
        ", ".join(functions.FUNCTIONS))

    help_string_alg = "Name of a function, this can be: {} ".format(
        ", ".join(runner.get_function_names))

    pars = argparse.ArgumentParser()
    pars.add_argument("-f", "--function", type=functions.check_valid,
                      help=help_string_func, required=True)

    pars.add_argument("-a", "--algorithm", type=runner.check_valid,
                      help=help_string_alg, required=True)
    return pars


def main():
    """Main function."""
    parser = get_parser()
    args = parser.parse_args(sys.argv[1:])
    #
    # guess, function = algo.alg(args.function)
    #
    # print("We got: {}".format(guess))
    # print("The corect values are {}".format(function.correct_values))
    print(args)

if __name__ == "__main__":
    main()
