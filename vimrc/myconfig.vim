call plug#begin()
Plug 'scrooloose/nerdtree'
Plug 'majutsushi/tagbar'
" vim-airline
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
" vim-illuminate
Plug 'rrethy/vim-illuminate'
" IndentLine
Plug 'Yggdroot/indentLine'
Plug 'Mofiqul/vscode.nvim'
" Python 自动补全
Plug 'davidhalter/jedi-vim'
" 可以在导航目录中看到git版本信息
Plug 'Xuyuanp/nerdtree-git-plugin'
" markdown插件
Plug 'iamcco/mathjax-support-for-mkdp'
Plug 'iamcco/markdown-preview.vim'
" 在vim中tab补全
Plug 'vim-scripts/SuperTab'


call plug#end()

" $VIMRUNTIME refers to the versioned system directory where Vim stores its
" system runtime files -- /usr/share/vim/vim<version>.
"
" Vim will load $VIMRUNTIME/defaults.vim if the user does not have a vimrc.
" This happens after /etc/vim/vimrc(.local) are loaded, so it will override
" any settings in these files.
"
" If you don't want that to happen, uncomment the below line to prevent
" defaults.vim from being loaded.
" let g:skip_defaults_vim = 1
"
" If you would rather _use_ default.vim's settings, but have the system or
" user vimrc override its settings, then uncomment the line below.
" source $VIMRUNTIME/defaults.vim

" All Debian-specific settings are defined in $VIMRUNTIME/debian.vim and
" sourced by the call to :runtime you can find below.  If you wish to change
" any of those settings, you should do it in this file or
" /etc/vim/vimrc.local, since debian.vim will be overwritten everytime an
" upgrade of the vim packages is performed. It is recommended to make changes
" after sourcing debian.vim so your settings take precedence.

runtime! debian.vim

" Uncomment the next line to make Vim more Vi-compatible
" NOTE: debian.vim sets 'nocompatible'.  Setting 'compatible' changes
" numerous options, so any other options should be set AFTER changing
" 'compatible'.
"set compatible

" Vim5 and later versions support syntax highlighting. Uncommenting the next
" line enables syntax highlighting by default.
if has("syntax")
  syntax on
endif

" If using a dark background within the editing area and syntax highlighting
" turn on this option as well
set background=dark

" Uncomment the following to have Vim jump to the last position when
" reopening a file
"au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif

" Uncomment the following to have Vim load indentation rules and plugins
" according to the detected filetype.
filetype plugin indent on

" The following are commented out as they cause vim to behave a lot
" differently from regular Vi. They are highly recommended though.
"set showcmd		" Show (partial) command in status line.
set showmatch		" Show matching brackets.
set ignorecase		" Do case insensitive matching
set smartcase		" Do smart case matching
set incsearch		" Incremental search
"set autowrite		" Automatically save before commands like :next and :make
set hidden		" Hide buffers when they are abandoned
set mouse=a		" Enable mouse usage (all modes)

" Source a global configuration file if available
if filereadable("/etc/vim/vimrc.local")
  source /etc/vim/vimrc.local
endif

set list lcs=tab:\|\   		" Set to use a vertical bar  when displaying Tab characters
set number
set tabstop=4
set autoindent
set cindent "针对 C 语言代码启用自动缩进功能。这会影响大括号、关键字后的自动缩进行为。
set st=4 "设置软制表符（softtabstop）宽度为4个空格。这意味着当按下 Tab 键时，即使实际写入的是制表符，其效果也会表现为 4 个空格。
set shiftwidth=4  "设置自动缩进时的宽度为 4 个空格。使用命令 gg=G 时，自动缩进为 4 个空格。
set sts=4 "设置在插入模式下按下 Tab 键时插入的空格数为 4 个。这通常与tabstop和shiftwidth设置保持一致，以维持代码的一致性。

set ruler " 显示光标当前位置的行号和列号。

set showmode " 显示当前Vim的工作模式（如 Normal、Insert 等）在屏幕的左下角，帮助用户了解当前的操作环境。

