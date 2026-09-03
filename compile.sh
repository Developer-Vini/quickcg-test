#!/bin/bash
g++ main.cpp quickcg.cpp -o main -lSDL -lSDL_gfx

if [ $? -eq 0 ]; then
    echo "Compilou com sucesso! Rodando..."
    ./main
else
    echo "Erro na compilação."
fi