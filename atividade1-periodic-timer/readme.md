# 🚦 Atividade 1 - Semáforo com Temporizador Periódico

## 📚 Descrição do Projeto
Este projeto implementa um **semáforo** utilizando a placa **RP2040**, onde três LEDs (vermelho, amarelo e verde) alternam automaticamente em um ciclo contínuo, simulando o funcionamento de um semáforo real. 

A mudança de estados ocorre a cada **3 segundos**, utilizando um **temporizador periódico** para controlar a transição dos sinais.

---

## 🎯 Funcionalidades Implementadas

1. **Controle automático dos LEDs do semáforo**  
   - LED **vermelho** acende por 3 segundos. 🔴  
   - LED **amarelo** acende por 3 segundos. 🟡  
   - LED **verde** acende por 3 segundos. 🟢  
   - O ciclo reinicia continuamente.

2. **Uso de temporizador periódico**  
   - Alternância dos LEDs sem necessidade de interação manual.

3. **Mensagens de depuração via serial**  
   - Exibe mensagens indicando o estado atual do semáforo.

---

## 🛠️ Componentes Utilizados

### **Hardware**
- **LED Vermelho** - GPIO 11  
- **LED Amarelo** - GPIO 12  
- **LED Verde** - GPIO 13  

### **Software**
- **RP2040 SDK**
- **Linguagem C**
- **Biblioteca `hardware/timer.h` para uso do temporizador periódico**

---

## ⚙️ Diagrama de Conexões

| LED       | GPIO  | Função    |
|-----------|-------|-----------|
| Vermelho  | 11    | Parar     |
| Amarelo   | 12    | Atenção   |
| Verde     | 13    | Seguir    |

---

## 📂 Organização do Código

- **`atividade1-periodic-timer.c`**  
  - Configuração dos GPIOs dos LEDs.  
  - Implementação do temporizador periódico para alternar os LEDs.  
  - Loop principal para depuração via serial.  

---

## 🛠️ Instruções de Compilação e Execução

1. Clone o repositório para o ambiente local.
2. Certifique-se de que o **RP2040 SDK** está configurado corretamente.
3. Compile o código e carregue o firmware na placa **RP2040**.
4. Conecte a placa e observe os LEDs alternando automaticamente.

---

## 📹 Demonstração do Projeto

- O vídeo de demonstração exibe:  
  - A sequência de troca do semáforo.  
  - O funcionamento do temporizador.  
  - A saída das mensagens no console serial.

---

## 💻 Autor
- **Matheus Gouveia de Deus Bastos**

---

## 📜 Licença
Este projeto é de uso acadêmico e segue as diretrizes da Embarcatech.