set bg=dark " 设置编辑器的背景色为深色，以适应暗色主题。
set hlsearch " 启用搜索高亮功能，使得进行搜索时匹配的文本被高亮显示。
set laststatus=2 " 总是显示状态栏。确保状态栏在任何时候都可见，提供有关文件名、模式和编码等信息。
" Set Automatically Complete Parentheses
set clipboard=unnamed
vnoremap <C-c> :w !xclip -selection clipboard<CR>

inoremap ' ''<LEFT>
inoremap " ""<LEFT>
inoremap ( ()<LEFT>
inoremap [ []<LEFT>
"inoremap < <><ESC>i
inoremap { {}<LEFT>


" Configure the NERDTree plugin mapping button
" Automatically open NERDTree after opening the file
autocmd VimEnter * NERDTree
" Key F2: Map other tabs
"map <F2> :NERDTreeMirror<CR>
" Key F3: Expand/shrink NERDTree
"map <F3> :NERDTreeToggle<CR>
" Key f: In the NERDTree window, jump the cursor to the currently open file.
map <C-f> :NERDTreeFind<CR>
" Key 1: Switch to the previous tab
"map 1 :tabp<CR>
" Key 2: Switch to the next tab
"map 2 :tabn<CR>


" Configure the Tagbar plugin mapping button
" Set the plug-in of ctags used by tagbar
let g:tagbar_ctags_bin='/usr/bin/ctags'
" Key F4: Shrink/Expand Tagbar Window
map <F4> :TagbarToggle<CR>
" Set the window width of tagbar to 35
let g:tagbar_width = 35
" Append the C/C++standard library header file to tags
set tags+=/usr/include/tags
" Open the tagbar automatically when opening the file
autocmd BufReadPost *.cpp,*.c,*.h,*.cc,*.cxx call tagbar#autoopen()

" airline
" Set up the theme
let g:airline_theme = 'angr'

" 配置单词高亮
hi illuminatedWord ctermfg=white ctermbg=8

" 配置括号匹配高亮
hi MatchParen cterm=none ctermfg=white ctermbg=8


" IndentLine
" Enable IndentLine plugin
let g:indentLine_enabled = 1
" Set the characters for the indentation line, with a default value of '|'
let g:indentLine_char = '|'
" Make the plugin run properly
let g:indentLine_conceallevel = 2
" 终端颜色
let g:indentLine_color_term = 239
 
" GUI 颜色
let g:indentLine_color_gui = '#A4E57E'

" 插入模式下自动跳过右括号
inoremap <expr> ) JumpOver(')')
inoremap <expr> ] JumpOver(']')
inoremap <expr> } JumpOver('}')

function! JumpOver(char)
    let line = getline('.')
    let col = col('.')
    " 如果光标后面是要跳过的括号，则光标右移，否则插入字符
    if col <= len(line) && line[col - 1] == a:char
        return "\<Right>"
    endif
    return a:char
endfunction

" 退格时成对删除括号
inoremap <expr> <BS> DeletePair()

function! DeletePair()
    let col = col('.')  " 获取光标位置
    if col <= 1  " 如果光标在行首，执行普通退格
        return "\<BS>"
    endif

    let line = getline('.')  " 获取当前行的内容
    let len_line = len(line)  " 获取当前行的长度

    " 获取光标前后字符，避免越界访问
    let prev_char = col > 1 ? line[col - 2] : ''
    let next_char = col <= len_line ? line[col - 1] : ''

    " 使用 `and` 替代 `&&`，避免 `invalid expression` 错误
    if ( (prev_char == '(' && next_char == ')') || (prev_char == '[' && next_char == ']') || (prev_char == '{' && next_char == '}') )
        return "\<BS>\<Right>\<BS>"
    endif

    " 否则执行普通退格
    return "\<BS>"
endfunction


" 启用 Python 代码自动补全
let g:jedi#completion_enabled = 1
" 设置自动补全菜单的最大高度
let g:jedi#popup_on_dot = 1
let g:jedi#popup_select_first = 0
let g:jedi#popup_select_single_mappings = 1
let g:jedi#popup_select_at_cursor = 1


"\1 发送运行命令到右侧pane并移到光标到右侧
nnoremap <Leader>1 :w \| call system("tmux send-keys -t right 'python3 " . shellescape(expand('%')) . "' Enter") \| call system("tmux select-pane -R")<CR>

"\2 发送运行命令到下侧pane并移到光标到下侧
"待定
