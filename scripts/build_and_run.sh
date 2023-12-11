#!/bin/bash

# Parando a execução se algum comando falhar
set -e

# Diretório onde o projeto está localizado (um nível acima do diretório do script)
PROJECT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"/..

# Criando e entrando no diretório de build
mkdir -p "$PROJECT_DIR/build"
cd "$PROJECT_DIR/build"

# Gerando os Makefiles com CMake e compilando o projeto
cmake ..
make

# Executando o executável principal
./djks
