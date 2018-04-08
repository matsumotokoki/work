set nu
set expandtab
set tabstop=4
set autoindent
set smartindent
set shiftwidth=2
set incsearch
set ignorecase
set smartcase
set hlsearch
nnoremap <Esc><Esc> :nohlsearch<CR>
set whichwrap=b,s,h,l,<,>,[,],~
set backspace=indent,eol,start
set wildmenu
set history=1000
if &term =~ "xterm"
    let &t_SI .= "\e[?2004h"
    let &t_EI .= "\e[?2004l"
    let &pastetoggle = "\e[201~"
    function XTermPasteBegin(ret)
      set paste
      return a:ret
    endfunction

  ¦ inoremap <special> <expr> <Esc>[200~ XTermPasteBegin("")
endif
"dein Scripts-----------------------------
if &compatible
  set nocompatible               " Be iMproved
  endif
" Required:
  set
  runtimepath+=/home/koki/.cache/dein/repos/github.com/Shougo/dein.vim
" Required:
  if dein#load_state('/home/koki/.cache/dein')
    call dein#begin('/home/koki/.cache/dein')
" Let dein manage dein
" Required:
  call dein#add('/home/koki/.cache/dein/repos/github.com/Shougo/dein.vim')
" Add or remove your plugins here:
 call dein#add('tomasr/molokai')
 call dein#add('itchyny/lightline.vim')
  ¦ set laststatus=2 " ステータスラインを常に表示
  ¦ set showmode " 現在のモードを表示
  ¦ set showcmd " 打ったコマンドをステータスラインの下に表示
  ¦ set ruler " ステータスラインの右側にカーソルの現在位置を表示する
 call dein#add('scrooloose/nerdtree')
 call dein#add('Yggdroot/indentLine')
 call dein#add('Shougo/neosnippet.vim')
 call dein#add('Shougo/neosnippet-snippets')
 call dein#add('Shougo/neocomplete.vim')
 call dein#add('tpope/vim-fugitive')
  ¦ let g:acp_enableAtStartup=0
  ¦ let g:neocomplete#enable_at_startup=1
  ¦ let g:neocomplete#enable_smart_case=1
  ¦ let g:neocomplete#sources#syntax#min_keyword_lenth=2
  ¦ let gLneocomplete#lock_buffer_name_pattern='\*ku\*'
  ¦ if !exists('g:neocomplete#keyword_patterns')
  ¦ ¦ ¦let g:neocomplete#keyword_patterns={}
  ¦ endif
  ¦ let g:neocomplete#keyword_patterns['default']='\h\w*'
  ¦ inoremap <expr><C-g> neocomplete#undo_completion()
  ¦ inoremap <expr><C-l> neocomplete#complete_common_string()
  ¦ inoremap <expr><TAB> pumvisible() ? "\<C-n>" : "\<TAB>"
"You can specify revision/branch/tag.
" call dein#add('Shougo/deol.nvim')
" Required:
call dein#end()
  ¦ set background=dark
  ¦ colorscheme molokai
  ¦ syntax on
  call dein#save_state()
endif
" Required:
filetype plugin indent on
syntax enable
" If you want to install not installed plugins on startup.
if dein#check_install()
  call dein#install()
endif
"End dein Scripts-------------------------
