#!/usr/bin/env python
"""
Tema 0 la Algoritmi Genetici.
"""
from __future__ import print_function

import abc

import six

import random

INTERVAL = [-10, 10]
RETRY = 10000


@six.add_metaclass(abc.ABCMeta)
class Function(object):
    def __init__(self, interval, name, nr_args):
        """Init a function object.

        :param interval:
            Domeniul functiei data ca o lista, sau tuple de tipul
            (start, finish) si va fi interpretat ca [start, finish].
        :param name:
            Numele functiei.
        :param nr_args:
            Number of argument for the function body.
        """
        self._interval = interval
        self._name = name
        self._nr_args = nr_args

    @abc.abstractmethod
    def __call__(self, *args):
        """Function body.

        :pram *args:
            All the arguments needed for the function expresion

        :rtype: float
        """
        pass


def Runner(object):
    """Runner object that implement the optimization algorithm."""

    def __init__(self):
        """Initialize the runner object."""


def f(*args):
    return (args[0] + 2 * args[1] - 7) ** 2 + (2*args[0] + args[1] - 5) ** 2


def run():
    min_val = 100
    for _ in range(RETRY):
        rez = f(random.randint(*INTERVAL), random.randint(*INTERVAL))
        min_val = rez if min_val > rez else min_val
    print("Val :", min_val)


if __name__ == "__main__":
    run()
