#
# ~/.bashrc
#
# If not running interactively, don't do anything
[[ $- != *i* ]] && return

alias ls='ls -a --color=auto'
alias grep='grep --color=auto'

alias f='fastfetch'
alias edit='nvim config.def.h && rm -rf config.h && sudo make clean install'
alias dwm='cd dotfiles/dwm/'

PS1='\[\033[1;33m\]φ \[\033[0m\]'
