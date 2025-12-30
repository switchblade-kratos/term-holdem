# term-holdem
A CLI for playing a terminal-based Texas Hold'em with your own computer

## Usage

term-holdem [options]

Options:
-  `-h`, `--help`                    Show help
-  `-v`, `--version`                 Show version information
-  `--no-color`, `--no-colour`       Disables no-color

### Terminal support

term-holdem uses ANSI escape codes.

Supported:
- Linux terminals
- macOS Terminal/iTerm
- Windows Terminal
- PowerShell (modern)
- WSL

Not supported:
- legacy cmd.exe

# Installation

`git clone https://github.com/switchblade-kratos/term-holdem.git`
`cd term-holdem`
`make`
`sudo make install`


# Uninstall 

`sudo make uninstall`
