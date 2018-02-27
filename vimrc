set nocompatible
filetype off
filetype plugin indent on
set backspace=indent,eol,start
set number
set wildmenu
set history=5000
set autoindent
set fenc=utf-8
set nobackup
set cursorline
set smartindent
set showmatch
set matchtime=1
set wildmode=list:longest
set ignorecase
set smartcase
set incsearch
set tabstop=2
set hlsearch
nnoremap <Esc><Esc> :nohlsearch<CR><ESC>
syntax on
set whichwrap=b,s,h,l,<,>,[,],~
set display=lastline
nnoremap + <C-a>
nnoremap - <C-x>
set pumheight=20  "補完メニューの数
"-----------------------------------------------------------------------------------------
set completeopt=menuone
for k in split("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_",'\zs')
				 exec "imap " . k . " " . k . "<C-N><C-P>"
	endfor
imap <expr> <TAB> pumvisible() ? "\<Down>" : "\<Tab>"
"----------------------------------------------------------------------------------------------
"-------------------------------------------------------------------------------------------
"set completeopt=menuone
"for k in split("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_",'\zs')
"				  exec "imap <expr> " . k . " pumvisible() ? '" . k . "' : '" . k . "\<C-X>\<C-P>\<C-N>'"
"	endfor
"-----------------------------------------------------------------------------------------------
"set clipboard=unnamed,unnamedplus
set clipboard=unnamed,autoselect
"set background=dark
"Bundle 'itchyny/lightline.vim'
"colorscheme hybrid

"Bundle Scripts-----------------------------
if &compatible
				set nocompatible               " Be iMproved
endif

" Required:
set runtimepath+=/home/matsu/.vim/bundle/neobundle.vim/

" Required:
call neobundle#begin(expand('/home/matsu/.vim/bundle'))

" Let NeoBundle manage NeoBundle
" Required:
NeoBundleFetch 'Shougo/neobundle.vim'

" Add or remove your Bundles here:
NeoBundle 'Shougo/neosnippet.vim'
NeoBundle 'Shougo/neosnippet-snippets'
NeoBundle 'tpope/vim-fugitive'
NeoBundle 'ctrlpvim/ctrlp.vim'
NeoBundle 'flazz/vim-colorschemes'

" You can specify revision/branch/tag.
NeoBundle 'Shougo/vimshell', { 'rev' : '3787e5' }

"Required:
"call neobundle#end()

"Required:
filetype plugin indent on

" If there are uninstalled bundles found on startup,
" this will conveniently prompt you to install them.
NeoBundleCheck
"End NeoBundle Scripts-------------------------

""----------------------------------------------------------------------------
if has('vim_starting')
				set runtimepath+=~/.vim/bundle/neobandle.vim/
endif
NeoBundleFetch 'Shougo/neobundle.vim'
NeoBundle 'itchyny/lightline.vim'
set laststatus=2 " ステータスラインを常に表示
set showmode " 現在のモードを表示
set showcmd " 打ったコマンドをステータスラインの下に表示
set ruler " ステータスラインの右側にカーソルの現在位置を表示する
NeoBundleCheck
call neobundle#end()
colorscheme molokai " カラースキームにmolokaiを設定する
		set t_Co=256 " iTerm2など既に256色環境なら無くても良い
		syntax enable " 構文に色を付ける
