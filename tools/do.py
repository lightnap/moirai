#! /usr/bin/env python3
# This script is meant for building, dependency handling and cleaning build artifacts.
# In general it handles all project actions whose commands are long.

import argparse
import pathlib
import shutil
import subprocess
import sys


def configure_argument_parser(parser):
    parser.add_argument(
        "-c", "--clean", action="store_true", help="Clean all build artifacts"
    )
    parser.add_argument(
        "-b", "--build", action="store_true", help="Build project, in debug mode"
    )

    # TODO: Implement verbosity levels.


def delete_all_directory_files(dir_path):
    print(
        "[DO][CLEAN]: Deleting all files from directory [",
        dir_path.parent.name + "/" + dir_path.name,
        "]",
    )

    for file_path in pathlib.Path.iterdir(dir_path):
        try:
            if pathlib.Path.is_file(file_path) or pathlib.Path.is_symlink(file_path):
                pathlib.Path.unlink(file_path)
                # print("  Deleting file/symling", file_path) # TODO: Implement verbosity levels.
            elif pathlib.Path.is_dir(file_path):
                shutil.rmtree(file_path)
                # print("  Deleting directory", file_path) # TODO: Implement verborisy levels.
        except Exception as e:
            print("[DO][CLEAN]: Failed to delete %s. Reason: %s" % (file_path, e))
            print("[DO] Terminating program...")
            sys.exit(1)


def perform_clean_action():
    print("[DO][CLEAN]: Cleaning all previous builds")

    main_project_dir_path = pathlib.Path(__file__).resolve().parents[1]
    build_dir_path = main_project_dir_path.joinpath("build")
    bin_dir_path = main_project_dir_path.joinpath("bin")
    external_dir_path = main_project_dir_path.joinpath("external")
    raylib_dir_path = external_dir_path.joinpath("raylib")

    delete_all_directory_files(build_dir_path)
    delete_all_directory_files(raylib_dir_path)
    delete_all_directory_files(bin_dir_path)

    print("[DO][CLEAN]: Finished!")


def perform_build_action():
    print("[DO][BUILD]: Building the moirai project")

    main_project_dir_path = pathlib.Path(__file__).resolve().parents[1]
    build_dir_path = main_project_dir_path.joinpath("build")
    cmake_configure_result = subprocess.run(
        [
            "cmake",
            "-S",
            main_project_dir_path,
            "-B",
            build_dir_path,
            "-G",
            "Unix Makefiles",
        ]
    )

    if cmake_configure_result.returncode != 0:
        print("[DO][BUILD]: Error during the cmake configuration phase.")
        print("[DO] Terminating program...")
        sys.exit(1)

    cmake_build_result = subprocess.run(
        ["cmake", "--build", build_dir_path, "--parallel", "10"]
    )

    if cmake_build_result.returncode != 0:
        print("[DO][BUILD]: Error during the compilation/linking step.")
        print("[DO] Terminating program...")
        sys.exit(1)

    print("[DO][BUILD]: Finished!")


def main():
    print("[DO]: Invoked the project manager script")
    parser = argparse.ArgumentParser(description="Script to manage the moirai project.")
    configure_argument_parser(parser)
    args = parser.parse_args()

    if not args.clean and not args.build:
        parser.error("No action requested, please select one of the available actions")

    if args.clean:
        perform_clean_action()

    if args.build:
        perform_build_action()

    print("[DO]: Finished!")


if __name__ == "__main__":
    main()
