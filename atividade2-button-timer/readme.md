# 🔘 Atividade 2 - Controle de LEDs com Botão

## 📚 Descrição do Projeto
Este projeto implementa o controle de três LEDs (azul, vermelho e verde) através de um **botão**. Quando o botão é pressionado, os LEDs acendem em sequência e apagam de forma programada.

---

## 🎯 Funcionalidades Implementadas

1. **Acionamento dos LEDs pelo botão**  
   - Ao pressionar o botão, **todos os LEDs acendem simultaneamente**.  
   - Após **3 segundos**, o LED **azul** apaga. 🔵❌  
   - Após **mais 3 segundos**, o LED **vermelho** apaga. 🔴❌  
   - Após **mais 3 segundos**, o LED **verde** apaga. 🟢❌  

2. **Uso de temporizadores para controle da sequência**  
   - Implementação de **chamadas assíncronas** para desligamento progressivo.

3. **Mensagens de depuração via serial**  
   - Indica os estados dos LEDs ao longo do ciclo.

---

## 🛠️ Componentes Utilizados

### **Hardware**
- **LED Azul** - GPIO 11  
- **LED Vermelho** - GPIO 12  
- **LED Verde** - GPIO 13  
- **Botão** - GPIO 5  

### **Software**
- **RP2040 SDK**
- **Linguagem C**
- **Biblioteca `hardware/timer.h` para controle de tempo**

---

## ⚙️ Diagrama de Conexões

| Componente  | GPIO  | Função                        |
|------------|------|--------------------------------|
| LED Azul   | 11   | Primeiro a apagar              |
| LED Vermelho | 12  | Segundo a apagar              |
| LED Verde  | 13   | Último a apagar                |
| Botão      | 5    | Dispara a sequência de LEDs   |

---

## 📂 Organização do Código

- **`atividade2-button-timer.c`**  
  - Configuração dos **GPIOs** para LEDs e botão.  
  - Configuração de temporizadores para desligamento progressivo.  
  - Callback para detectar o **pressionamento do botão** e iniciar a sequência.  

---

## 🛠️ Instruções de Compilação e Execução

1. Clone o repositório para o ambiente local.
2. Certifique-se de que o **RP2040 SDK** está configurado corretamente.
3. Compile o código e carregue o firmware na placa **RP2040**.
4. Pressione o botão e observe a sequência dos LEDs.

---

## 💻 Autor
- **Matheus Gouveia de Deus Bastos**

---

## 📜 Licença
Este projeto é de uso acadêmico e segue as diretrizes da Embarcatech.
