# This script is meant for building, dependency handling and cleaning build artifacts.
# In general it handles all project actions whose commands are long.

import argparse


def configure_argument_parser(parser):
    parser.add_argument(
        "-c", "--clean", action="store_true", help="Clean all build artifacts"
    )
    parser.add_argument(
        "-b", "--build", action="store_true", help="Build project, in debug mode"
    )

    # TODO: Sone level of verbosity,


def check_argument_validity(parser, args):
    if not args.clean and not args.build:
        parser.error("No action requested, please select one of the available actions")


def perform_clean_action():
    print("[DO SCRIPT]: Cleaning all previous builds")
    # TODO: The commands that clean previous builds


def perform_build_action():
    print("[DO SCRIPT]: Building the moirai project")
    # TODO: The commands that build the project


def main():
    print("[DO SCRIPT]: Invoked the project manager script")
    parser = argparse.ArgumentParser(description="Script to manage the moirai project.")
    configure_argument_parser(parser)
    args = parser.parse_args()
    check_argument_validity(parser, args)

    if args.clean:
        perform_clean_action()

    if args.build:
        perform_build_action()

    print("[DO SCRIPT]: Finished!")


if __name__ == "__main__":
    main()
