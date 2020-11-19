#/usr/bin/bash

function err_cd() {
    echo "create dirctory $1 failed"
}

function err_cf() {
    echo "create file $1 failed"
}


if [[ ! -e ~/.vim ]]; then 
    mkdir ~/.vim;
    if [[ $? -ne 0 ]]; then err_cd("~/.vim"); exit 1; done
    if [[ ! -e ~/.vim/plugin ]]; then 
        mkdir ~/.vim/plugin
        mkdir ~/.vim/doc
    fi
fi

ctags_path=$(which ctags)

