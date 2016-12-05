#!/usr/bin/env python
"""
Function with there specific needs.
"""
from __future__ import print_function
import abc
import argparse
import random

import six

import functions


@six.add_metaclass(abc.ABCMeta)
class Algorithm(object):
    """Runner object that implement the optimization algorithm."""

    RETRY_COUN = 1000

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

    @abc.abstractmethod
    def alg(self, function_name):
        """Aply the algorithm on the function.

        :rtype tuple:
        """


# ======================== Utils
ALGORITHMS = (
)


def check_valid(name):
    """Check if a function name is valid."""
    names = [alg.name for alg in ALGORITHMS]
    if name not in names:
            raise argparse.ArgumentTypeError(
                "%s is not a knows Algorithm!", name)
    return name
