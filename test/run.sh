#! /bin/sh

if ! [ -d "./build" ]; then
    mkdir "build"
fi

if [ $# -ne 1 ]; then
    echo "expected 'run.sh [file name without extension]'"
    exit 1
fi

if ! [ -f "$1.c" ]; then
    echo "'$1.c' does not exist"
    exit 1
fi

if [ -f "build/$1" ]; then
    rm build/"$1"
fi

isgcc="no"
case "$(type gcc)" in "gcc is"*)
    isgcc="yes"
esac

if [ isgcc = "yes" ]; then
    gcc "$1.c" -o "build/$1"
else
    clang $1.c -o build/$1
fi

if [ -f "build/$1" ]; then
    ./build/"$1"
fi