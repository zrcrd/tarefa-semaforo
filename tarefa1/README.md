# Projeto Semáforo - Raspberry Pi Pico W

Atividade avaliativa proposta pelo **Cepedi** como parte dos critérios de avaliação do curso de capacitação em software e sistemas embarcados (**Embarcatech**).

## 📚 Sumário
- Proposta de Projeto
- Objetivos
- Componentes Utilizados
- Funcionalidades Implementadas
- Requisitos Técnicos
- Como Executar
- Estrutura do Repositório
- Demonstração
- Contribuições
- Licença
- Contato

## 📋 Proposta de Projeto
Este projeto tem como objetivo consolidar os conceitos relacionados ao controle de LEDs utilizando o **Raspberry Pi Pico W**. O desenvolvimento propõe a simulação de um semáforo, alternando entre três cores e exibindo mensagens na porta serial.

## 🎯 Objetivos
- Compreender o funcionamento dos GPIOs no **RP2040**.
- Implementar um semáforo funcional com LEDs.
- Exibir mensagens na porta serial.
- Desenvolver uma aplicação funcional combinando hardware e software.

## 🛠️ Componentes Utilizados
- Raspberry Pi Pico W
- LED Vermelho - **GPIO 15**
- LED Amarelo - **GPIO 14**
- LED Verde - **GPIO 13**
- Resistores de 330Ω
- Protoboard e fios jumper

## ⚙️ Funcionalidades Implementadas
- Alternância dos estados do semáforo a cada 3 segundos.
- LEDs controlados via GPIOs.
- Mensagens exibidas na porta serial a cada 1 segundo.
- Implementação em **C** utilizando o **Pico SDK**.

## 📝 Requisitos Técnicos
- Utilização do **Raspberry Pi Pico W**.
- Controle de LEDs utilizando GPIOs.
- Uso de **CMake** para compilação.
- Código bem estruturado e comentado.

## 🚀 Como Executar
1. Baixe ou clone o repositório do projeto no seu computador.
2. Acesse a pasta do projeto pelo terminal ou explorador de arquivos.
3. Crie uma pasta chamada `build` dentro do diretório do projeto.
4. Compile o código utilizando o CMake e o Make.
5. Conecte o Raspberry Pi Pico W ao computador no modo de bootloader.
6. Copie o arquivo gerado `.uf2` para a unidade de armazenamento do Pico W.
7. Execute o projeto e observe o funcionamento do semáforo.

## 📂 Estrutura do Repositório
O repositório contém os seguintes arquivos e pastas:

- `projeto_semaforo.c` - Código-fonte principal.
- `CMakeLists.txt` - Arquivo de configuração do CMake.
- `pico_sdk_import.cmake` - Arquivo de configuração do SDK do Pico.
- `.gitignore` - Configuração para ignorar arquivos no Git.
- `.vscode/` - Configurações do Visual Studio Code.



## 🤝 Contribuições
Sinta-se à vontade para contribuir com melhorias e sugestões!

## 📄 Licença
Este projeto está licenciado sob a **MIT License**.

## 📧 Contato
Entre em contato pelo e-mail: jose.s0805@ufob.edu.br

