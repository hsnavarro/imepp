syntax on
set encoding=utf-8
set et ts=2 sw=0 sts=-1 ai nu hls cindent
set noswapfile
nnoremap ; :
vnoremap ; :
noremap <c-j> 15gj
noremap <c-k> 15gk
nnoremap <s-k> i<CR><ESC>
inoremap ,. <esc>
vnoremap ,. <esc>
nnoremap ,. <esc>

if empty(glob('~/.local/share/nvim/site/autoload/plug.vim'))
          silent !curl -fLo ~/.local/share/nvim/site/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
            autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
endif

"Plugins
call plug#begin('~/.data/nvim/plugged')
Plug 'vim-airline/vim-airline-themes'
Plug 'vim-airline/vim-airline'
Plug 'tpope/vim-fugitive'
Plug 'tomasiser/vim-code-dark'
call plug#end()

set t_Co=256
set t_ut=
colorscheme codedark

nmap <F8> :bprev<CR>
nmap <F9> :bnext<CR>

let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#formatter='unique_tail'

let g:airline#extensions#branch#enabled=1
let g:airline_theme='codedark'
let g:airline_powerline_fonts=1

let g:airline_section_a = airline#section#create(['mode', ' ', 'branch'])
