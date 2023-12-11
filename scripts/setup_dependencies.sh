#!/bin/bash

# Parando a execução se algum comando falhar
set -e

# Atualizando os pacotes disponíveis e suas versões
sudo apt-get update

# Instalando o CMake e o g++
sudo apt-get install -y cmake g++

echo "Todas as dependências foram instaladas com sucesso."
