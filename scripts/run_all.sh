#!/usr/bin/env bash
set -e

root="$(cd "$(dirname "$0")/.." && pwd)"
build="$root/build"
filter="${1:-week_}"

mkdir -p "$build"

for source in "$root"/src/"$filter"*/*.cpp; do
    directory="$(dirname "$source")"
    week="$(basename "$directory" | cut -d_ -f1,2)"
    name="${week}_$(basename "$source" .cpp)"

    g++ -std=c++17 -Wall -Wextra -I"$directory" "$source" -o "$build/$name"

    echo "=== $name"
    "$build/$name"
    echo
done
