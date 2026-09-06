#!/bin/env python3
import sys
import os
from base64 import b64encode, b64decode


def main(av):
    sys.exit(84)

if __name__ == '__main__':
    try:
        if len(sys.argv) != 1:
            sys.exit (84)
        main(sys.argv)
    except:
        sys.exit(84)
