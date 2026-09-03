#!/bin/bash
set -e

SRC="src"
LIB="lib"
INC="include"
BIN="bin"
OUT="$BIN/main"

mkdir -p "$BIN"

g++ -I"$INC" "$SRC/main.cpp" "$LIB/quickcg.cpp" -o "$OUT" -lSDL -lSDL_gfx

echo "Compilou: $OUT"
./"$OUT"