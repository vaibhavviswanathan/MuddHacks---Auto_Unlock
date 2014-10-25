B#!/usr/bin/env python

import sys
import serial
import argparse


########## parser definition ##########

parser = argparse.ArgumentParser(description="talk_to_arduino.py:\n "+\
      "Send a few basic commands from the raspi to the arduino.")

group = parser.add_mutually_exclusive_group()

group.add_argument("-g", "--get-state", help="Get the state of the "+\
            "arduino. Returns 'locked' or 'unlocked'.", action="store_true")

group.add_argument("-s", "--set-state", help="Set the state of the "+\
            "arduino. Options are 'locked' or 'unlocked'.",
            choices=["locked", "unlocked"])


########## helper functions ##########

# This error is thrown when something unexpected happens durring
# serial commuication with the arduino
class SerialError(Exception):
    def __init__(self, value):
        self.value = value
    def __str__(self):
        return str(self.value)


# Returns either the string 'locked' or 'unlocked'.
# Throws SerialError.
def get_state():
    # TODO
    return "locked"


def set_state(state):
    if (state == "locked"):
        lock()
    elif (state == "unlocked"):
        unlock()
    

# Throws SerialError.
def lock():
    # TODO
    pass


# Throws SerialError.
def unlock():
    # TODO
    pass


########## main ##########

def main():
    exstat = 0
    args = vars(parser.parse_args())
    
    try:
        if (args["get_state"]):
            state = get_state()
            sys.stdout.write(state+"\n")
        else:
            set_state(args["set_state"])
    except SerialError as err:
        sys.stderr.write("Caught SerialError: \n"+str(err))
        exstat = 1
    exit(exstat)

if __name__ == "__main__": main()
