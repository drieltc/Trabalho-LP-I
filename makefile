# Compilador
CC = g++

# Flags de Compilacao
##-Wall -> habilita avisos de compilacao importantes
##-g -> gera infos de depuracao
##-Iheaders -> adiciona o diretorio heares a lista de diretorios que o compilador procura arquivos
CFLAGS = -Wall -g -Iheaders

# Nome do Executavel
TARGET = main

# Diretório para arquivos objeto
OBJDIR = obj

# Arquivos Objeto
OBJS = $(OBJDIR)/main.o $(OBJDIR)/Cidade.o $(OBJDIR)/Controlador.o $(OBJDIR)/Passageiro.o $(OBJDIR)/Trajeto.o $(OBJDIR)/Transporte.o $(OBJDIR)/Viagem.o

# Regra padrao para construir o executavel 
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regras para construir arquivos objeto
## alvo: dependencias {cpp e h} | $(OBJDIR) {$(OBJDIR) e criado antes das dependencias}
### $(CC) {chama o compilador} $(CFLAGS) {chama as flags} -c {compilador deve compilar, nao linkar} [...].cpp {arquivo a ser compilado} -o [...].o {nome do arquivo de saida}
$(OBJDIR)/main.o: main.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/Cidade.o: classes/Cidade.cpp headers/Cidade.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c classes/Cidade.cpp -o $(OBJDIR)/Cidade.o

$(OBJDIR)/Controlador.o: classes/Controlador.cpp headers/Controlador.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c classes/Controlador.cpp -o $(OBJDIR)/Controlador.o

$(OBJDIR)/Passageiro.o: classes/Passageiro.cpp headers/Passageiro.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c classes/Passageiro.cpp -o $(OBJDIR)/Passageiro.o

$(OBJDIR)/Trajeto.o: classes/Trajeto.cpp headers/Trajeto.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c classes/Trajeto.cpp -o $(OBJDIR)/Trajeto.o

$(OBJDIR)/Transporte.o: classes/Transporte.cpp headers/Transporte.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c classes/Transporte.cpp -o $(OBJDIR)/Transporte.o

$(OBJDIR)/Viagem.o: classes/Viagem.cpp headers/Viagem.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c classes/Viagem.cpp -o $(OBJDIR)/Viagem.o

# Regra para criar o diretório obj se não existir
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Limpeza dos arquivos
clean:
	rm -f $(TARGET) $(OBJS)
	rm -rf $(OBJDIR)
