# QuickCG Test

Teste da biblioteca [QuickCG](https://lodev.org/) com SDL1.2.

## Estrutura

```
.
├── src/         # código principal
├── include/     # headers (quickcg.h)
├── lib/         # sources da lib (quickcg.cpp)
├── bin/         # executável gerado (ignorado pelo git)
├── compile.sh   # script de compilação
└── README.md
```

## Dependências (Ubuntu/Debian)

```bash
sudo apt install libsdl1.2-dev libsdl-gfx1.2-dev
```

## Compilar e rodar

```bash
./compile.sh
```

O executável fica em `bin/main`.