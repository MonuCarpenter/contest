#!/usr/bin/env bash
set -euo pipefail

if [ $# -ne 1 ]; then
  echo "Usage: $0 <folder>"
  exit 1
fi

folder="$1"

git add . ":(exclude)$folder"
git commit -m "added: codeforces solutions $folder"
git push origin main
./run "$folder"
