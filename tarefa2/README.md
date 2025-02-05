# Projeto Botão OneShot - Raspberry Pi Pico W

Atividade avaliativa proposta pelo Cepedi como parte dos critérios de avaliação do curso de capacitação em software e sistemas embarcados (Embarcatech).

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
Este projeto tem como objetivo consolidar os conceitos relacionados ao uso de interrupções no Raspberry Pi Pico W, utilizando um botão configurado no modo "OneShot". O desenvolvimento propõe a captura de eventos de pressão de botão, garantindo que cada acionamento gere uma única resposta sem efeitos indesejados de "bouncing".

## 🎯 Objetivos
- Compreender o funcionamento das interrupções no microcontrolador RP2040.  
- Implementar um botão com efeito "OneShot" para evitar acionamentos repetidos.  
- Exibir mensagens na porta serial para indicar a detecção do evento.  
- Desenvolver uma aplicação funcional combinando hardware e software.  

## 🛠️ Componentes Utilizados
- Raspberry Pi Pico W  
- Botão de Pressão - GPIO 10  
- LED Indicador - GPIO 15  
- Resistores de 10kΩ (pull-down) e 330Ω (LED)  
- Protoboard e fios jumper  

## ⚙️ Funcionalidades Implementadas
- Detecção de pressão do botão utilizando interrupções.  
- Implementação do efeito "OneShot" para evitar acionamentos indesejados.  
- Acionamento de LED ao pressionar o botão.  
- Exibição de mensagens no terminal serial para cada acionamento do botão.  

## 📝 Requisitos Técnicos
- Utilização do Raspberry Pi Pico W.  
- Configuração de interrupções nos GPIOs.  
- Implementação de debounce via software.  
- Uso de CMake para compilação.  
- Código bem estruturado e comentado.  

## 🚀 Como Executar
1. Baixe ou clone o repositório do projeto no seu computador.  
2. Acesse a pasta do projeto pelo terminal ou explorador de arquivos.  
3. Crie uma pasta chamada `build` dentro do diretório do projeto.  
4. Compile o código utilizando o CMake e o Make.  
5. Conecte o Raspberry Pi Pico W ao computador no modo de bootloader.  
6. Copie o arquivo gerado `.uf2` para a unidade de armazenamento do Pico W.  
7. Execute o projeto e pressione o botão para testar o comportamento OneShot.  

## 📂 Estrutura do Repositório
O repositório contém os seguintes arquivos e pastas:
- `atividade2/` - Diretório contendo arquivos relacionados à segunda atividade.  
- `.vscode/` - Configurações do Visual Studio Code.  
- `.gitignore` - Configuração para ignorar arquivos no Git.  
- `CMakeLists.txt` - Arquivo de configuração do CMake.  
- `README.md` - Documento de descrição do projeto.  
- `pico_sdk_import.cmake` - Arquivo de configuração do SDK do Pico.  
- `projeto_oneshot.c` - Código-fonte principal.  
- `wokwi.toml` - Arquivo de configuração para simulação no Wokwi.  

## 🤝 Contribuições
Sinta-se à vontade para contribuir com melhorias e sugestões!

## 📄 Licença
Este projeto está licenciado sob a MIT License.

## 📧 Contato
Entre em contato pelo e-mail: jose.s0805@ufob.edu.br

