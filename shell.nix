{ pkgs ? import <nixpkgs> {} } :
  pkgs.mkShell {
    packages = with pkgs; [
      #gnat13 # gcc and utils
      clang # Version 17
      clang-tools
      cmake
      gnumake
      bashInteractiveFHS
      cool-retro-term 
    ];
} 
