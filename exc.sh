#!/usr/bin/env bash
set -euo pipefail

if [ $# -ne 1 ]; then
  echo "Usage: $0 <folder>"
  exit 1
fi

folder="$1"

git add . ":(exclude)$folder"

if git diff --cached --quiet; then
  echo "No changes to commit. Skipping git commit and push."
else
  git commit -m "added: codeforces solutions $folder"
  git push origin main
fi

./run "$folder"
