# Lemon Girls

## Create you'r AI character and chat with him/her.
### You can select gender, age, name.



# Installation 

## Linux & macOS

### Install Ollama

```bash
curl -fsSL https://ollama.com/install.sh | sh
```

### Start the Ollama API server

```bash
ollama serve
```

> **Do NOT close the terminal after running this command.**

### Install model

```bash
ollama pull qwen3.5:4b
```

### Clone repository and build

```bash
git clone https://github.com/KoTTana24/LemonGirls.git
cd LemonGirls
mkdir build
cd build
cmake ..
cmake --build .
```

### Start

```bash
./LemonGirls
```

## Windows

### Install Ollama

Download and install Ollama from:

https://ollama.com/download/windows

### Start the Ollama server

After installation, launch **Ollama** from the Start Menu. It will start in the system tray automatically.

Or run in PowerShell:

```powershell
ollama serve
```

> **Do NOT close the terminal if you started Ollama manually.**

### Install model

```powershell
ollama pull qwen3.5:4b
```

### Clone repository

```powershell
git clone https://github.com/KoTTana24/LemonGirls.git
cd LemonGirls
```

### Build

#### Using CMake

```powershell
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### Start

If you built in **Release** mode:

```powershell
.\Release\LemonGirls.exe
```

Otherwise:

```powershell
.\LemonGirls.exe
```
