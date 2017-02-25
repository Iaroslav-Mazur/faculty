#!/usr/bin/env python
"""Laborator Cripto 1"""
from __future__ import print_function

import argparse


class App(object):
    """App. """
    def __init__(self, key):
        self._key = key

    @staticmethod
    def _clean_text(text):
        """Clean `text` for encripting."""
        pass

    def encript(self, text):
        """Encript."""
        pass

    def decript(self, text):
        """Encript."""
        pass


def parser():
    """Return ArgumentParser."""
    par = argparse.ArgumentParser()
    par.add_argument("decript", help="Decript a text.")
    par.add_argument("encript", help="Encript a text.")
    par.add_argument("--text", dest="text",
                     help="The text we want to work with.")

    return par


if __name__ == "__main__":
    args = parser().parse_args()
