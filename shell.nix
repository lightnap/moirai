# Nix shell script. Used by the nix package manager to load all libraries that the project uses.
{ pkgs ? import <nixpkgs> {} } :
  pkgs.mkShell {
    packages = with pkgs; [
      #gnat13 # gcc and utils
      clang # Version 17
      clang-tools
      cmake
      gnumake
      bashInteractiveFHS
      kdePackages.wayland # This contains the wayland protocols.
      wayland-scanner
      pkg-config
      libxkbcommon
      libffi
      libGL # OpenGL.
    ];
    # This makes it so that the dynamic linker can find the listed libraries.
    LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath (with pkgs; [
        wayland
	libxkbcommon
    ]);
} 
