#!/usr/bin/env python
"""
Function with there specific needs.
"""
mport abc
import math

import six


@six.add_metaclass(abc.ABCMeta)
class Function(object):
    """Base class for function."""
    def __init__(self, domain, name, nr_args, corect_result):
        """Init a function object.

        :param domain:
            Function domain.
        :param name:
            Name of the function.
        :param nr_args:
            Number of argument for the function body.
        """
        self._domain = domain
        self._name = name
        self._nr_args = nr_args
        self._corect_result = corect_result

    def _check_args(self, args):
        """Check of we have enough args."""
        if len(args) < self.nr_args:
            raise ValueError("There are not enogut argumenst !"
                             "We need %d but we get %d", self._nr_args,
                             len(args))

    def get_from_interval(self, precision, number):
        """Return the floating number from the interval with give precision."""
        sections = self._domain[1] - self._domain[0]
        divisions = (sections * 10 ** precision)
        nr_bits = math.ceil(math.log(divisions, 2))
        return (self._domain[0] + int(number, 2) *
                (sections / (2 ** nr_bits - 1)))

    @property
    def domain(self):
        """Return the domain."""
        return self._domain

    @property
    def name(self):
        """Return the name."""
        return self._name

    @property
    def nr_args(self):
        """Return the number of arguments."""
        return self._nr_args

    @property
    def correct_values(self):
        """Return the domain."""
        return self._corect_result

    @abc.abstractmethod
    def __call__(self, *args):
        """Function body.

        :pram *args:
            All the arguments needed for the function expresion

        :rtype: float
        """
        pass


class BoothFunction(Function):
    """Booth Function."""
    def __init__(self):
        name = "booth_function"
        nr_args = 2
        domain = (-10, 10)
        corect_result = (1, 3)
        super(BoothFunction, self).__init__(domain, name, nr_args,
                                            corect_result)

    def __call__(self, *args):
        self._check_args(args)
        return (args[0] + 2*args[1] - 7)**2 + (2*args[0] + args[1] - 5)**2


@six.add_metaclass(abc.ABCMeta)
class BohachevskyFunctionBase(Function):
    """Bohachevsky Functions Base Class."""
    def __init__(self, name):
        nr_args = 2
        domain = (-100, 100)
        corect_result = (0, 0)
        super(BohachevskyFunctionBase, self).__init__(
            domain, name, nr_args, corect_result)

    @abc.abstractmethod
    def __call__(self, *args):
        pass


class BohachevskyFunction1(BohachevskyFunctionBase):
    """Bohachevsky Functions 1."""
    def __init__(self):
        name = "bohachevsky_functions_1"
        super(BohachevskyFunction1, self).__init__(name)

    def __call__(self, *args):
        self._check_args(args)
        return (args[0] ** 2 + 2 * args[1] ** 2 - .3 *
                math.cos(3*math.pi*args[0]) -
                .4 * math.cos(4*math.pi*args[1]) + .7)


class BohachevskyFunction2(BohachevskyFunctionBase):
    """Bohachevsky Functions 2."""
    def __init__(self):
        name = "bohachevsky_functions_2"
        super(BohachevskyFunction2, self).__init__(name)

    def __call__(self, *args):
        self._check_args(args)
        return (args[0] ** 2 + 2 * args[1] ** 2 - .3 *
                math.cos(3*math.pi*args[0]) *
                math.cos(4*math.pi*args[1]) + .3)


class BohachevskyFunction3(BohachevskyFunctionBase):
    """Bohachevsky Functions 3."""
    def __init__(self):
        name = "bohachevsky_functions_3"
        super(BohachevskyFunction3, self).__init__(name)

    def __call__(self, *args):
        self._check_args(args)
        return (args[0] ** 2 + 2 * args[1] ** 2 - .3 *
                math.cos(3*math.pi*args[0] + 4*math.pi*args[1]) + .3)


# ======================== Utils
FUNCTIONS = (
    BoothFunction,
    BohachevskyFunction1,
    BohachevskyFunction2,
    BohachevskyFunction3,
)


def check_valid(name):
    """Check if a function name is valid."""
    names = [func.name for func in FUNCTIONS]
    if name not in names:
            raise argparse.ArgumentTypeError(
                "%s is not a knows function !", name)
    return name
