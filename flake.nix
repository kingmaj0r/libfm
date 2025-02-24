{
  description = "File manager library that provides all the essentials.";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-24.11";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachSystem [ "x86_64-linux" ] (system: let
      pkgs = nixpkgs.legacyPackages.${system};
    in {
      packages.filerix = pkgs.stdenv.mkDerivation rec {
        pname = "filerix";
        version = "1.0.3";

        src = ./.;

        nativeBuildInputs = [
          pkgs.cmake
          pkgs.make
          pkgs.pkg-config
          pkgs.zlib
        ];

        buildInputs = [
          pkgs.gcc
          pkgs.libcxx
        ];

        installPhase = ''
          sudo make install
        '';

        meta = with pkgs.lib; {
          description = "File manager library that provides all the essentials.";
          license = licenses.mit;
          platforms = platforms.linux;
        };
      };
    });
}
