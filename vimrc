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
set synmaxcol=150
set whichwrap=b,s,h,l,<,>,[,],~
set display=lastline
nnoremap + <C-a>
nnoremap - <C-x>
set pumheight=10  "補完メニューの数
"-----------------------------------------------------------------------------------------
"set completeopt=menuone
"for k in split("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_",'\zs')
"				 exec "imap " . k . " " . k . "<C-N><C-P>"
"	endfor
"imap <expr> <TAB> pumvisible() ? "\<Down>" : "\<Tab>"
"-----------------------------------------------------------------------------------------

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
NeoBundle 'Shougo/neocomplcache'
let g:acp_enableAtStartup = 0
let g:neocomplcache_enable_at_startup = 1
let g:neocomplcache_enable_smart_case = 1
let g:neocomplcache_min_syntax_length = 1
let g:neocomplcache_lock_buffer_name_pattern = '\*ku\*'
let g:neocomplcache_dictionary_filetype_lists = {
    \ 'default' : ''
    \ }
inoremap <expr><C-g>     neocomplcache#undo_completion()
inoremap <expr><C-l>     neocomplcache#complete_common_string()
inoremap <silent> <CR> <C-r>=<SID>my_cr_function()<CR>
function! s:my_cr_function()
				  return neocomplcache#smart_close_popup() . "\<CR>"
	endfunction
inoremap <expr><TAB>  pumvisible() ? "\<Down>" : "\<TAB>"
inoremap <expr><C-h> neocomplcache#smart_close_popup()."\<C-h>"
inoremap <expr><BS> neocomplcache#smart_close_popup()."\<C-h>"
inoremap <expr><C-y>  neocomplcache#close_popup()
inoremap <expr><C-e>  neocomplcache#cancel_popup()
inoremap <expr><CR>  pumvisible() ? neocomplcache#close_popup() : "<CR>"
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
