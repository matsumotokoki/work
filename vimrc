"dein Scripts-----------------------------
if &compatible
  set nocompatible               " Be iMproved
endif
" Required:
set runtimepath+=/home/koki/.cache/dein/repos/github.com/Shougo/dein.vim
" Required:
if dein#load_state('/home/koki/.cache/dein')
  call dein#begin('/home/koki/.cache/dein')
" Let dein manage dein
" Required:
call dein#add('/home/koki/.cache/dein/repos/github.com/Shougo/dein.vim')
 " Add or remove your plugins here:
 call dein#add('itchyny/lightline.vim')
 call dein#add('scrooloose/nerdtree')
    let NERDTreeShowHidden = 0
    nmap tt :NERDTreeToggle<CR>
    nnoremap <C-n> gt
    nnoremap <C-p> gT
 call dein#add('jistr/vim-nerdtree-tabs')
    if argc()==1
      let g:nerdtree_tabs_open_on_console_startup=0
    end
 call dein#add('Yggdroot/indentLine')
 call dein#add('thinca/vim-quickrun')
    nmap qq :QuickRun<CR><C-w><C-w>
    nmap <C-z><C-z> :q<CR>
    let g:quickrun_config={'*':{'split':'vertical30sp'} }
    set splitright
 call dein#add('Townk/vim-autoclose') 
 call dein#add('airblade/vim-gitgutter')
    let g:gitgutter_highlight_lines = 1
    nmap hh :GitGutterLineHighlightsToggle<CR>
 call dein#add('Shougo/neosnippet.vim')
 call dein#add('Shougo/neosnippet-snippets')
 call dein#add('Shougo/neocomplete.vim')
    let g:neocomplete#enable_at_startup=1
    let g:neocomplete#enable_smart_case=1
    let g:neocomplete#sources#syntax#min_keyword_lenth=2
    let gLneocomplete#lock_buffer_name_pattern='\*ku\*'
    if !exists('g:neocomplete#keyword_patterns')
       let g:neocomplete#keyword_patterns={}
    endif
    let g:neocomplete#keyword_patterns['default']='\h\w*'
    inoremap <expr><C-g> neocomplete#undo_completion()
    inoremap <expr><C-l> neocomplete#complete_common_string()
    inoremap <expr><TAB> pumvisible() ? "\<C-n>" : "\<TAB>"
    "inoremap <expr><CR>  neocomplete#smart_close_popup()."\<CR>"
    inoremap <expr><BS> neocomplete#smart_close_popup()."\<C-h>"
    inoremap <expr><CR>  pumvisible() ? neocomplete#close_popup( ):"<CR>"
 call dein#add('tpope/vim-fugitive')
    let g:airline#extensions#branch#enabled=1
    let g:acp_enableAtStartup=0
    set statusline=%<%f\ %h%m%r%{fugitive#statusline()}%=%-14.(%l,%c%V%)\ %P
    if isdirectory(expand('~/.vim/bundle/vim-fugitive'))
        set statusline+=%{fugitive#statusline()}
    endif
  call dein#add('davidhalter/jedi-vim')
    autocmd FileType python setlocal completeopt-=preview
  call dein#add('jmcantrell/vim-virtualenv')
  call dein#add('hynek/vim-python-pep8-indent')
  call dein#add('tomasr/molokai')
  call dein#add('romainl/Apprentice')
  call dein#add('sjl/badwolf')
  call dein#add('jacoborus/tender.vim')
  call dein#add('Shougo/unite.vim')
"You can specify revision/branch/tag.
" call dein#add('Shougo/deol.nvim')
" Required:
call dein#end()
  call dein#save_state()
endif
" Required:
"filetype plugin indent on
syntax enable
" If you want to install not installed plugins on startup.
if dein#check_install()
  call dein#install()
endif
"End dein Scripts-------------------------
set nu
set fenc=utf-8
set expandtab
set tabstop=4
set autoindent
set virtualedit=onemore
set smartindent
set shiftwidth=2
set incsearch
set ignorecase
set smartcase
set title
set hlsearch
set noswapfile
set pumheight=10
set cursorline
set scrolloff=22
nnoremap n nzz 
nnoremap N Nzz
nnoremap * *zz
nnoremap # #zz
nnoremap g* g*zz
nnoremap g# g#zz
nnoremap j gj
nnoremap k gk
nnoremap <Down> gj
nnoremap <Up>   gk
nnoremap <C-j> <C-w>j
nnoremap <C-h> <C-w>h
nnoremap <C-k> <C-w>k
nnoremap <C-l> <C-w>l
hi clear Cursorline
nnoremap <silent><Esc><Esc> :nohlsearch<CR>
nmap ss :source ~/.vimrc<CR>
nnoremap <C-t> :terminal<CR>
set whichwrap=b,s,h,l,<,>,[,],~
set backspace=indent,eol,start
set wildmenu
set history=500
set clipboard=unnamed,autoselect

"#colorscheme#
set background=dark
colorscheme tender
syntax on
set t_Co=256

"#('itchyny/lightline.vim')#
set laststatus=2 " ステータスラインを常に表示
set showmode " 現在のモードを表示
set showcmd " 打ったコマンドをステータスラインの下に表示
set ruler " ステータスラインの右側にカーソルの現在位置を表示する
