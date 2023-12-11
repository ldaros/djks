# djks

## Iniciando

Este documento fornece instruções sobre como configurar o ambiente para desenvolvimento e teste do projeto.

### Pré-requisitos

Antes de iniciar, você precisará das seguintes ferramentas instaladas:

- CMake
- GCC/G++

### Instalando as Dependências

Para instalar as dependências necessárias, execute o script `setup_dependencies.sh`:

```bash
cd scripts
./setup_dependencies.sh
```

Este script irá instalar o CMake, o GCC/G++ no seu sistema.

### Compilando o Projeto

Para compilar o projeto, utilize o script `build_and_run.sh` que se encontra no diretório `scripts`:

```bash
cd scripts
./build_and_run.sh
```

Este script irá criar um diretório `build`, compilar o projeto e executar o executável principal.

## Executando os Testes

Os testes automatizados podem ser executados usando o seguinte comando a partir do diretório `build`:

```bash
./djks_tests
```

Certifique-se de que todos os testes passam sem erros.

## Autores

- **Luan Daros** - _Desenvolvedor_ - [ldaros](https://github.com/ldaros)
