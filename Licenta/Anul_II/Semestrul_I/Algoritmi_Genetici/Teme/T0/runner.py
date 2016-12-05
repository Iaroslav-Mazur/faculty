#!/usr/bin/env python
"""
Function with there specific needs.
"""
from __future__ import print_function
import argparse
import random

from six import moves

import functions


class Algorithm(object):
    """Runner object that implement the optimization algorithm."""

    GUESS = 1000

    def __init__(self, alg_type=min):
        """Initialize the runner object.

        :param alg_type:
            A function that returns how good the guess is.
        """
        self._functions = []
        self._fit = alg_type

    def add_function(self, function):
        """Add a new function class to the Algorithm.

        :param function:
            A implemented verion of the Function class.
        """
        if not issubclass(function, functions.Function):
            raise TypeError("We need a `functions.Function` type not %s",
                            function)
        if function.name in [func.name for func in self._functions]:
            raise ValueError("We have a function with name %s",
                             function.name)

        self._functions.append(function())

    @property
    def get_function_names(self):
        """Return a tuple with all the funcion names.

        :rtype tuple:
        """
        return tuple([function.name for function in self._functions])

    def _get_function_by_name(self, name):
        """Search for a function with a specific name.

        :param name:
            Name of the function.

        :rtype functions.Function:
        """
        if name not in self.get_function_names:
            raise KeyError("We don't have a function with name %s",
                           name)

        for function in self._functions:
            if name == function.name:
                return function

    @staticmethod
    def _get_params(domain, nr_args):
        """Return a tuple with possible parametes.

        The tuple will have `nr_args` argumens of type `int`
        and all of the ints will from the domain.
        :param domain:
            List or Tuple with two elements (start, finish).

        :param nr_args:
            Int representing the number of argumenst we need.

        :rtype tuple:
        """
        start = domain[0]
        finish = domain[1]
        return [random.uniform(start, finish) for _ in moves.range(nr_args)]

    def _get_nr_guess(self, domain, nr_args):
        """Return how many times we should try.

        :param domain:
            List or Tuple with two elements (start, finish).

        :param nr_args:
            Int representing the number of argumenst we need.
        """
        start = domain[0]
        finish = domain[1]
        domain_length = (finish - start + 1)
        guess = self.GUESS * random.randint(1, self.GUESS / domain_length)

        return domain_length * nr_args * guess

    def check_valid(self, name):
        """Check if the name of a function is valid.

        :rtype bool:
        """
        if name not in self.get_function_names:
            raise argparse.ArgumentTypeError(
                "%s is not a knows function !", name)
        return name

    def alg(self, function_name):
        """Aply the algorithm on the function.

        :rtype tuple:
        """
        function = self._get_function_by_name(function_name)
        nr_args = function.nr_args
        domain = function.domain
        nr_guess = self._get_nr_guess(domain, nr_args)

        # Choose a random best
        best_args = self._get_params(domain, nr_args)
        best_y = function(*best_args)
        print("We have to: ", nr_guess)
        for _ in moves.range(nr_guess):
            # Get a new guess
            guess_args = self._get_params(domain, nr_args)
            guess_y = function(*guess_args)
            # Compute the fitnes for the new guess
            fit = self._fit(guess_y, best_y)
            # Keep the best one
            if guess_y == fit:
                best_args = guess_args
        return guess_args, function
